#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
void writeChar(uchar *character, uchar x, uchar page)
{
    set_address(x, page);
    for( x = 0; x < 8; x++)
    {
        lcdWrite(*character, HIGH);
        character++;
    }
}
