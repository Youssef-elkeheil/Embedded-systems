#include "../../01- LIB/BIT_MATH.h"
#include "../../01- LIB/STD_TYPES.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void MGIE_voidEnable(void)
{
	SET_BIT(SREG,GIE_PIN);
}

void MGIE_voidDisable(void)
{
	CLR_BIT(SREG,GIE_PIN);
}