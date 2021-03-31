/*****************************************************************/
/****************** Name    :Mohamed Tarek ***********************/
/****************** Date    : 31/3/2021    ***********************/
/****************** Version : 1.0V         ***********************/
/****************** SWC     : RCC          ***********************/
/*****************************************************************/

/*LIB Layer*/
#include "LIB_BIT_MATH.h"
#include "LIB_STD_TYPES.h"

#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"

void RCC_voidInit(void)
{
#if 	RCC_CLK_TYPE == RCC_HSE_CRYSTAL
	/*Not bypass - Enable HSE - SW = HSE*/
	RCC_CR = 0x00010000;
	RCC_CFGR = 0x00000001;
	/*polling till HSE is Ready*/
	while (GET_BIT(RCC_CR,17) == 0) {
		asm("NOP");
	}

#elif	RCC_CLK_TYPE == RCC_HSE_RC
/*Not bypass - Enable HSE - SW = HSE*/
RCC_CR   = 0x00010000;
RCC_CFGR = 0x00000001;
/*polling till HSE is Ready*/
while(GET_BIT(RCC_CR,17)==0)
{
	asm("NOP");
}

#elif	RCC_CLK_TYPE == RCC_HSI
/*Enable HSI*/
SET_BIT(RCC_CR,0);
/*SW => HSI*/
CLR_BIT(RCC_CFGR,1);
CLR_BIT(RCC_CFGR,0);
/*polling till HSI is Ready*/
while(GET_BIT(RCC_CR,1)==0)
{
	asm("NOP");
}

#elif	RCC_CLK_TYPE == RCC_PLL
/*Enable PLL*/
SET_BIT(RCC_CR,24);
/*SW => PLL*/
SET_BIT(RCC_CFGR,1);
CLR_BIT(RCC_CFGR,0);
/*polling till PLL is Ready*/
while(GET_BIT(RCC_CR,25)==0)
{
asm("NOP");
}

/*PLL source => RCC_PLL_SOURCE (HSI/2,HSE,HSE/2)*/
#if 	RCC_PLL_SOURCE == RCC_PLL_HSI_DIV_2
CLR_BIT(RCC_CFGR,16);
#elif	RCC_PLL_SOURCE == RCC_PLL_HSE
SET_BIT(RCC_CFGR,16);
CLR_BIT(RCC_CFGR,17);
#elif	RCC_PLL_SOURCE == RCC_PLL_HSE_DIV_2
SET_BIT(RCC_CFGR,16);
SET_BIT(RCC_CFGR,17);
#else	#error ("Wrong choice of PLL source ")
#endif
/*PLL multiplication factor*/
#if 	RCC_PLL_MUL_VAL == 2
CLR_BIT(RCC_CFGR,21);
CLR_BIT(RCC_CFGR,20);
CLR_BIT(RCC_CFGR,19);
CLR_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 3
CLR_BIT(RCC_CFGR,21);
CLR_BIT(RCC_CFGR,20);
CLR_BIT(RCC_CFGR,19);
SET_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 4
CLR_BIT(RCC_CFGR,21);
CLR_BIT(RCC_CFGR,20);
SET_BIT(RCC_CFGR,19);
CLR_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 5
CLR_BIT(RCC_CFGR,21);
CLR_BIT(RCC_CFGR,20);
SET_BIT(RCC_CFGR,19);
SET_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 6
CLR_BIT(RCC_CFGR,21);
SET_BIT(RCC_CFGR,20);
CLR_BIT(RCC_CFGR,19);
CLR_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 7
CLR_BIT(RCC_CFGR,21);
SET_BIT(RCC_CFGR,20);
CLR_BIT(RCC_CFGR,19);
SET_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 8
CLR_BIT(RCC_CFGR,21);
SET_BIT(RCC_CFGR,20);
SET_BIT(RCC_CFGR,19);
CLR_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 9
CLR_BIT(RCC_CFGR,21);
SET_BIT(RCC_CFGR,20);
SET_BIT(RCC_CFGR,19);
SET_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 10
SET_BIT(RCC_CFGR,21);
CLR_BIT(RCC_CFGR,20);
CLR_BIT(RCC_CFGR,19);
CLR_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 11
SET_BIT(RCC_CFGR,21);
CLR_BIT(RCC_CFGR,20);
CLR_BIT(RCC_CFGR,19);
SET_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 12
SET_BIT(RCC_CFGR,21);
CLR_BIT(RCC_CFGR,20);
SET_BIT(RCC_CFGR,19);
CLR_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 13
SET_BIT(RCC_CFGR,21);
CLR_BIT(RCC_CFGR,20);
SET_BIT(RCC_CFGR,19);
SET_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 14
SET_BIT(RCC_CFGR,21);
SET_BIT(RCC_CFGR,20);
CLR_BIT(RCC_CFGR,19);
CLR_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 15
SET_BIT(RCC_CFGR,21);
SET_BIT(RCC_CFGR,20);
CLR_BIT(RCC_CFGR,19);
SET_BIT(RCC_CFGR,18);
#elif 	RCC_PLL_MUL_VAL == 16
SET_BIT(RCC_CFGR,21);
SET_BIT(RCC_CFGR,20);
SET_BIT(RCC_CFGR,19);
CLR_BIT(RCC_CFGR,18);
#else #error ("Wrong choice for Multiplication factor ")

#endif

#else	#error ("Wrong choice of RCC Clock type")
#endif
}

u8 RCC_u8EnablePeripheralCLK(u8 Copy_u8Bus, u8 Copy_u8Per)
{
	u8 Local_u8Errorstate = STD_TYPES_OK;
	/*Range check*/
	if (Copy_u8Per < 32) 
	{
		switch (Copy_u8Bus) 
		{
		case RCC_AHB:
			SET_BIT(RCC_AHBENR, Copy_u8Per);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR, Copy_u8Per);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR, Copy_u8Per);
			break;

		}
	} 
	else 
	{
		Local_u8Errorstate = STD_TYPES_NOK;
	}
	return Local_u8Errorstate;

}

u8 RCC_u8DisablePeripheralCLK(u8 Copy_u8Bus, u8 Copy_u8Per)
{
	Local_u8Errorstate = STD_TYPES_OK;
	/*Range check*/
	if (Copy_u8Per < 32) 
	{
		switch (Copy_u8Bus) 
		{
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR, Copy_u8Per);
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR, Copy_u8Per);
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR, Copy_u8Per);
			break;

		}
	} 
	else
	{
		Local_u8Errorstate = STD_TYPES_NOK;
	}
	return Local_u8Errorstate;

}
