int ledPin1 = 3;    // LED connected to digital pin 3 and 9
int ledPin2 = 9;
int fadeDel = 1;
int lightDarkDel = 2000;
double fadeChng = 0.075;
double fadeValue = 0;

//need to fix the rapid start of the light coming back on
void setup() {
    pinMode(ledPin1, OUTPUT); 
    digitalWrite(ledPin1, LOW);

    pinMode(ledPin2, OUTPUT); //set pin 2 as OUTPUT
    digitalWrite(ledPin2, LOW);
}

//short leg is flat side, and long side goes in row with cathode

void loop() {
  // fade in from min to max in increments of 5 points:
  
  for (fadeValue; fadeValue <= 255; fadeValue += fadeChng) {
        // wait for fadeDel milliseconds to see the dimming effect
        delay(fadeDel);
        // sets the value (range from 0 to 255):
        analogWrite(ledPin1, fadeValue);

        // sets the value (range from 0 to 255):
        analogWrite(ledPin2, fadeValue);
  }

 //delay(lightDarkDel);

  // fade out from max to min in increments of 0.1 points:
  for (fadeValue; fadeValue >= 0; fadeValue -= fadeChng) {
        // sets the value (range from 0 to 255):
        analogWrite(ledPin1, fadeValue);

        // sets the value (range from 0 to 255):
        analogWrite(ledPin2, fadeValue);
        
        // wait for fadeDel milliseconds to see the dimming effect
        delay(fadeDel);
  }
  
  delay(lightDarkDel);



    
}
