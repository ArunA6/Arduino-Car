#define trigPin 12
#define echoPin 13
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LightPin = 0;
int threshold = 980;
unsigned long previousMillis = 0;
const long interval = 1000;
int ledState = LOW;


int n;
long duration, distance;
String readString;

#include <Servo.h>
Servo myservo1;
Servo myservo2;

void setup() {
  Serial.begin(9600);
  myservo1.attach(8);
  myservo2.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  Serial.println(analogRead(LightPin));

  digitalWrite(trigPin, HIGH);
  _delay_ms(500);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  unsigned long currentMillis = millis();

  if (analogRead(LightPin) > threshold && currentMillis - previousMillis > interval) {
    if (ledState == HIGH) {
      ledState = LOW;
      Serial.println("low");
    } else {
      ledState = HIGH;
      Serial.println("high");
    }
    digitalWrite(LED5 , ledState);

  }
    if (distance < 30) {
      //  digitalWrite(LED1,LOW);
      //  digitalWrite(LED2,LOW);
      //  digitalWrite(LED3,HIGH);
      //  digitalWrite(LED4,HIGH);
      myservo1.write(n);
      myservo2.write(180 - n);
      delay(1000);
      myservo1.write(n);
      myservo2.write(90 - n);
      delay(500);
    }
    else {
      // digitalWrite(LED1, HIGH);
      // digitalWrite(LED2, HIGH);
      // digitalWrite(LED3, LOW);
      // digitalWrite(LED4,LOW);
      myservo1.write(180 - n);
      myservo2.write(n);

    }
  }