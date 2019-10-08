#include "config.h"
#include "set_address.h"
#include "writeChar.h"
void showScore(uchar score, uchar x, uchar page)
{
   
    switch(score)
    {
       
        case 0:
                set_address(x,page);
                writeChar(&cero[0], x, page);  // pointer required!!!! *ptr
                break;   
           
    }
    
}
