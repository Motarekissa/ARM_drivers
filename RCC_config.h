/*****************************************************************/
/****************** Name    :Mohamed Tarek ***********************/
/****************** Date    : 31/3/2021    ***********************/
/****************** Version : 1.0V         ***********************/
/****************** SWC     : RCC          ***********************/
/*****************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*		RCC_CLK_TYPE types:
 * 							1-RCC_HSE_CRYSTAL
 * 							2-RCC_HSE_RC
 * 							3-RCC_HSI
 * 							4-RCC_PLL			*/

#define RCC_CLK_TYPE		RCC_HSE_CRYSTAL

/* PLL source Types :
 * 		1-RCC_PLL_HSI_DIV_2
 * 		2-RCC_PLL_HSE
 * 		3-RCC_PLL_HSE_DIV_2
*/
#if			RCC_CLK_TYPE == 	RCC_PLL
	#define RCC_PLL_SOURCE		RCC_PLL_HSI_DIV_2
	#define RCC_PLL_MUL_VAL		9
#endif /* RCC_CONFIG_H_ */
