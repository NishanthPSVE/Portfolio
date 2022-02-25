#define BLYNK_PRINT Serial  
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "zi5ITQ8ZMOHK2U4uSQgPR-btJ2sqpxH0";
char ssid[] = "Galaxy A513281";
char pass[] = "ochf3829";
int trig = 25;
int echo = 26;

void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop()
{
  long dur,t;
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo,HIGH);
  t = (dur*0.01723);
  Serial.print(t);
  Blynk.virtualWrite(V5,t);
  Blynk.run();
  delay(1000);
}
