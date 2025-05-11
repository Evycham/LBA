//! @file
//******************************************************************************
//! \brief MSP430G25xx Demo - Dice LEDs
//! \mainpage Dice with LEDs
//!
//!              Demo - Dice LEDs on P1
//!
//!  Configuration: ACLK = n/a, MCLK = SMCLK = default DCO
//!
//!
//!
//!
//!
//!
//!
//!
//!                  MSP430G25xx
//!            Vcc  -------------------
//!            -----|                 |
//!                 |              XIN|-               Vcc
//!            PB   |                 |                ----
//!            -----|RST          XOUT|-                  |
//!                 |                 |                   |
//!        ---------|P1.7-->P2.6      |    LED            |
//!        |        |             P1.0|----|<|---| R |----x
//!        |        |                 |                   |
//!        |        |             P1.1|----|<|---| R |----x
//!     | --        |                 |                   |
//!     | PB        |             P1.2|----|<|---| R |----x
//!     | --        |                 |                   |
//!        |        |             P1.3|----|<|---| R |----x
//!        |   GND  |                 |                   |
//!        x--------|             P1.4|----|<|---| R |----x
//!        |        |                 |                   |
//!       ---       |             P1.5|----|<|---| R |----x
//!                 |                 |                   |
//!                 |             P1.6|----|<|---| R |-----
//!                 |                 |
//!                 -------------------
//!
//!
//!
//!                 ---------  Dice
//!                 |0     6|  Layout
//!                 |       |
//!                 |1  3  5|
//!                 |       |
//!                 |2     4|
//!                 ---------
//!
//!
//! @author  U. Creutzburg
//! @copyright   Hochschule Stralsund
//! $Id: Dice_0.c 522 2022-02-06 20:42:03Z UweCreutzburg $
//  IAR Embedded Workbench Version: 7.xx
//******************************************************************************

#include "msp430.h"
#include "Dice_Display.h"

// Define delay-time for each value displayed
#define COUNT_DELAY_MAX 0xffff  //!< Counter max. value for the delay loop

// Variables: global, RAM
unsigned short usCountDelay;    //!< Counter variable for the delay loop

// Program
int main( void )
{
  //! Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  //! Initialize Display
  Dice_InitDisplay();

  //! Loop forever
  while(1)
  {
    //! - Counter for the display (index)
    unsigned char ucCountLoop;

    //! - Loop over output array
    for (ucCountLoop=1; ucCountLoop <= COUNT_LOOP_MAX; ucCountLoop++)
    {
      //! - -- Set Display
      Dice_SetDisplay(ucCountLoop);

      //! - -- Delay for a while
      for (usCountDelay=0; usCountDelay < COUNT_DELAY_MAX; usCountDelay++);
    }
  }
}
