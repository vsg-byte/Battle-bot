//CH2 Left Motor 
//CH3 Right Motor
//CH6 RelayModule

//FrontWeapon
#define relayPin 5

//RightWheel
#define MOTOR1INA 7
#define MOTOR1INB 8
#define MOTOR1PWM 6
 
//LeftWheel
#define MOTOR2INA 9
#define MOTOR2INB 10
#define MOTOR2PWM 11

int rpins[]={2,3,4};
int rvals[]={0,0,0,0,0,0};

void setup() {
    
    Serial.begin(115200);
for(int i=0;i<=3;i++)
{
  pinMode(rpins[i],INPUT);
}
  
pinMode(relayPin, OUTPUT);
//RightWheel
pinMode(MOTOR1INA,OUTPUT);
pinMode(MOTOR1INB,OUTPUT);
pinMode(MOTOR1PWM,OUTPUT);
//LeftWheel
pinMode(MOTOR2INA,OUTPUT);
pinMode(MOTOR2INB,OUTPUT);
pinMode(MOTOR2PWM,OUTPUT);
  


}

void loop() {
  // put your main code here, to run repeatedly:
   long stime=micros();
 for(int i=0;i<=3;i++){
  
  rvals[i]=pulseIn(rpins[i],HIGH);  
  Serial.print("CH");
  Serial.print(i);
  Serial.print(":");
  Serial.print(rvals[i]);
  Serial.print('\t');
  
}
  Serial.println("");
int frontMotor=rvals[2];
int rightMotor=rvals[0];//CH1 in monitor
int leftMotor=rvals[1];//CH0 in monitor
int rightmotorFront;
int rightmotorBack;
int leftmotorFront;
int leftmotorBack;


if(frontMotor>=1800){

digitalWrite(relayPin,LOW);
Serial.println("RelayOn");
  
}
else{
digitalWrite(relayPin,HIGH);
}



if(rightMotor>=1480&&rightMotor<=1500){
  Serial.println("rightWheelStop");

}
else if(rightMotor>1500&&rightMotor<=1810){

rightmotorFront=((1810-rightMotor)/360)*255;
Serial.println(rightmotorFront);
Serial.println("GoingFront");
digitalWrite(MOTOR1INA,HIGH);
digitalWrite(MOTOR1INB,LOW);
analogWrite(MOTOR1PWM,rightmotorFront);


  
}
else if(rightMotor<1480&&rightMotor>=1155){

rightmotorBack=((1500-rightMotor)/300)*255;
Serial.println(rightmotorBack);
Serial.println("GoingBack");;
digitalWrite(MOTOR1INA,LOW);
digitalWrite(MOTOR1INB,HIGH);
analogWrite(MOTOR1PWM,rightmotorBack);
}
else if(leftMotor>1480&&leftMotor<=1500){

Serial.println("Stop");

  
}
else if (leftMotor>1500&&leftMotor<=1860)
{
leftmotorFront=((1860-leftMotor)/360)*255;
Serial.println(leftmotorFront);
digitalWrite(MOTOR2INA,HIGH);
digitalWrite(MOTOR2INB,LOW);
analogWrite(MOTOR2PWM,leftmotorFront);
  
}
else if (leftMotor<1480&&leftMotor<=1200)
{
leftmotorBack=((1480-leftMotor)/300)*255;

Serial.println(leftmotorFront);
digitalWrite(MOTOR2INA,LOW);
digitalWrite(MOTOR2INB,HIGH);
analogWrite(MOTOR2PWM,leftmotorBack);
  
}

}
