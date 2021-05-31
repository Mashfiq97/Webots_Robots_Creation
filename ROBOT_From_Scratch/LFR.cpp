//#include <webots/DistanceSensor.hpp>
//#include <webots/Motor.hpp>
//#include <webots/Robot.hpp>

//#include <webots/Camera.hpp>

#define TIME_STEP 64
using namespace webots;

int main(int argc, char **argv) {
  
  Robot *robot = new Robot(); //Pyhton
  
    Motor left_motor=robot->getMotor("Left Wheel Motor");
    Motor right_motor=robot->getMotor("Right Wheel Motor");
    left_motor->setPosition(INFINITY);
    right_motor->setPosition(INFINITY);
    left_motor->setVelocity(0.0);
    right_motor->setVelocity(0.0);



    DistanceSensor right_ir=robot->getDistanceSensor("ds_right");
    right_ir->enable(TIME_STEP);

    DistanceSensor mid_ir=robot->getDistanceSensor("ds_middle");
    mid_ir->enable(TIME_STEP);

    DistanceSensor left_ir=robot->getDistanceSensor("ds_left");
    left_ir->enable(TIME_STEP);


  
  
  while (robot->step(TIME_STEP) != -1) {


    right_ir_val = right_ir->getValue();
    mid_ir_val = mid_ir->getValue();
    left_ir_val = left_ir->getValue();

    double leftSpeed = -1.0;
    double rightSpeed = -1.0;
    
    if ((left_ir_val<700) && (right_ir_val<700) && (mid_ir_val>=700)){
        left_motor->setVelocity(-leftSpeed);
        right_motor->setVelocity(-rightSpeed);
    }
    if ((left_ir_val<700) && (right_ir_val>=700) && (mid_ir_val>=700)){
        left_motor->setVelocity(-leftSpeed);
        right_motor->setVelocity(0.0);
    }
    if ((left_ir_val>=700) && (right_ir_val<700) && (mid_ir_val>=700)){
        left_motor->setVelocity(0.0);
        right_motor->setVelocity(-rightSpeed);
    }
    if ((left_ir_val>=700) && (right_ir_val<700) && (mid_ir_val<700)){
        left_motor->setVelocity(0.0);
        right_motor->setVelocity(-rightSpeed);
    }
    if ((left_ir_val<700) && (right_ir_val>=700) && (mid_ir_val<700)){
        left_motor->setVelocity(-leftSpeed);
        right_motor->setVelocity(0.0);
    }

    if ((left_ir_val<700) && (right_ir_val<700) && (mid_ir_val<700)){
        left_motor->setVelocity(-leftSpeed);
        right_motor->setVelocity(-rightSpeed);
    }
    
  }
  delete robot;
  return 0;  // EXIT_SUCCESS
}