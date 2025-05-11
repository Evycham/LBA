//! @file
//! @page
//! \brief MSP430G25xx Demo - Dice LEDs Display
//! Dice with LEDs
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
//! $Id: Dice_Display.h 523 2022-02-07 19:37:05Z UweCreutzburg $
//!
//  IAR Embedded Workbench Version: 7.xx
//******************************************************************************

#ifndef DICE_DISPLAY_H
#define DICE_DISPLAY_H

// Defines: Literal replacements (preprocessor)
#define C_0 (0x00) //!< All LEDs are off
#define C_1 (BIT3) //!< LED in the center of the dice
#define C_2 (BIT0+BIT4)
#define C_3 (BIT0+BIT3+BIT4)
#define C_4 (BIT0+BIT2+BIT4+BIT6)
#define C_5 (BIT0+BIT2+BIT3+BIT4+BIT6)
#define C_6 (BIT0+BIT1+BIT2+BIT4+BIT5+BIT6) //!< The six

//! Declare the port pins for the dice (mask)
#define P1_DIR (0x7F)

//! The max. index into the array for the display
#define COUNT_LOOP_MAX ((unsigned char) 6)

//! Layout of the display (ROM)
extern const unsigned char c0to6[COUNT_LOOP_MAX+1];

// Module Procedures
extern void Dice_InitDisplay(void);
extern void Dice_SetDisplay(unsigned char ucNumber);

#endif //DICE_DISPLAY_H