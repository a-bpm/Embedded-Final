/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Final.ino
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"

/// Global Variables
    // hard coded stop distance
const byte DISTANCE_THRESHOLD_INCHES = 12;

// hard variables
byte speed = 200;
Robot *car = NULL;

  // set up speed and delay
void setup() {
    // set up console
    while(!Serial){

    }
    Serial.begin(9600);

    car = new Robot(speed);
    Serial.println("Made car");
    /*
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
    */
}

bool ultrasonicInterrupt = true;
// global count for the correction durring movement
int count = 0;

// testing variable for debugging
bool debugging = false;

const int DELAY = 3 * 1000;
void loop() 
{
  // test loop
  if (debugging)
  {
      car->orientRight();
      delay(1000);
      car->orientLeft();
      delay(1000);
  } 
  else // main loop
  {
    // ir button trigger flag to override loop and take control
    if(ultrasonicInterrupt) 
    {
      //checkDirection

      // turn off flag
      ultrasonicInterrupt = false;
    }

    // TODO: how would we make this work with timers?
    if(car->scanDirection(Robot::ROBOT_MID) >= DISTANCE_THRESHOLD_INCHES)      //If there are no objects within the stopping distance, move forward
    {
      // run motors dont stop
      car->moveForward();
      delay(DELAY);

      // corrections during drive (global timer/ counter)

      // occassionally look left and right to correct the robot

      /* Dynamic
      if (count % 5)
      {
        car.scanDirection(Robot::RobotDirection::ROBOT_LEFT); // scan left

        car.scanDirection(Robot::RobotDirection::ROBOT_RIGHT); // scan right
      }
      count++;
      */
    }
    else 
    {  // if too close (past stop distance threshhold)
       // get the decision whether to turn left or right

        car->stop();                                     //Stop the motors
        int turnDirection = car->getTurnDirection();
        switch(turnDirection)
        {
            case Robot::ROBOT_LEFT: // Turn Left 
                car->orientLeft();
                break;

            case Robot::ROBOT_LEFT_MID: // Turn Right
                break;

            case Robot::ROBOT_MID: // Turn Right
                break;

            case Robot::ROBOT_RIGHT_MID: // Turn Right
                break;

            case Robot::ROBOT_RIGHT: // Turn Right
                car->orientRight();
                break;
        } // end switch
        delay(DELAY);
    }
  }
}

ISR(TIMER_OCF_vect) {
    ultrasonicInterrupt = true;
}
