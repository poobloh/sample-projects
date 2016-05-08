#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// Switch Pin - wiringPi pin 1 is BCM_GPIO 18.
// Some code implemented from WiringPi examples (such as defining LED/SWITCH, etc)
/* I attempted to use the waitForInterrupt methods (both ISR and the old method)to read consecutive switch entries
   but was unsuccessful. There is some leftover commented code on the bottom */
// The code works as intended, although if you leave the button pressed for a little too long, bouncing occurs, but rarely

#define	LED	0
#define SWITCH  1
#define COUNT_KEY 0

void storeNum(int x)
{
    if(!digitalRead(SWITCH))
    {
        digitalWrite(LED, HIGH);
        delay(250);
        digitalWrite(LED, LOW);
        x++;
    }
    delay(250);
}

int main(void)
{
    printf ("STORE COMBINATION\n") ;
    printf ("--------------------\n");
    wiringPiSetup () ;
    pinMode (LED, OUTPUT) ;
    pinMode (SWITCH, INPUT);
    digitalWrite(SWITCH, HIGH);
    digitalWrite(LED, LOW);
    int i = 0;
    int counter = 0;
    int combo[] = {0, 0, 0};

    for(i=0; i<3; i++)
    {
        printf("Password digit #%d?\n", i+1);
        delay(500);
        int j = 0;
        for(j=0; j<10; j++)
            storeNum(counter);
        printf("Number of presses read: %d\n", counter);
        combo[i] = counter;
        delay(1500);
    }
    printf ("--------------------\n");
    printf("Combo is %d - %d - %d\n", combo[0], combo[1], combo[2]);

    return 0;

    /* for(i=0; i<3; i++)
     {
       printf("Input %d\n", i);
       delay(1000);
       printf("Waiting... "); fflush(stdout);

       while(counter == lastCounter)
       {
    piLock(COUNT_KEY);
    counter = globalCounter;
    piUnlock(COUNT_KEY);
    delay(500);
       }

       printf("Counter is %d\n", counter);
       pass[i] = counter;
       lastCounter = counter;
       delay(2000);
     }*/

}
