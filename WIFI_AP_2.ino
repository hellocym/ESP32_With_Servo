#include <WiFi.h>
#include <ESP32Servo.h>
#include <Arduino.h>

Servo myservo;
int servoPin = 5;

const char* ssid     = "ESP32-Access-Point";
const char* password = "123456789";
int pre_client_count, cur_client_count;

void setup() {
  myservo.setPeriodHertz(50); 
  myservo.attach(servoPin);
  myservo.write(0); 
  Serial.begin(115200);
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);
  pre_client_count = 0;
  cur_client_count = 0;
}

void loop() {
  Serial.print("Stations connected: ");
  cur_client_count = WiFi.softAPgetStationNum();
  Serial.println(WiFi.softAPgetStationNum());
  if(cur_client_count > pre_client_count){
    Serial.print("芝麻开门");
    myservo.write(20);
    delay(2000);
    myservo.write(0); 
    //ServoOn();
  }
  pre_client_count = cur_client_count;
  delay(1000);
  // put your main code here, to run repeatedly:

}
