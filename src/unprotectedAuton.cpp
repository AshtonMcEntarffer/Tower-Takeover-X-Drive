#include "main.h"
#include "global.h"
#include "lcd.h"
#include "autonomous.h"
#include "initialize.h"
#include "unprotectedAuton.h"

using namespace okapi;



void preUnprotectedAuton(){
  /*
  auto profileController = AsyncControllerFactory::motionProfile(
      0.35,  // Maximum linear velocity of the Chassis in m/s
      1.0,  // Maximum linear acceleration of the Chassis in m/s/s
      10.0, // Maximum linear jerk of the Chassis in m/s/s/s
      chassis // Chassis Controller
  );
  */
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{4.7_ft, 0_ft, 0_deg}},//4.2
    "Blue Small First" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{3.1_ft, 0_ft, 0_deg}},//2.3
    "Blue Small First Second" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{1.4_ft, 0_ft, 0_deg}},
    "Blue Small Second" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{2_ft, 0_ft, 0_deg}},
    "Blue Small Third" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{0.5_ft, 0_ft, 0_deg}},
    "Shift A" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{0.55_ft, 0_ft, 0_deg}},
    "Shift B" // Profile name
  );
}

void unprotectedAuton(){
  //flip out
  ramp.set_brake_mode(MOTOR_BRAKE_HOLD);
  top_left_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  top_right_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  bottom_left_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  bottom_right_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  armRight.set_brake_mode(MOTOR_BRAKE_HOLD);
  if(deploy){
    //move(500, 50);
    lift(1450, 100);
    pros::delay(200);
    intake(-200);
    //pros::delay(600);
    //move(-500, 50);
    pros::delay(500);
    lift(250, 100);
  }
  pros::delay(100);
  //int OGline = lineSensor.get_value();
  intake(150);
  forwardDrive();
  profileController.setTarget("Blue Small First");
  /*delay(1500);
  pros::lcd::print(0,"Line Sensor: %d; + %d", lineSensor.get_value(),OGline-100);
  int MAX_OFF = 50;
  if(lineSensor.get_value()!=8&&lineSensor.get_value()>OGline-MAX_OFF){
    delay(300);
    if(lineSensor.get_value()>OGline-MAX_OFF){
      delay(300);
      if(lineSensor.get_value()>OGline-MAX_OFF){
        pros::lcd::print(0,"FAILED: %d; + %d", lineSensor.get_value(),OGline-100);
        printf("Line Sensor: %d", lineSensor.get_value());
        master.rumble("-");
        reverseDrive();
        profileController.setTarget("Blue Small First Second");
        rollerRight.move_velocity(0);
        rollerLeft.move_velocity(0);
        while(true){
          top_left_mtr.move_velocity(0);
          top_right_mtr.move_velocity(0);
          bottom_left_mtr.move_velocity(0);
          bottom_right_mtr.move_velocity(0);
        }
        delay(13*1000);
      }
    }
  }*/
  delay(3250);
  intake(0);
  profileController.waitUntilSettled();
  /*
  turnPID(45 * color, 300);
  profileController.setTarget("Shift A");
  profileController.waitUntilSettled();
  reverseDrive();
  profileController.setTarget("Shift A");
  profileController.waitUntilSettled();
  forwardDrive();
  turnPID(-45 * color, 300);
  */
  reverseDrive();
  profileController.setTarget("Blue Small First Second");
  //delay(300); //1500
  //intake(0);
  profileController.waitUntilSettled();

  forwardDrive();
  turnPID(-127 * color,300);
  //turnRightNonAsync((-340*2+250) * color,46); //40 mmmmmmmmjh213 //230
  profileController.setTarget("Blue Small Second");
  profileController.waitUntilSettled();

  lift(-50, 100);
  intake(-600,140);
  delay(150);
  int initialPos = ramp.get_position();
  ramp.move_relative(2350,150); //100
  waitUntilTarget(ramp, 2350+initialPos);
  initialPos = ramp.get_position();
  ramp.move_relative(700,40);
  delay(100);
  //intake(-9000,350); //100 spd
  //delay(150); //500
  reverseDrive();
  profileController.setTarget("Blue Small Third");
  intake(-100);
  profileController.waitUntilSettled();
  intake(0);
}
