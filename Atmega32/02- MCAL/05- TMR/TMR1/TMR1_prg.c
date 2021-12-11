/*
 * Includes 
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Files */
#include "DIO_int.h"

/* Module Files */
#include "TMR1_int.h"
#include "TMR1_reg.h"
#include "TMR1_pri.h"
#include "TMR1_cfg.h"

/*
 * Global Object
 */
void (* G_ptr_TMR1IcuNotification) (void) = NULL;
u16 *G_ptr_u16_Counts = NULL;

/*
 * Function Definition 
 */
void M_TMR1_void_Init(void){
	/* Initialize the Clock Source for the selected option in configuration file */
	TCCR1B = (TCCR1B & TMR1_SELECT_CLOCK_MASKING) | (TMR1_CLOCK_SOURCE);

/* Initialize the mode for the selected option in configuration file */
	#if   TMR1_MODE == TMR1_MODE_FAST_PWM_TOP_ICR1
	/* Set the channel & Inverting or Non-Inverting Mode */
	#if   TMR1_CHANNEL == TMR1_CHANNEL_A
		/* Set pin as output */
		M_DIO_void_WritePinDir(M_DIO_PORTID_PORTD, M_DIO_PINID_PIN5, M_DIO_PINDIR_OUTPUT);
		#if   TMR1_CHANNEL_MODE == TMR1_CHANNEL_MODE_INVERTING
			SET_BIT(TCCR1A, COM1A1);
			SET_BIT(TCCR1A, COM1A0);
		#elif TMR1_CHANNEL_MODE == TMR1_CHANNEL_MODE_NON_INVERTING
			SET_BIT(TCCR1A, COM1A1);
			CLR_BIT(TCCR1A, COM1A0);
		#endif
	#elif TMR1_CHANNEL == TMR1_CHANNEL_B
		/* Set pin as output */
		M_DIO_void_WritePinDir(M_DIO_PORTID_PORTD, M_DIO_PINID_PIN4, M_DIO_PINDIR_OUTPUT);
		#if   TMR1_CHANNEL_MODE == TMR1_CHANNEL_MODE_INVERTING
			SET_BIT(TCCR1A, COM1B1);
			SET_BIT(TCCR1A, COM1B0);
		#elif TMR1_CHANNEL_MODE == TMR1_CHANNEL_MODE_NON_INVERTING
			SET_BIT(TCCR1A, COM1B1);
			CLR_BIT(TCCR1A, COM1B0);
		#endif
	#endif
	
	

	/* Initialize the top */
	ICR1 = TMR1_TOP_VALUE;
	
	/* Initialize the counter */
	TCNT1 = 0;
	
#elif TMR1_MODE == TMR1_MODE_ICU
	M_DIO_void_WritePinDir(M_DIO_PORTID_PORTD, M_DIO_PINID_PIN6, M_DIO_PINDIR_INPUT);
	SET_BIT(TCCR1B,	ICES1);
#endif
}

void M_TMR1_void_SetDuty(u8 copy_u8_DutyCycle){
#if TMR1_CHANNEL == TMR1_CHANNEL_A
	OCR1A = copy_u8_DutyCycle;
#elif TMR1_CHANNEL == TMR1_CHANNEL_B
	OCR1B = copy_u8_DutyCycle;
#endif
}

void M_TMR1_void_SetIcuCallBack(void (* ptr_FunSetCallBack)(void)){
#if TMR1_MODE == TMR1_MODE_ICU
	/* Store the function to be called */
	if (ptr_FunSetCallBack != NULL){
		G_ptr_TMR1IcuNotification = ptr_FunSetCallBack;
	}else{
		/* Error */
	}
	/* Enable ICU interrupt */
	SET_BIT(TIMSK, TICIE1);
#endif
}

void M_TMR1_void_SetTriggeringEdge(u8 copy_EdgeID){
	if (copy_EdgeID == M_TMR1_TRIGGERING_MODE_FALLING){
		SET_BIT(TCCR1B,	ICES1);
	}else if (copy_EdgeID == M_TMR1_TRIGGERING_MODE_RISING){
		CLR_BIT(TCCR1B,	ICES1);
	}
}

void M_TMR1_void_ClearTimerValue(void){
	TCNT1 = 0;
}

void M_TMR1_void_GetIcuValue(u16 * ptr_u16_IcuValue){
	*ptr_u16_IcuValue = ICR1;
}

/*
 * ISR body definition 
 */

/* ISR for ICU */
void __vector_6 (void) {
	if (G_ptr_TMR1IcuNotification != NULL){
		G_ptr_TMR1IcuNotification();
	}else {
		/* Error */
	}

}
