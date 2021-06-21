#include <xArmServoController.h>
//#include <SoftwareSerial.h>

// To use SoftwareSerial:
// 1. Uncomment include statement above and following block.
// 2. Update xArmServoController with mySerial.
// 3. Change Serial1.begin to mySerial.begin.
/* 
#define rxPin 2
#define txPin 3

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);
*/
xArmServoController myArm = xArmServoController(LeArm, Serial1);

void setup() {
  Serial1.begin(9600);
/*
  // xArm servo positions
   xArmServo home[] = {{1, 500},
                      {2, 500},
                      {3, 500},
                      {4, 500},
                      {5, 500},
                      {6, 500}};
  xArmServo bow[] = {{1, 650},
                     {3, 130},
                     {4, 845},
                     {5, 650}};
                     */
 
  // LeArm servo positions. To use:
  // 1. Comment out above xArmServo definitions above.
  // 2. Change xArmServoController mode to LeArm.
  // 3. Uncomment following block.
  
/*
  xArmServo bow[] = {{1, 2365},
                     {3, 520},
                     {4, 650},
                     {5, 1035}};
                     */
    


 /*
  myArm.setPosition(bow, 4, 3000, true);
  delay(1000);
  myArm.setPosition(home, 6);
  */
  

  // Your setup here.
  defaultPos();
}

void loop() {
  delay(1000);

  // Your code here.
  //1 = CLAW open close
  //2 = CLAW twist
  //3 = top bend
  //4 = mid bend
  //5 = low bend
  //6 = SWIVEL BASE
  bend();
  closeClaw();
  twist();
  openClaw();
  defaultPos();
  //exit(0); //use this to end  
   delay(2000);//just a delay before the sequence repeats              
}

void bend(){
      unsigned int a[]={800,1500,800,800,1900,1500};
      xArmServo bend[] = {{1, a[0]},{2, a[1]},{3,a[2]},{4,a[3]},{5,a[4]}, {6,a[6]}};
      //myArm.setPosition(positionArray, arraySize, seconds to execute, waitForAction);
     myArm.setPosition(bend, 6, 1000, true); 
     delay(1000);
}

void closeClaw(){
      xArmServo closeClaw[] = {{1, 1200}, {4, 800}};
      //myArm.setPosition(positionArray, arraySize, seconds to execute, waitForAction);
     myArm.setPosition(closeClaw, 2, 1000, true); 
     delay(1000);
}


void twist(){

    xArmServo lift[] = {{4, 1000}};                 
    //myArm.setPosition(positionArray, arraySize, seconds to execute, waitForAction);
     myArm.setPosition(lift, 1, 1000, true); 
  
    xArmServo twist[] = {{6, 600}};                 
    //myArm.setPosition(positionArray, arraySize, seconds to execute, waitForAction);
     myArm.setPosition(twist, 1, 1000, true); 
          delay(1000);
  }

  void openClaw(){
      xArmServo lower[] = { {4, 800}};
      myArm.setPosition(lower, 1, 1000, true); 
      xArmServo openClaw[] = {{1, 700}};
      //myArm.setPosition(positionArray, arraySize, seconds to execute, waitForAction);
     myArm.setPosition(openClaw, 1, 1000, true); 
          delay(1000);
}

void defaultPos(){
  xArmServo defaultPos[] = {{1, 1300},
                      {2, 1500},
                      {3, 1500},
                      {4, 1500},
                      {5, 1500},
                      {6, 1500}};
  myArm.setPosition(defaultPos, 6, 4000, true);
  delay(1000);

}
