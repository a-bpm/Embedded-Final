/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: MyServo.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "MyServo.hpp"
#include <Servo.h>
#include <Arduino.h>

MyServo::MyServo() 
: _pin{0}, _SERVO_SPEED(0) {

}

MyServo::MyServo(byte servoPin, byte servoSpeed)
: _servo{}, _pin{servoPin}, _SERVO_SPEED{servoSpeed} {
    _servo.detach();
}

void MyServo::look(byte positionIndex) { // TODO: function pointer here
    _servo.attach(_pin);
    int dynamicDelay = 1300; // 1300 is the total ms it takes to go from 0 to 180
    Serial.print("Position: ");
    Serial.println(positionIndex);
    Serial.print("Direction: ");
   switch(positionIndex) {
       case SERVO_POSITION_1:
           dynamicDelay = getServoDelay(SERVO_LEFT);
           Serial.print(SERVO_LEFT);
            _servo.write(SERVO_LEFT);
            break;

        case SERVO_POSITION_2:
            dynamicDelay = getServoDelay(SERVO_LEFT_MID);
            Serial.print(SERVO_LEFT_MID);
            _servo.write(SERVO_LEFT_MID);

            break;

        case SERVO_POSITION_3:
            dynamicDelay = getServoDelay(SERVO_MID);
            Serial.print(SERVO_MID);
            _servo.write(SERVO_MID);

            break;

        case SERVO_POSITION_4:
            dynamicDelay = getServoDelay(SERVO_RIGHT_MID);
            Serial.print(SERVO_RIGHT_MID);
            _servo.write(SERVO_RIGHT_MID);

            break;

        case SERVO_POSITION_5:
            dynamicDelay = getServoDelay(SERVO_RIGHT);
            Serial.print(SERVO_RIGHT);
            _servo.write(SERVO_RIGHT);
   }
   delay(dynamicDelay); // TODO: Do I have to detach before I wait? or after
   _servo.detach();
}

int MyServo::getServoDelay(byte newPosition) {
    byte currentPosition = _servo.read();
    Serial.print("Current servo reading");
    Serial.println(currentPosition);
    byte delta = 0;
    if (newPosition >= currentPosition) {
        delta = newPosition - currentPosition;
    } else {
        delta = currentPosition - newPosition;
    }
    return (delta * _SERVO_SPEED);
}
