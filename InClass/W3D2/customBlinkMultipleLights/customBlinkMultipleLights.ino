int ledPin2 = 2;
int ledPin3 = 3;
int ledPin4 = 4;
int time1 = 200;
int time2 = 50;   
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);


}
//flat side is is ground or cathode
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin2, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);                       // wait for a second */

  digitalWrite(ledPin3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin3, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);                       // wait for a second */

  digitalWrite(ledPin4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time1);                       // wait for a second
  digitalWrite(ledPin4, LOW);    // turn the LED off by making the voltage LOW
  delay(time2);                       // wait for a second */
}
