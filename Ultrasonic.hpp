/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Ultrasonic.hpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Abstracts an Ultrasonic sensor component
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ULTRASONIC_HPP
#define ULTRASONIC_HPP
#include <Arduino.h>

class Ultrasonic {
    private:
        byte _triggerPin;
        byte _echoPin;
        const unsigned long _maxDuration = 12 * 74 * 2;

    public:
        Ultrasonic();
        Ultrasonic(byte pinNum);
        Ultrasonic(byte triggerPin, byte echoPin);
        unsigned long measureTime();
        double measureInch();
        double measureCm();
}; // end ultrasonic
#endif // Ultrasonic
