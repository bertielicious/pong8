#include "config.h"
void splitDigits(uchar score)
{
           units = score%10;    // units equals remainder after score is divided by ten
           tens = (score/10)%10;     // tens equals score integer divided by tentake modulus eg (13.5/10)%10 = 1.3%10 = 1
}
