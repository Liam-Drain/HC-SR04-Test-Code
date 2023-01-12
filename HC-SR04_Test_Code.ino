// ---------------------------------------------------------------- //
// Arduino Ultrasonic Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Edited by Liam Drain for the purpose of University of Nottingham
// Using Arduino IDE 2.0.3
// Using HC-SR04 Module
// Tested on 12 January 2023
// ---------------------------------------------------------------- //

#define echoPin 18 // attach pin D18 ESP to pin Echo of HC-SR04
#define trigPin 5 //attach pin D5 ESP to pin Trig of HC-SR04
int LEDPin = 16;

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(distance);
  digitalWrite(LEDPin,HIGH);
  delay(100);
  digitalWrite(LEDPin,LOW);
}
