/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: MyServo.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "MyServo.hpp"
#include <Servo.h>
#include <Arduino.h>

MyServo::MyServo() : _pin{0}, _SERVO_SPEED(0) {

}

MyServo::MyServo(byte servoPin) : _servo{new Servo()}, _pin{servoPin}, _SERVO_SPEED{7} {
    _servo->detach();
}

void MyServo::look(byte positionIndex) { // TODO: function pointer here
    _servo->attach(_pin);
    int dynamicDelay = 1300;
    Serial.print("Look Index :");
    Serial.println(positionIndex);
   switch(positionIndex) {
       case SERVO_POSITION_1:
            _servo->write(SERVO_LEFT);
            dynamicDelay = getServoDelay(SERVO_LEFT);
            Serial.println("Pos 1");
            break;

        case SERVO_POSITION_2:
            _servo->write(SERVO_LEFT_MID);
            dynamicDelay = getServoDelay(SERVO_LEFT_MID);
            Serial.println("Pos 2");

            break;

        case SERVO_POSITION_3:
            _servo->write(SERVO_MID);
            dynamicDelay = getServoDelay(SERVO_MID);
            Serial.println("Pos 3");

            break;

        case SERVO_POSITION_4:
            _servo->write(SERVO_RIGHT_MID);
            dynamicDelay = getServoDelay(SERVO_RIGHT_MID);
            Serial.println("Pos 4");

            break;

        case SERVO_POSITION_5:
            _servo->write(SERVO_RIGHT);
            dynamicDelay = getServoDelay(SERVO_RIGHT);
            Serial.println("Pos 5");
   }
   delay(dynamicDelay); // TODO: Do I have to detach before I wait? or after
   _servo->detach();
}

int MyServo::getServoDelay(byte newPosition) {
    byte currentPosition = _servo->read();
    int delta = 0;
    if (newPosition >= currentPosition) {
        delta = newPosition - currentPosition;
    } else {
        delta = currentPosition - newPosition;
    }
    return (delta * _SERVO_SPEED);
}
