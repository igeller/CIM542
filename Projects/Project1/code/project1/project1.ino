int ledPin1 = 3;    // LED connected to digital pin 3 and 9
int ledPin2 = 6;
int ledPin3 = 9;
int pushButton = 2;

boolean buttonPushed = false;
int mode = 0;

long pMillis = 0;
int interval = 10;
boolean flipFlop = false;
double counter = 0;
double fadeChngDwn = 1;
double fadeChngUp = 0.5;


//short leg is flat side, and long side goes in row with resistor


void setup() {

  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT); //set pin 2 as OUTPUT
  pinMode(ledPin3, OUTPUT); //set pin 3 as OUTPUT
}


void loop() {

  //button stuff so we need a counter
  int buttonState = digitalRead(pushButton);
  if (buttonState == 1) { // light on
    buttonPushed = true;
  }

  if (buttonState == 0 && buttonPushed == true) { //light off
    buttonPushed = false;
    mode++;
  }

  if (mode == 0) { //light off
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  } else if (mode == 1) { // light on
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    counter = 0;
  } else if (mode == 2) { //pattern on
    Serial.println(mode);
    millisPat();
  } else {
    mode = 0;
  }
}

void millisPat() {
  if (millis() - pMillis >= interval) {
    pMillis = millis();
    if (flipFlop == false) {
      counter += fadeChngUp;
    } else {
      counter -= fadeChngDwn;
    }
    Serial.println(counter);
  }


  analogWrite(ledPin1, counter);
  analogWrite(ledPin2, counter);
  analogWrite(ledPin3, counter);


  if (counter >= 255) {
    flipFlop = true;
  }

  if (counter <= 0) {
    flipFlop = false;
    delay(2000);
  }
}
