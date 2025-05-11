#include "msp430.h"

#define COUNT_START 0x20000ul
#define MASK_DIM_PER 0x0FFFu
#define MASK_DIM_OFF 0x007Fu
#define MASK_BUTTON (BIT3)
#define MASK_LED_RD (BIT6)
#define MASK_LED_GN (BIT0)
#define MASK_LEDS (MASK_LED_RD + MASK_LED_GN)

// base type renaming
typedef unsigned long  U32_t; // create short name for 32 bit unsigned integer

// globals
U32_t uCount;

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;    // Stop watchdog timer

  // Check for validity of DCO cal-data
  if (CALBC1_12MHZ==0xFF) while(1);

  // and set required factory-calibrated clock
  DCOCTL  = 0;
  BCSCTL1 = CALBC1_12MHZ;
  DCOCTL  = CALDCO_12MHZ;

  // prepare digital I/O
  P1OUT  = MASK_LEDS + MASK_BUTTON; // Set LEDs to "1" and prepare pull-up for button
  P1OUT &= ~MASK_LED_RD;            // Reset red LED
  P1REN  = MASK_BUTTON;             // Enable pull-up for P1.3

  // Forever do
  while (1)
  {
    P1DIR |= MASK_LEDS;       // Set LEDs to output direction
    if( P1IN & MASK_BUTTON)   // Button not pressed
    {
      P1OUT ^= MASK_LEDS;     // Toggle LEDs
      uCount = COUNT_START;
      while (uCount > 0)
      {
        uCount--;
      }
    }
    else                      // Button pressed
    {
      P1OUT ^= MASK_LEDS;     // Toggle LEDs

      uCount = COUNT_START;   // Set start value for delay-loop
      while (uCount > 0)
      {
        uCount--;
        if ((uCount & MASK_DIM_OFF) == MASK_DIM_OFF)
          P1DIR  &= ~MASK_LEDS;  // LEDs: OFF
        if ((uCount & MASK_DIM_PER) == MASK_DIM_PER)
          P1DIR  |= MASK_LEDS;   // LEDs: ON
      }
    }
  }
}


