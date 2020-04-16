# Project 2: Penguin Clock - Playful Interfaces

#### Project Info:
The goal of this project is to create a fun analog interface. Think of a toy, gag, carnival games, musical instruments, etc. Try finding items around that house to help you build your projects. As you are building your project, think about a component you would need to 3D print. Using the tools you have, design your part on Onshape.



<br>

#### Video
![gif]()

<br>

#### Structure
By taking apart my old iPenguin [image of toy](https://thumbs.worthpoint.com/zoom/images2/1/0713/05/cy-penguin-2006-hasbro-mp3-ipod_1_0501ae3b3c665a5925e35c93ff3f1eab.jpg) I worked to preserve the normal motorfunction but add the capability of the clock. I had to remove bits of its inner housing becuase the opaque white belly was not thin enough to clearly show the numbers on the clock. I am using small screws in place of original plastic studs in order to hold parts in place. I preserved the buttons the toy came with but repurposed them as needed.

![tail](media/photo/apartTail.png)
<!-- ![3d1](media/photos/structure3D1.jpg)
![3d2](media/photos/structure3D2.jpg)
![3d3](media/photos/structure3D3.jpg)
![3d4](media/photos/structure3D4.jpg) -->



<br>

#### Circuit (items I added)
- 1 220ohm resistrs
- 1 led (red)
- 1 photoresistor
- 1 10k resistor
- 4segment 7 disit display

![beforePlacedInHousing](media/photos/circuitBirdsEye.jpg)
![beforePlacedInHousing](media/photos/circuitSideView.jpg)
![final steup](media/photos/finalSetup.jpg)


<br>

#### [Code](code/project2/finalCode/timeSerialPDE.ino)
The code features 1 mode where the light dims and brightens according to the light that enters through the clear housing. It should automatically dim the digits on the clock but it does not always work, so there is an LED near the tail to display how the light should change.


<br>

#### Issues
- To be honest I should have spent more time on the project but corona has really reduced my motivation so I feel I did not give this project my all. I am happy with the result becuase it is still neat but I had a really big vision and I did not allow enough time to see it through
- When I was trying to solder the wires, the solder would not stick for some reason so that was very annoying.
- The original wiring for the toy was VERY flimsy and broke a few times 
- The clock portion flickers. Even after trying a multitude of different brightnesses, configurations with resistors and playing with delays I was not able to reduce it anymore.
- Sometimes the numbers do not show correctly but when tested as individuals, not where digits are passed, they always display perfectly. I believe part of this is due to how difficult it was to display all 4 segments with different numbers at 1 time. 


