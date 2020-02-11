int ledPin = 3;
int counter = 0;

boolean flipFlop = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //debugging code opes the serial port and sets the speed of communication to 9600 baud or bps (bits per sec)
  pinMode(ledPin, OUTPUT);
}

void loop() {

  if(flipFlop == false){
      counter++;
  }else{
    counter--;
  }


  if (counter >= 255) {
      flilpFlop == true;
  }

  if(counter <= 0){
    flipFlop = false;
  }
  Serial.println(counter);
  analogWrite(ledPin, counter);
  delay(50)


}
