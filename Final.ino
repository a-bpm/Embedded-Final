/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Final.ino
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"

/// Global Variables

// Servo
/*
Servo neckServo;
int FORWARDPOS = 0;
int LEFTPOS = 0;
int RIGHTPOS = 0;
// move this into Robot class maybe?
*/

  // set up speed and delay
void setup() {
    // set up console
    Serial.begin(9600);
  // set up timer1 count
    TCNT1H = 0xF3;
    TCNT1L = 0xCB;
  
  // set up timer1 mode: normal
    TCCR1A = 0x00;
  
  // Set up  clock in TCCR1B
    TCCR1B = (1 << CS10) | (1 << CS12); // Prescaler = 1024
  
  // set up timer1 interupt
    TIMSK1 = (1 << TOIE1);

  // enable global interupts
    interrupts();
}

bool ultrasonicInterrupt = false;

Robot car;
byte speed = 0;
const int DELAY = 6 * 1000;

void loop() {
  /*
  if(ultrasonicInterrupt) {
    checkDirection

    ultrasonicInterrupt = false;

  }
  car._neck.look();
  servoLook.write(FORWARDPOS);                            //Set the servo to look straight ahead
  delay(750);
  int forwardDistance = ultrasonicSensor.measure();                   //Check that there are no objects ahead
  if(forwardDistance >= stopDist)                        //If there are no objects within the stopping distance, move forward
  {
    moveForward();
  }
  while(forwardDistance >= stopDist)                     //Keep checking the object distance until it is within the minimum stopping distance
  {
    forwardDistance = ultrasonicSensor.measure();
    delay(250);
  }
  else{
    stop();                                     //Stop the motors
    int turnDir = checkDirection();
  }

  switch(turnDirectionState)
  {
    case TURNLEFT:

    case TURNRIGHT:
  }
*/
}

ISR(TIMER_OCF_vect) {
    ultrasonicInterrupt = true;
}
