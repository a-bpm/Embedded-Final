/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Final.ino
    Written by: Kevin Kostage and Andrew Bryan
    Description: Implements pathfinding logic using the Car
                 class
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"
#include <IRremote.hpp>

/// Global Variables
const byte DISTANCE_THRESHOLD_INCHES = 5;
const byte IR_RECEIVER_PIN = 12;

enum IRbutton {
    IR_UP_BUTTON = 70,
    IR_RIGHT_BUTTON = 67,
    IR_DOWN_BUTTON = 21,
    IR_LEFT_BUTTON = 68,
    IR_OK_BUTTON = 64,
    IR_STAR_BUTTON = 66,
    IR_HASH_BUTTON = 74,
    IR_ROKU_UP_BUTTON = 153,
    IR_ROKU_DOWN_BUTTON = 179,
    IR_ROKU_LEFT_BUTTON = 158,
    IR_ROKU_RIGHT_BUTTON = 173,
    IR_ROKU_OK_BUTTON = 42,
    IR_ROKU_BACK_BUTTON = 102,
    IR_ROKU_HOME_BUTTON = 3,
};

const byte speed = 125;
const unsigned long MOTOR_DELAY = 275;
Robot *car = nullptr;

  // set up speed and delay
void setup() {
    // set up console
    Serial.begin(9600);
    car = new Robot(speed);
    car->init();
    IrReceiver.begin(IR_RECEIVER_PIN, true);
}

const int DRIVE_DELAY = 800;
const int FORWARD_DELAY = 500;
const int REVERSE_DELAY = 1000;
bool speedChanged = false;
bool flag = false;
bool sent = true;

void loop() 
{
    car->stop();
    delay(250);
    int buttonCode = 0;  // init IR button variable
    if (IrReceiver.decode()) {  // decodes the incoming data

        // takes decoded input of IR receiver and put it into switch case
        buttonCode = IrReceiver.decodedIRData.command; 
        if(buttonCode == IR_STAR_BUTTON || buttonCode == IR_ROKU_BACK_BUTTON) {
            // stop the instruction
            car->stop();

            // set the while loop flag to true
            flag = true;
        } // end of if
        while (flag)
        {
            sent = false;
            // loop through
            if (IrReceiver.decode())
            {
                // initialize string output variable
                buttonCode = IrReceiver.decodedIRData.command;
                String buttonPressed = ""; 

                switch(buttonCode) {
                    case IR_UP_BUTTON:
                        buttonPressed = "UP";
                        car->moveForward();
                        break;

                    case IR_RIGHT_BUTTON:
                        buttonPressed = "RIGHT";
                        car->tankTurnRight();
                        break;

                    case IR_DOWN_BUTTON:
                        buttonPressed = "DOWN";
                        car->setSpeed(110);
                        car->moveReverse();
                        car->_prevDirection = car->_direction;
                        car->_direction = Robot::ROBOT_REVERSE;
                        speedChanged = true;

                        delay(DRIVE_DELAY);
                        if (speedChanged) {
                            car->setSpeed(speed);
                        }
                        break;

                    case IR_LEFT_BUTTON:
                        buttonPressed = "LEFT";
                        car->tankTurnLeft();
                        break;

                    case IR_OK_BUTTON:
                        buttonPressed = "STOP";
                        car->stop();
                        break;

                    case IR_STAR_BUTTON:
                        buttonPressed = "REMOTE ON";
                        break;

                    case IR_HASH_BUTTON:
                        buttonPressed = "QUIT";
                        sent = false;
                        break;

                    case IR_ROKU_UP_BUTTON:
                        buttonPressed = "UP";
                        car->moveForward();
                        break;

                    case IR_ROKU_DOWN_BUTTON:
                        buttonPressed = "DOWN";
                        car->setSpeed(110);
                        car->moveReverse();
                        car->_prevDirection = car->_direction;
                        car->_direction = Robot::ROBOT_REVERSE;
                        speedChanged = true;

                        delay(DRIVE_DELAY);
                        if (speedChanged) {
                            car->setSpeed(speed);
                        }
                        break;

                    case IR_ROKU_LEFT_BUTTON:
                        buttonPressed = "LEFT";
                        car->tankTurnLeft();
                        break;

                    case IR_ROKU_RIGHT_BUTTON:
                        buttonPressed = "RIGHT";
                        car->tankTurnRight();
                        break;

                    case IR_ROKU_OK_BUTTON:
                        buttonPressed = "STOP";
                        car->stop();
                        break;

                    case IR_ROKU_BACK_BUTTON:
                        buttonPressed = "REMOTE ON";
                        break;

                    case IR_ROKU_HOME_BUTTON:
                        buttonPressed = "QUIT";
                        sent = false;
                        break;

                    default:
                        break;  // there to remind that we need it incase no 
                } // end switch
                Serial.println(buttonPressed);  // print the string variable
                Serial.println(buttonCode);
                IrReceiver.resume();
                if (sent)
                {
                    flag = false;
                }
            } // end of if
        } // end of while
        IrReceiver.resume();  // resumes waiting for input
    } // end decode if
    bool canProceed = true;
    canProceed = canProceed && car->scanDirection(Robot::ROBOT_RIGHT_MID) > DISTANCE_THRESHOLD_INCHES;
    canProceed = canProceed && car->scanDirection(Robot::ROBOT_MID) > DISTANCE_THRESHOLD_INCHES;
    canProceed = canProceed && car->scanDirection(Robot::ROBOT_LEFT_MID) > DISTANCE_THRESHOLD_INCHES;
    if(canProceed)      //If there are no objects within the stopping distance, move forward
    {
        byte turnDirection = car->getTurnDirection();
        /*
           if (car->_direction == Robot::ROBOT_LEFT && car->_prevDirection == Robot::ROBOT_LEFT) {
           turnDirection = Robot::ROBOT_RIGHT;
           }

           if (car->_direction == Robot::ROBOT_RIGHT && car->_prevDirection == Robot::ROBOT_RIGHT) {
           turnDirection = Robot::ROBOT_LEFT;
           }
         */
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
        delay(DRIVE_DELAY);
    } // end if
    else
    {
        car->setSpeed(110);
        car->moveReverse();
        car->_prevDirection = car->_direction;
        car->_direction = Robot::ROBOT_REVERSE;
        speedChanged = true;
        delay(REVERSE_DELAY);
    } // end reverse
    if (speedChanged) {
        car->setSpeed(speed);
    }
}
