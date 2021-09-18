#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


//command pins
#define LCD_RS      PINB0
#define LCD_RW      PINB1
#define LCD_EN      PINB2
//data pins
// pins DB0 ~ DB3 not used in 4 bit mode
#define LCD_DB4     PIND4
#define LCD_DB5     PIND5
#define LCD_DB6     PIND6
#define LCD_DB7     PIND7

#define FUN_SET_4BITS_MODE 0x02 /* to initialize function set in 4 bit mode      */
#define FUN_SET 0x08            /* set 2 lines and font 5x7                      */

//Common commands
#define LCD_CLEAR 0x01       /* replace all characters with ASCII 'space'     */
#define LCD_RETURN_HOME 0x02 /* return cursor to first position on first line */
#define LCD_ENTRY_MODE 0x06  /* shift cursor from left to right on read/write */
#define LCD_DISPLAY_MODE 0x00
#define LCD_DISPLAY_OFF 0x08   /* turn display off                              */
#define LCD_DISPLAY_ON 0x0C    /* display on, cursor off, don't blink character */
#define LCD_RESET 0x30         /* reset the LCD                                 */
#define LCD_CURSOR_OFFSET 0x80 /* set cursor position                           */

#endif