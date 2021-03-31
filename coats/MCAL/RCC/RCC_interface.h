/*****************************************************************/
/****************** Name    :Mohamed Tarek ***********************/
/****************** Date    : 31/3/2021    ***********************/
/****************** Version : 1.0V         ***********************/
/****************** SWC     : RCC          ***********************/
/*****************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/*RCC config*/
void RCC_voidInit(void);
u8 RCC_u8EnablePeripheralCLK(u8 Copy_u8Bus, u8 Copy_u8Per);
u8 RCC_u8DisablePeripheralCLK(u8 Copy_u8Bus, u8 Copy_u8Per);

/*Macros for Buses*/
#define RCC_AHB				0
#define RCC_APB1			1
#define RCC_APB2			2

#endif /* RCC_INTERFACE_H_ */
