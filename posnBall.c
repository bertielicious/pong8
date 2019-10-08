#include "config.h"
#include "render.h"
#include <stdio.h>

void posnBall(uchar col, uchar row, bool erase)
{
    uchar r, c;
    struct posnData ret;    // define a variable ret of type struct posnData
    if( row >=0 && row <8)
    {
        ret.pageHigh = 0;
        ret.pageLow = 1;
    }
    else if (row >=8 && row <16)
    {
        ret.pageHigh = 1;
        ret.pageLow = 2;
    }
    else if (row >=16 && row <24)
    {
        ret.pageHigh = 2;
        ret.pageLow = 3;
    }
    else if (row >=24 && row <32)
    {
        ret.pageHigh = 3;
        ret.pageLow = 4;
    }
    else if (row >=32 && row <40)
    {
        ret.pageHigh = 4;
        ret.pageLow = 5;
    }
    else if (row >=40 && row <48)
    {
        ret.pageHigh = 5;
        //ret.pageLow = 5;
    }
    switch(row%8)       // 0 to 9
    {
        case 0:
            
            if(erase == 1)
            {
                ret.dataHigh = 0;
                ret.dataLow = 0;
            }
            else
            {
                ret.dataHigh = 0x07;
                ret.dataLow = 0x00;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;     
            
        case 1:
            
            if(erase == 1)
            {               
                ret.dataHigh = 0;               
                ret.dataLow = 0;
            }
            else
            {                
                ret.dataHigh = 0x0e;              
                ret.dataLow = 0x00;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;   
            
        case 2:
            
            if(erase == 1)
            {                
                ret.dataHigh = 0;              
                ret.dataLow = 0;
            }
            else
            {               
                ret.dataHigh = 0x1c;               
                ret.dataLow = 0x00;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;
            
        case 3:
            
            if(erase == 1)
            {               
                ret.dataHigh = 0;               
                ret.dataLow = 0;
            }
            else
            {               
                ret.dataHigh = 0x38;              
                ret.dataLow = 0x00;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;  
            
        case 4:
            
            if(erase == 1)
            {               
                ret.dataHigh = 0;               
                ret.dataLow = 0;
            }
            else
            {             
                ret.dataHigh = 0x70;              
                ret.dataLow = 0x00;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;    
            
        case 5:
            
            if(erase == 1)
            {   
                ret.dataHigh = 0;                
                ret.dataLow = 0;
            }
            else
            {               
                ret.dataHigh = 0xe0;                
                ret.dataLow = 0x00;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;
            
            case 6:
            
            if(erase == 1)
            {                
                ret.dataHigh = 0x00;               
                ret.dataLow = 0x00;
            }
            else
            {                
                ret.dataHigh = 0xc0;               
                ret.dataLow = 0x01;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;
            
            case 7:
            
            if(erase == 1)
            {              
                ret.dataHigh = 0;              
                ret.dataLow = 0;
            }
            else
            {              
                ret.dataHigh = 0x80;              
                ret.dataLow = 0x03;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;
            
            case 8:
            
            if(erase == 1)
            {               
                ret.dataHigh = 0;                
                ret.dataLow = 0;
            }
            else
            {              
                ret.dataHigh = 0x07;              
                ret.dataLow = 0x00;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;     
            
            
            case 9:
            
            if(erase == 1)
            {               
                ret.dataHigh = 0;               
                ret.dataLow = 0;
            }
            else
            {               
                ret.dataHigh = 0x0e;               
                ret.dataLow = 0x00;
            }
            ret.col = col;
            ret.row = row;
            render(ret, erase);
            break;   
    }
     
    if(ret.col == 2)
    //if(ret.col <3)
    {
        position[ret.pageHigh][1] = ret.dataHigh;  // ball position at column 2
        position[ret.pageLow][1] = ret.dataLow;    // test is made to see if the ball and paddle are going to collide  
      //  printf("positionH[%d][1] = %x\t  positionL[%d][1]= %x\n ", ret.pageHigh, position[ret.pageHigh][1], ret.pageLow, position[ret.pageLow][1] );
      //  printf("position[%d][0] = %x\t     position[%d][0] = %x\n", page-1, position[page - 1][0], page, position[page][0]);
    }
    
}
