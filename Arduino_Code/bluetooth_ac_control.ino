#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX
int relay1 = 8;
int relay2 = 9;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

  digitalWrite(relay1, HIGH); // শুরুতে OFF
  digitalWrite(relay2, HIGH);

  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (BT.available()) {
    char c = BT.read();
    Serial.println(c);

    if (c == '1') {
      digitalWrite(relay1, LOW);  // Load-1 ON
      Serial.println("Load 1 ON");
    }
    else if (c == '2') {
      digitalWrite(relay1, HIGH); // Load-1 OFF
      Serial.println("Load 1 OFF");
    }
    else if (c == '3') {
      digitalWrite(relay2, LOW);  // Load-2 ON
      Serial.println("Load 2 ON");
    }
    else if (c == '4') {
      digitalWrite(relay2, HIGH); // Load-2 OFF
      Serial.println("Load 2 OFF");
    }
  }
}
