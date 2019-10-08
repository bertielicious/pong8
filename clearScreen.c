#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
void clearScreen(void)
{
    uchar row, col = 0;
    for(row = 0; row < 6; row++)
    {
        for(col = 0; col < 83; col++)
        {
            set_address(col, row);
            lcdWrite(0x00, HIGH);
           /* if(gameplay_area[row][col] >0)
            {
                gameplay_area[row][col] = 0;
            }*/
        }
    }
}
