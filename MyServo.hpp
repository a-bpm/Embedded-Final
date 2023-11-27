/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: MyServo.hpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MYSERVO_HPP
#define MYSERVO_HPP
#include <Servo.h>
#include <Arduino.h>

class MyServo {
    private:
        Servo *_servo;
        byte _pin;
        const byte _SERVO_SPEED;

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
        MyServo(byte servoPin);

        void look(byte positionIndex);
        int getServoDelay(byte newPosition);
}; // end MyServo
#endif // END MYSERVO_HPP
