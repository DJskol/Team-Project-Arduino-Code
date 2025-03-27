#include <Stepper.h>

// Number of steps per revolution of the motor
int rotStep = 60;  // Standard for 28BYJ-48 stepper motors

// Define the stepper motors
Stepper HorzStepper(rotStep, 2, 3, 4, 5); // Pins for horizontal motor
Stepper VertStepper(rotStep, 6, 7, 8, 9); // Pins for vertical motor

int stepSpeed = 10;  // Speed of the stepper motors (RPM)

void setup() {
  Serial.begin(9600);

  // Set motor speeds
  HorzStepper.setSpeed(stepSpeed);
  VertStepper.setSpeed(stepSpeed);
}

void loop() {
  // Read sensor values for direction control
  int pH_r = analogRead(A0);  // Right sensor
  int pH_u = analogRead(A1);  // Up sensor
  int pH_d = analogRead(A2);  // Down sensor
  int pH_l = analogRead(A3);  // Left sensor

  // Print sensor values for debugging
  Serial.print("Up: ");
  Serial.print(pH_u);
  Serial.print(" Left: ");
  Serial.print(pH_l);
  Serial.print(" Down: ");
  Serial.print(pH_d);
  Serial.print(" Right: ");
  Serial.println(pH_r);

  // Horizontal motor control (Left / Right)
  if (pH_r > pH_l + 10) {
    HorzStepper.step(rotStep);  // Move right
  } 
  else if (pH_l > pH_r + 10) {
    HorzStepper.step(-rotStep); // Move left
  }

  // Vertical motor control (Up / Down)
  if (pH_u > pH_d + 10) {
    VertStepper.step(rotStep);  // Move up
  } 
  else if (pH_d > pH_u + 10) {
    VertStepper.step(-rotStep); // Move down
  }
}
