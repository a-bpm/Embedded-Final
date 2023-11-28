/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
    Filename: Robot.cpp
    Written by: Kevin Kostage and Andrew Bryan
    Description: Does something?
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Robot.hpp"

// right motor pins
const byte MOTOR_LEFT_ENABLE_PIN = 5;
const byte MOTOR_LEFT_FORWARD_PIN = 4;
const byte MOTOR_LEFT_BACKWARD_PIN = 2;

// left motor pins
const byte MOTOR_RIGHT_ENABLE_PIN = 6;
const byte MOTOR_RIGHT_BACKWARD_PIN = 7;
const byte MOTOR_RIGHT_FORWARD_PIN = 8;

// Ultrasonic pins
const byte ULTRASONIC_TRIGGER_PIN = A1;
const byte ULTRASONIC_ECHO_PIN = A0;

const byte SERVO_PIN = A2;
const byte IR_RECEIVER_PIN = 12;

const byte SERVO_SPEED = 7;

Robot::Robot() {}

Robot::Robot(byte speed)
: _rightLeg{new Motor(MOTOR_RIGHT_FORWARD_PIN, MOTOR_RIGHT_BACKWARD_PIN,
                      MOTOR_RIGHT_ENABLE_PIN)},
_leftLeg{new Motor(MOTOR_LEFT_FORWARD_PIN, MOTOR_LEFT_BACKWARD_PIN,
                      MOTOR_LEFT_ENABLE_PIN)},
_eye{new Ultrasonic(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN)},
_neck{MyServo(SERVO_PIN, SERVO_SPEED)},
_speed{speed} {
    _leftLeg->setSpeed(_speed);
    _rightLeg->setSpeed(_speed);
  //_irReceiver.begin(IR_RECEIVER_PIN, true);
} // end Robot constructor

// turning servo and getting measurement
double Robot::scanDirection(RobotDirection direction) {
  _neck.look(direction); // Set the servo to look @ desired direction
  double distance = _eye->measureInch();

  Serial.print(distance);
  Serial.print(" inches");

  return distance;
}

// US sensor
double Robot::measureDistance() {
  // declare variable
  // assign it to the measurement from the US eye in inches
}

// getting measurements on both sides and return which direction to turn based
// on measurement values
byte Robot::getTurnDirection(double frontDistance) {
  // set up declare distances and direction variables
  byte turnDir = 0;

  // turn the neck to look left and get the distance and assign it to a distance
  // 1 value
  double leftDistance = scanDirection(RobotDirection::ROBOT_LEFT); // left

  // turn the neck to look right and get the distance and assign it to a
  // distance 2 value
  double rightDistance = scanDirection(RobotDirection::ROBOT_RIGHT); // right

  // determine direction to turn based on determined measurements
  // if the right area is more open then do a...
  if (leftDistance <= 14 && frontDistance <= 7 &&
      rightDistance > 14) { // Right Turn
    turnDir = 1;
  }

  // return the direction for the switch
  return turnDir;
}

// byte Robot::correctDirection() {
//  set up declare distances and direction variables

// turn the neck to look left
//_neck.look(MyServo::ServoDirection::SERVO_LEFT)
// delay

// get the distance and assign it to a distance 1 value
// left = checkDistance();
// turn the neck to look right
//_neck.look(MyServo::ServoDirection::SERVO_RIGHT)
// delay

// get the distance and assign it to a distance 2 value
// right = checkDistance();
// determine direction to turn

// determine measurement
/*
if(left > 14 && Forward > 14 && Right > 14)
{
  Finished
}

else if(left < 7 && Forward > 14 && Right > 7)
{
  Left of Center
}

else if(left > 7 && Forward > 14 && Right < 14)
{
  Right of Centered
}

else // (left > 7 && Forward > 14 && Right > 7)
{
  Centered
}
*/
//}

void Robot::stop() {
  Serial.println("Stopping right...");
  _rightLeg->run(Motor::MotorDirection::MotorStop);
  Serial.println("Stopping left...");
  _leftLeg->run(Motor::MotorDirection::MotorStop);
  Serial.println("Stopped both");
}

void Robot::moveForward() {
  _rightLeg->run(Motor::MotorForward);
  _leftLeg->run(Motor::MotorForward);
}

void Robot::moveReverse() {
    _rightLeg->run(Motor::MotorReverse);
    _leftLeg->run(Motor::MotorReverse);
}

void Robot::moveLeft() {
  _rightLeg->setSpeed(_leftLeg->getSpeed() / 2);
  _rightLeg->run(Motor::MotorForward);
  _leftLeg->run(Motor::MotorForward);
  delay(150);
  _rightLeg->setSpeed(_leftLeg->getSpeed());
}

void Robot::moveRight() {
  _leftLeg->setSpeed(_rightLeg->getSpeed() / 2);

  _rightLeg->run(Motor::MotorDirection::MotorForward);
  _leftLeg->run(Motor::MotorDirection::MotorForward);
  delay(150);
  _leftLeg->setSpeed(_rightLeg->getSpeed());
}

void Robot::orientLeft() {
  _rightLeg->run(Motor::MotorDirection::MotorForward);
  _leftLeg->run(Motor::MotorDirection::MotorReverse);
  delay(250);
}

void Robot::orientRight() {
  _rightLeg->run(Motor::MotorDirection::MotorForward);
  _leftLeg->run(Motor::MotorDirection::MotorReverse);
  delay(250);
}

void Robot::orient180() {
  _rightLeg->run(Motor::MotorDirection::MotorForward);
  _leftLeg->run(Motor::MotorDirection::MotorReverse);
  delay(500);
}
