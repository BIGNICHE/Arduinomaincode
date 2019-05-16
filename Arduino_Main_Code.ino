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
int switchState;

bool bumpForwardState = false;
bool bumpBackwardState = false;

Servo backServo;
Servo leftServo;
Servo rightServo;
Servo scoopArticulateServo;
Stepper elevatorStepper(stepsPerRevolution, 31,32,33,34);

int bumpSwitchForwardPin = 2;
int bumpSwitchBackPin = 3;

unsigned long startTime;
int currTime;






void setup() {
  pinMode(43, OUTPUT);
  digitalWrite(43, HIGH);       // This block is the enables for the motor drivers
  
  backServo.attach(28);
  leftServo.attach(29);
  rightServo.attach(30);
  scoopArticulateServo.attach(31);
  elevatorStepper.setSpeed(60);
  
  pinMode(bumpSwitchForwardPin, INPUT_PULLUP);
  pinMode(bumpSwitchBackPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bumpSwitchForwardPin), bumpForward, FALLING);
  attachInterrupt(digitalPinToInterrupt(bumpSwitchBackPin), bumpBackward, FALLING);
  Serial.begin(9600);
  bumpForwardState = false;
  bumpBackwardState = false;

  interrupts();

  bumpForwardState = 0;
  bumpBackwardState = 0;
  
}

void loop() {


  delay(4000);


  scoopArticulateServo.write(50);


  forward(4000);

  left(15000);



  backward(500);

  rotateClockwise(500);

  

  





  
}

void lowerArm(int finalSteps) {

  elevatorStepper.step(-finalSteps);
  
}

void raiseArm(int finalSteps) {
  elevatorStepper.step(finalSteps);
}

void rotateClockwise(int distance) {
  int time_current = millis();
  do {
  backServo.write(180);
  leftServo.write(0);
  rightServo.write(0);
  } while (millis() < time_current + distance);
  
  stopChassis();
  
}


void left(double distance) {
  int time_current = millis();
  do {
  backServo.write(180);
  leftServo.write(70);
  rightServo.write(70);
  } while (millis() < time_current + distance);
  
  stopChassis();
  
}

void right(double distance) {

  int time_current = millis();
  do {
  backServo.write(0);
  leftServo.write(100);
  rightServo.write(100);
  } while (millis() < time_current + distance);
  stopChassis();
  
}

void forward(double distance) {
  
  int time_current = millis();
  do {
  rightServo.write(0);
  leftServo.write(180);
  backServo.write(90);
  } while (millis() < time_current + distance);
  stopChassis();
  
  
}

void backward(double distance) {

  int time_current = millis();
  do {
  rightServo.write(180);
  leftServo.write(0);
  backServo.write(90);
  } while (millis() < time_current + distance);
  stopChassis();
  
}


void stopChassis() {
  leftServo.write(90);
  rightServo.write(90);
  backServo.write(90);
}

void bumpForward() {
  

  bumpForwardState = 1;
}

void bumpBackward() {


  
//  do{
//    switchState = digitalRead(bumpSwitchBackPin);
//    leftServo.write(180);
//    rightServo.write(0);
//    backServo.write(90);
//  } while (switchState = 0);
  bumpBackwardState = 1;

  
}
