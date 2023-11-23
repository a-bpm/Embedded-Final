/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: MyServo.hpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MYSERVO_HPP
#define MYSERVO_HPP
#include <Servo.h>

class MyServo {
    private:
        Servo _servo;
        byte _pin;

    public:
        enum ServoDirection {
            SERVO_LEFT = 0,
            SERVO_LEFT_MID = 45,
            SERVO_MID = 90,
            SERVO_RIGHT_MID = 135,
            SERVO_RIGHT = 180
        };

        // Constructor
        MyServo();
        MyServo(byte servoPin);

        void look();



}; // end MyServo

#endif // END MYSERVO_HPP
