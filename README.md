# typer-robot
A robo with a hardware similar to 3d printer except that has pen and not filament and same plotter mechanism to help me write low-value tasks like onpaper applications and other documents and save my precious time

(P.s I am using arduino as i have that aldready)

The problem:
I have to spend a lot of time doing low value task like writing handmade applications for school, making a card or maybe writing notes 

The Solution:
I really wanna make a cool plotter that will write for me (very close to a human style)!!


**Working of the Robot**

* The robot will be powered by my ardiuno (I have that) additionaly!
  It will have the parts 3d-printed like base, penholders.etc (In CAD)
  
- Draws on paper through the CNC Motion

#Softwares 
* Inkscape – Vector design creation
* Inkscape G-code Extension – G-code generation
* Universal G-code Sender (UGS) – Command transmission  
  *Allows control like start, pause, resume, and stop
  
- NOTE: UGS does not generate motion logic
UGS does not control motors directly, 
UGS does not require custom firmware


* GRBL Firmware – Motion control execution
* Arduino IDE – Firmware upload and testing

**How it works:**  
Drawing → G-code → Controller → Motors → Pen movement

**Text Handling**
The plotter does not make text directly.
all text is converted into vector outlines before plotting.

**Using Inkscape** – Converts Text to Vector
Converts  text into vector that the robot will follow and move the pen around and make the text on paper 
Removes dependency on fonts during plotting

**Arduino IDE**
Used for:
- Uploading firmware
- Testing calibration and motion routines





**For the reviewer:**
Hello there!! 
You have visited the right place and welcome to my project repo find the README (Which you are reading rn), CAD, Pcb and other concept images.
along with the bill of material,

Edit: I have explain the concept better in readme and made the 



please take your time to review!!
you can also reach out to me
email: Study.hridhaan@gmail.com
slack: @Hridhaan
