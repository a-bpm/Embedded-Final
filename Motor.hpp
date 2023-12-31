/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Motor.hpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Abstracts a hobby motor component
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
        void run(int direction);

}; // end motor
#endif // end MOTOR_HPP
