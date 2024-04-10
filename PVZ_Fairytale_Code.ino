#include <Servo.h>


#define SERVO_PIN_1 9    
#define SERVO_PIN_2 10  
#define TOUCH_SENSOR_PIN A0 /
#define PIEZO_PIN 3      
#define LED_PIN_1 4      
#define LED_PIN_2 5      
#define RESET_BUTTON_PIN 6 

Servo servo1; 
Servo servo2; 

bool firstCircuitConnected = false; 
bool secondCircuitConnected = false; 
bool touchSensorActivated = false; 


void setup() {
 servo1.attach(SERVO_PIN_1); 
 servo2.attach(SERVO_PIN_2); 
 pinMode(TOUCH_SENSOR_PIN, INPUT); 
 pinMode(PIEZO_PIN, OUTPUT); 
 pinMode(LED_PIN_1, OUTPUT);  
 pinMode(LED_PIN_2, OUTPUT);   
 pinMode(RESET_BUTTON_PIN, INPUT_PULLUP); 
}


void loop() {
 
 if (digitalRead(RESET_BUTTON_PIN) == LOW) {
   
   firstCircuitConnected = false;
   secondCircuitConnected = false;
   touchSensorActivated = false;
   servo1.write(0);
   servo2.write(0);
   digitalWrite(LED_PIN_1, LOW); 
   digitalWrite(LED_PIN_2, LOW); 
   noTone(PIEZO_PIN); 
 }


 
 if (!firstCircuitConnected && analogRead(TOUCH_SENSOR_PIN) > 500) {
   
   servo1.write(90);
   firstCircuitConnected = true; 
 }


 
 if (firstCircuitConnected && !secondCircuitConnected && analogRead(TOUCH_SENSOR_PIN) > 500) {
   
   servo2.write(90);
   secondCircuitConnected = true; 
 }


 
 if (firstCircuitConnected && secondCircuitConnected && !touchSensorActivated && analogRead(TOUCH_SENSOR_PIN) > 500) {
   
   tone(PIEZO_PIN, 1000); 
   delay(1000); 
   noTone(PIEZO_PIN); 
  
   touchSensorActivated = true; 


 
 if (touchSensorActivated && digitalRead(LED_PIN_1) == HIGH) {
   
   digitalWrite(LED_PIN_2, HIGH);
 }
}

