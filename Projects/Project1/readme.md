# Project 1: Light and Emotion

#### Project Info:
The goal of the the project was to combine our knowledge of led programming and the circuit cutter to represent an emotion. The emotion I chose to represent is **lulled** (meaning calm down, quiet).

To represent the emotion of being pulled into sleep i generated a nightlight with a calming on and off sequence.


#### Process
I used a 3d pentagon to create the "shade" for the lights. I cut stars, moons, and clouds into the panels that would appear on the upper half, with the intention that the light would shine to the walls in such shapes.

# help! not showing my images when I try them as png or jpg or heic

1. flat shape with patterns cut out
![photo](/Projects/Project1/media/photos/pentagonflat.HEIC)
![patternZoomed](Projects/Project1/media/photos/pentagonflatzoomed.png)
2. build shape
![pentagonBuilt](Projects/Project1/media/photos/pentagon3D1.jpg)
![pentagonBuilt](Projects/Project1/media/photos/pentagon3D2.HEIC)
![pentagonBuilt](Projects/Project1/media/photos/pentagon3D3.HEIC)
![pentagonBuilt](Projects/Project1/media/photos/pentagon3D4.HEIC)
3. write code for the lights to fade
```ino
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

```

4. wire up the breadboards
# add iimages
5. extend leds and rewire
6. run
<img src="media/videos/nightlight.gif" width="400px">
