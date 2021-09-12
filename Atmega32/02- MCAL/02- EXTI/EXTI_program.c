#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"

void MEXTI_voidEXTI0Enable(void)
{
	/* Select Falling Edge As Source Triggering */
	CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_MCUCR_ISC00_BIT);
	SET_BIT(EXTI_u8_MCUCR_REG,EXTI_MCUCR_ISC01_BIT);
	/* Enable For " PIE of INT0 " */
	SET_BIT(EXTI_u8_GICR_REG,EXTI_GICR_INT0_ENABLE);
}