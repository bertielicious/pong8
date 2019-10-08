#include "config.h"
#include "lcdWrite.h"
void set_address (uchar x, uchar page)
{
    lcdWrite(VERT_ADDR, LOW);   // vertical addressing mode
    lcdWrite(SET_Y|page, LOW);  // set Y address to value held in page (0 - 5)    
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
    lcdWrite(SET_X|x, LOW);     // set X address to value (0 - 83)    
}
