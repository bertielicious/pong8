#include <pic16f1459.h>

void TMR0_setup(void)
{
    /*****8 bit timer mode*******/
    /****interrupt on overflow****/
    OPTION_REGbits.TMR0CS = 0;      // 8 bit timer mode
    OPTION_REGbits.PSA = 0;         // Pre-scaler assigned to TMR0 module
    OPTION_REGbits.PS2 = 1;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 1;         // 256:1 prescaler
    INTCONbits.GIE = 1;             // enable interrupts
    INTCONbits.TMR0IE = 1;          // TMR0 interrupt enabled
    INTCONbits.TMR0IF = 0;          // TMRO interrupt flag cleared
    TMR0 = 0x00;                    // clear Timer0 count to zero
}
