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

class Robot {
    private:
        Motor _rightLeg;
        Motor _leftLeg;
        Ultrasonic _eye;
        MyServo _neck;
        //IRrecv _irReceiver; // Not sure how I wanna handle ANYTHING related to this
    public:
      //constructors
        Robot();

      // methods

        // looking
        double looking(MyServo::ServoDirection direction);

        // -checking left and right
        byte check_L_R_SideDirection(double frontMeasure);

        // US
        double measureDistance();

        // -dynamic
        byte correctDirection();
        
        // movement
        void stop();

        // -dynamic 
        void moveForward();
        void moveReverse();
        // keep in mind may not be feasible because prof allen says its too hard
        void moveRight();
        void moveLeft();
        

        // -stationary
        void orientStart();
        void orientLeft();
        void orientRight();

}; // end Robot
#endif // End ROBOT_HPP
