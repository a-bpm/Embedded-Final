/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
Filename: Robot.cpp
Written by: Kevin Kostage and Andrew Bryan
Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"

// right motor pins
const byte MOTOR_LEFT_ENABLE_PIN = 5;
const byte MOTOR_LEFT_FORWARD_PIN = 2;
const byte MOTOR_LEFT_BACKWARD_PIN = 4;

// left motor pins
const byte MOTOR_RIGHT_ENABLE_PIN = 6;
const byte MOTOR_RIGHT_BACKWARD_PIN = 8;
const byte MOTOR_RIGHT_FORWARD_PIN = 7;

// Ultrasonic pins
const byte ULTRASONIC_TRIGGER_PIN = A1;
const byte ULTRASONIC_ECHO_PIN = A0;

const byte SERVO_PIN = A2;
const byte IR_RECEIVER_PIN = 12;

const unsigned long SERVO_DELAY = 600; // servo takes 550ms to go from 0 to 180

Robot::Robot() {}

Robot::Robot(byte speed)
    : _rightLeg{new Motor(MOTOR_RIGHT_FORWARD_PIN, MOTOR_RIGHT_BACKWARD_PIN,
            MOTOR_RIGHT_ENABLE_PIN)},
    _leftLeg{new Motor(MOTOR_LEFT_FORWARD_PIN, MOTOR_LEFT_BACKWARD_PIN,
            MOTOR_LEFT_ENABLE_PIN)},
    _eye{new Ultrasonic(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN)},
    _neck{MyServo(SERVO_PIN, SERVO_DELAY)},
    _speed{speed} {
        _leftLeg->setSpeed(_speed);
        _rightLeg->setSpeed(_speed);
        //_irReceiver.begin(IR_RECEIVER_PIN, true);
    } // end Robot constructor

// turning servo and getting measurement
double Robot::scanDirection(RobotDirection direction) {
    _neck.look(direction); // Set the servo to look @ desired direction
    double distance = _eye->measureInch();

    Serial.print(distance);
    Serial.println(" inches");
    return distance;
}

// getting measurements on both sides and return which direction to turn based
// on measurement values
byte Robot::getTurnDirection() {
    // set up declare distances and direction variables
    byte turnDir = 0;

    double frontDistance = scanDirection(Robot::RobotDirection::ROBOT_MID);
    double leftDistance = scanDirection(RobotDirection::ROBOT_LEFT);
    double rightDistance = scanDirection(RobotDirection::ROBOT_RIGHT);

    if (frontDistance > leftDistance && frontDistance > rightDistance) {
        turnDir = ROBOT_MID;
    } else if (leftDistance > rightDistance) {
        turnDir = ROBOT_LEFT;
    } else {
        turnDir = ROBOT_RIGHT;
    }
    _neck.look(ROBOT_MID);
    // return the direction for the switch
    return turnDir;
}

/* TODO: DYNAMIC MOVEMENT, 
   byte Robot::correctDirection() {
   set up declare distances and direction variables

   turn the neck to look left
   _neck.look(MyServo::ServoDirection::SERVO_LEFT)
   delay

   get the distance and assign it to a distance 1 value
   left = checkDistance();
   turn the neck to look right
   _neck.look(MyServo::ServoDirection::SERVO_RIGHT)
   delay

   get the distance and assign it to a distance 2 value
   right = checkDistance();
   determine direction to turn

   determine measurement
   if(left > 14 && Forward > 14 && Right > 14)
   {
   Finished
   }

   else if(left < 7 && Forward > 14 && Right > 7)
   {
   Left of Center
   }

   else if(left > 7 && Forward > 14 && Right < 14)
   {
   Right of Centered
   }

   else // (left > 7 && Forward > 14 && Right > 7)
   {
   Centered
   }
   }
   */

void Robot::stop() {
    _rightLeg->run(Motor::MotorDirection::MotorStop);
    _leftLeg->run(Motor::MotorDirection::MotorStop);
}

void Robot::moveForward() {
    _rightLeg->run(Motor::MotorForward);
    _leftLeg->run(Motor::MotorForward);
}

void Robot::moveReverse() {
    _rightLeg->run(Motor::MotorReverse);
    _leftLeg->run(Motor::MotorReverse);
}

void Robot::orientLeft() {
    _rightLeg->run(Motor::MotorDirection::MotorForward);
    _leftLeg->run(Motor::MotorDirection::MotorReverse);
    delay(275);
    this->stop();
}

void Robot::orientRight() {
    _rightLeg->run(Motor::MotorDirection::MotorReverse);
    _leftLeg->run(Motor::MotorDirection::MotorForward);
    delay(275);
    this->stop();
}

void Robot::orient180() {
    _rightLeg->run(Motor::MotorDirection::MotorForward);
    _leftLeg->run(Motor::MotorDirection::MotorReverse);
    delay(275);
    this->stop();
}

void Robot::moveLeft() {
    _rightLeg->setSpeed(_leftLeg->getSpeed() / 2);
    _rightLeg->run(Motor::MotorForward);
    _leftLeg->run(Motor::MotorForward);
    delay(250);
    _rightLeg->setSpeed(_leftLeg->getSpeed());
}

void Robot::moveRight() {
    _leftLeg->setSpeed(_rightLeg->getSpeed() / 2);

    _rightLeg->run(Motor::MotorDirection::MotorForward);
    _leftLeg->run(Motor::MotorDirection::MotorForward);
    delay(250);
    _leftLeg->setSpeed(_rightLeg->getSpeed());
}

