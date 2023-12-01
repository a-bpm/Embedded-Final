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


const unsigned long SERVO_DELAY = 600; // servo takes 550ms to go from 0 to 180

Robot::Robot() {}

Robot::Robot(byte speed)
    : _rightLeg{new Motor(MOTOR_RIGHT_FORWARD_PIN, MOTOR_RIGHT_BACKWARD_PIN,
            MOTOR_RIGHT_ENABLE_PIN)},
    _leftLeg{new Motor(MOTOR_LEFT_FORWARD_PIN, MOTOR_LEFT_BACKWARD_PIN,
            MOTOR_LEFT_ENABLE_PIN)},
    _eye{new Ultrasonic(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN)},
    _neck{MyServo(SERVO_PIN, SERVO_DELAY)} {
        _leftLeg->setSpeed(speed);
        _rightLeg->setSpeed(speed);
        //_irReceiver.begin(IR_RECEIVER_PIN, true);
    } // end Robot constructor

// turning servo and getting measurement
double Robot::scanDirection(RobotDirection direction) {
    this->stop();
    _neck.look(direction); // Set the servo to look @ desired direction
    double distance = _eye->measureInch();

    Serial.print(distance);
    Serial.print(" inches");
    Serial.print(" in ");
    switch(direction) {
        case ROBOT_LEFT:
            Serial.println("Left");
                break;

        case ROBOT_LEFT_MID:
            Serial.println("Left Mid");
                break;

        case ROBOT_MID:
            Serial.println("Straight");
                break;

        case ROBOT_RIGHT_MID:
            Serial.println("Right Mid");
                break;

        case ROBOT_RIGHT:
            Serial.println("Right");
                break;
    }
    return distance;
}

// getting measurements on both sides and return which direction to turn based
// on measurement values
byte Robot::getTurnDirection() {
    const byte totalDistances = 5;
    double distances [totalDistances];
    delay(250);
    distances[ROBOT_LEFT] = scanDirection(RobotDirection::ROBOT_LEFT);
    distances[ROBOT_LEFT_MID] = (0.71 * scanDirection(RobotDirection::ROBOT_LEFT_MID));  // cosine of 45 
    distances[ROBOT_MID] = scanDirection(Robot::RobotDirection::ROBOT_MID);
    distances[ROBOT_RIGHT_MID] = (0.71 * scanDirection(RobotDirection::ROBOT_RIGHT_MID));   // cosine of 45
    distances[ROBOT_RIGHT] = scanDirection(RobotDirection::ROBOT_RIGHT);

    _neck.look(ROBOT_MID);
    double largest = 0.0;
    int largestDistanceDirection = 0;
    for (int i = 0; i < totalDistances; i++) {
        double current = distances[i];
        if (current > largest) {
            largestDistanceDirection = i;
            largest = distances[i];
        }
    }

    switch (largestDistanceDirection) {
        case ROBOT_LEFT:
            if (distances[largestDistanceDirection] > 400 &&
                distances[ROBOT_MID] < 400 &&
                distances[ROBOT_RIGHT] < 400)
            {
                largestDistanceDirection = ROBOT_LEFT;
            }
                break;

        case ROBOT_MID:
            if (distances[largestDistanceDirection] > 400 &&
                distances[ROBOT_LEFT] < 400 &&
                distances[ROBOT_RIGHT] < 400)
            {
                largestDistanceDirection = ROBOT_MID;
            }
                break;

        case ROBOT_RIGHT:
            if (distances[largestDistanceDirection] > 400 &&
                distances[ROBOT_LEFT] < 400 &&
                distances[ROBOT_MID] < 400)
            {
                largestDistanceDirection = ROBOT_RIGHT;
            }
                break;
    }
    // dont turn in the same direction twice
    _prevDirection = _direction;
    _direction = largestDistanceDirection;
    return largestDistanceDirection;
}

void Robot::setSpeed(byte speed) {
    this->_leftLeg->setSpeed(speed);
    this->_rightLeg->setSpeed(speed);
}

void Robot::stop() {
    _rightLeg->run(Motor::MotorDirection::MotorStop);
    _leftLeg->run(Motor::MotorDirection::MotorStop);
    delay(150);
}

void Robot::moveForward() {
    _rightLeg->run(Motor::MotorForward);
    _leftLeg->run(Motor::MotorForward);
}

void Robot::moveReverse() {
    _rightLeg->run(Motor::MotorReverse);
    _leftLeg->run(Motor::MotorReverse);
}

void Robot::tankTurnLeft() {
    _rightLeg->run(Motor::MotorDirection::MotorForward);
    _leftLeg->run(Motor::MotorDirection::MotorReverse);
    delay(325);
    this->stop();
}

void Robot::nudgeLeft() {
    _rightLeg->run(Motor::MotorDirection::MotorForward);
    _leftLeg->run(Motor::MotorDirection::MotorReverse);
    delay(80);
    this->stop();
}

void Robot::tankTurnRight() {
    _rightLeg->run(Motor::MotorDirection::MotorReverse);
    _leftLeg->run(Motor::MotorDirection::MotorForward);
    delay(325);
    this->stop();
}

void Robot::nudgeRight() {
    _rightLeg->run(Motor::MotorDirection::MotorReverse);
    _leftLeg->run(Motor::MotorDirection::MotorForward);
    delay(80);
    this->stop();
}


void Robot::tankTurn180() {
    _rightLeg->run(Motor::MotorDirection::MotorForward);
    _leftLeg->run(Motor::MotorDirection::MotorReverse);
    delay(550);
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

void Robot::init() {
    _neck.look(ROBOT_MID);
    _prevDirection = ROBOT_MID;
    _direction = ROBOT_MID;
    this->stop();
}
