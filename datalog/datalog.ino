#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <TimeLib.h>
#include "DS1307RTC.h"
File datalog;

void setup() {
  Serial.begin(115200);
  while (!Serial); 
  delay(200);

  if(!SD.begin()){
    Serial.println("SD card adapter connection failed");
    Serial.println("I have a bad feeling about this :(");
  }
  
}
int count = 0;
void loop() {
   tmElements_t tm;
   datalog = SD.open("log.txt", FILE_WRITE);

  if (RTC.read(tm) && datalog) {
    Serial.print(tmYearToCalendar(tm.Year)); Serial.write('/');
    Serial.print(tm.Month); Serial.write('/');
    Serial.print(tm.Day); Serial.print(", ");
    
    print2digits(tm.Hour); Serial.write(':');
    print2digits(tm.Minute); Serial.write(':');
    print2digits(tm.Second); Serial.println("\t");

    datalog.print(tmYearToCalendar(tm.Year)); datalog.print('/');
    datalog.print(tm.Month); datalog.print('/');
    datalog.print(tm.Day); datalog.print(", ");
    
    log2digits(tm.Hour); datalog.print(':');
    log2digits(tm.Minute); datalog.print(':');
    log2digits(tm.Second); datalog.println("\t");

    datalog.close();
  }

  else if (!RTC.read(tm)){
    Serial.println("RTC connection failed");
    Serial.println("I solemly swear that I'm up to no good");
  }

  delay(1000);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

void log2digits(int number) {
  if (number >= 0 && number < 10) {
    datalog.print('0');
  }
  datalog.print(number);
}
