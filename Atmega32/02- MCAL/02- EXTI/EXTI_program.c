#include "../../01- LIB/STD_TYPES.h"
#include "../../01- LIB/BIT_MATH.h"

#include "../01- DIO/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_registers.h"


void (*G_ptr_ISR0FunctionExcution) (void) = NULL;
void (*G_ptr_ISR1FunctionExcution) (void) = NULL;
void (*G_ptr_ISR2FunctionExcution) (void) = NULL;

void EXTI_voidInt0Init(void (*ptr_ISR0FunctionLogic)(void))
{
	MDIO_voidSetPinDirection(INT0_PIN,OUTPUT);
	MDIO_voidSetPinValue(INT0_PIN,HIGH);
	
	SET_BIT(GICR_REG,GICR_INT0);//specific Interrupt 0 Enable
	
	MCUCR_REG|= EXTI0_MODE;     // Set interrupt 0 mode in MCUCR register

	G_ptr_ISR0FunctionExcution = ptr_ISR0FunctionLogic;
}

void EXTI_voidInt1Init(void (*ptr_ISR1FunctionLogic)(void))
{
	MDIO_voidSetPinDirection(INT1_PIN,OUTPUT);
	MDIO_voidSetPinValue(INT1_PIN,HIGH);
	
	SET_BIT(GICR_REG,GICR_INT1);//specific Interrupt 1 Enable
	
	MCUCR_REG|= EXTI1_MODE;     // Set interrupt 1 mode in MCUCR register

	G_ptr_ISR1FunctionExcution = ptr_ISR1FunctionLogic;
}

void EXTI_voidInt2Init(void (*ptr_ISR2FunctionLogic)(void))
{
	MDIO_voidSetPinDirection(INT2_PIN,OUTPUT);
	MDIO_voidSetPinValue(INT2_PIN,HIGH);
	
	SET_BIT(GICR_REG,GICR_INT2);//specific Interrupt 2 Enable

	MCUCSR_REG |= EXTI2_MODE; 	// Set interrupt 2 mode in MCUCSR register

	G_ptr_ISR2FunctionExcution = ptr_ISR2FunctionLogic;
}
//__attribute__((signal)) means : stop optimezer from deleting this function,
// As it is called by hardware not software
void __vector_1(void) __attribute__((signal));
void __vector_1 (void)						  
{
	G_ptr_ISR0FunctionExcution();
}

void __vector_2(void) __attribute__((signal));
void __vector_2 (void)
{
	G_ptr_ISR1FunctionExcution();
}

void __vector_3(void) __attribute__((signal));
void __vector_3 (void)
{
	G_ptr_ISR2FunctionExcution();
}