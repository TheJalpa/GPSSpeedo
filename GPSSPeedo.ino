#include <Stepper.h>
#include <SoftwareSerial.h>  
#include <TinyGPS++.h>

// The TinyGPS++ object
TinyGPSPlus gps;

SoftwareSerial ss(12, 3, false);

const int STEPS = 600;  // change this to fit the number of steps per revolution
const int TEST = 100;
int stepCount = 0;

// initialize the stepper library on pins 4 through 7
Stepper myStepper(STEPS, 4, 5, 6, 7);

void setup() {
  // initialize the serial port:
  {  
    myStepper.setSpeed(60);
  Serial.begin(115200);  
  ss.begin(9600);  
  
 }
}

void loop() {

int sensorReading = gps.speed.mph();
Serial.print("Miles Per Hour=");
Serial.print(sensorReading);
int motorSpeed = sensorReading;
Serial.print("Motorspeed=");
Serial.print(motorSpeed);

if (motorSpeed > 5) {
  myStepper.step(-STEPS);
}


}
