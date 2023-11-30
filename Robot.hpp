/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Robot.hpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Arduino.h>
//#include <IRremote.hpp>
#include "Motor.hpp"
#include "Ultrasonic.hpp"
#include "MyServo.hpp"

extern const byte MOTOR_RIGHT_ENABLE_PIN;
extern const byte MOTOR_RIGHT_FORWARD_PIN;
extern const byte MOTOR_RIGHT_BACKWARD_PIN;

extern const byte MOTOR_LEFT_ENABLE_PIN;
extern const byte MOTOR_LEFT_FORWARD_PIN;
extern const byte MOTOR_LEFT_BACKWARD_PIN;

extern const byte ULTRASONIC_TRIGGER_PIN;
extern const byte ULTRASONIC_ECHO_PIN;

extern const byte SERVO_PIN;
extern const byte IR_RECEIVER_PIN;

extern const unsigned long SERVO_DELAY;

class Robot {
    private:
        Motor *_rightLeg;
        Motor *_leftLeg;
        Ultrasonic *_eye;
        MyServo _neck;
        byte _speed;
        //IRrecv _irReceiver; // Not sure how I wanna handle ANYTHING related to this
    public:
      // specify the look trajectory for coresponding robot
        enum RobotDirection {
            ROBOT_LEFT = 0,
            ROBOT_LEFT_MID = 1,
            ROBOT_MID = 2,
            ROBOT_RIGHT_MID = 3,
            ROBOT_RIGHT = 4
        };

      //constructors
        Robot();
        Robot(byte speed);

      // methods

        // looking (turning servo doing specific delay and measuring the distance)
        double scanDirection(RobotDirection direction);

        // -checking left and right
        byte getTurnDirection();

        // US
        double measureDistance();

        // -dynamic
        //byte correctDirection(); TODO
        
        // movement
        void stop();

        // -dynamic 
        void moveForward();
        void moveReverse();
        // keep in mind may not be feasible because prof allen says its too hard
        void moveRight();
        void moveLeft();
        

        // -stationary
        void orientLeft();
        void orientRight();
        void orient180();

}; // end Robot
#endif // End ROBOT_HPP
