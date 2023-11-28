/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: MyServo.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "MyServo.hpp"
#include <Servo.h>
#include <Arduino.h>

MyServo::MyServo() 
: _pin{0}, _servoDelay(0) {

}

MyServo::MyServo(byte servoPin, byte servoDelay)
: _servo{}, _pin{servoPin}, _servoDelay{servoDelay} {
    _servo.detach();
}

void MyServo::look(byte positionIndex) {
    _servo.attach(_pin);
    switch(positionIndex) {
        case SERVO_POSITION_1:
            moveAndDelay(SERVO_LEFT);
            break;

        case SERVO_POSITION_2:
            moveAndDelay(SERVO_LEFT_MID);
            break;

        case SERVO_POSITION_3:
            moveAndDelay(SERVO_MID);
            break;

        case SERVO_POSITION_4:
            moveAndDelay(SERVO_RIGHT_MID);
            break;

        case SERVO_POSITION_5:
            moveAndDelay(SERVO_RIGHT);
    }
    _servo.detach();
}

inline void MyServo::moveAndDelay(MyServo::ServoAngle angle) {
     unsigned int dynamicServoDelay = getServoDelay(angle);
     _servo.write(angle);
     delay(dynamicServoDelay); // must delay before detaching
}

unsigned int MyServo::getServoDelay(byte newAngle) {
    byte currentAngle = _servo.read();
    double delta = 0.0;
    if (newAngle >= currentAngle) {
        delta = ((newAngle - currentAngle) / 180.0);
    } else {
        delta = ((currentAngle - newAngle) / 180.0);
    }
    Serial.print("Servo delay from ");
    Serial.print(currentAngle);
    Serial.print(" to ");
    Serial.print(newAngle);
    Serial.print(" is ");
    Serial.println(delta * _servoDelay);
    delay(1500);
    return (delta * _servoDelay);
}

