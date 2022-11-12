// declaration of the motors that will be used 
 #define Motor11 7
 #define Motor12 6
 #define Motor21 9
 #define Motor22 8
 #define PWMmotor1 5
 #define PWMmotor2 10

 int valuePWM1=120; // speed motor 1 
 int valuePWM2=150; // speed motor 2
 
void setup() {
  // declaration of the hardware pins that will be used for the motors
  pinMode(Motor11,OUTPUT);
  pinMode(Motor12,OUTPUT);
  pinMode(Motor21,OUTPUT);
  pinMode(Motor22,OUTPUT);
  pinMode(PWMmotor1,OUTPUT);
  pinMode(PWMmotor2,OUTPUT);

pinMode(A0, INPUT); // initialize Right sensor as an inut
pinMode(A1, INPUT); // initialize Left sensor as as input

}

void loop() {
  // definition of the IR sensors to the hardware pins
  int LEFT_SENSOR = analogRead(A0);
  int RIGHT_SENSOR = analogRead(A1);

// the next section of "if else" statements 
//will define the movement of the bot according to the values of the sensors.
  
if(RIGHT_SENSOR<36 && LEFT_SENSOR<36) //FORWARD
{
            digitalWrite(Motor11, HIGH);
            digitalWrite(Motor12, LOW);
            digitalWrite(Motor21, HIGH);
            digitalWrite(Motor22, LOW);
            analogWrite(PWMmotor1, valuePWM1);
            analogWrite(PWMmotor2, valuePWM1);
}

 else if(RIGHT_SENSOR>36 && LEFT_SENSOR<36) //LEFT
 {
            digitalWrite(Motor11, LOW);
            digitalWrite(Motor12, HIGH);
            digitalWrite(Motor21, HIGH);
            digitalWrite(Motor22, LOW);
            analogWrite(PWMmotor1, valuePWM2);
            analogWrite(PWMmotor2, valuePWM2);
}

else if(RIGHT_SENSOR<36 && LEFT_SENSOR>35) //RIGHT
 {
              digitalWrite(Motor11, HIGH);
              digitalWrite(Motor12, LOW);
              digitalWrite(Motor21, LOW);
              digitalWrite(Motor22, HIGH);
              analogWrite(PWMmotor1, valuePWM2);
              analogWrite(PWMmotor2, valuePWM2);
}

else if(RIGHT_SENSOR>35 && LEFT_SENSOR>35) //BACK
{
              digitalWrite(Motor11, LOW);
              digitalWrite(Motor12, LOW);
              digitalWrite(Motor21, LOW);
              digitalWrite(Motor22, LOW);
              delay(10000);
 }
}
