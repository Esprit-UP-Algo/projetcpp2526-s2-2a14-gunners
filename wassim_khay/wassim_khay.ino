#define TRIG_PIN        10
#define ECHO_PIN         9
#define LED_GREEN        3
#define LED_RED          2
#define BUTTON_PIN       4

#define DIST_MIN         1
#define DIST_MAX        10

#define NO_DETECT_TIMEOUT   10000
#define RESULT_HOLD          3000
#define MEASURE_INTERVAL      150
#define BLINK_INTERVAL        300

enum State {
  IDLE,
  SCANNING,
  DETECTED,
  FAILED,
};

State         state           = IDLE;
unsigned long lastMeasure     = 0;
unsigned long scanStart       = 0;
unsigned long resultStart     = 0;
unsigned long lastBlink       = 0;
bool          blinkOn         = false;
bool          lastButtonState = HIGH;

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;
  return (duration * 0.0343) / 2.0;
}

bool buttonPressed() {
  bool current = digitalRead(BUTTON_PIN);
  if (current == LOW && lastButtonState == HIGH) {
    lastButtonState = current;
    return true;
  }
  lastButtonState = current;
  return false;
}

void startScan() {
  Serial.println("BUTTON_PRESSED");
  state       = SCANNING;
  scanStart   = millis();
  lastBlink   = millis();
  lastMeasure = 0;
  blinkOn     = true;
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED,   HIGH);
}

void goIdle() {
  state = IDLE;
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED,   LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN,   OUTPUT);
  pinMode(ECHO_PIN,   INPUT);
  pinMode(LED_GREEN,  OUTPUT);
  pinMode(LED_RED,    OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED,   LOW);
}

void loop() {
  unsigned long now = millis();

  // Bouton toujours écouté sauf pendant résultat
  if (state != DETECTED && state != FAILED && buttonPressed()) {
    startScan();
    return;
  }

  // ── IDLE ──────────────────────────────────────────────
  if (state == IDLE) {
    return;
  }

  // ── SCANNING : deux LEDs clignotent, on mesure ────────
  if (state == SCANNING) {

    if (now - lastBlink >= BLINK_INTERVAL) {
      lastBlink = now;
      blinkOn   = !blinkOn;
      digitalWrite(LED_GREEN, blinkOn ? HIGH : LOW);
      digitalWrite(LED_RED,   blinkOn ? HIGH : LOW);
    }

    if (now - lastMeasure >= MEASURE_INTERVAL) {
      lastMeasure = now;
      float dist  = measureDistance();
      bool inRange = (dist > 0 && dist >= DIST_MIN && dist <= DIST_MAX);

      if (inRange) {
        state       = DETECTED;
        resultStart = now;
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED,   LOW);
        Serial.println("1");
        return;
      }
    }

    if (now - scanStart >= NO_DETECT_TIMEOUT) {
      state       = FAILED;
      resultStart = now;
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED,   HIGH);
      Serial.println("0");
    }
  }

  // ── DETECTED : LED verte fixe 3s puis IDLE ────────────
  if (state == DETECTED) {
    if (now - resultStart >= RESULT_HOLD) {
      goIdle();
    }
  }

  // ── FAILED : LED rouge fixe 3s puis IDLE ──────────────
  if (state == FAILED) {
    if (now - resultStart >= RESULT_HOLD) {
      goIdle();
    }
  }
}