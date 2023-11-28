/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Ultrasonic.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Ultrasonic.hpp"
#include <Arduino.h>


Ultrasonic::Ultrasonic()
: _triggerPin{0}, _echoPin{0} {}

Ultrasonic::Ultrasonic(byte pinNum)
: _triggerPin(pinNum), _echoPin{pinNum} {
    pinMode(_echoPin, OUTPUT);
    pinMode(_triggerPin, OUTPUT);
    digitalWrite(_triggerPin, LOW);
    digitalWrite(_echoPin, LOW);
}

Ultrasonic::Ultrasonic(byte triggerPin, byte echoPin) 
: _triggerPin{triggerPin}, _echoPin{echoPin} {
      pinMode(_echoPin, OUTPUT);
      pinMode(_triggerPin, OUTPUT);
      digitalWrite(_triggerPin, LOW);
      digitalWrite(_echoPin, LOW);
}

unsigned long Ultrasonic::measureTime() {
    noInterrupts();

    unsigned long duration = 0;

    pinMode(_echoPin, OUTPUT);
    digitalWrite(_echoPin, LOW);
    pinMode(_triggerPin, OUTPUT);

    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(5);
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_triggerPin, LOW);

    pinMode(_echoPin, INPUT);
    duration = pulseIn(_echoPin, _maxDuration);

    interrupts();

    if (duration > 0) {
        duration /= 2;
    }

    return duration;
}

double Ultrasonic::measureInch() {
    double inches = 0;
    unsigned long duration = measureTime();
    if (duration > 0) {
        inches = duration / 74;
    }
    // interrupted = false; TODO
    return inches;
}

double Ultrasonic::measureCm() {
    double centimeters = 0;
    unsigned long duration = measureTime();
    if (duration > 0) {
        centimeters = duration / 29.1;
    }
    // interrupted = false; TODO
    return centimeters;
}
