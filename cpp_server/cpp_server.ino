#include <Servo.h>
#include <ArduinoJson.h>

Servo myservo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  DynamicJsonBuffer jBuffer;
  JsonObject& root = jBuffer.createObject();

  root["pos"] = pos;
  root.prettyPrintTo(Serial);
  
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(1);
  }
}
