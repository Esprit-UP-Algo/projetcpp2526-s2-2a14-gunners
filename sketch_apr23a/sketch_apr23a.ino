#include <Keypad.h>
#include <Servo.h>

/* 
 * SMART RESEARCH - ARDUINO ID VERIFIER
 * -----------------------------------
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
  
  // TEST INITIAL : Le servo bouge pour confirmer la connexion matérielle
  myServo.write(90); delay(500); myServo.write(0); 
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  // Signal de démarrage : 3 clignotements rapides
  for(int i=0; i<3; i++) {
    digitalWrite(LED_BUILTIN, HIGH); delay(100);
    digitalWrite(LED_BUILTIN, LOW); delay(100);
  }
  Serial.println("--- ARDUINO READY ---");
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    // Feedback visuel pour chaque touche pressée
    digitalWrite(LED_BUILTIN, HIGH); delay(50); digitalWrite(LED_BUILTIN, LOW);

    if (key == '#') {
      if (enteredID.length() > 0) {
        // Nettoyer les anciens messages résiduels avant d'envoyer
        while(Serial.available() > 0) Serial.read(); 
        
        Serial.println(enteredID); // Envoyer au PC
        Serial.print("ID Envoye : "); Serial.println(enteredID); // Debug Monitor

        long startTime = millis();
        bool received = false;
        
        // Attendre la réponse du PC pendant 3 secondes
        while (millis() - startTime < 3000) { 
          if (Serial.available()) {
            char response = Serial.read();
            Serial.print("Reponse PC : "); Serial.println(response); // Debug Monitor
            
            if (response == '1') { 
              handleAccessGranted(); 
              received = true; 
              break; 
            }
            else if (response == '0') { 
              handleAccessDenied(); 
              received = true; 
              break; 
            }
          }
        }
        
        if (!received) {
          Serial.println("ERREUR : Pas de reponse (Timeout)");
          handleTimeout();
        }
        enteredID = ""; 
      }
    } 
    else if (key == '*') {
      enteredID = ""; 
      Serial.println("ID Efface");
    } 
    else {
      enteredID += key; 
    }
  }
}

void handleAccessGranted() {
  Serial.println("ACCES ACCORDE !");
  // Clignotement rapide pour le succès
  for(int i=0; i<10; i++) { 
    digitalWrite(LED_BUILTIN, HIGH); delay(50); 
    digitalWrite(LED_BUILTIN, LOW); delay(50); 
  }
  
  // Ouverture fluide du servo
  for(int pos = 0; pos <= 90; pos++) { 
    myServo.write(pos); 
    delay(15); 
  }
  delay(2000); // Reste ouvert 2 secondes
  // Fermeture fluide
  for(int pos = 90; pos >= 0; pos--) { 
    myServo.write(pos); 
    delay(15); 
  }
}

void handleAccessDenied() {
  Serial.println("ACCES REFUSE");
  // LED allumée fixe pendant 1 seconde
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(1000); 
  digitalWrite(LED_BUILTIN, LOW);
}

void handleTimeout() {
  // 3 clignotements lents pour indiquer un problème de communication
  for(int i=0; i<3; i++) { 
    digitalWrite(LED_BUILTIN, HIGH); delay(500); 
    digitalWrite(LED_BUILTIN, LOW); delay(500); 
  }
}
