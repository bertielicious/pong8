/*                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
 *Player select  2 |RA5      | 19
 * Paddle up  L  3 |RA4      | 18
 *    MCLR/ RST  4 |         | 17
 *    GREEN LED  5 |RC5      | 16
 *           CE  6 |RC4      | 15
 *RST op to 5110 7 |         | 14  RC2 Paddle down L
 *           SS  8 |         | 13 
 *           SDO 9 |         | 12
 *           TX 10 |         | 11  SCK
 *                  ---------
 
 */



#include "config.h"
#include <stdio.h>
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "putch.h"
#include "lcd_setup.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "interrupt isr.h"
#include "lcdWrite.h"
#include "set_address.h"
#include "set_game_area.h"
#include "paddleMove.h"
#include "animate.h"
#include "posnBall.h"
#include "render.h"
#include "clearScreen.h"
#include "update.h"
#include "clearPosition.h"
#include "writeChar.h"
#include "showScore.h"
#include "splitDigits.h"

void main(void) 
{
config_osc();       // internal clock frequency = 8MHz
setup_ports();      
init_spi();
set_usart();
lcd_setup();        // configures the LCD
set_game_area();
TMR0_setup();
TMR1_setup();
clearScreen();

printf("Pong !\n");

float row = 0 ;
float col = 3 ;
uchar currentScore = 0;
float colSpeed = 0.2;
float rowSpeed = 0.4;
//set initial ball position
set_address(0, page);   // column = 0, page = 3
lcdWrite (paddle[0], HIGH);
set_address(1, page);   // column = 1, page = 3
GIE = 0;    // interrupts off
lcdWrite (paddle[1],HIGH);


splitDigits(leftScore);
showScore(units, 10, 1);
//splitDigits(rightScore);
//showScore(units, 70,1);
__delay_ms(10000);
GIE = 1; //interrupts on
//position[page-1][0] = 0;       // page above paddle is empty
//position[page][0] = paddle[0]; // paddle is on page 3 all 8 bits are set - write paddle position into

        while(1)
        {
             if(col > WIDTH && col != 42)            // if the ball travels past the width of the screen
            {
                colSpeed = -0.2;        // reverse the direction of the ball at speed 0.2
            }
             //else if(col <3)     // stops the ball hitting the paddle
             //else if((position[page - 1][0] && position[page - 1][1]) | (position[page][0] && position[page][1]) >0 )
             else if(col < 4 && ( (position[page][0] && position[page][1]) >0 || (position[page-1][0] && position[page-1][1]) > 0))
            {
             //   printf(" position[%d][0] = %x, position[%d][1] = %x, position[%d][0] || position[%d][1] = %x\n", page,position[page][0], page,position[page][1], page-1, page-1, position[page-1][0] && position[page-1][1] );
                colSpeed = 0.3;
                clearPosition();        // clears data stored in collision detecting array position[6][2]]
                leftScore = leftScore + 1;
               //printf("%d\n", leftScore);
                
                
            }
             else
             {
                 
             }
             
            
             
                 
             
            col = col + colSpeed;       // horizontal ball bouncing
            animate(col, row,0);
            
            if(row > DEPTH)
            {
                rowSpeed = -0.2;
            }
            
            if (row <= 0)
            {
                rowSpeed = 0.1;
            }
            row = row + rowSpeed;       // vertical ball bouncing
            animate(col, row, 0); 
        }     
}  
              

                            

