# Project 3: Penguin Clock and Timer - Helpful

#### Project Info:
The goal for this project is to make a helpful or not helpful robot. Choose a task in your day to day. Create a device that can help you achieve that task. 

I also used this project to fix project two and dd some functionality



<br>

#### Videos
Time Changing: no more blinking
![timeChanging](./media/final/video/timeChange.gif)

I fixed the wiring and added resistors to help reduce flickering. I also reduced the complexity of code by using a library for the 7 segment display called sevensegment which meant I did not need to assign the letters and numbers based on pins.

Power:
![power](./media/final/video/powerOnOff.gif)
added IR receiver and remote to add on/off functionality.

Timer:
![timer](./media/final/video/timer.gif)
Added the IR receiver and remote and programmed the remote to display a timer and when the timer completes it returns to the clock. I only implemented the code with clicking the "1" button, but if I had more time I would implement it with other numbers to have longer and shorter timers. Currently the code flickers a LOT and I only have a much shorter time set. If you run the program using the serial monitor, you can see that it prints the correct number but I was having trouble displaying it.

Dimming:
![dim](./media/final/video/dimming.gif)
Automatic dimming of display as the light changes which is nice for using the clock at night

<br>

#### Structure
By taking apart my old iPenguin [image of toy](https://thumbs.worthpoint.com/zoom/images2/1/0713/05/cy-penguin-2006-hasbro-mp3-ipod_1_0501ae3b3c665a5925e35c93ff3f1eab.jpg) I worked to preserve the normal motorfunction but add the capability of the clock. I had to remove bits of its inner housing becuase the opaque white belly was not thin enough to clearly show the numbers on the clock. I am using small screws in place of original plastic studs in order to hold parts in place. I preserved the buttons the toy came with but repurposed them as needed.

<img src="./media/photo/apartTail.png" height="500">
<img src="./media/photo/apartcircuitAndMotor.png" height="500">
<img src="./media/photo/apartFeetAndFrontOfBody.png" height="500">
<img src="https://i.ytimg.com/vi/Si2wuA8wWqk/maxresdefault.jpg" width="375">

<br>

#### Circuit (items I added)
- 1 220ohm resistrs
- 1 led (red)
- 1 photoresistor
- 1 10k resistor
- 3 330 ohm resistors
- 4segment 7 disit display
- 1 IR receiver
- 1 remote

<img src="./media/photo/beforeHousing.png" height="500">
<img src="./media/photo/inHousing1.png" height="500">
<img src="./media/photo/inHousing2.png" height="500">

<img src="./media/final/photo/img1.png" height="500">
<img src="./media/final/photo/img2.png" height="500">
<img src="./media/final/photo/img3.png" height="500">


<br>
#### [Code](./finalCode/finalCode/sketch_apr30a/sketch_apr30a.ino)
The code features 1 mode where the light dims and brightens according to the light that enters through the clear housing. It automatically dim the digits on the clock and there is an LED near the tail to display how the light changes. In addition there is are new libraries added sevenseg and IRRemote which helped set digits without having to identify each pin. The libraries added greatly reduced the complexity of the code

<br>

#### [onShape](https://cad.onshape.com/documents/61008bd472f8507714109f0e/w/44c81a49c0ab38aae9e49e19/e/344895309297a4d64a855e7c)
As you can see in the image below, the original housing has little nubs to help holding the motor, and circuit and other pices in place. Since I had to remove the inner housing i designed one of the nubs, specifically the middle ones for the arms, so that they would flap properly when the motor runs. Since the design is roughly the same for each nub, I would just modify the design in the link listed above.

<img src="./media/photo/whiteHousingRemoved.png" height="500">


#### Issues
- As usual I my ideas were much larger than what I was capable of doing. I wanted to have buttons sequence off of one another, but even after placing resume functions everywhere the buttons were not able to trigger in the correct places.
- I also did not give myself enough time to work on the project but I am proud that I managed to get the timer kind of working and returning to the clock while the clock continues keeping time.
- There is a lot of potential with this device from adding sound and figuring out the remote which could be a fun summer project
- To be honest I should have spent more time on the project but corona has really reduced my motivation so I feel I did not give this project my all. I am happy with the result becuase it is still neat but I had a really big vision and I did not allow enough time to see it through
- When I was trying to solder the wires, the solder would not stick for some reason so that was very annoying.
- The original wiring for the toy was VERY flimsy and broke a few times 
- When I was doing my final touches and soldering the final pieces, the wires snapped from the toy's original motor so it no longer worked. Below is what happened when the original wiring of the toy was working (click the link and download so you can hear the sound of the motor moving, becuase it was not connected to the feet and arms so the movement is diffuicult to see.) [video](./media/video/motor.MOV)


