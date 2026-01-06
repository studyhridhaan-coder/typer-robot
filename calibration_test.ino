// Simple XY Calibration Test Code
// Purpose: Verify direction, distance, and step calibration
// NOTE: This is NOT full CNC firmware

#define X_STEP_PIN 2
#define X_DIR_PIN 5

#define Y_STEP_PIN 3
#define Y_DIR_PIN 6

#define STEPS_PER_MM 80   // CHANGE THIS DURING CALIBRATION
#define TEST_DISTANCE_MM 50

void stepMotor(int stepPin, int dirPin, bool direction, int steps) {
  digitalWrite(dirPin, direction);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
}

void setup() {
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("XY Calibration Test Started");
}

void loop() {
  int steps = STEPS_PER_MM * TEST_DISTANCE_MM;

  Serial.println("Moving X axis");
  stepMotor(X_STEP_PIN, X_DIR_PIN, HIGH, steps);
  delay(1000);
  stepMotor(X_STEP_PIN, X_DIR_PIN, LOW, steps);
  delay(1000);

  Serial.println("Moving Y axis");
  stepMotor(Y_STEP_PIN, Y_DIR_PIN, HIGH, steps);
  delay(1000);
  stepMotor(Y_STEP_PIN, Y_DIR_PIN, LOW, steps);
  delay(3000);
}

#include <Servo.h>
Servo pen;

void setup() {
  pen.attach(9);
}

void loop() {
  pen.write(30);  // pen up
  delay(1000);
  pen.write(80);  // pen down
  delay(1000);
}
