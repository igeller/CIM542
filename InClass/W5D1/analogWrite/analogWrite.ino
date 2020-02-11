int ledPin = 3;
int counter = 0;

boolean flipFlop = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //debugging code opes the serial port and sets the speed of communication to 9600 baud or bps (bits per sec)
  pinMode(ledPin, OUTPUT);
}

void loop() {
  /* //analog write goes from 0 to 255 where 0 is off
    analogWrite(ledPin, 0);
    delay(500);
    analogWrite(ledPin, 127); //127 is about 1/2 brightness
    delay(500);
    analogWrite(ledPin, 255);//full brightness
    delay(500);*/

  counter++;

  if (counter >= 255) {
    counter = 0;
  }
  Serial.println(counter);
  analogWrite(ledPin, counter);
  delay(50)


}
