Pin Mapping 
ULN2003 
X Motor: pins 2, 3, 4, 5
Y Motor: pins 6, 7, 8, 9
Servo: pin 10
  
#include <Sero.h>

/* =========================
   STEPPER MOTOR SETUP
========================= */

// 28BYJ-48 step sequence (half-step)
int stepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

// X-axis pins
int xPins[4] = {2, 3, 4, 5};
// Y-axis pins
int yPins[4] = {6, 7, 8, 9};

// Step delay (speed control)
int stepDelay = 2;

/* =========================
   SERVO SETUP
========================= */

Servo penServo;
int penUpAngle = 60;
int penDownAngle = 20;

/* =========================
   FUNCTIONS
========================= */

void stepMotor(int pins[], int steps, bool direction) {
  for (int i = 0; i < steps; i++) {
    for (int step = 0; step < 8; step++) {
      int index = direction ? step : (7 - step);
      for (int pin = 0; pin < 4; pin++) {
        digitalWrite(pins[pin], stepSequence[index][pin]);
      }
      delay(stepDelay);
    }
  }
}

void moveX(int steps, bool dir) {
  stepMotor(xPins, steps, dir);
}

void moveY(int steps, bool dir) {
  stepMotor(yPins, steps, dir);
}

void penUp() {
  penServo.write(penUpAngle);
  delay(300);
}

void penDown() {
  penServo.write(penDownAngle);
  delay(300);
}

/* =========================
   SETUP
========================= */

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(xPins[i], OUTPUT);
    pinMode(yPins[i], OUTPUT);
  }

  penServo.attach(10);
  penUp();
}

/* =========================
   MAIN LOOP (DEMO)
========================= */

void loop() {
  penDown();

  // Draw a square
  moveX(300, true);
  moveY(300, true);
  moveX(300, false);
  moveY(300, false);

  penUp();

  delay(5000); // wait before repeating
}
