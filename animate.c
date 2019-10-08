#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
#include "posnBall.h"
void animate(uchar colInit, uchar rowInit, bool erase)
{
    uchar col, row;
    row = rowInit;
    for (col = colInit; col < colInit + 3; col++)   // show the ball at the start position col = 0, page 1
    {
        posnBall(col,row,erase);
    }
    
}
