
#include <Servo.h>

// Global constants

const byte US_ECHO = A0;
const byte US_TRIGGER = A1;

const byte SERVO_PIN = 

const int H1A = 4;
const int H2A = 3;
const int H12EN = 10;

const int H3A = 5;
const int H4A = 6;
const int H34EN = 11;

class Motor {
    private: // _var denotes property variables
        byte _pin1;
        byte _pin2;
        byte _enable;
        byte _speed;

    public:
        enum MotorDirection {
            MotorStop = 0,
            MotorForward,
            MotorReverse
        }; // end enum MotorDir

        Motor() : _pin1{0}, _pin2{0}, _enable{0}, _speed{0} { }
        Motor(byte pin1, byte pin2, byte enable)
            : _pin1{pin1}, _pin2{pin2}, _enable{enable}, _speed{0}
        {
            pinMode(_pin1, OUTPUT);
            pinMode(_pin2, OUTPUT);
            pinMode(_enable, OUTPUT);
        } // end Motor prop constructor

        byte getSpeed();
        void setSpeed(byte newSpeed);
        void run(MotorDirection direction);

}; // end motor

class Ultrasonic {
    private:
        byte triggerPin;
        byte echoPin;
        const unsigned long maxDuration = 12 * 74 * 2;

    public:
        Ultrasonic();
        Ultrasonic(byte);
        Ultrasonic(byte, byte);
        unsigned long measureTime();
        double measureInch();
        double measureCm();
}; // end ultrasonic

void setup() {

    Serial.begin(9600);
    pinMode(SIG_PIN, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    digitalWrite(SIG_PIN, LOW);
    digitalWrite(TRIG_PIN, LOW);

    TCNT1H = 0xC2;
    TCNT1L = 0xF7;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TIMSK1 = (1 << TOIE1);

    interrupts();


}

void loop() {
}

Ultrasonic::Ultrasonic() {
    triggerPin = 0;
    echoPin = 0;
}

Ultrasonic::Ultrasonic(byte pinNum) {
    triggerPin = pinNum;
    echoPin = pinNum;
}

Ultrasonic::Ultrasonic(byte sigPin, byte trigPin) {
    triggerPin = sigPin;
    echoPin = trigPin;
}

unsigned long Ultrasonic::measureTime() {
    noInterrupts();

    unsigned long duration = 0;

    pinMode(echoPin, OUTPUT);
    pinMode(triggerPin, OUTPUT);

    digitalWrite(triggerPin, LOW);
    delayMicroseconds(5);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, maxDuration);

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
    interrupted = false;
    return inches;
}

double Ultrasonic::measureCm() {
    double centimeters = 0;
    unsigned long duration = measureTime();
    if (duration > 0) {
        centimeters = duration / 29.1;
    }
    interrupted = false;
    return centimeters;
}

ISR(TIMER_OCF_vect) {
    interrupted = true;
}
