#include "Time.h"
#include "TimeLib.h"

/*
   TimeSerial.pde
   example code illustrating Time library set through serial port messages.

   Messages consist of the letter T followed by ten digit time (as seconds since Jan 1 1970)
   you can send the text on the next line using Serial Monitor to set the clock to noon Jan 1 2013
  T1357041600

   A Processing example sketch to automatically send the messages is included in the download
   On Linux, you can use "date +T%s\n > /dev/ttyACM0" (UTC time zone)
*/


#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

int ledPin = 13;

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 12;
int pinF = 7;
int pinG = 8;

int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 6;

String time [4] = {};


//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0

//Variables
int value;          // Store value from photoresistor (0-1023)
int v;




void setup()  {
  Serial.begin(9600);
  //  while (!Serial) ; // Needed for Leonardo only
  pinMode(ledPin, OUTPUT);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)


  setSyncProvider( requestSync);  //set function to call when sync required
  Serial.println("Waiting for sync message");
  //  v = analogRead(pResistor);
}

void loop() {


  //  analogWrite(ledPin, value);
  //  if(v >= value+10 || v <= value-10){
  //    Serial.println("big change");
  //  }

  if (Serial.available()) {
    processSyncMessage();
  }
  if (timeStatus() != timeNotSet) {
    digitalClockDisplay();
  }
  if (timeStatus() == timeSet) {
    digitalWrite(13, HIGH); // LED on if synced
  } else {
    digitalWrite(13, LOW);  // LED off if needs refresh
  }






}

void digitalClockDisplay() {
//   digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();

  getTimeArr(String(hour()), String(minute()));
  setTimeBoard();
}

void printDigits(int digits) {
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}


void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if (Serial.find(TIME_HEADER)) {
    pctime = Serial.parseInt();
    if ( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
      setTime(pctime); // Sync Arduino clock to the time received on the serial port
    }
  }
}

time_t requestSync()
{
  Serial.write(TIME_REQUEST);
  return 0; // the time will be sent later in response to serial mesg
}


void getTimeArr(String hr, String min) {
  if (hr.length() == 2) {
    time[0] = int(hr.charAt(0));
    time[1] = hr.charAt(1);
  } else {
    time[0] = "0";
    time[1] = min.charAt(0);
  }

  if (min.length() == 2) {
    time[2] = min.charAt(0);
    time[3] = min.charAt(1);
  } else {
    time[2] = "0";
    time[3] = min.charAt(0);
  }

}

void setTimeBoard() {
  setD1("2", 1);//time[0], 1);
  setD1(time[1], 2);
  setD1(time[2], 3);
  setD1(time[3], 4);
}

void setSeg(int seg) {
  delay(1);
  if (seg == 1) {
    analogWrite(D1, 100);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  }
  else if (seg == 2) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  }
 else if (seg == 3) {
    analogWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
  }
  else if (seg == 4) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    analogWrite(D4, 150);
  }
}

void setD1(String t, int seg) {
  switch (t.charAt(0)) {
    case '0':
      setSeg(seg);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      return;
    case '1':
      setSeg(seg);
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      return;
    case '2':
      setSeg(seg);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, 0);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      return;
    case '3':
      setSeg(seg);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      return;
    case '4':
      setSeg(seg);
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      return;
    case '5':
      setSeg(seg);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      return;
    case '6':
      setSeg(seg);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      return;
    case '7':
      setSeg(seg);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      return;
    case '8':
      setSeg(seg);
      Serial.println("8?!?!?!?");
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      return;
    case '9':
      setSeg(seg);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      return;
    default:
      return;
  }

  return;
}
