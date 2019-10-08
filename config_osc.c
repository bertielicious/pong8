#include <pic16f1459.h>

void config_osc(void)
{
    OSCCONbits.IRCF3 = 1;       // IRCF<3:0>: Internal Oscillator Frequency Select bits
    OSCCONbits.IRCF2 = 1;       // 1111 = 16 MHz or 48 MHz HF (see Section 5.2.2.1 ?HFINTOSC?)
                                // 1110 = 8 MHz - selected
                                // 1101 = 4 MHz
                                // 1100 = 2 MHz
                                // 1011 = 1 MHz
  
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 1;       // set for 16MHz
    
    OSCCONbits.SCS1 = 1;       //internal osc block selected
}
