#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
void set_game_area (void)
{
 uchar x, y = 0;
 for (y = 0; y < 6; y++)
 {
    for (x = 0;x <84; x++)
    {
        set_address(x, y);
        lcdWrite(gameplay_area[y][x], HIGH);
    }
 }
} 
