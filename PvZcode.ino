#include <Servo.h>

 #define SERVO_PIN_1 9   
 #define SERVO_PIN_2 10   
 #define PIEZO_PIN 3   


const int switch1 = 13; // first circuit 
const int switch2 = 12; // second circuit
const int switch3 = 11; //third circuit
const int switch4 = 7; //fourth circuit 
int switchState = 0; 

Servo servo1;
Servo servo2; 

bool firstCircuitConnected = false; 
bool secondCircuitConnected = false; 
bool thirdCircuitConnected = false;
bool fourthCircuitConnected = false; 

void setup() {

  Serial.begin(9600);

  servo1.attach(SERVO_PIN_1); 
  servo2.attach(SERVO_PIN_2); 

  pinMode(PIEZO_PIN, OUTPUT); 
  pinMode(4, OUTPUT);   
  pinMode(5, OUTPUT);   
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);

  servo1.write(0);
  servo2.write(0);

  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
  //Serial.println(thirdCircuitConnected);
  switchState = digitalRead(switch1);

  // if(switch1 == HIGH){
  //   firstCircuitConnected = !firstCircuitConnected;
  // }

  if(digitalRead(switch1) == HIGH) {
    servo1.write(0);
  } else {
    servo1.write(90);
  }

  Serial.println(switchState);

  
  if (digitalRead(switch2) == HIGH) {
    servo2.write(0);
    secondCircuitConnected = true; 
  }else {
    servo2.write(90);
  }

  if (digitalRead(switch3) == HIGH) {
    thirdCircuitConnected = true;
    digitalWrite(4, HIGH);
  }else {
    digitalWrite(4, LOW);
  }

  if (digitalRead(switch4) == HIGH) {
    fourthCircuitConnected = true;
    digitalWrite(5, HIGH);
  }else {
    digitalWrite(5, LOW);
  }
}

