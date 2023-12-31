/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: MyServo.hpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Abstracts a servo component to allow for easy movement
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MYSERVO_HPP
#define MYSERVO_HPP
#include <Servo.h>
#include <Arduino.h>

class MyServo {
    private:
        Servo _servo;
        byte _pin;
        const unsigned long _servoDelay;

    public:
        enum ServoPosition {
            SERVO_POSITION_1 = 0,
            SERVO_POSITION_2 = 1,
            SERVO_POSITION_3 = 2,
            SERVO_POSITION_4 = 3,
            SERVO_POSITION_5 = 4,
        };

        enum ServoAngle {
            SERVO_LEFT = 0,
            SERVO_LEFT_MID = 45,
            SERVO_MID = 90,
            SERVO_RIGHT_MID = 135,
            SERVO_RIGHT = 180
        };
        // Constructor
        MyServo();
        MyServo(byte servoPin, unsigned long servoSpeed);

        void look(byte positionIndex); 
        void lookNoDelay(byte positionIndex);
                                       
                                       
        inline void moveAndDelay(MyServo::ServoAngle);
        inline void moveNoDelay(MyServo::ServoAngle);
        unsigned int getServoDelay(byte newAngle);
}; // end MyServo
#endif // END MYSERVO_HPP
