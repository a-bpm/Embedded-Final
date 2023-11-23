/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Filename: Robot.hpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Servo.h>
#include <IRremote.h>

#include "Motor.hpp"
#include "Ultrasonic.hpp"

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

// how do we set up the pins for the robot, how do we call the constructors?
class Robot {
    private:
        Motor _rightLeg;
        Motor _leftLeg;
        Ultrasonic _eye;
        Servo _neck;
        IRRecv _irReceiver;
    public:
      //constructors
        Robot() { }

      // methods

        // looking
        int checkDirection();
        
        // movement
        void moveForward();
        void stop();
        void moveLeft();
        void moveRight();
        void moveReverse();
}; // end ultrasonic
#endif // Ultrasonic
