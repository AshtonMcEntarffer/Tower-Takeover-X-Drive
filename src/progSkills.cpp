#include "main.h"
#include "global.h"
#include "lcd.h"
#include "autonomous.h"
#include "initialize.h"
#include "progSkills.h"


using namespace okapi;

void preProgSkills(){//
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{8_ft, 0_ft, 0_deg}},//3.8
    "InFirst8" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{4.5_ft, 0_ft, 0_deg}},//3.8
    "InFirst4" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{0.4_ft, 0_ft, 0_deg}},//3.8
    "strafeTower" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{1.8_ft, 0_ft, 0_deg}},//3.8
    "InMiddle1" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{4.1_ft, 0_ft, 0_deg}},//3.8
    "InEnd4" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{0.5_ft, 0_ft, 0_deg}},//3.8
    "revB4Stack" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{1.8_ft, 0_ft, 0_deg}},//3.8
    "for4Stack" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{0.3_ft, 0_ft, 0_deg}},//3.8
    "for4StackSmol" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{2.3_ft, 0_ft, 0_deg}},//3.8
    "backUpFromStack" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{2.3_ft, 0_ft, 0_deg}},//3.8
    "for4Tower" // Profile name
  );
  profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{1_ft, 0_ft, 0_deg}},//3.8
    "backUpFromTower" // Profile name
  );
}

void progSkills(){
  //flip out
  ramp.set_brake_mode(MOTOR_BRAKE_HOLD);
  lift(1500, 100);
  pros::delay(200);
  intake(-650);
  pros::delay(1200);
  lift(100, 100);

  pros::delay(100);

  intake(650);

  profileController.setTarget("InFirst4");
  profileController.waitUntilSettled();
  delay(100);
  leftDrive();
  profileController.setTarget("strafeTower");
  profileController.waitUntilSettled();
  delay(100);
  forwardDrive();
  profileController.setTarget("InMiddle1");
  profileController.waitUntilSettled();
  delay(100);
  rightDrive();
  profileController.setTarget("strafeTower");
  profileController.waitUntilSettled();
  delay(100);
  forwardDrive();
  profileController.setTarget("InEnd4");
  profileController.waitUntilSettled();
  delay(100);

  reverseDrive();
  profileController.setTarget("revB4Stack");
  profileController.waitUntilSettled();
  delay(100);
  forwardDrive();
  turnRightNonAsync(-130,20,2);
  delay(100);
  intake(200);
  profileController.setTarget("for4Stack");
  delay(2500);
  profileController.waitUntilSettled();

  /*lift(-100, 100);

  lift(-70, 100);
  intake(-1200,200);
  delay(500); //300
  int initialPos = ramp.get_position();
  ramp.move_relative(1700,100);
  waitUntilTarget(ramp, 1700+initialPos);
  initialPos = ramp.get_position();
  ramp.move_relative(600,20);
  delay(500);
  intake(-700,100);
  delay(500);*/
  //new stack code
  lift(-30, 100);
  intake(-1200,200);
  delay(300);
  int initialPos = ramp.get_position();
  ramp.move_relative(1700,150); //100
  waitUntilTarget(ramp, 1700+initialPos);
  initialPos = ramp.get_position();
  ramp.move_relative(600,20);
  delay(300);
  intake(-950,300); //100 spd
  delay(150); //500

  reverseDrive();
  profileController.setTarget("backUpFromStack");
  delay(1000);
  ramp.move_relative(-2200,50);
  intake(-200);
  profileController.waitUntilSettled();



  forwardDrive();
  turnRightNonAsync(353,20,2); //470 (like 180)

  lift(400, 100);

  intake(200);

  profileController.setTarget("for4Tower");
  profileController.waitUntilSettled();



  reverseDrive();
  profileController.setTarget("backUpFromTower");
  delay(50);
  intake(0);
  intake(-400, 200);
  profileController.waitUntilSettled();

  lift(2200, 100);

  delay(1000);

  forwardDrive();
  profileController.setTarget("backUpFromTower");
  profileController.waitUntilSettled();

  intake(-200);


  delay(3000);
  intake(0);
}
