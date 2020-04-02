int ledPin = 3;
int analogPin = A0;
int potRead = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  potRead = analogRead(analogPin);
//  potRead = potRead / 4; //this or the map function to get right values
//  int mappedValue = map(potRead, 0, 1023, 0, 255); //this is the better way to do it - led mapped value
//  int mappedValue = map(potRead, 0, 1023, 31, 4978); //this is for tone mapped
  int mappedValue = map(potRead, 300, 960, 31, 4978); //this if for using the photo sensor 
  if(mappedValue < 31){
    mappedValue = 31;
  }

  if(mappedValue > 4978){
    mappedValue = 4978;
  }
  Serial.print("Mapped Value: ");
  Serial.print(mappedValue);

  Serial.print("    potRead: ");
  Serial.println(potRead);
  
//  analogWrite(ledPin, mappedValue); 
  tone(ledPin, mappedValue, 100); //100 is a delay
}
