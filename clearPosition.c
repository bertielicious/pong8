#include "config.h"

void clearPosition(void)
{
    uchar col2, row2;
    for(col2 = 0; col2 < 2; col2++)  
    {
      for(row2 = 0; row2 < 6; row2++)  
         {
             position[row2][col2] = 0x00;
         }
    }
}
