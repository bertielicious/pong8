#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
#include <stdio.h>
void paddleMove(void)
{    
    
   
    if(PADDLEUP == LOW && PADDLEDWN == HIGH)       // paddleUp button pressed
    {
        set_address(0, page-1);   // x = 0, y = 2  upper page column 0
        //gameplay_area[page-1][0] = gameplay_area[page-1][0]| up[buttonPress];
        lcdWrite(up[buttonPress]|gameplay_area[page-1][0], HIGH);    // write up[0 to 7]
        
        set_address(1, page-1);   // x = 0, y = 3 upper page column 1
        //gameplay_area[page-1][1] = gameplay_area[page-1][1]| up[buttonPress];
        lcdWrite(up[buttonPress]|gameplay_area[page-1][1], HIGH);    // write up[0 to 7]
        
        set_address(0, page);   // x = 0, y = 2 LOWER PAGE COLUMN 0
        //gameplay_area[page][0] = gameplay_area[page][0]|down[buttonPress];
        lcdWrite(down[buttonPress]|gameplay_area[page][0], HIGH);    // write up[0 to 7]
        
        set_address(1, page);   // x = 0, y = 3     lower page column 1
        //gameplay_area[page][1] = gameplay_area[page][1]|down[buttonPress];
        lcdWrite(down[buttonPress]|gameplay_area[page][1], HIGH);    // write up[0 to 7]
       // printf("buttonPress %d, page %d, up[%d],%x, down[%d], %x\n", buttonPress, page, buttonPress, up[buttonPress], buttonPress, down[buttonPress] );
        buttonPress++;
        if(buttonPress == 9 && page != 1)
        {
            buttonPress = 1;
            page = page - 1;        // because we are moving up
        }
        if(page == 1 && buttonPress >8)
        {
            page = 1;
            buttonPress = 8;
        }  
    }
    
     if(PADDLEUP == HIGH && PADDLEDWN == LOW)       // paddleDown button pressed
     {
        set_address(0, page-1);   // x = 0, y = 3
        //gameplay_area[page-1][0] = gameplay_area[page-1][0]| up[buttonPress];
       lcdWrite(up[buttonPress], HIGH);    // write up[0 to 7]
        
        set_address(1, page-1);   // x = 0, y = 3
        //gameplay_area[page-1][1] = gameplay_area[page-1][1]| up[buttonPress];
        lcdWrite(up[buttonPress], HIGH);    // write up[0 to 7]
        
        set_address(0, page);   // x = 0, y = 2
        //gameplay_area[page][0] = gameplay_area[page][0]| down[buttonPress];
        lcdWrite(down[buttonPress], HIGH);    // write up[0 to 7]
        set_address(1, page);   // x = 0, y = 3
        //gameplay_area[page][1] = gameplay_area[page][1]| down[buttonPress];
        lcdWrite(down[buttonPress], HIGH);    // write up[0 to 7]
       // printf("DWNbuttonPress %d, page %d, up[%d],%x, down[%d], %x\n", buttonPress, page, buttonPress, up[buttonPress], buttonPress, down[buttonPress] );
        
        if(buttonPress > 0)
        {
            buttonPress--;
        }
        else
        {
            if(page < 5)
            {
                page = page + 1;
                buttonPress = 7;
            }   
        } 
     }
    
    position[page - 1][0] = up[buttonPress];   // copy current position of paddle into position[row][0]]
    position[page][0] = down[buttonPress];
    
    //printf("position[%d][0] = %x\t     position[%d][0] = %x\n", page-1, position[page - 1][0], page, position[page][0]);
   
}