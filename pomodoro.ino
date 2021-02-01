#include <TM1637Display.h>

//the pins for the display
#define CLK 2
#define DIO 3

//the pin for the button
#define input_pin A0
//the pin for the LED
#define output_pin 8
#define buzzer 11

//the work and break time
#define work_time 1500
#define break_time 300

//global variables
int state = HIGH, reading;
int seconds = 0, minutes = 0;
TM1637Display display(CLK, DIO);

void setup()
{
  display.setBrightness(3);
  display.clear();
  pinMode(output_pin, OUTPUT);
  pinMode(input_pin, INPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DIO, OUTPUT);
}

void loop()
{
  display.showNumberDecEx(0, 0b01000000, true);
  reading = !digitalRead(input_pin);

  if(reading == HIGH)
  {
    if(state == HIGH)
    {
      state = LOW;
      digitalWrite(output_pin, LOW);
      count(work_time);

      digitalWrite(output_pin, 5);
      tone(buzzer, 440);
      delay(200);
      
      digitalWrite(output_pin, LOW);
      noTone(buzzer);
      delay(200);
      
      tone(buzzer, 440);
      digitalWrite(output_pin, 5);
      delay(200);
      
      noTone(buzzer);
      //TODO: MAKE THE DIGITS BLINK!!!

      delay(1400);
      count(break_time);
      digitalWrite(output_pin, LOW);
      tone(buzzer, 493.88);
      delay(200);
      noTone(buzzer);
    }
    
    state = HIGH;
  }
}

void count(int sec)
{
  unsigned long timer = millis();
  
  while(sec >= 0)
  { 
    if(millis() > timer)
    {
      minutes = (sec % 3600) / 60;
      seconds = (sec % 3600) % 60;
      
      timer = millis() + 1000;
      
      display.showNumberDecEx(seconds + minutes * 100, 0b01000000, true);
      sec--;
    }
  }
}
