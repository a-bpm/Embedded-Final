#ifndef MOTOR_HPP
#define MOTOR_HPP

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

#endif
