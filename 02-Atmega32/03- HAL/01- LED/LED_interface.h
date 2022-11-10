#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



typedef struct 
{
    uint_8 port_ID :4;
    uint_8 pin_ID  :4;
}ST_LED;

typedef enum
{
    LED_OFF, LED_ON, LED_TOGGLE
}EN_LEDstate;

/* Initialize LED */
void H_LED_voidLEDinit(ST_LED LED_object);
/* change LED state */
void H_LED_voidChangeState (ST_LED LED_object, EN_LEDstate newState);
/* return LED value*/
EN_LEDstate H_LED_EnGetState (ST_LED LED_object);

#endif
