#include <Servo.h>
#include "ultrasonic.h"
#include "motor.h"

// Global constants

// US pins
const byte ULTRASONIC_ECHO = A0;
const byte ULTRASONIC_TRIGGER = A1;

// servo signal pin
const byte SERVO_PIN = A2;

// ir pin
const byte INFRARED_REMOTE_PIN = 12;

// right motor pins
const byte MOTOR_RIGHT_ENABLE = 5;
const byte MOTOR_RIGHT_FORWARD = 4;
const byte MOTOR_RIGHT_BACKWARD = 2;

// left motor pins
const byte MOTOR_LEFT_ENABLE = 6;
const byte MOTOR_LEFT_FORWARD = 8;
const byte MOTOR_LEFT_BACKWARD = 7;

/// Global Variables

// US
Ultrasonic ultrasonicSensor(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);

// Servo
Servo neckServo;
int position = 0;

// Motors
  // set up Left Motor
Motor leftMotor;
  // set up Right Motor
Motor rightMotor;
  // set up speed and delay
byte speed = 0;
const int DELAY = 6 * 1000;

// IR_S

void setup() {
    // set up console
    Serial.begin(9600);

    // set up servo
    neckServo.attach(SERVO_PIN, 500, 2500);
    // set up US

    // set up Motors
    leftMotor = Motor(MOTOR_LEFT_FORWARD, MOTOR_LEFT_BACKWARD, MOTOR_LEFT_ENABLE);
    rightMotor = Motor(MOTOR_RIGHT_FORWARD, MOTOR_RIGHT_BACKWARD, MOTOR_RIGHT_ENABLE);

    // set up IR
    IrReceiver.begin(IR_RECEIVE_PIN, true);

    // ?
    pinMode(SIG_PIN, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    digitalWrite(SIG_PIN, LOW);
    digitalWrite(TRIG_PIN, LOW);

  // set up timer1 count
    TCNT1H = 0xF3;
    TCNT1L = 0xCB;
  
  // set up timer1 mode: normal
    TCCR1A = 0x00;
  
  // Set up  clock in TCCR1B
    TCCR1B = (1 << CS10) | (1 << CS12); // Prescaler = 1024
  
  // set up timer1 interupt
    TIMSK1 = (1 << TOIE1);

  // enable global interupts
    interrupts();
}

void loop() {

  if(flag) {


  }
  /// look around (I have a feeling we can somehow make this process into a for loop or robot class method called three times)
  // for(int i = 0; i > 2; i++ ) // we can make the poistion change in this too i think but we can make explicit changes as well
  // look left
    position = /*left*/;
    // turn neck left
    neckServo.write(position);
  
    // measurement
    unsigned long durationLeftLength = ultrasonicSensor.measure;
    
    // delay
    delay(1300);

    // get ready to turn left
    position = /*middle */
  
  // look middle
    neckServo.write(position);
  
    // measurement
    unsigned long durationMiddleLength = ultrasonicSensor.measure;
    
    // delay
    delay(1300);

    // get ready to turn left
    position = /*right*/
  // look right
    neckServo.write(position);
  
    // measurement
    unsigned long durationRightLength = ultrasonicSensor.measure;
    
    // delay
    delay(1300);

  ///determine measurement
  if(left > 14 && Forward > 14 && Right > 14)
  {
    Finished
  }

  if(left > 7 && Forward > 14 && Right > 14)
  {
    Centered
  }

  if(left > 7 && Forward > 14 && Right > 14)
  {
    Left of Center
  }

  if(left > 7 && Forward > 14 && Right > 14)
  {
    Right of Centered
  }

  if(left > 14 && Forward > 14 && Right > 14)
  {
    Left Turn
  }

  if(left > 14 && Forward > 14 && Right > 14)
  {
    Right Turn
  }

  // move

  // turn based on measure (we can use enums for the movement states)
  switch(state)
  
  // move forward
  Serial.println("Forwwad..");
  leftMotor.run(Motor::MotorForward);
  rightMotor.run(Motor::MotorForward);
  delay(DELAY);
  
}


ISR(TIMER_OCF_vect) {
    interrupted = true;
}
