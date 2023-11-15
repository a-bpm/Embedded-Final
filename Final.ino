#include <Servo.h>
#include "ultrasonic.h"
#include "motor.h"

// Global constants

// US pins
const byte ULTRASONIC_ECHO = A0;
const byte ULTRASONIC_TRIGGER = A1;

// servo signal pin
const byte SERVO_PIN = A2;

// ir pin
const byte IR_PIN = 12;

// right motor pins
const byte MOTOR_RIGHT_ENABLE = 5;
const byte MOTOR_RIGHT_FORWARD = 4;
const byte MOTOR_RIGHT_BACKWARD = 2;

// left motor pins
const byte MOTOR_LEFT_ENABLE = 6;
const byte MOTOR_LEFT_FORWARD = 8;
const byte MOTOR_LEFT_BACKWARD = 7;


void setup() {
    // set up console

    // set up servo

    // set up US

    // set up Left Motor

    // set up Right Motor
  
    // set up IR

    Serial.begin(9600);
    pinMode(SIG_PIN, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    digitalWrite(SIG_PIN, LOW);
    digitalWrite(TRIG_PIN, LOW);

    TCNT1H = 0xC2;
    TCNT1L = 0xF7;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TIMSK1 = (1 << TOIE1);

    interrupts();
}

void loop() {

  // look / measure

  // process measurement

  //determine measurement
  if(left > 14 && Forward > 14 && Right > 14)
  {
    Finished
  }

  if(left > 7 && Forward > 14 && Right > 14)
  {
    Centered
  }

  if(left > 7 && Forward > 14 && Right > 14)
  {
    Left of Center
  }

  if(left > 7 && Forward > 14 && Right > 14)
  {
    Right of Centered
  }

  if(left > 14 && Forward > 14 && Right > 14)
  {
    Left Turn
  }

  if(left > 14 && Forward > 14 && Right > 14)
  {
    Right Turn
  }



  // turn based on measure

  // move forward

  

}


ISR(TIMER_OCF_vect) {
    interrupted = true;
}
