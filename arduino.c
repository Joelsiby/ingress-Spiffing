#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "joel"
#define WIFI_PASSWORD "12345670"

//MY firebase info
#define FIREBASE_HOST "tut-50e77.firebaseio.com"
#define FIREBASE_AUTH "ZrtBBoxW9xGO4uIAgA5TbSkupUqJG8FPQG1SkMdM"

int ledPower = 5;

void setup() {
  //  setup code , to run once:
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(ledPower, OUTPUT);
}

void loop() {
  // main code, to run repeatedly:
  int ledStatus = Firebase.getInt("ledStatus/ledStatus");
  if(ledStatus == 1){
    digitalWrite(ledPower, HIGH);
  } else {
    digitalWrite(ledPower, LOW);
  }

  //set data:
  //Firebase.set(ledStatus, "1");
}