/*
*  SPI Test Sketch Master
 *
 * by Rick Anderson
 *
 */

#include <ArduinoTestSuite.h>
#include <SPI.h>

void setup () 
{
  Serial.begin(9600);
  ATS_begin("Arduino", "SPI Tests");
  SPI.begin();
  //Run tests
  refConfig();
  testTransfer();
  refConfig();
  testBitOrder();
  refConfig();
  testClockDivider();
  refConfig();
  testDataMode();

  SPI.end();
  ATS_end();
}

void testBitOrder()
{
  boolean result = false;
  byte spireturn;
  //LSB test 1
  setSlaveBitOrder(LSBFIRST);
  SPI.setBitOrder(LSBFIRST);
  spireturn = SPI.transfer(0x02);
  if (spireturn == 0x01)
  {
    result = true;
  }
  ATS_PrintTestStatus("1. setBitOrder(LSBFIRST)", result);
  result = false;

  //MSB test 2
  setSlaveBitOrder(MSBFIRST);
  SPI.setBitOrder(MSBFIRST);
  spireturn = SPI.transfer(0x02);
  if (spireturn == 0x01)
  {
    result = true;
  }
  ATS_PrintTestStatus("2. setBitOrder(MSBFIRST)", result);
}

void testDataMode()
{

  boolean result = false;
  byte spireturn;
  //SPI_MODE0 test 3
  setSlaveDataMode(SPI_MODE0);
  SPI.setDataMode(SPI_MODE0);
  spireturn = SPI.transfer(0x02);
  if (spireturn == 0x01)
  {
    result = true;
  }
  ATS_PrintTestStatus("3. setDataMode(SPI_MODE0)", result);
  result = false;

  /*
  SPI.setDataMode(SPI_MODE0);
   SPI.setDataMode(SPI_MODE1);
   SPI.setDataMode(SPI_MODE2);
   SPI.setDataMode(SPI_MODE3);
   */

}

void testClockDivider()
{

  boolean result = false;
  byte spireturn;
  //SPI_MODE0 test 3
  setSlaveClockDivider(SPI_CLOCK_DIV2);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  spireturn = SPI.transfer(0x02);
  if (spireturn == 0x01)
  {
    result = true;
  }
  ATS_PrintTestStatus("4. setClockDivider(SPI_CLOCK_DIV2)", result);
  result = false;
  /*

   
   SPI.setClockDivider(SPI_CLOCK_DIV2);
   SPI.setClockDivider(SPI_CLOCK_DIV4);
   SPI.setClockDivider(SPI_CLOCK_DIV8);
   SPI.setClockDivider(SPI_CLOCK_DIV16);
   SPI.setClockDivider(SPI_CLOCK_DIV32);
   SPI.setClockDivider(SPI_CLOCK_DIV64); 
   SPI.setClockDivider(SPI_CLOCK_DIV128);
   */
}

void testTransfer()
{

  boolean result = false;
  byte spireturn;
  //transfer test 5
  spireturn = SPI.transfer(0x02);
  if (spireturn == 0x01)
  {
    result = true;
  }
  ATS_PrintTestStatus("5. transfer(0x02)", result);
  result = false;


}
boolean setSlaveBitOrder(uint8_t bitorder)
{
  return false;
}
boolean setSlaveDataMode(uint8_t datamode)
{
  return false;
}

boolean setSlaveClockDivider(uint8_t clockdivider )
{   
  return false;
}

void refConfig()
{
}

void loop ()
{

}



