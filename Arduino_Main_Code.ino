#include <Servo.h>

#include <Stepper.h>


int stepsPerRevolution = 200;

int startingHeight = 150;
int targetHeight = 250;
int currentHeight;

int distanceFromStartToSea = 300;         //These values are temp
int widthOfCompound = 400;                //
int distanceFromSeaToInland = 1000;

int normalTravelVelocity = 700; //This is in millimeters per second

int stepsLowerScoop = 9300; //Positive Integer that represents the displacement of the scoop from the start position to being low enough to pick up the balls
int travelTime;

Servo backServo;
Servo leftServo;
Servo rightServo;
Stepper elevatorStepper(stepsPerRevolution, 31,32,33,34);

int bumpSwitchForwardPin = 2;
int bumpSwitchBackPin = 3;

unsigned long startTime;
int currTime;






void setup() {
//  pinMode(4, OUTPUT);
//  pinMode(5, OUTPUT);
//  pinMode(6, OUTPUT);
//  pinMode(7, OUTPUT);
//  pinMode(8, OUTPUT);
//  pinMode(9, OUTPUT);
//  pinMode(10, OUTPUT);
//  pinMode(11, OUTPUT);
//  pinMode(12, OUTPUT);
  pinMode(30, OUTPUT);
  digitalWrite(30, HIGH);
  pinMode(43, OUTPUT);
  digitalWrite(43, HIGH);       // This block is the enables for the motor drivers
  
  backServo.attach(46);
  leftServo.attach(44);
  rightServo.attach(45);
  elevatorStepper.setSpeed(150);
  
  pinMode(bumpSwitchForwardPin, INPUT_PULLUP);
  pinMode(bumpSwitchBackPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bumpSwitchForwardPin), bumpForward, RISING);
  attachInterrupt(digitalPinToInterrupt(bumpSwitchBackPin), bumpBackward, RISING);
  
}

void loop() {

  //lowerArm(stepsLowerScoop);

  //break();

  left(300);
  delay(1000);
  right(300);
  delay(1000);

}

void lowerArm(int finalSteps) {


  // This block checks if either bump switch is triggered
//  for (int currentSteps = 0;currentSteps < finalSteps; currentSteps = currentSteps + 200) {
//    while(digitalRead(forwardBumpSwitch) = HIGH) {
//      leftServo.write(0);
//      rightServo.write(0);
//      backServo.write(90);
//    }
//    while(digitalRead(backBumpSwitch) = HIGH) {
//      leftServo.write(180);
//      rightServo.write(180);
//      backServo.write(90);
//    }
//
//    
//    
//    stopChassis();
//    
//    myStepper.step(-200);



//Do it with interrupts instead

  elevatorStepper.step(-finalSteps);
  
}

void left(double distance) {

  backServo.write(180);
  leftServo.write(60);
  rightServo.write(60);
  delay(distance);
  stopChassis();
  
}

void right(double distance) {

  backServo.write(0);
  leftServo.write(110);
  rightServo.write(110);
  delay(distance);
  stopChassis();
  
}

void forward(double distance) {
  
//  startTime = millis(); 
//  travelTime = distance / normalTravelVelocity;
//  while (millis() < startTime + travelTime) {
//    rightServo.write(180);
//    leftServo.write(180);
//    backServo.write(90);
//  }

    rightServo.write(0);
    leftServo.write(180);
    backServo.write(90);
    delay(distance);

  stopChassis();
  
}

void backward(double distance) {

//  startTime = millis(); 
//  travelTime = distance / normalTravelVelocity;
//  while (millis() < startTime + travelTime) {
//    rightServo.write(0);
//    leftServo.write(0);
//    backServo.write(90);
//  }

    rightServo.write(180);
    leftServo.write(0);
    backServo.write(90);
    delay(distance);
    
  stopChassis();
  
}


void stopChassis() {
  leftServo.write(90);
  rightServo.write(90);
  backServo.write(90);
}

void bumpForward() {

  stopChassis();
  
//  while (digitalRead(bumpSwitchBackPin) = HIGH) {
//    
//    leftServo.write(180);
//    rightServo.write(180);
//    backServo.write(90);
//  }

  stopChassis();
  
}

void bumpBackward() {

  stopChassis();
  
//  while (digitalRead(bumpSwitchBackPin) = HIGH) {
//    
//    leftServo.write(0);
//    rightServo.write(180);
//    backServo.write(90);
//  }

  stopChassis();
  
}
