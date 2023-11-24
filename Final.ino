/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Final.ino
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"

/// Global Variables
    // hard coded stop distance
const byte DISTANCE_THRESHOLD = 7;

// hard variables
byte speed = 200;
Robot *car = NULL;
const int DELAY = 2 * 1000;
Motor leftMotor;
Motor rightMotor;

Servo servo;
  // set up speed and delay
void setup() {
    // set up console
    Serial.begin(9600);

    car = new Robot(speed);
    Serial.println("Made car");
    servo.attach(A2);
    leftMotor = Motor(4, 2, 5);
    rightMotor = Motor(8, 7, 6);
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

// testing variable for sandbox loop
bool debugging = true;

void loop() 
{
  // test loop
  if (debugging)
  {
    Serial.println("Stop!");
    leftMotor.setSpeed(150);
    rightMotor.setSpeed(150);
    leftMotor.run(1);
    rightMotor.run(2);
    //car->stop();
    delay(DELAY);
    delay(DELAY);
    delay(DELAY);
    servo.write(0);
    delay(DELAY);
    delay(DELAY);
    servo.write(90);
    delay(DELAY);
    delay(DELAY);
    servo.write(180);
    delay(DELAY);
    delay(DELAY);

    car->scanDirection(0);
    delay(DELAY);
    car->scanDirection(1);
    delay(DELAY);
    car->scanDirection(2);
    delay(DELAY);
    car->scanDirection(3);
    delay(DELAY);
    car->scanDirection(4);
    delay(DELAY);

    delay(DELAY);
    delay(DELAY);
    delay(DELAY);
    Serial.println("Start Forward!");
    //car->moveForward();
    Serial.println("Going Forward!");
    delay(DELAY);
    //car->moveReverse();
    delay(DELAY);
    /*
    car.moveRight();
    car.moveLeft();
    car.moveReverse();
    car.orientLeft();
    car.orientRight();
    car.orient180();
    car.orient180();
    car.orientRight();

    car.scanDirection(0);
    car.scanDirection(1);
    car.scanDirection(2);
    */

  } /*
  else // main loop
  {
    // ir button trigger flag to override loop and take control
    if(ultrasonicInterrupt) 
    {
      //checkDirection

      // turn off flag
      ultrasonicInterrupt = false;
    }

    // look forward and get distance
    double frontDistance = car.scanDirection(Robot::RobotDirection::ROBOT_MID); // Check that there are no objects ahead
  
    // TODO: how would we make this work with timers?
    if(frontDistance >= DISTANCE_THRESHOLD)      //If there are no objects within the stopping distance, move forward
    {
      // run motors dont stop
      car.moveForward();

      // corrections during drive (global timer/ counter)

      // occassionally look left and right to correct the robot

      if (count % 5)
      {
        car.scanDirection(Robot::RobotDirection::ROBOT_LEFT); // scan left

        car.scanDirection(Robot::RobotDirection::ROBOT_RIGHT); // scan right
      }
      count++;
    }

    else 
    {  // if too close (past stop distance threshhold)
      car.stop();                                     //Stop the motors

      // get the decision whether to turn left or right
      int turnDir = car.getTurnDirection(frontDistance);
      
      // based on decision do said action  fix me !!! :(
      switch(turnDir)
      {
          case 0: // Turn Left 
              car.orientLeft();
              break;

          case 1: // Turn Right
              car.orientRight();
              break;
      }
    }
  } */
}

ISR(TIMER_OCF_vect) {
    ultrasonicInterrupt = true;
}
