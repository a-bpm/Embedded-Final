/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Final.ino
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"
#include <IRremote.hpp>
/// Global Variables
const byte DISTANCE_THRESHOLD_INCHES = 10;

const byte IR_RECEIVER_PIN = 12;
// hard variables
const byte speed = 150;
const unsigned long MOTOR_DELAY = 275;
Robot *car = NULL;

  // set up speed and delay
void setup() {
    // set up console
    Serial.begin(9600);
    car = new Robot(speed);
    car->init();
    IrReceiver.begin(IR_RECEIVER_PIN, true);
}

const int DELAY = 1000;
bool speedChanged = false;
void loop() 
{
  while(true)
  {
    int buttonCode = 0;  // init IR button variable
    if (IrReceiver.decode()) {  // decodes the incoming data
        
        // takes decoded input of IR receiver and put it into switch case
        buttonCode = IrReceiver.decodedIRData.command; 
        Serial.println(buttonCode);
    }
  }
    delay(250);
    if(car->scanDirection(Robot::ROBOT_RIGHT_MID) > DISTANCE_THRESHOLD_INCHES ||
       car->scanDirection(Robot::ROBOT_LEFT_MID) > DISTANCE_THRESHOLD_INCHES ||
       car->scanDirection(Robot::ROBOT_MID) > DISTANCE_THRESHOLD_INCHES)      //If there are no objects within the stopping distance, move forward
    {
        byte turnDirection = car->getTurnDirection();
        if (car->_direction == Robot::ROBOT_LEFT && car->_prevDirection == Robot::ROBOT_LEFT) {
            turnDirection = Robot::ROBOT_RIGHT;
        }

        if (car->_direction == Robot::ROBOT_RIGHT && car->_prevDirection == Robot::ROBOT_RIGHT) {
            turnDirection = Robot::ROBOT_LEFT;
        }

        switch(turnDirection)
        {
            case Robot::ROBOT_LEFT: // Turn Left 
                car->tankTurnLeft();
                break;
/*
            case Robot::ROBOT_LEFT_MID: // Turn Right
                car->nudgeLeft();
                break;
*/
            case Robot::ROBOT_MID: // no turn
                break;
/*
            case Robot::ROBOT_RIGHT_MID: // slight right
                car->nudgeRight();
                break;
*/
            case Robot::ROBOT_RIGHT: // Turn Right
                car->tankTurnRight();
                break;
        } // end switch
        car->moveForward();
    } else {
        car->setSpeed(110);
        car->moveReverse();
        car->_prevDirection = car->_direction;
        car->_direction = Robot::ROBOT_REVERSE;
        speedChanged = true;
    } // end else
    delay(DELAY);
    if (speedChanged) {
        car->setSpeed(speed);
    }
}
