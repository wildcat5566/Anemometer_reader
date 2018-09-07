# Anemometer_reader
Case file #001 : Anemometer reader, RTC &amp; SD card logger @NTUAS

## Description
Save a record of following contents to attached SD card every sampling time interval. </br>
(1) Standard time (YYYY/MM/DD hour:min:sec) provided by an RTC (Real Time Clock) module. </br>
(2) Sensor readings from the "Trisonica Mini" anemometer. </br>

## Materials
![alt text](./src/Materials.jpg) </br>
### Arduino UNO </br>
### Anemometer "Trisonica Mini" </br>
- Operating voltage 12 VDC. </br>
- Communication protocol RS232. </br>
### DS1307 Real time clock module </br>
- Communication protocol I2C.
### Micro SD card adapter module </br>
- Communication protocol SPI.
### Peripherals </br>
- RS232-UART adapter.
- Lithium battery CR2032.

## Wiring diagram
![alt text](./src/wiring.JPG)

## Current results
RTC time information successfully logged to SD card. See LOG.txt. </br>
Synchronous serial monitor display demonstrated in screenshot below. </br>
![alt text](./src/Serial_monitor_output.JPG)
