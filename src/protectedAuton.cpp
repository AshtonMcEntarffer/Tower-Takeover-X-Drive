#include "main.h"
#include "global.h"
#include "lcd.h"
#include "autonomous.h"
#include "initialize.h"
#include "protectedAuton.h"

using namespace okapi;



void preProtectedAuton(){
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
      Point{1.9_ft, 0_ft, 0_deg}},//3.8
      "Shift" // Profile name
    );
    profileController.generatePath({
      Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
      Point{1.9_ft, 0_ft, 0_deg}},//2.3
      "Left Shift" // Profile name
    );
    profileController.generatePath({
      Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
      Point{1.5_ft, 0_ft, 0_deg}},
      "Next Cube 1" // Profile name
    );
    profileController.generatePath({
      Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
      Point{2.35_ft, 0_ft, 0_deg}},
      "Next Cube 2" // Profile name
    );
    profileController.generatePath({
      Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
      Point{0.4_ft, 0_ft, 0_deg}},//3.8
      "Smol Shift" // Profile name
    );
    profileController.generatePath({
      Point{0_ft, 0_ft, 0_deg},
      Point{4.0_ft, 0_ft, 0_deg}},
      "Cube Stack"
    );
    profileController.generatePath({
      Point{0_ft,0_ft,0_deg},
      Point{3_ft,0_ft,0_deg}},
      "Goal Zone"
    );
  /*profileController.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{3.5_ft, 0_ft, 0_deg}},
    "Cube Stack"
  );
  profileController.generatePath({
    Point{0_ft,0_ft,0_deg},
    Point{3_ft,0_ft,0_deg}},
    "Goal Zone"
  );*/
}

void protectedAuton(){
  //flip out
  ramp.set_brake_mode(MOTOR_BRAKE_HOLD);
  if(deploy){
    /*lift(1500, 100);
    pros::delay(200);
    intake(-650);
    pros::delay(1200);
    lift(250, 100);*/
    move(500, 60);
    lift(1450, 100);
    pros::delay(200);
    intake(-200);
    //pros::delay(600);
    move(-500, 60);
    pros::delay(300);
    lift(250, 100);
  }

  pros::delay(100);

  intake(650);

//5 pt
forwardDrive();
profileController.setTarget("Left Shift");
delay(2500);
intake(0);
profileController.waitUntilSettled();
turnPID(85 * color, 200);
intake(150);
profileController.setTarget("Next Cube 2");
delay(2300);
intake(0);
profileController.waitUntilSettled();
//turnPID(30 * color, 200);
if(color == 1){
  rightDrive();
}
else{
  leftDrive();
}
profileController.setTarget("Shift");
profileController.waitUntilSettled();
//lift(-50, 100);
intake(-600,90);
delay(150);
int initialPos = ramp.get_position();
ramp.move_relative(2350,150); //100
waitUntilTarget(ramp, 2350+initialPos);
initialPos = ramp.get_position();
ramp.move_relative(700,40);
delay(150);
reverseDrive();
profileController.setTarget("Next Cube 2");
intake(-50);
profileController.waitUntilSettled();
intake(0);

  //pros::delay(50);
  /*if(color == 1){
    leftDrive(); //blue
  }
  else{
    rightDrive();
  }
  profileController.setTarget("Left Shift");
  profileController.waitUntilSettled();
  forwardDrive();
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();
  reverseDrive();
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();*/
  /*if(color == -1){
    leftDrive(); //red
  }
  else{
    rightDrive();
  }
  //profileController.setTarget("Next Cube 1");
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();*/
  /*forwardDrive();
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();
  reverseDrive();
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();*/

  //old auton
  /*forwardDrive();
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();
  reverseDrive();
  if(color == -1){
    leftDrive(); //red
  }
  else{
    rightDrive();
  }
  profileController.setTarget("Next Cube 2");
  profileController.waitUntilSettled();
  forwardDrive();
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();
  //turnPID(145 * color);
  reverseDrive();
  turnRightNonAsync(-340 * color,46, 2);
  forwardDrive();
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();
  lift(-50, 100);
  intake(-900,100);
  delay(300);
  int initialPos = ramp.get_position();
  ramp.move_relative(2350,150); //100
  waitUntilTarget(ramp, 2350+initialPos);
  initialPos = ramp.get_position();
  ramp.move_relative(700,40);
  delay(300);
  reverseDrive();
  profileController.setTarget("Next Cube 2");
  intake(-100);
  profileController.waitUntilSettled();
  intake(0);*/






  /*profileController.setTarget("Left Shift");
  profileController.waitUntilSettled();
  forwardDrive();
  profileController.setTarget("Shift");
  profileController.waitUntilSettled();
  reverseDrive();*/

  /*profileController.setTarget("Smol Shift");
  profileController.waitUntilSettled();*/

  //turnRightNonAsync(-340 * color, 46, 2);


  /*intake(-1200,200);
  delay(300);
  int initialPos = ramp.get_position();
  ramp.move_relative(1700,100);
  waitUntilTarget(ramp, 1700+initialPos);
  initialPos = ramp.get_position();
  ramp.move_relative(600,20);
  delay(300);
  intake(-1000,500);
  delay(200);
  reverseDrive();*/
  //lift(-60, 100);



  //lift(-100, 100);
  /*intake(-800,200);
  delay(300);
  int initialPos = ramp.get_position();
  ramp.move_relative(1700,100);
  waitUntilTarget(ramp, 1700+initialPos);
  initialPos = ramp.get_position();
  ramp.move_relative(600,20);
  delay(500);
  intake(-700,100);
  delay(500);
  reverseDrive();*/




  /*profileController.setTarget("Blue Small First Second");
  //delay(500);
  //intake(0);
  profileController.waitUntilSettled();
  forwardDrive();
  turnRightNonAsync((-340*2+213) * color,40);
  profileController.setTarget("Blue Small Second");
  profileController.waitUntilSettled();

  lift(-100, 100);

  intake(-400,50);
  delay(300);
  int initialPos = ramp.get_position();
  ramp.move_relative(1700,100);
  waitUntilTarget(ramp, 1700+initialPos);
  initialPos = ramp.get_position();
  ramp.move_relative(600,20);
  delay(500);
  intake(-600,100);
  delay(500);
  reverseDrive();
  profileController.setTarget("Blue Small Third");
  profileController.waitUntilSettled();
  intake(0);*/
}
