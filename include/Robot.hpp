#ifndef ROBOT_HPP
#define ROBOT_HPP


// how do we set up the pins for the robot, how do we call the constructors?
class Robot {
    private:
        Motor leftLeg;
        Motor rightLeg;
        Ultrasonic eye;
        Servo neck;

    public:
      //constructors
        Robot();
        // it will only need the US trigger and echo since it is the only class that can be initialized globally, the rest of the modules of the robot will be inialized inside set up
        Robot(byte triggerPin, byte echoPin);

      // methods

        // looking
        int checkDirection();
        
        // movement
        void moveForward();
        void moveStop();
        void moveLeft();
        void moveRight();
        void moveReverse();





        
}; // end ultrasonic
#endif // Ultrasonic