const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;
const int redSensorPin = A0;
const int blueSensorPin = A1;
const int greenSensorPin = A2;
int redValue = 0;
int blueValue = 0;
int greenValue = 0;
int redSensorValue = 0;
int blueSensorValue = 0;
int greenSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(redPin, OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  Serial.print("Raw Sensor Values \tred: ");
  Serial.print(redSensorValue);
  Serial.print("\tgreen: ");
  Serial.print(greenSensorValue);
  Serial.print("\tblue: ");
  Serial.print(blueSensorValue);
  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;
  Serial.print("Mapped sensor values \tred: ");
  Serial.print(redValue);
  Serial.print("\tgreen: ");
  Serial.print(greenValue);
  Serial.print("\tBlue: ");
  Serial.println(blueValue);
  analogWrite(redPin,redValue);
  analogWrite(bluePin,blueValue);
  analogWrite(greenPin,greenValue);

}
