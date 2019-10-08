#include "config.h"
#include "lcdWrite.h"
void lcd_setup(void)
{
    RST = LOW;
    __delay_ms(1);
    RST = HIGH;
    
    lcdWrite(FUNC_SET_EXTEND, LOW); // function set command LCD active, Horiz mode, extended instruction set
    lcdWrite(LCD_CONTRAST, LOW); // set LCD Vop contrast
    lcdWrite(LCD_TEMP_COEFF, LOW); // set temp coefficient
    lcdWrite(LCD_BIAS, LOW); // LCD bias mode
    lcdWrite(BASIC_IS, LOW); // LCD basic instruction set
    lcdWrite(NORMAL_MODE, LOW); // normal display mode
    
    lcdWrite(SET_Y|0x00, LOW);       // sets address at top LH corner (origin) of LCD)
    lcdWrite(SET_X|0x00, LOW);
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
}
