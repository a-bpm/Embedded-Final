/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Robot.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <Servo.h>
#include <IRRemove.h>

#include "Robot.hpp"
#include "include/Ultrasonic.hpp"
#include "include/Motor.hpp"

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

Robot::Robot() : {
    _rightLeg = Motor(MOTOR_RIGHT_ENABLE_PIN, MOTOR_RIGHT_FORWARD_PIN,
            MOTOR_RIGHT_BACKWARD_PIN);
    _leftLeg = Motor(MOTOR_LEFT_ENABLE_PIN, MOTOR_LEFT_FORWARD_PIN,
                                   MOTOR_LEFT_BACKWARD_PIN);
    _eye = UltrasonicSensor(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);
    _neck.attach(SERVO_PIN, 500, 2500);
    _irReceiver.begin(IR_RECEIVER_PIN, true);

}
