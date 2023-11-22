#include <Servo.h>
#include <IRremote.h>
#include "include/Ultrasonic.hpp"
#include "include/Motor.hpp"

/// Global constants
// Ultrasonic pins
const byte ULTRASONIC_TRIGGER_PIN = A1;
const byte ULTRASONIC_ECHO_PIN = A0;

// servo signal pin
const byte SERVO_PIN = A2;

// ir pin
const byte IR_RECEIVER_PIN = 12;

// right motor pins
const byte MOTOR_RIGHT_ENABLE_PIN = 5;
const byte MOTOR_RIGHT_FORWARD_PIN = 4;
const byte MOTOR_RIGHT_BACKWARD_PIN = 2;

// left motor pins
const byte MOTOR_LEFT_ENABLE_PIN = 6;
const byte MOTOR_LEFT_FORWARD_PIN = 8;
const byte MOTOR_LEFT_BACKWARD_PIN = 7;

/// Global Variables
// Ultrasonic
Ultrasonic ultrasonicSensor(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);

// Servo
Servo neckServo;
int FORWARDPOS = 0;
int LEFTPOS = 0;
int RIGHTPOS = 0;


// Motors
  // set up Left Motor
Motor leftMotor;
  // set up Right Motor
Motor rightMotor;
  // set up speed and delay
byte speed = 0;
const int DELAY = 6 * 1000;

void setup() {
    // set up console
    Serial.begin(9600);

    // set up servo
    neckServo.attach(SERVO_PIN, 500, 2500);
    // set up US

    // set up Motors
    leftMotor = Motor(MOTOR_LEFT_FORWARD_PIN, MOTOR_LEFT_BACKWARD_PIN, MOTOR_LEFT_ENABLE_PIN);
    rightMotor = Motor(MOTOR_RIGHT_FORWARD_PIN, MOTOR_RIGHT_BACKWARD_PIN, MOTOR_RIGHT_ENABLE_PIN);

    // set up IR
    IrReceiver.begin(IR_RECEIVER_PIN, true);

    // ?
    pinMode(ULTRASONIC_ECHO_PIN , OUTPUT);
    pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT);
    digitalWrite(ULTRASONIC_ECHO_PIN, LOW);
    digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);

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

bool ultrasonicInterrupt = false;
void loop() {

  // loop A: (look forward, move, determine)

  if(ultrasonicInterrupt) {

  }
  
  servoLook.write(FORWARDPOS);                            //Set the servo to look straight ahead
  delay(750);
  int forwardDistance = ultrasonicSensor.measure();                   //Check that there are no objects ahead
  if(forwardDistance >= stopDist)                        //If there are no objects within the stopping distance, move forward
  {
    moveForward();
  }
  while(forwardDistance >= stopDist)                     //Keep checking the object distance until it is within the minimum stopping distance
  {
    forwardDistance = ultrasonicSensor.measure();
    delay(250);
  }
  else{
    stopMove();                                     //Stop the motors
    int turnDir = checkDirection();
  }

  switch(turnDirectionState)
  {
    case TURNLEFT:

    case TURNRIGHT:
  }
  
  
  // loop B (look, determine, move):
  
  
  /// look around (I have a feeling we can somehow make this process into a for loop or robot class method called three times)
  // for(int i = 0; i > 2; i++ ) // we can make the poistion change in this too i think but we can make explicit changes as well
  // look left
    //position = *left*/;
    // turn neck left
    neckServo.write(position);

    // delay to properly time the servo turn before US measure
    delay(1300);
  
    // measurement
    unsigned long durationLeftLength = ultrasonicSensor.measureInch();
    
    // small delay to time servo after measurement
    delay(130);

    // get ready to turn middle
    //position = /*middle */;
  
  // look middle
    
  // look right
    
  ///determine measurement


  /*
  if(left > 14 && Forward > 14 && Right > 14)
  {
    Finished
  }

  else if(left > 7 && Forward > 14 && Right > 14)
  {
    Centered
  }

  else if(left > 7 && Forward > 14 && Right > 14)
  {
    Left of Center
  }

  else if(left > 7 && Forward > 14 && Right > 14)
  {
    Right of Centered
  }

  else if(left > 14 && Forward > 14 && Right > 14)
  {
    //Left Turn

    left();
    delay(500);
    Stop();
    delay(200);
  }

  else if(left > 14 && Forward > 14 && Right > 14)
  {
    //Right Turn
    right();
    delay(500);
    Stop();
    delay(200);
  }
  */

/// move

  // turn based on measure (we can use enums for the movement states)
  //switch(state)
  
  // move forward
  Serial.println("Forward...");
  leftMotor.run(Motor::MotorForward);
  rightMotor.run(Motor::MotorForward);
  delay(DELAY);
  
}


ISR(TIMER_OCF_vect) {
    ultrasonicInterrupt = true;
}
