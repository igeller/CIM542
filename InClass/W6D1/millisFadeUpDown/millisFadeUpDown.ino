int counter = 0;

long pMillis = 0;

int interval = 10;

const int ledPin = 3;
const int ledPin2 = 6;

boolean flipFlop = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
    pinMode(ledPin2, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - pMillis >= interval) {
    pMillis = millis();
    if (flipFlop == false) {
      counter++;
    } else {
      counter--;
    }
    Serial.println(counter);
  }

  analogWrite(ledPin, counter);
    analogWrite(ledPin2, counter);

  

  if (counter >= 255) {
    flipFlop = true;
  }

  if(counter <= 0){
    flipFlop = false;
    delay(2000);
  }

}
