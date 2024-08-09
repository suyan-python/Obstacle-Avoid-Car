#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);  //TX, RX
String readvoice;
// int RMF = 3; // IN1
// int RMB = 4; //  IN2
// int LMF = 5; // IN3
// int LMB = 6; // IN4

const int trigPin = 9; // ultrasonic sensor
const int echoPin = 8;
long duration;
float pulse_width, distance;

void setup() {

  BT.begin(9600);
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  pulse_width = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = (pulse_width * .0343) / 2;
  Serial.print("Distance: ");
  Serial.print(distance);

  Serial.println(" cm");
  delay(200);

  while (BT.available()) {
    delay(5);
    char c = BT.read();
    readvoice += c;
  }

    if (distance <= 60) {
      digitalWrite(6, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    } 
  else if (readvoice.length() > 0) {

    Serial.println(readvoice);

    if (readvoice == "forward") {
      digitalWrite(6, HIGH);  //in1
      digitalWrite(3, LOW);   //in2
      digitalWrite(4, HIGH);  //in3
      digitalWrite(5, LOW);   //in4
    } else if (readvoice == "back") {
      digitalWrite(6, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    } else if (readvoice == "right") {
      digitalWrite(6, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    } else if (readvoice == "left") {
      digitalWrite(6, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    } else if (readvoice == "stop") {
      digitalWrite(6, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      }
      readvoice = "";
}
     

    // else if (readvoice == "dance") {
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, LOW);
    //   delay(400);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(600);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(500);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, HIGH);
    //   delay(500);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, LOW);
    //   delay(400);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(600);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(500);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, HIGH);
    //   delay(500);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, LOW);
    //   delay(400);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(600);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(500);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, HIGH);
    //   delay(500);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, LOW);
    //   delay(400);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(600);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(500);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, HIGH);
    //   delay(500);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, LOW);
    //   delay(400);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(600);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(500);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, HIGH);
    //   delay(500);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, LOW);
    //   delay(400);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(600);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(500);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, HIGH);
    //   delay(500);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, LOW);
    //   delay(400);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(600);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(500);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, HIGH);
    //   delay(500);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, LOW);
    //   delay(400);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(600);
    //   digitalWrite(RMF, LOW);
    //   digitalWrite(RMB, HIGH);
    //   digitalWrite(LMF, HIGH);
    //   digitalWrite(LMB, LOW);
    //   delay(500);
    //   digitalWrite(RMF, HIGH);
    //   digitalWrite(RMB, LOW);
    //   digitalWrite(LMF, LOW);
    //   digitalWrite(LMB, HIGH);
    //   delay(500);
    // }
  
}