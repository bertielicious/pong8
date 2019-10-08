#include "config.h"
#include "interrupt isr.h"
#include "paddleMove.h"
#include "clearScreen.h"
#include "set_address.h"
#include "lcdWrite.h"
#include "animate.h"


void interrupt isr(void)
{
    uchar row, col;
    
    if ( INTCONbits.TMR0IF == 1)
    {
        GREEN_LED = ~GREEN_LED;
        for(row = 0; row < 6; row++ )
        {
            for(col = 2; col < 83; col++)
            {
                set_address(col,row);
                lcdWrite(gameplay_area[row][col], HIGH);
            }
        }
      
        
       
         TMR0 = 0x00; 
         INTCONbits.TMR0IF = 0; 
    }
    if (PIR1bits.TMR1IF == 1)       // TMR1 is 1 sec gravity timer interrupt        
    {  
        TMR1H = 0x00;               // preload TMR1 to generate a 125ms interrupt
        TMR1L = 0x00;
        paddleMove();  
        PIR1bits.TMR1IF = 0;     
    }
        
}

