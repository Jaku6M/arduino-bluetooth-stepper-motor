#include <Arduino.h>
#include <SoftwareSerial.h>
// software serial #1: TX = digital pin 23, RX = digital pin 22
SoftwareSerial XM15B(23,22);
char data;

void setup()
{
 // Open serial communications and wait for port to open:
  //Serial.begin(9600);

  // Start each software serial port
  XM15B.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

  // while there is data coming in, read it
  // and send to the hardware serial port:
  if (XM15B.available()) 
  {
    data = XM15B.read();
    if (data == 'L')
    {
      digitalWrite(LED_BUILTIN,1);
    }
    if (data == 'l')
    {
      digitalWrite(LED_BUILTIN,0);
    }
  }
}
