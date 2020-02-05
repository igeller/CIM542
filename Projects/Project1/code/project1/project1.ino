int ledPin = 3;    // LED connected to digital pin 9
int fadeDel = 1;
int lightDarkDel = 2000;
double fadeChng = 0.075;
double fadeValue = 0;

//need to fix the rapid start of the light coming back on
void setup() {
    pinMode(ledPin, OUTPUT); //set pin 2 as OUTPUT
    digitalWrite(ledPin, LOW);
}

void loop() {
  // fade in from min to max in increments of 5 points:
  
  for (fadeValue; fadeValue <= 255; fadeValue += fadeChng) {
        delay(fadeDel);
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for fadeDel milliseconds to see the dimming effect
  }

 //delay(lightDarkDel);

  // fade out from max to min in increments of 0.1 points:
  for (fadeValue; fadeValue >= 0; fadeValue -= fadeChng) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for fadeDel milliseconds to see the dimming effect
    delay(fadeDel);
  }
  
  delay(lightDarkDel);



    
}
