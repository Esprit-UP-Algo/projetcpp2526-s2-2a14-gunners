/**
 * SmartResearch — Single 7-Segment Display Controller
 * =====================================================
 * Hardware: Arduino + 1× raw 7-segment display (common anode)
 *
 * Wiring (unchanged from your original):
 *   Segment A ──► Pin 7    Segment B ──► Pin 6
 *   Segment C ──► Pin 4    Segment D ──► Pin 3
 *   Segment E ──► Pin 2    Segment F ──► Pin 8
 *   Segment G ──► Pin 9    DP        ──► Pin 5
 *
 * Protocol from Qt (9600 baud, newline-terminated):
 *   "PUB:<total>:<journals>:<conferences>\n"
 *   Example: "PUB:42:18:24\n"
 *
 * Display behaviour:
 *   - Each digit of the TOTAL is shown for DIGIT_HOLD_MS milliseconds
 *   - Then a blank gap of BLANK_MS before the next digit
 *   - After the full number, a longer pause before repeating
 *   - If total is 0, display shows "0"
 *
 * No library required — pure digitalWrite.
 */

// ── Pin definitions (keep your original wiring) ──────────────
const int A_PIN = 7, B_PIN = 6, C_PIN = 4, D_PIN = 3;
const int E_PIN = 2, F_PIN = 8, G_PIN = 9, DP_PIN = 5;

const int segPins[8] = {A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, F_PIN, G_PIN, DP_PIN};

// ── Timing configuration ──────────────────────────────────────
#define DIGIT_HOLD_MS   800   // ms each digit stays on screen
#define BLANK_MS        200   // ms blank gap between digits
#define END_PAUSE_MS   2000   // ms pause after displaying the full number

// ── 7-segment encoding: segments A-G (LOW = ON for common anode) ──
//                         A  B  C  D  E  F  G
const bool digits[10][7] = {
  {0, 0, 0, 0, 0, 0, 1},  // 0
  {1, 0, 0, 1, 1, 1, 1},  // 1
  {0, 0, 1, 0, 0, 1, 0},  // 2
  {0, 0, 0, 0, 1, 1, 0},  // 3
  {1, 0, 0, 1, 1, 0, 0},  // 4
  {0, 1, 0, 0, 1, 0, 0},  // 5
  {0, 1, 0, 0, 0, 0, 0},  // 6
  {0, 0, 0, 1, 1, 1, 1},  // 7
  {0, 0, 0, 0, 0, 0, 0},  // 8
  {0, 0, 0, 0, 1, 0, 0},  // 9
};

// ── Helpers ──────────────────────────────────────────────────

void showDigit(int num) {
  int pins[7] = {A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, F_PIN, G_PIN};
  num = constrain(num, 0, 9);
  for (int i = 0; i < 7; i++) {
    digitalWrite(pins[i], digits[num][i] ? HIGH : LOW);
  }
}

void blankDisplay() {
  // Turn all segments OFF (HIGH = off for common anode)
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], HIGH);
  }
}

// Scroll through every digit of `number`, one at a time
void scrollNumber(int number) {
  // Build digit array (handle 0 specially)
  char buf[12];
  itoa(number, buf, 10);
  int len = strlen(buf);

  for (int i = 0; i < len; i++) {
    showDigit(buf[i] - '0');
    delay(DIGIT_HOLD_MS);
    blankDisplay();
    delay(BLANK_MS);
  }
  delay(END_PAUSE_MS);
}

// ── Serial parsing ────────────────────────────────────────
// Accepts two message formats:
//   1. "PUB:<total>:<journals>:<conferences>"  → shows total
//   2. "<number>"                               → shows that number directly
//      (sent when user picks a specific journal from the dropdown)
// Returns the number to display, or -1 on error.

String inputBuffer = "";
int g_total       = 0;
bool g_hasData    = false;

int parseMessage(String msg) {
  msg.trim();

  // Format 1: PUB:total:journals:conferences
  if (msg.startsWith("PUB:")) {
    String data = msg.substring(4);
    int sep = data.indexOf(':');
    String totalStr = (sep >= 0) ? data.substring(0, sep) : data;
    for (int i = 0; i < (int)totalStr.length(); i++) {
      if (!isDigit(totalStr[i])) return -1;
    }
    return totalStr.toInt();
  }

  // Format 2: plain integer  e.g. "3"
  if (msg.length() > 0) {
    bool allDigits = true;
    for (int i = 0; i < (int)msg.length(); i++) {
      if (!isDigit(msg[i])) { allDigits = false; break; }
    }
    if (allDigits) return msg.toInt();
  }

  return -1;  // unrecognised
}

// ── Setup / Loop ─────────────────────────────────────────────

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 8; i++) {
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], HIGH);  // all OFF at start
  }

  // Show "8" (all segments) briefly as power-on test
  showDigit(8);
  delay(600);
  blankDisplay();
  delay(300);
}

void loop() {
  // 1. Read incoming serial data
  while (Serial.available()) {
    char c = (char)Serial.read();
    if (c == '\n') {
      if (inputBuffer.length() > 0) {
        int parsed = parseMessage(inputBuffer);
        if (parsed >= 0) {
          g_total   = parsed;
          g_hasData = true;
          Serial.println("OK");   // ACK back to Qt
        }
        inputBuffer = "";
      }
    } else if (c != '\r') {
      inputBuffer += c;
    }
  }

  // 2. Display: scroll through digits of total count if data received
  if (g_hasData) {
    scrollNumber(g_total);
  }
}
