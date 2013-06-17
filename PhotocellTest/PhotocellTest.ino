/*
*  Photocell night and day test
 *
 * by Rick Anderson
 *
 */

#include <ArduinoTestSuite.h>
const int ledPin = 11;
const int photocell = A0;
void setup()
{
  //Configure circuit
  pinMode(ledPin, OUTPUT);
  //Configure test
  ATS_begin("Arduino", "Night and Day photocell test");

  testNight();
  testDay();

  ATS_end();
}

void testNight()
{
  boolean result = false;
  int brightness;
  analogWrite(ledPin, 0);
  brightness = analogRead(A0);
  if (brightness == 0)
  {
    result = true;
  }
  ATS_PrintTestStatus("1. Night test: ", result);
}

void testDay()
{
  boolean result = false;
  int brightness;
  analogWrite(ledPin, 192);
  brightness = analogRead(A0);
  if (brightness >= 750)
  {
    result = true;
  }
  ATS_PrintTestStatus("2. Day test: ", result);
}


void loop()
{
}


