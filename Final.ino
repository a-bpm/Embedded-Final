/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Final.ino
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"

/// Global Variables

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


// testing variable for sandbox loop
bool test = 0;

// global count for the correction durring movement
int count = 0;

void loop() 
{
  // test loop
  if (test)
  {




  }
  // main loop
  else 
  {
    // ir button trigger flag to override loop and take control
    if(ultrasonicInterrupt) 
    {
      //checkDirection

      ultrasonicInterrupt = false;

    }
    // hard coded stop distance
    double stopDist = 7;

    // look forward and get distance
    double frontDistance = car.looking(2);                   //Check that there are no objects ahead
  
    if(frontDistance >= stopDist)                        //If there are no objects within the stopping distance, move forward
    {
      // run motors dont stop
      car.moveForward();

      // corrections during drive (global timer/ counter)

      // occassionally look left and right to correct the robot

      if (count % 5)
      {
        
      }
    }

    else 
    {  // if too close (past stop distance threshhold)
      car.stop();                                     //Stop the motors

      // get the decision whether to turn left or right
      int turnDir = car.check_L_R_SideDirection(frontDistance);
      
      /*// based on decision do said action
      switch(turnDir)
      {
        case 0: // Turn Left 
          break;

        case 1: // Turn Right
      }
      */
    }
  }
}

ISR(TIMER_OCF_vect) {
    ultrasonicInterrupt = true;
}
