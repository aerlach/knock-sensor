/*
 * Knock Sensor based on the example http://www.arduino.cc/en/Tutorial/Knock.
 */

const int ledPin = 13;
const int knockSensor = A0;
const int threshold = 75;  // threshold value to decide when the detected sound is a knock or not

int sensorReading = 0;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorReading = analogRead(knockSensor);
  if (sensorReading >= threshold) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    Serial.println(sensorReading);
  } else if (sensorReading != 0) {
    Serial.println(sensorReading);
  }
  delay(100);
}
