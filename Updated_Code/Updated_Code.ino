#include <Stepper.h>

#define rotStep 200

Stepper horzStepper(rotStep, 8, 9, 10, 11);
Stepper vertStepper(rotStep, 7, 6, 5, 4);

int upSensor = A2;
int leftSensor = A3;
int downSensor = A4;
int rightSensor = A5;
int interval = 10;

void setup() {
  // Set the speed of the motor (RPM)
  horzStepper.setSpeed(120);
  vertStepper.setSpeed(120);
  Serial.begin(9600);
}

void loop() {
  int up = analogRead(upSensor);
  int left = analogRead(leftSensor);
  int down = analogRead(downSensor);
  int right = analogRead(rightSensor);

  Serial.print("||  Up: ");
  Serial.print(up);
  Serial.print("||  Left: ");
  Serial.print(left);
  Serial.print("||  Down: ");
  Serial.print(down);
  Serial.print("||  Right: ");
  Serial.println(right);

  if (right > left + interval) {
    horzStepper.step(rotStep);  // Move right
  } 
  else if (left > right + interval) {
    horzStepper.step(-rotStep); // Move left
  }

  // Vertical motor control (Up / Down)
  if (up > down + interval) {
    vertStepper.step(rotStep);  // Move up
  } 
  else if (down > up + interval) {
    vertStepper.step(-rotStep); // Move down
  }

}
