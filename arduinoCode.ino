// Add the Adafruit Motor Sheild Library

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

unsigned long durationSpeed;
unsigned long durationDir;
int Speed, Dir;
int speedPin = 10;
int dirPin = 9;


void setup() {
  Serial.begin(9600);
}

void loop() {

  durationSpeed = pulseIn(speedPin, HIGH);
  durationDir = pulseIn(dirPin, HIGH);
  if (durationSpeed < 1600) {
    Speed  = map(durationSpeed, 1600, 1400, 100, 170);
  }
  else if (durationSpeed > 1700) {
    Speed  = -1 * map(durationSpeed, 1700, 2100, 50, 170);
  }
  else {
    Speed = 0;
  }

  if (durationDir < 1400) {
    Dir  = -1 * map(durationDir, 1400, 1000, 0, 50);
  }
  else if (durationDir > 1600) {
    Dir  = map(durationDir, 1600, 1940, 0, 50 );
  }
  else {
    Dir = 0;
  }

  Serial.print(durationSpeed);
  Serial.print(" . ");
  Serial.print(Speed);
  Serial.print(" . ");
  Serial.print(durationDir);
  Serial.print(" . ");
  Serial.println(Dir);
  logic(Speed, Dir);


}


void moveRobot(AF_DCMotor motorG, int speedVal)
{
  motorG.setSpeed(abs(speedVal));
  if (speedVal <= 0) {
    motorG.run(BACKWARD);
  }
  else {
    motorG.run(FORWARD);
  }
}


void logic(int mySpeed, int myDir)
{

  int speed1 = 255 ;
  int speed2 = 150;

  if (myDir == 0 && mySpeed > 0) {
    moveRobot(motor1, -speed1);
    moveRobot(motor2, -speed1);
    moveRobot(motor3, -speed1);
    moveRobot(motor4, -speed1);
  }
  else if (myDir == 0 && mySpeed < 0) {
    moveRobot(motor1, speed1);
    moveRobot(motor2, speed1);
    moveRobot(motor3, speed1);
    moveRobot(motor4, speed1);
  }

  else if (myDir > 0 && mySpeed == 0 ) {
    moveRobot(motor1, -speed1);
    moveRobot(motor2, -speed1);
    moveRobot(motor3, speed1);
    moveRobot(motor4, speed1);
  }
  else if (myDir < 0 && mySpeed == 0 ) {
    moveRobot(motor1, speed1);
    moveRobot(motor2, speed1);
    moveRobot(motor3, -speed1);
    moveRobot(motor4, -speed1);
  }

  else if (myDir < 0 && mySpeed > 0 ) {
    moveRobot(motor1, -speed1);
    moveRobot(motor2, -speed1);
    moveRobot(motor3, speed1);
    moveRobot(motor4, speed1);
  }
  else if (myDir > 0 && mySpeed > 0 ) {
    moveRobot(motor1, speed2);
    moveRobot(motor2, speed2);
    moveRobot(motor3, -speed1);
    moveRobot(motor4, -speed1);
  }

  else if (myDir < 0 && mySpeed < 0 ) {
    moveRobot(motor1, speed1);
    moveRobot(motor2, speed1);
    moveRobot(motor3, -speed2);
    moveRobot(motor4, -speed2);
  }
  else if (myDir > 0 && mySpeed < 0 ) {
    moveRobot(motor1, -speed2);
    moveRobot(motor2, -speed2);
    moveRobot(motor3, speed1);
    moveRobot(motor4, speed1);
  }

  else if (myDir == 0 && mySpeed == 0) {
    moveRobot(motor1, 0);
    moveRobot(motor2, 0);
    moveRobot(motor3, 0);
    moveRobot(motor4, 0);
  }
}

