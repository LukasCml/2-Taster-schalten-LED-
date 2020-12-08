/*
    Programm:         Eine LED soll mit 2 Tastern An und Aus geschaltet werden können.
                      Dabei müssen die Taster gleichzeitig gedrückt werden
    Letzte Änderung:  08.12.2020
    Programmierer:    Lukas Camehl
    Version:          1.0
    Bibliohek:        OneButon

    Hardware:         Arduino UNO / Taster 1 an Pin 13, Taster 2 an Pin 12, beide mit jeweils einem Vorwiderstand als Pull-Down / LED an Pin 2

*/

#include <OneButton.h>
OneButton button1(13, false);
OneButton button2(12, false);
#define LED 2
bool taster1Gedrueckt = false;
bool taster2Gedrueckt = false;
int statusLED = false;



void setup()
{
  button1.attachLongPressStart(Taster1);
  button2.attachLongPressStart(Taster2);
  pinMode(LED, OUTPUT);
}

void loop()
{
  Serial.begin(9600);
  button1.tick();
  button2.tick();
  delay(10);
  if (taster1Gedrueckt == true && taster2Gedrueckt == true)
  {
    statusLED = !statusLED;
    digitalWrite(LED, statusLED);
    if (digitalRead(13) == false)
    {
      taster1Gedrueckt = false;
      taster2Gedrueckt = false;
      statusLED = false;
    }
    if (digitalRead(12) == false)
    {
      taster1Gedrueckt = false;
      taster2Gedrueckt = false;
      statusLED = false;
    }
  }
  else
  {
    digitalWrite(LED, LOW);
    statusLED = false;
  }
}


void Taster1 ()
{
  taster1Gedrueckt = !taster1Gedrueckt;
  Serial.println("Taster 1 gedrueckt");
}

void Taster2 ()
{
  taster2Gedrueckt = !taster2Gedrueckt;
  Serial.println("Taster 2 gedrueckt");
}

