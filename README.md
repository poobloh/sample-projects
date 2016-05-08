# sample-projects
Code from previous classes and personal projects

### ASM Project
Language: x86 Assembly
* Complex string manipulation in x86 Assembler language

### Data Structure Projects
Language: C++
* BST: Binary Search Tree creation, implementation, and testing
* Employee: Polymorphism creation, implementation, and testing

### Digital Systems Projects
Language: C
* Homework2: Converting data from little endian to big endian to prepare for host-to-network and network-to-host interaction. Flipping a number in binary. More information [here.](https://github.com/poobloh/sample-projects/blob/master/Digital%20Systems%20Projects/Homework2.pdf)
* XOR flipper: XOR function

### Embedded Systems Final Project
Language: C
* Using [STM32F4 Discovery Board microcontroller board], final project consisted of demonstrating all embedded systems knowledge
* Project summary [here.](https://github.com/poobloh/sample-projects/blob/master/Final%20Project/375Lab12.pdf)
* Board must _**simultaneously**_:
  * read input from keyboard through Breakout module and change LED blink rate on STM board
  * read input from hex keypad (16 buttons, pseudo-piano capable of different scales) and convert to music
  ![alt text](http://www.circuitstoday.com/wp-content/uploads/2014/05/hex-keypad-arduino.png "Hex-Keypad Sample")  
  * read input from pseudo-theremin (photocell resistor whose values raise or lower according to light on it). As hand moves closer or farther away from theremin, sound output is higher or lower dB
  * output music notes to terminal through Sparkfun FT232R Breakout module
  * output music to speaker system
  * output sound from pseudo-theremin module

##### Finished Project (speaker not shown):
<img src="https://raw.githubusercontent.com/poobloh/sample-projects/master/Final%20Project/IMG_20150512_012240.jpg" width="450">

### Lab 6
Language: Java
* Various self-made programs that replicate the ArrayList and List classes

### Magic Square
Language: C 
* [Magic Square](https://en.wikipedia.org/wiki/Magic_square) program. An n by n matrix  whose sum of each row, column, and diagonals are always the same.

### Probability Project
Language: MATLAB
* Program to test knowledge of Random Discrete Variables
* Rolling 3 four-sided dice, summing the values, and repeating for 100,000 trials.
* Matlab code reveals CDF, PDF, and probabilities of each sum from the 100,000 trial data
* Project outline [here.](https://github.com/poobloh/sample-projects/blob/master/Probability%20Project/Prob%20Project.pdf)

### Prog3
Language: Java
* Programs that utilize java.io File functions
  * Prog3a: 2 command line inputs (inputFilename and word), opens file to search for word
  * Prog3b: 2 command line inputs (inputFilename and outputFilename), reads csv file and writes a new file with spaces replacing commas
  * Prog3c: 1 command line input (inputFilename), reads double values from file and prints as longitude/latitude pairs

### RPi Project
Language: C
* Utilizing the RaspberryPi GPIO connected to breadboard with push button and LED, created a program that records a combination from pushing the button (a-la morse code).
* Once combination is recorded, the LED is turned off and waits for input
* After input, LED either blinks with incorrect code or remains on with correct combination
* Project Outline [here.](https://github.com/poobloh/sample-projects/blob/master/RPi%20Project/Student%20Project.pdf)

##### Finished Project:
![alt text](https://raw.githubusercontent.com/poobloh/sample-projects/master/RPi%20Project/rpi.png "RPi Project")

### Tic Tac Toe A.I.
Language: C++
* Command-line driven game with ASCII graphics 
* Tic Tac Toe with capability of playing against another player or the computer
* Computer AI is unbeatable and utilizes the minmax algorithm explained [here.](https://en.wikipedia.org/wiki/Minimax#Combinatorial_game_theory).

### Weather Watcher
Language: Java
* [realtimeweb WeatherService](https://github.com/RealTimeWeb/weather/tree/master/java/src/realtimeweb), tests methods with cached .json file and prints/analyzes data in table format
* .json file cached and pulled from 
