#ifndef ULTRASONIC_HPP
#define ULTRASONIC_HPP

class Ultrasonic {
    private:
        byte _triggerPin;
        byte _echoPin;
        const unsigned long _maxDuration = 12 * 74 * 2;

    public:
        Ultrasonic();
        Ultrasonic(byte);
        Ultrasonic(byte, byte);
        unsigned long measureTime();
        double measureInch();
        double measureCm();
}; // end ultrasonic

#endif // Ultrasonic
