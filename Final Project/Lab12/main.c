#include <STM32F0xx.h>
#include <math.h>
#include "lib.h"

/*Interrupt debouncer*/
int64_t debounce = 0;
int64_t ms=0;

/*Hexpad utility variables*/
int scancode = 0, noteChange = 0,
    newNote = 0, startKey = 60, prevNote = 0;
int same = 0;
float frequency;

/* USART utility */
uint8_t c;


void init();                   
void playNote(int scan);    
void noteOff();
int getNum();       
void printNote(int on, int note, uint64_t mil);
void SysTick_Handler();

int main() {
  init();
  while(1) 
	{
    /* Hexpad */
    scancode = butPress();
    if(scancode==8) noteChange=1;
    else if(noteChange) {
      if(getNum() == -1) {
        noteChange = 0;
        startKey = newNote;
        newNote = 0;
      }
      else if(scancode && butPress() && debounce<=0) {
        newNote = (newNote*10) + getNum();
        debounce = 7;
      }
    }
    else if(butPress() && scancode) {
			debounce = 7;
			playNote(scancode);
		}
		else if(!butPress()) {
			noteOff();
      speakerOff();
		}
		
		/* USART */
		c = getChar();
		if(c!=0xFF) {
			if(c>0x60 && c<0x7B)
				c -= 0x20;
			if(c == 0x0D || c == 0x0A) {
				putChar(0x0A);
        putChar(0x0D);
			}
		}
		if(c!=0xFF)
			putChar(c);
  }
}

void init() {
  portEnable('A');
	portEnable('B');
  portEnable('C');
  initHex();
  initSpeaker();
	initSpeaker2();
  SysTick_Config(SystemCoreClock/1000);
	serialStart(9600);
}

// Musical Formula: 2 ^ (note - 69)/12 * 440 Hz
void playNote(int scan) {
  if (scan>8) scan--;
	if(!prevNote) {
		prevNote = scan;
		printNote(0, scan+startKey, ms);
	}
  frequency = pow(2.0, ((float)(startKey + (scan*2))-69.0)/12.0) * 440.0;
  speakerOn(frequency, 50, 50);
	printNote(1, startKey + scan, ms);
}

void noteOff() {
	if(prevNote) {
		printNote(prevNote, prevNote+startKey, ms);
		prevNote = 0;
	}
}

// Prints note
void printNote(int on, int note, uint64_t mil) {
	putChar('N'); putChar('o'); putChar('t'); putChar('e'); putChar(' ');
	
	// print note
	putChar((note%10)+'0');
	
	if(on) {
		putChar(' '); putChar('o'); putChar('n'); putChar(' ');
	}
	else {
		putChar(' '); putChar('o'); putChar('f'); putChar('f'); putChar(' ');
	}
	
	// print ms
	putChar('0');
	
	putChar(' '); putChar('m'); putChar('s');
	putChar(0x0D); putChar(0x0A);
}

/* Gets the true number of button press
 * to the corresponding scancode. */
int getNum() {
	scancode= butPress();
  while(scancode>12||scancode%4==0) {
    scancode = butPress();
    if(scancode==15) return -1;
    if(scancode==14) return 0;
  }
  return scancode-(scancode/4);
}

/* Systick for debouncing */
void SysTick_Handler() {
  if(!butPress()) debounce--;
	ms++;
	
	if(usrButPress() && debounce<=0) {
		debounce = 7;
	}
}