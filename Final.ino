/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Final.ino
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"

/// Global Variables
const byte DISTANCE_THRESHOLD_INCHES = 12;

// hard variables
const byte speed = 200;
const unsigned long MOTOR_DELAY = 275;
Robot *car = NULL;

  // set up speed and delay
void setup() {
    // set up console
    Serial.begin(9600);
    car = new Robot(speed);
    car->init();
}

const int DELAY = 2 * 1000;
void loop() 
{
    delay(250);
    if (false) // IR placeholder
    {

    } else if(car->scanDirection(Robot::ROBOT_MID) > DISTANCE_THRESHOLD_INCHES)      //If there are no objects within the stopping distance, move forward
    {
        int turnDirection = car->getTurnDirection();
        switch(turnDirection)
        {
            case Robot::ROBOT_LEFT: // Turn Left 
                car->tankTurnLeft();
                break;

            case Robot::ROBOT_LEFT_MID: // Turn Right
                car->nudgeLeft();
                break;

            case Robot::ROBOT_MID: // no turn
                break;

            case Robot::ROBOT_RIGHT_MID: // slight right
                car->nudgeRight();
                break;

            case Robot::ROBOT_RIGHT: // Turn Right
                car->tankTurnRight();
                break;
        } // end switch
        car->moveForward();
    } else {
        car->moveReverse();
    } // end else
    delay(DELAY);
}
