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

  // loop A: (look forward, move, determine)

  if(ultrasonicInterrupt) {

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
  
  
  // loop B (look, determine, move):
  
  
  /// look around (I have a feeling we can somehow make this process into a for loop or robot class method called three times)
  // for(int i = 0; i > 2; i++ ) // we can make the poistion change in this too i think but we can make explicit changes as well
  // look left
    //position = left;
    // turn neck left
    neckServo.write(position);

    // delay to properly time the servo turn before US measure
    delay(1300);
  
    // measurement
    unsigned long durationLeftLength = ultrasonicSensor.measureInch();
    
    // small delay to time servo after measurement
    delay(130);

    // get ready to turn middle
    //position = middle;
  
  // look middle
    
  // look right
    
  ///determine measurement


  
  if(left > 14 && Forward > 14 && Right > 14)
  {
    Finished
  }

  else if(left > 7 && Forward > 14 && Right > 14)
  {
    Centered
  }

  else if(left > 7 && Forward > 14 && Right > 14)
  {
    Left of Center
  }

  else if(left > 7 && Forward > 14 && Right > 14)
  {
    Right of Centered
  }

  else if(left > 14 && Forward > 14 && Right > 14)
  {
    //Left Turn

    left();
    delay(500);
    Stop();
    delay(200);
  }

  else if(left > 14 && Forward > 14 && Right > 14)
  {
    //Right Turn
    right();
    delay(500);
    Stop();
    delay(200);
  }
  

/// move
  // turn based on measure (we can use enums for the movement states)
  //switch(state)
  
  // move forward
  Serial.println("Forward...");
  leftMotor.run(Motor::MotorForward);
  rightMotor.run(Motor::MotorForward);
  delay(DELAY);
  
    

    */
}

ISR(TIMER_OCF_vect) {
    ultrasonicInterrupt = true;
}
