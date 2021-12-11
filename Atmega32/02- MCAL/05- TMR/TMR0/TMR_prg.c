/*
 * Includes 
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Module Files */
#include "TMR_int.h"
#include "TMR_reg.h"
#include "TMR_pri.h"
#include "TMR_cfg.h"

/*
 * Global Object
 */
void (* G_ptr_TMR0Notification) (void) = NULL;

/*
 * Function Definition 
 */
void M_TMR0_void_Init(void){

/* Initialize the mode for the selected option in configuration file */
#if   TMR0_MODE == TMR0_MODE_OVERFLOW 
	/* Select Normal Mode */
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	/* Initialize the Counter */
	TCNT0 = TMR0_PRELOAD_VALUE;
#elif TMR0_MODE == TMR0_MODE_CTC
	/* Select CTC Mode */
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	/* Select the CTC Top */
	OCR0 = TMR0_CTC_TOP_VALUE;
	/* Initialize the Counter */
	TCNT0 = TMR0_PRELOAD_VALUE;
#endif

/* Initialize the Clock Source for the selected option in configuration file */
	TCCR0 = (TCCR0 & TMR0_SELECT_CLOCK_MASKING) | (TMR0_CLOCK_SOURCE);
}

void M_TMR0_void_MeasureTimeAsync(void (* ptr_TMR0SetCallBack)(void)){
/* Enable the Interrupt for the required mode */
#if   TMR0_MODE == TMR0_MODE_OVERFLOW 
	SET_BIT(TIMSK, TOIE0);
#elif TMR0_MODE == TMR0_MODE_CTC
	SET_BIT(TIMSK, OCIE0);
#endif	

	if (ptr_TMR0SetCallBack != NULL){
		G_ptr_TMR0Notification = ptr_TMR0SetCallBack;

	}else {
		/* Error */
	}
}

/*
 * ISR body definition 
 */
#if  TMR0_MODE == TMR0_MODE_CTC
/* ISR for CTC */
 void __vector_10 (void) {
	 static volatile u32 local_CTC_counter = 0;
	 local_CTC_counter++;
	 if (local_CTC_counter == TMR0_NEEDED_OVERFLOW){
		 TCNT0 = TMR0_PRELOAD_VALUE;
		 if (G_ptr_TMR0Notification != NULL){
			 G_ptr_TMR0Notification();
		 }
		 local_CTC_counter = 0;
	 }
 }
#elif TMR0_MODE == TMR0_MODE_OVERFLOW
/* ISR for Overflow */
 void __vector_11 (void) {
	 static volatile u32 local_OV_counter = 0;
	 local_OV_counter++;
	 if (local_OV_counter == TMR0_NEEDED_OVERFLOW){
		 TCNT0 = TMR0_PRELOAD_VALUE;
		 if (G_ptr_TMR0Notification != NULL){
			 G_ptr_TMR0Notification();
		 }else {
			 /* Error */
		 }
		 /* to allow the required time to be measured again */
		 local_OV_counter = 0;
	 }
 }
#endif
