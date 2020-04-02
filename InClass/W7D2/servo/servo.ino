int analogPin = A0;


void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potRead = analogRead(analogPin);
  Serial.println(potRead);

}
