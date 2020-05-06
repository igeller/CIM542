#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>

int RECV_PIN = A5;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
//  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
//  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    byte btn = results.value;
    Serial.println(btn);
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}






//
//
//const int RECV_PIN = A5;
//IRrecv irrecv(RECV_PIN);
//decode_results results;
//
//void setup() {
//  Serial.begin(9600);
//  irrecv.enableIRIn();
//  irrecv.blink13(true);
//}
//
//void loop() {
////  int val = analogRead(RECV_PIN);
////  if(val !=1023){
////    Serial.println(results);
////  }
//  if (irrecv.decode(&results)) {
//    Serial.println(results.value, HEX);
//    irrecv.resume();
//  }
//}
