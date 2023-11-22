#include "Robot.hpp"

Robot::Robot() : {}

Robot::Robot(byte triggerPin, byte echoPin) {
  Ultrasonic ultrasonicSensor(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);
}