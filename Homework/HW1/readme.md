# HW1: SOS Signal

Create an SOS Signal using an LED and the skills learned in class.

### Video
SOS signal working, with a 3 second delay between "rounds"

![video](/Homework/HW1/media/video/sosrun.gif)


### Code
``` arduino
int ledPin = 3;
int time1 = 500;
int time2 = 300;
int time3 = 1500;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

}

void loop() {
  //3 short flashes
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);                       // wait for a second */
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);

  //3 long flashes
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time3);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);                       // wait for a second */
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time3);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time3);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);


  //3 short flashes
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);                       // wait for a second */
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);

  delay(3000);
}
```
