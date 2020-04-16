# Project 2: Penguin Clock - Playful Interfaces

#### Project Info:
The goal of this project is to create a fun analog interface. Think of a toy, gag, carnival games, musical instruments, etc. Try finding items around that house to help you build your projects. As you are building your project, think about a component you would need to 3D print. Using the tools you have, design your part on Onshape.



<br>

#### Video
![beforeHousing](./media/video/testing.gif)

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
- 4segment 7 disit display

<img src="./media/photo/beforeHousing.png" height="500">
<img src="./media/photo/inHousing.png" height="500">

<br>

#### [Code](code/project2/finalCode/timeSerialPDE.ino)
The code features 1 mode where the light dims and brightens according to the light that enters through the clear housing. It should automatically dim the digits on the clock but it does not always work, so there is an LED near the tail to display how the light should change.

<br>

#### [onShape](https://cad.onshape.com/documents/61008bd472f8507714109f0e/w/44c81a49c0ab38aae9e49e19/e/344895309297a4d64a855e7c)
As you can see in the image below, the original housing has little nubs to help holding the motor, and circuit and other pices in place. Since I had to remove the inner housing i designed one of the nubs, specifically the middle ones for the arms, so that they would flap properly when the motor runs. Since the design is roughly the same for each nub, I would just modify the design in the link listed above.

<img src="./media/photo/whiteHousingRemoved.png" height="500">


#### Issues
- To be honest I should have spent more time on the project but corona has really reduced my motivation so I feel I did not give this project my all. I am happy with the result becuase it is still neat but I had a really big vision and I did not allow enough time to see it through
- When I was trying to solder the wires, the solder would not stick for some reason so that was very annoying.
- The original wiring for the toy was VERY flimsy and broke a few times 
- The clock portion flickers. Even after trying a multitude of different brightnesses, configurations with resistors and playing with delays I was not able to reduce it anymore.
- Sometimes the numbers do not show correctly but when tested as individuals, not where digits are passed, they always display perfectly. I believe part of this is due to how difficult it was to display all 4 segments with different numbers at 1 time. 


