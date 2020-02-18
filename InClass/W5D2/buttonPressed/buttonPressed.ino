
int pushButton = 2;// digital pin 2 has a pushbutton attached to it. Give it a name:
int ledPin = 3;

boolean pressed = false;
int counter = 0;





// the setup routine runs once when you press reset:
void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.print("ButtonState: ");
  Serial.print(buttonState);
  
  delay(1);        // delay in between reads for stability
  // digitalWrite(ledPin, buttonState); //high = 1 and low = 0 so since button state is 1 or 0 we replace

  if (buttonState == HIGH) {
    pressed = true;
  }

  if (buttonState == LOW && pressed == true) {
    //reverse state
    pressed = false;
    Serial.print("Pressed");
    counter++;
  }
  Serial.print("counter");
  Serial.print(counter);
  Serial.println();



  if (counter == 0) {
    digitalWrite(ledPin, LOW);
  } else if (counter == 1) {
    digitalWrite(ledPin, HIGH);
  } else if (counter == 2) {
    //sequence
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  } else {
    //the else reads if not 0, 1, or 2 then run code below
    counter = 0;
  }



}
