
#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void H_EEPROM_init(void);
uint_8 H_EEPROM_writeByte(uint_16 u16addr,uint_8 u8data);
uint_8 H_EEPROM_readByte(uint_16 u16addr,uint_8 *u8data);
 
#endif /* EXTERNAL_EEPROM_H_ */
