#include "../../01- LIB/std_types.h"
#include "../../01- LIB/common_macros.h"

#include "GIE_interface.h"
#include "GIE_register.h"

static uint_16 disableCount = 0 ;

void MGIE_voidEnable(void)
{
	if(disableCount == 0)
	{
		SET_BIT(SREG,GIE_PIN);
	}
	else
	{
		disableCount--;
	}
}

void MGIE_voidDisable(void)
{
	disableCount++;
	CLEAR_BIT(SREG,GIE_PIN);
}
