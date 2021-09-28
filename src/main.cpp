#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
 
 
void setup()
{
  Wire.begin();
 
  Serial.begin(115200);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}
 
 
void loop()
{
  byte error, address;
 
  Serial.println("Scanning...");

  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of the Write.endTransmisstion to see if a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      Serial.println(address, HEX);
    }    
  }
  delay(1000);         
}