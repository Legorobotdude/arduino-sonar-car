//Aditya Bawankule and Aniruth Nandella
//References:
//http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
//https://tronixlabs.com.au/news/tutorial-l298n-dual-motor-controller-module-2a-and-arduino
//https://www.arduino.cc/reference/en/language/functions/math/map/

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

//Ultrasonic Sensor pins
#define trigPin 13
#define echoPin 12

void setup()
{
  Serial.begin (9600);
  //Setup Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  digitalWrite(A5, HIGH);
  digitalWrite(2, HIGH);//Ultrasonic sensor uses this pin for power
}

void loop()
{
  Serial.print(analogRead(A4));
  //Read the Ultrasonic Sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  /*if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
  }*/
  if(distance <= 60)//If wall is too close, turn
  {
    //Serial.print(distance);
    //Serial.println(" cm");
    // turn on motors
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);  
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH); 
  long driveVal = 250;
  analogWrite(enA, driveVal);
  analogWrite(enB, driveVal);
  }
  else {
    //Serial.print(distance);
    //Serial.println(" cm");
    // turn on motors
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);  
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH); 
  //long driveVal = map(distance,0,200,1,255);
  long driveVal;
  if (distance > 200)
    driveVal = 255;
   else
    driveVal = map(distance,0,200,100,255);//Need to change 0-200 values to 1-255 (or higher)
  analogWrite(enA, driveVal-25);
    analogWrite(enB, driveVal);
    
  }
  int sensorValue = analogRead(A0);
  if (sensorValue > 800)
  {
    digitalWrite(A4,LOW);
  }
  else
  {
    digitalWrite(A4,HIGH);
  }
  delay(250);
}
