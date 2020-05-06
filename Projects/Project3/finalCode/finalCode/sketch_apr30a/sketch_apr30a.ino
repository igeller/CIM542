#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>

#include <SevSeg.h>

#include <Time.h>
#include <TimeLib.h>


#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 


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

SevSeg sevseg;
char time [4] = {};


//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0

//Variables
int value;          // Store value from photoresistor (0-1023)
int v;
boolean brightness = true;
boolean nums = true;
long curTime;
boolean noSet = false;
boolean back = false;
boolean fwd = false;
boolean oTime = false;

int curNum = 60;
int oldNum = 0;
long oldTime;

int RECV_PIN = A5;
IRrecv irrecv(RECV_PIN);
decode_results results;

char t[4] = {};

int i = 0;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  byte numDigits = 4;
  byte digitPins[] = {9, 10, 11, 6};
  byte segmentPins[] = {2, 13, 4, 5, 12, 7, 8};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = true; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);
  //  sevseg.setBrightness(90);
  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
  setSyncProvider( requestSync);  //set function to call when sync required

  Serial.println("Waiting for sync message");
  //  //  v = analogRead(pResistor);
}





void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  if (irrecv.decode(&results)) {
    btnClicked(results.value);
    irrecv.resume();

  }

  if (Serial.available()) {
    processSyncMessage();
  }
  if (timeStatus() != timeNotSet) {
    getTimeArr(String(hour()), String(minute()));
    //  setTimeBoard();
  


  float aFloat = atof(time);

  value = analogRead(pResistor);
  if (brightness) {
    sevseg.setBrightness(value);
    if(oTime==false){
           sevseg.setNumber(aFloat);

    }else{
      sevseg.setNumber(curNum);
//      sevseg.refreshDisplay();
      while(curNum !=0){
        Serial.println(curNum);
        if(millis()-oldTime >= 100){
          oldTime = millis();
          oldNum = curNum;
          curNum = oldNum-1;
          sevseg.setNumber(curNum);
                sevseg.refreshDisplay();}

        }
              oTime = false;

      }
      }
    


    
    /*
       if back pressed go back to clock
       if forward pressed set clock
       press okay to validate time
       press 0 or 1 (make function) which will have alarm on or off
       if alarm on then at least 8hrs before it goes off set brigthness to off
       after time reached make sure alarm set to off and clock is back on
    */
   else {
    sevseg.blank();
  }}

  if (timeStatus() == timeSet) {
    analogWrite(ledPin, value); // LED on if synced
  } else {
    analogWrite(ledPin, 0);  // LED off if needs refresh
  }

  sevseg.refreshDisplay(); // Must run repeatedly

}



int handleBtn(String methodName) {

  byte btn = results.value;
  if (methodName == "acceptGoForward") {
    return acceptGoForward();
  } else if (methodName == "sTimer") {
//    return sTimer(i);
  } else {
    btnClicked(btn);
    return 0;
  }
  //    Serial.println(results.value, HEX);
}



boolean acceptGoForward() {
  irrecv.resume(); // Receive the next value

  Serial.println("accgofor: ");
  
}







boolean btnClicked(byte btnNum) {
  switch (btnNum) {
    case 255:
      Serial.println("btn held down");
      break;
    case 93:
      Serial.println("pwr btn");
      if (brightness) {
        brightness = false;
        value = 0;
      } else {
        brightness = true;
      }
      break;
    case 157:
      Serial.println("pwr btn");
      break;
    case 29:
      Serial.println("fun btn");
      if (nums) {
        nums = false;
        curTime = millis();
      } else {
        nums = true;
      }
      break;
    case 221:
      Serial.println("back btn");
      back = true;
      break;
    case 253:
      Serial.println("play btn");
     
//      sevseg.setNumber(60);
      break;
    case 61:
      Serial.println("fwd btn");
      fwd = true;
      break;
    case 207:
      Serial.println("1 btn");
      oTime = true;
      sevseg.setNumber(curNum);
      
      oldTime = millis();
      break;
    case 231:
      Serial.println("2 btn");
      break;
    case 133:
      Serial.println("3 btn");
      break;
    case 239:
      Serial.println("4 btn");
      break;
    case 199:
      Serial.println("5 btn");
      break;
    case 165:
      Serial.println("6 btn");
      break;
    case 189:
      Serial.println("7 btn");
      break;
    case 181:
      Serial.println("8 btn");
      break;
    case 173:
      Serial.println("9 btn");
      break;
  };
  return true;
}







void digitalClockDisplay() {
  //   digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());

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
