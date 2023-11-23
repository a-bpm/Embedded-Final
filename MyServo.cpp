/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: MyServo.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "MyServo.hpp"
#include <Arduino.h>

MyServo::MyServo(byte servoPin) : _pin{servoPin} {

}

void MyServo::look(MyServo::ServoDirection lookDirection) {
    _servo.attach(_pin);
    switch(lookDirection) {
        case SERVO_LEFT:
            _servo.write(SERVO_LEFT);
            break;

        case SERVO_LEFT_MID:
            _servo.write(SERVO_LEFT_MID);

            break;

        case SERVO_MID:
            _servo.write(SERVO_MID);

            break;

        case SERVO_RIGHT_MID:
            _servo.write(SERVO_RIGHT_MID);

            break;

        case SERVO_RIGHT:
            _servo.write(SERVO_RIGHT);
    }
    _servo.detach();
}
