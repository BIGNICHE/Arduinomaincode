#include <Servo.h>

#include <Stepper.h>


const stepsPerRevolution = 200;

const startingHeight = 150;
const targetHeight = 250;
int currentHeight;

const distanceFromStartToSea = 300;         //These values are temp
const widthOfCompound = 400;                //
const distanceFromSeaToInland = 1000;

const normalTravelVelocity = 700; //This is in millimeters per second

int stepsLowerScoop = 9300; //Positive Integer that represents the displacement of the scoop from the start position to being low enough to pick up the balls
int travelTime;

Servo backServo;
Servo leftServo;
Servo rightServo;
Stepper elevatorStepper(stepsPerRevolution, 6,7,8,9);

#define bumpSwitchForwardPin 22;
#define bumpSwitchBackPin 23;

unsigned long startTime;
int currTime;






void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  backServo.attach(10);
  leftServo.attach(11);
  rightServo.attach(12);
  

  
}

void loop() {

  forward(
 

}

void lowerArm(stepsLowerScoop); {

  for (int currentSteps = 0; currentSteps < stepsLowerScoop
  {
  elevatorStepper.step(-10);
  currentSteps = currentSteps + 10;
  }
  
}

void left(double distance) {
  
}

void forward(double distance) {
  
  startTime = millis(); 
  travelTime = distance / normalTravelVelocity;
  while (millis() < startTime + travelTime) {
    rightServo.write(180);
    leftServo.write(180);
    backServo.write(90);
  }

  stop_();
  
}

void backward(double distance) {

  startTime = millis(); 
  travelTime = distance / normalTravelVelocity;
  while (millis() < startTime + travelTime) {
    rightServo.write(0);
    leftServo.write(0);
    backServo.write(90);
  }

  stop_();
  
}


void stop_(); {
  leftServo.write(90);
  rightServo.write(90);
  backServo.write(90);
}

void bumpForward() {

  stop_();
  
  while (digitalRead(bumpSwitchBackPin) = HIGH) {
    
    leftServo.write(180);
    rightServo.write(180);
    backServo.write(90);
  }

  stop_();
  
}

void bumpBackward() {

  stop_();
  
  while (digitalRead(bumpSwitchBackPin) = HIGH) {
    
    leftServo.write(0);
    rightServo.write(180);
    backServo.write(90);
  }

  stop_();
  
}
