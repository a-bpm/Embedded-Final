/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: MyServo.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "MyServo.hpp"
#include <Arduino.h>

MyServo::MyServo(byte servoPin) : _pin{servoPin}, _SERVO_SPEED{7} {

}

void MyServo::look(byte positionIndex) { // TODO: function pointer here
    _servo.attach(_pin);
    int dynamicDelay = 1300;
   switch(positionIndex) {
       case SERVO_POSITION_1:
            _servo.write(SERVO_LEFT);
            dynamicDelay = getServoDelay(SERVO_LEFT);
            break;

        case SERVO_POSITION_2:
            _servo.write(SERVO_LEFT_MID);
            dynamicDelay = getServoDelay(SERVO_LEFT_MID);

            break;

        case SERVO_POSITION_3:
            _servo.write(SERVO_MID);
            dynamicDelay = getServoDelay(SERVO_MID);

            break;

        case SERVO_POSITION_4:
            _servo.write(SERVO_RIGHT_MID);
            dynamicDelay = getServoDelay(SERVO_RIGHT_MID);

            break;

        case SERVO_POSITION_5:
            _servo.write(SERVO_RIGHT);
            dynamicDelay = getServoDelay(SERVO_RIGHT);
   }
   delay(dynamicDelay); // TODO: Do I have to detach before I wait? or after
   _servo.detach();
}

int MyServo::getServoDelay(byte newPosition) {
    byte currentPosition = _servo.read();
    int delta = 0;
    if (newPosition >= currentPosition) {
        delta = newPosition - currentPosition;
    } else {
        delta = currentPosition - newPosition;
    }
    return (delta * _SERVO_SPEED);
}
