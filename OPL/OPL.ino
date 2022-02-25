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
  pinMode(33,OUTPUT);
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
  t = (dur*0.01723*10);  " distance in mm "
  if (t<=55)
  {
   digitalWrite(33,HIGH); " Relay will be in off state "
  }
  else if (t>=55)
  {
    digitalWrite(33,LOW);  " Relay will be in on state "
  }
  
  Serial.print(t);
  Blynk.virtualWrite(V5,t);
  Blynk.run();
  delay(400);
}
