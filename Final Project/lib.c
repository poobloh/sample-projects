#include "lib.h"

void portEnable(char port) {
  RCC->AHBENR |= (1<<(17+(port-'A')));
}
// Sets pin to output 1
void pinHigh(char port, int pin) {
  switch(port) {
    case 'A':
      GPIOA->BSRR |= (1<<pin);
      break;
    case 'B':
      GPIOB->BSRR |= (1<<pin);
      break;
    case 'C':
      GPIOC->BSRR |= (1<<pin);
      break;
    case 'D':
      GPIOD->BSRR |= (1<<pin);
      break;
    case 'F':
      GPIOF->BSRR |= (1<<pin);
      break;
  }
}

// Resets pin to output 0
void pinLow(char port, int pin) {
  switch(port) {
    case 'A':
      GPIOA->BRR |= (1<<pin);
      break;
    case 'B':
      GPIOB->BRR |= (1<<pin);
      break;
    case 'C':
      GPIOC->BRR |= (1<<pin);
      break;
    case 'D':
      GPIOD->BRR |= (1<<pin);
      break;
    case 'F':
      GPIOF->BRR |= (1<<pin);
      break;
  }
}

void initPin(char port, int pin, int mode) {
  switch(port) {
    case 'A':
      GPIOA->MODER |= (mode<<pin*2);
      break;
    case 'B':
      GPIOB->MODER |= (mode<<pin*2);
      break;
    case 'C':
      GPIOC->MODER |= (mode<<pin*2);
      break;
    case 'D':
      GPIOD->MODER |= (mode<<pin*2);
      break;
    case 'F':
      GPIOF->MODER |= (mode<<pin*2);
      break;
  }
}

int row=0, col= 0;
void initHex() {
   /* Set fist 4 pins to output
   * Set last 4 pins as pullup (input by default)*/
  GPIOC->MODER |= (0x55<<HEXPAD); 
  GPIOC->PUPDR |= (0x55<<(HEXPAD+4)*2);
}

// Scancode formula: 4(row) + col + 1
uint8_t butPress() {
	GPIOC->BSRR |= (0xf<<(HEXPAD));
	for(row=0; row<4; row++) {
    GPIOC->BRR |= (1<<(HEXPAD+row));
    for(col=0; col<4; col++)
      if(~GPIOC->IDR & (1<<((HEXPAD+4)+col))) {
        GPIOC->BSRR |= (1<<(HEXPAD+row));
        return (row*4) + col + 1;
      }
    GPIOC->BSRR |= (1<<(HEXPAD+row));
  }
  return 0;
}

void initSpeaker() {
	RCC->APB2ENR |= (1<<11);
	TIM1->PSC = 48;
	TIM1->CCER |= (0x55<<0);
	TIM1->CCMR1 |= (0x60);
	TIM1->CCMR1 |= (0x60<<8);
	TIM1->BDTR |= (1<<15);
  GPIOA->MODER |= (0xA<<SPEAKER);
  GPIOA->AFR[1] |= (0x22);
}

void speakerOn(uint16_t period, uint16_t duty1, uint16_t duty2) {
  if((TIM1->CCR1)<(TIM1->ARR) && !(TIM1->CCR1==0)) return;
  period = ((SystemCoreClock/48) / (period)) - 1;
  TIM1->ARR = period;
  TIM1->CCR1 = (duty1 * period / 100);
  TIM1->CCR2 = (duty2 * period / 100);
  TIM1->CR1 |= (1<<0);
}

void speakerOff() {
  TIM1->CCR1 = 0;
  TIM1->CCR2 = 0;
}

void initSpeaker2() {
  RCC->APB1ENR |= (1<<1);
	TIM3->PSC = 48;
	TIM3->CCER |= (0x01<<0);
	TIM3->CCMR1 |= (0x60);
  GPIOB->MODER |= (2<<8);
  GPIOB->AFR[0] |= (1<<16);
}

void speaker2On(uint16_t period) {
  period = ((SystemCoreClock/48) / (period)) - 1;
  TIM3->ARR = period;
  TIM3->CCR1 = (50 * period / 100);
  TIM3->CR1 |= (1<<0);
} //End speaker2On()

void speaker2Off() {
  TIM3->CCR1 = 0;
}

/**USART COMMS****************************************************/
/**                                                             **/
/*This enables the USART. The settings set the buad rate to
 * the int argument passed */
void serialStart(uint16_t baud) {
  RCC->APB2ENR |= (1<<14); 
  initPin('B', 6, ALTMODE);     //TX pin
  initPin('B', 7, ALTMODE);    //RX pin
  GPIOA->AFR[0] |= (0x00<<24);
  baud = SystemCoreClock/baud;
  USART1->BRR = baud;
  USART1->CR1 |= 0xD;
}

uint8_t getChar() {
  if(USART1->ISR & (1<<5)) return USART1->RDR;
  return 0xFF;
}

int putChar(uint8_t txChar) {
  if(!(USART1->ISR & (1<<7))) return 0;
  USART1->TDR = txChar;
  return 1;
}

/* Starts the clock used for interrupts at 1ms*/
void clockStart() {
  SysTick_Config(SystemCoreClock/1000);
}

void initButton() {
  GPIOA->MODER &= ~(3<<BUT*2);
  GPIOA->OTYPER &= ~(3<<BUT*2);
}

// Returns 1 if USER button is pressed
uint32_t usrButPress() {
  return (GPIOA->IDR & (1<<BUT));
}

/* Initializes photocell. Requires port A enabled to function. */
void initPhotocell() {
  initPin('A', 1, ANALOG);
  RCC->APB2ENR |= (1<<9);
  ADC1->CR |= (1<<0);
  ADC1->CHSELR |= (1<<1);
}

void startConv() {
  ADC1->CR |= (1<<2);
}

uint16_t getConv() {
  return (ADC1->DR * .59) + 100; 
}