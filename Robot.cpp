/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
    Filename: Robot.cpp 
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"

// right motor pins
const byte MOTOR_RIGHT_ENABLE_PIN = 5;
const byte MOTOR_RIGHT_FORWARD_PIN = 4;
const byte MOTOR_RIGHT_BACKWARD_PIN = 2;

// left motor pins
const byte MOTOR_LEFT_ENABLE_PIN = 6;
const byte MOTOR_LEFT_FORWARD_PIN = 8;
const byte MOTOR_LEFT_BACKWARD_PIN = 7;

// Ultrasonic pins
const byte ULTRASONIC_TRIGGER_PIN = A1;
const byte ULTRASONIC_ECHO_PIN = A0;

const byte SERVO_PIN = A2;
const byte IR_RECEIVER_PIN = 12;

Robot::Robot():
    _rightLeg(MOTOR_RIGHT_ENABLE_PIN, MOTOR_RIGHT_FORWARD_PIN,
              MOTOR_RIGHT_BACKWARD_PIN),
    _leftLeg(MOTOR_LEFT_ENABLE_PIN, MOTOR_LEFT_FORWARD_PIN,
             MOTOR_LEFT_BACKWARD_PIN),
    _eye(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN),
    _neck(SERVO_PIN)
    {
        //_irReceiver.begin(IR_RECEIVER_PIN, true);
    }

void Robot::stop() {
    _rightLeg.run(Motor::MotorDirection::MotorStop);
    _leftLeg.run(Motor::MotorDirection::MotorStop);
}

void Robot::moveForward() {
    _rightLeg.run(Motor::MotorDirection::MotorForward);
    _leftLeg.run(Motor::MotorDirection::MotorForward);
}

void Robot::moveLeft() {
    _rightLeg.run(Motor::MotorDirection::MotorForward);
    _leftLeg.run(Motor::MotorDirection::MotorForward);
}

void Robot::moveRight() {
    _rightLeg.run(Motor::MotorDirection::MotorForward);
    _leftLeg.run(Motor::MotorDirection::MotorForward);
}

void Robot::moveReverse() {
    _rightLeg.run(Motor::MotorDirection::MotorReverse);
    _leftLeg.run(Motor::MotorDirection::MotorReverse);
}

void Robot::orientLeft() {
    _rightLeg.run(Motor::MotorDirection::MotorForward);
    _leftLeg.run(Motor::MotorDirection::MotorReverse);
}

void Robot::orientRight() {
    _rightLeg.run(Motor::MotorDirection::MotorForward);
    _leftLeg.run(Motor::MotorDirection::MotorReverse);
}

void Robot::orientStart() {
    _rightLeg.run(Motor::MotorDirection::MotorForward);
    _leftLeg.run(Motor::MotorDirection::MotorForward);
}
