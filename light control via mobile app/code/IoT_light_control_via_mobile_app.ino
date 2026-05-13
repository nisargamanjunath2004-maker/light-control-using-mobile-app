#define BLYNK_TEMPLATE_ID "TMPL30N1EdNNr"
#define BLYNK_TEMPLATE_NAME "Light Control"
#define BLYNK_AUTH_TOKEN "DJGL_itkCgJazYCUfcVeEZHZZTUCkyy8"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "AshwiniP";
char pass[] = "12345678";

#define RELAY_PIN D1
BLYNK_WRITE(V0) { // Virtual Pin 0 from Blynk app button
int value = param.asInt();
digitalWrite(RELAY_PIN, value);
Serial.println(value ? "Relay ON" : "Relay OFF");
}

void setup() {
Serial.begin(115200);
pinMode(RELAY_PIN, OUTPUT);
digitalWrite(RELAY_PIN, LOW);
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
Blynk.run();
}
