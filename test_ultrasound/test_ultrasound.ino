//
/* Ultrasonic Distance Display V1.0 - Matt Faraday 07 Feb 2015 
   To complete this project you need 
    
   An Arduino or ATTINY or compatible MCU 
   An ultrasonic sensor 
   A TM1637 driven segment display
   A buzzer
   The TM1637Display library 
   The NewPing library
   Voltage regulator, capacitor (If using ATTINY)
   
   e-mail: matt (AT) faraday (dot) at 
   
 Based on ultrasonic ping example from arduino.cc (Copyleft 2007 Jason Ch.)
 
 */
// 

#include <NewPing.h>
#include <Arduino.h>
#include <TM1637Display.h>

#define BUZZ 4
#define CLK 3
#define DIO 2
#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 200 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(0x0f);
  pinMode(BUZZ, OUTPUT);
}

void loop() {

  delay(50);                      
  unsigned int uS = sonar.ping(); 
  unsigned int distance = (uS / US_ROUNDTRIP_CM);
  display.showNumberDec(distance);
  
  if(distance > 30) { 
     digitalWrite(BUZZ, HIGH);    
     delay(250);
     digitalWrite(BUZZ, LOW); 
  }
  if(distance < 20) {
    digitalWrite(BUZZ, HIGH); 
    delay(150); 
    digitalWrite(BUZZ, LOW);  
  }
  
  if(distance < 10) {
    digitalWrite(BUZZ, HIGH);
  }
    
}
