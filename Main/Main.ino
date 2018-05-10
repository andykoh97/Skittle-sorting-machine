#include <Servo.h>
#include <Wire.h>
#include <Stepper.h> /* Libraries used */
#include "Adafruit_TCS34725.h" 
const int stepsPerRevolution = 200 ; /* Total steps in the stepper motor */
Servo myservoR;
Servo myservoO; 
Servo myservoY;
Servo myservoG; 
Servo myservoP; /* Servo motor of different container */
/* R = Red; O = Orange; Y = Yellow; G = Green; P = Purple */
Stepper upperStepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper lowerStepper(stepsPerRevolution, 2, 3, 4, 5); /* set the output pins for two stepper motor */

/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600); /* initalise the Arduino broad and bluetooth module*/
  
  // put your setup code here, to run once:
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
  myservoR.attach(40);
  myservoO.attach(41);
  myservoY.attach(42);
  myservoG.attach(43);
  myservoP.attach(44); /* output pins of the corresponding container */

  upperStepper.setSpeed(10);
  lowerStepper.setSpeed(50);/* Control the speed of the stepper */
  
}

void loop() {
  char ofswitch;
  if (Serial1.available()>0){
    ofswitch = Serial1.read(); 
    }
  Serial.print(ofswitch);
  while (ofswitch == 'S'){
    Upperstepper();
    if (Serial1.available()>0){
    ofswitch = Serial1.read(); 
    if (ofswitch == 'D'){
      break;
      }
    }
    }
  while (ofswitch == 'D' || ofswitch == 'Y' || ofswitch == 'R' || ofswitch == 'G' || ofswitch == 'P' || ofswitch == 'O'){
    if (Serial1.available()>0){
    ofswitch = Serial1.read(); 
    char val = ofswitch;
    switch (ofswitch){ /* receive the signal from the app and move the corrsponding servo motor */
    case 'R':
      Serial.print(val);
      Serial.print('\t');
      myservoR.write(180);
      delay(500); 
      myservoR.write(0);
      delay(500); 
      break; 
      
      case 'O':
      Serial.print(val);
      Serial.print('\t');
      myservoO.write(180);

      delay(500); 
      myservoO.write(0);
      delay(500); 
      break;
       
      case 'Y':
      Serial.print(val);
      Serial.print('\t');
      myservoY.write(180);
      delay(500); 
      myservoY.write(0);
      delay(500); 
      break;
      
      case 'G':
      Serial.print(val);
      Serial.print('\t');
      myservoG.write(180);
      delay(500); 
      myservoG.write(0);
      delay(500); 
      break;
      
      case 'P':
      Serial.print(val);
      Serial.print('\t');
      myservoP.write(180);
      delay(500); 
      myservoP.write(0);
      delay(500); 
      break;
      default:
      break;
}
    if (ofswitch == 'S'){
      break;
      }
    }
  }
}
