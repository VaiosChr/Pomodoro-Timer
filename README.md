# Pomodoro-Timer
An Arduino based timer implementing the pomodoro technique with a 4-digit, 7-segment display.



## The files:
* **TM1637-master:**
This folder contains the library (TM1637Display.h) that the project uses to write data on to the 4-digit, 7-segment display. Download this and add it to the libraries folder of the Arduino IDE.

* **pomodoro.ino:**
The code for the project.

* **pomodoro_schematic.png:**
The schematic for the project.



## **The parts:**
* **Display:**
A TM1637 display with the clock dots in the middle (XX:XX).

* **Push Button:**
A button to start the timer.

* **LED & Buzzer:**
An LED and buzzer to indicate when "work time" or "break time" has finished. 



## The pins:
* **LED:** digital pin 8 (D8)
* **Button:** analog pin 0 (A0)
* **Buzzer:** digital pin 11 (D11)
* **Display:** 
  1. GND: GND
  1. VCC: 5V
  1. DIO: digital pin 3 (D3)
  1. CLK: digital pin 2(D2)
