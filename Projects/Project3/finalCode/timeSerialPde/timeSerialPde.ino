#include "SevSeg.h"
#include "Time.h";
#include "TimeLib.h";
#include "SevSeg.h";

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

SevSeg sevseg; //Instantiate a seven segment controller object

int ledPin = 3;

int pinA = 2;
int pinB = 13;
int pinC = 4;
int pinD = 5;
int pinE = 12;
int pinF = 7;
int pinG = 8;

int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 6;

const int pResistor = A0;
int value;
char time [4] = {};

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {9, 10, 11, 6};
  byte segmentPins[] = {2, 13, 4, 5, 12, 7, 8};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
    pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)

}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  
  if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }

  sevseg.refreshDisplay(); // Must run repeatedly
}

/// END ///




//#include <SevSeg.h>
//
//#include "Time.h";
//#include "TimeLib.h";
//#include "SevSeg.h";
//
///*
//   TimeSerial.pde
//   example code illustrating Time library set through serial port messages.
//
//   Messages consist of the letter T followed by ten digit time (as seconds since Jan 1 1970)
//   you can send the text on the next line using Serial Monitor to set the clock to noon Jan 1 2013
//  T1357041600
//
//   A Processing example sketch to automatically send the messages is included in the download
//   On Linux, you can use "date +T%s\n > /dev/ttyACM0" (UTC time zone)
//*/
//
//
//#define TIME_HEADER  "T"   // Header tag for serial time sync message
//#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 
//
//int ledPin = 3;
//
//int pinA = 2;
//int pinB = 13;
//int pinC = 4;
//int pinD = 5;
//int pinE = 12;
//int pinF = 7;
//int pinG = 8;
//
//int D1 = 9;
//int D2 = 10;
//int D3 = 11;
//int D4 = 6;

//int D1 = A1;
//int D2 = A2;
//int D3 = A3;
//int D4 = A4;
//
//SevSeg sevseg;
//char time [4] = {};
//
//
////Constants
//const int pResistor = A0; // Photoresistor at Arduino analog pin A0
//
////Variables
//int value;          // Store value from photoresistor (0-1023)
//int v;
//
//byte numDigits = 4;
//  byte digitPins [] = {9, 10, 11, 6};
//  byte segmentPins[] = {2, 4, 5, 7, 8, 12, 13};
//
//  
//  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
//  byte hardwareConfig = COMMON_ANODE; // See README.md for options
//  bool updateWithDelays = false; // Default 'false' is Recommended
//  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
//  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]
//
//
//
//
//void setup()  {
//  Serial.begin(9600);
//  //  while (!Serial) ; // Needed for Leonardo only
//  pinMode(ledPin, OUTPUT);
//
//  pinMode(pinA, OUTPUT);
//  pinMode(pinB, OUTPUT);
//  pinMode(pinC, OUTPUT);
//  pinMode(pinD, OUTPUT);
//  pinMode(pinE, OUTPUT);
//  pinMode(pinF, OUTPUT);
//  pinMode(pinG, OUTPUT);
//
//  pinMode(D1, OUTPUT);
//  pinMode(D2, OUTPUT);
//  pinMode(D3, OUTPUT);
//  pinMode(D4, OUTPUT);
//
//  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
//
//  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
//  updateWithDelays, leadingZeros, disableDecPoint);
////  setSyncProvider( requestSync);  //set function to call when sync required
//  Serial.println("Waiting for sync message");
//  //  v = analogRead(pResistor);
//
// 
//
//}
//
//void loop() {
//    value =analogRead(pResistor);
////    Serial.println("testing");
//   Serial.println(value);
//  if (Serial.available()) {
//    processSyncMessage();
//  }
//  if (timeStatus() != timeNotSet) {
////     getTimeArr(String(hour()), String(minute()));
////  setTimeBoard();
//  sevseg.setSegments(3144); // Displays '3.141'
//
//  sevseg.setBrightness(value);
//
//
//  }
//  if (timeStatus() == timeSet) {
//    analogWrite(ledPin, value); // LED on if synced
//  } else {
//    analogWrite(ledPin, value)
//    ;  // LED off if needs refresh
//  }
//
//
//
//
//
//
//}

void digitalClockDisplay() {
//   digital clock display of the time
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
//  Serial.println();

 
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
    time[0] = hr.charAt(0);
    time[1] = hr.charAt(1);
  } else {
    time[0] = '0';
    time[1] = hr.charAt(0);
  }

  if (min.length() == 2) {
    time[2] = min.charAt(0);
    time[3] = min.charAt(1);
  } else {
    time[2] = '0';
    time[3] = min.charAt(0);
  }

}

void setTimeBoard() {
  setD1(time[0], 1);//time[0], 1);
  setD1(time[1], 2);
  setD1(time[2], 3);
  setD1(time[3], 4);
}

void setSeg(int seg) {
//  Serial.println("test");
//  Serial.println(value);
  delay(3);
  if (seg == 1) {       
    analogWrite(D1, value);
    analogWrite(D2, 255);
    analogWrite(D3, 255);
    analogWrite(D4, 255);
  }
  else if (seg == 2) {

    analogWrite(D1, 255);
    analogWrite(D2, value);    
    analogWrite(D3, 255);
    analogWrite(D4, 255);
  }
 else if (seg == 3) {

    analogWrite(D1, 255);
    analogWrite(D2, 255);
    analogWrite(D3, value);
    analogWrite(D4, 255);

  }
  else if (seg == 4) {
    analogWrite(D1, 255);
    analogWrite(D2, 255);
    analogWrite(D3, 255);
    analogWrite(D4, value);
  }
}

void setD1(char t, int seg) {
  switch (t) {
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
      digitalWrite(pinC, LOW);
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
