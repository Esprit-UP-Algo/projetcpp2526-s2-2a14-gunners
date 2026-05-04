#include <Keypad.h>
#include <Servo.h>

/* 
 * ARDUINO ID VERIFIER SCENARIO (ENHANCED)
 * ----------------------------
 * PIN CONNECTIONS:
 * - Keypad Rows: 9, 8, 7, 6
 * - Keypad Cols: 5, 4, 3, 2
 * - Servo Signal: 10
 * - LED Feedback: Built-in LED (Pin 13)
 */

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Servo myServo;
String enteredID = "";

void setup() {
  Serial.begin(9600);
  myServo.attach(10);
  myServo.write(0); 
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  // Signal that Arduino is ready (3 fast blinks)
  for(int i=0; i<3; i++) {
    digitalWrite(LED_BUILTIN, HIGH); delay(100);
    digitalWrite(LED_BUILTIN, LOW); delay(100);
  }
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // Visual feedback for any key press
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);

    if (key == '#') {
      if (enteredID.length() > 0) {
        Serial.println(enteredID); // Send to PC
        
        // Wait for response from PC
        long startTime = millis();
        bool received = false;
        while (millis() - startTime < 3000) { 
          if (Serial.available()) {
            char response = Serial.read();
            if (response == '1') {
              handleAccessGranted();
              received = true;
              break;
            } else if (response == '0') {
              handleAccessDenied();
              received = true;
              break;
            }
          }
        }
        
        if (!received) handleTimeout();
        enteredID = ""; 
      }
    } 
    else if (key == '*') {
      enteredID = ""; 
    }
    else {
      enteredID += key; 
    }
  }
}

void handleAccessGranted() {
  // Rapid blinking for success
  for(int i=0; i<10; i++) {
    digitalWrite(LED_BUILTIN, HIGH); delay(50);
    digitalWrite(LED_BUILTIN, LOW); delay(50);
  }
  
  for (int pos = 0; pos <= 90; pos++) {
    myServo.write(pos);
    delay(15); 
  }
  delay(2000);
  for (int pos = 90; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }
}

void handleAccessDenied() {
  // 1 second steady light for Access Denied
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); 
  digitalWrite(LED_BUILTIN, LOW);
}

void handleTimeout() {
  // 3 slow blinks for Timeout (No response from PC)
  for(int i=0; i<3; i++) {
    digitalWrite(LED_BUILTIN, HIGH); delay(500);
    digitalWrite(LED_BUILTIN, LOW); delay(500);
  }
}
