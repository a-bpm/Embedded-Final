/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Motor.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Abstracts a hobby motor component
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Motor.hpp"
#include <Arduino.h>

Motor::Motor() : _pin1{0}, _pin2{0}, _enablePin{0}, _speed{0} { } 

Motor::Motor(byte pin1, byte pin2, byte enable)
    : _pin1{pin1}, _pin2{pin2}, _enablePin{enable}, _speed{0} {
        pinMode(_pin1, OUTPUT);
        pinMode(_pin2, OUTPUT);
        pinMode(_enablePin, OUTPUT);
    } // end Motor prop constructor

void Motor::Motor::run(int direction) {
    switch(direction) {
        case 0:
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, LOW);
            digitalWrite(_enablePin, LOW);
            break;

        case 1:
            digitalWrite(_pin1, HIGH);
            digitalWrite(_pin2, LOW);
            analogWrite(_enablePin, _speed);
            break;

        case 2:
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, HIGH);
            analogWrite(_enablePin, _speed);
    }  // switch end
} // motor run end

void Motor::Motor::setSpeed(byte speed) {
    _speed = speed;
}

byte Motor::Motor::getSpeed() {
    return _speed;  
}
