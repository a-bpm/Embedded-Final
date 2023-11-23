/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Motor.hpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MOTOR_HPP
#define MOTOR_HPP
#include <Arduino.h>

class Motor {
    private: // _var denotes property variables
        byte _pin1;
        byte _pin2;
        byte _enablePin;
        byte _speed;

    public:
        enum MotorDirection {
            MotorStop = 0,
            MotorForward,
            MotorReverse
        }; // end enum MotorDir

        Motor();
        Motor(byte pin1, byte pin2, byte enable);

        byte getSpeed();
        void setSpeed(byte speed);
        void run(MotorDirection direction);

}; // end motor
#endif
