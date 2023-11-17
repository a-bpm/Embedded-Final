#include "motor.hpp"

void Motor::Motor::run(Motor::MotorDirection direction) {
  switch (direction) {
    case MotorStop:
      digitalWrite(_pin1, LOW);
      digitalWrite(_pin2, LOW);
      digitalWrite(_enable, LOW);
      break;

    case MotorForward:
      digitalWrite(_pin1, HIGH);
      digitalWrite(_pin2, LOW);
      analogWrite(_enable, _speed);
      break;

    case MotorReverse:
      digitalWrite(_pin1, LOW);
      digitalWrite(_pin2, HIGH);
      analogWrite(_enable, _speed);
  }  // switch end
}
