/*
 * ADC_Prog.c
 *
 * Created: 7/27/2023 5:42:36 PM
 *  Author: ORABY
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "ADC_Interface.h"
#include "ADC_Reg.h"
#include "ADC_Types.h"
#include "ADC_Config.h"

void ADC_Intitialize(void)
{
/******************** SELECTING VOLTAGE REFERENCE ********************/
ADMUX_REG &= ADC_VOLTAGE_REF_clr_msk;
ADMUX_REG |= ADC_VOLTAGE_REF_SELECTOR_msk;
/*********************************************************************/

		/******************** SELECTING ADC MODE ********************/
#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
SET_BIT(ADCSRA_REG,5);
SFIOR_REG &= ADC_AUTO_TRIG_SRC_clr_msk;
SFIOR_REG |= ADC_AUTO_TRIG_SRC_SELECTOR_msk;
#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
CLR_BIT(ADCSRA_REG,5);
#endif
/*********************************************************************/

/******************** SELECTING ADC PRESCALER ********************/
#if ADC_PRESCALER_SELECTOR_msk == ADC_PRESCALER_128_msk
ADCSRA_REG &= ADC_PRESCALER_clr_msk;
ADCSRA_REG |= ADC_PRESCALER_128_msk;
#elif ADC_PRESCALER_SELECTOR_msk == ADC_PRESCALER_2_msk
ADCSRA_REG &= ADC_PRESCALER_clr_msk;
ADCSRA_REG |= ADC_PRESCALER_2_msk;
#endif
/*********************************************************************/

		/******************** SELECTING ADJUSTMENT ********************/
#if ADC_ADJUSTEMENT_SELECTOR_msk == ADC_RIGHT_ADJUSTED
CLR_BIT(ADMUX_REG,5);
#elif ADC_ADJUSTEMENT_SELECTOR_msk == ADC_LEFT_ADJUSTED
SET_BIT(ADMUX_REG,5);
#endif
/*********************************************************************/

	/******************** CLEARING INTERRUPT FLAG ********************/
SET_BIT(ADCSRA_REG,4);	
/*********************************************************************/

			/******************** ENABLE ADC ********************/
SET_BIT(ADCSRA_REG,7);		
/*********************************************************************/	
}

void ADC_StartConversion(ADC_PIN_Types PIN_Type)
{
/**************************** SELECT ADC PIN ****************************/	
	ADMUX_REG &= ADC_PIN_SELECTOR_clr_msk;
	ADMUX_REG |= PIN_Type;
/*********************************************************************/

/**************************** ADC START CONVERSION ****************************/	
SET_BIT(ADCSRA_REG,6);
/*********************************************************************/
}

u16 ADC_GetResult(void)
{
	while(GET_BIT(ADCSRA_REG,6));	//BUSY WAIT FOR CONVERSION TO FINISH
	#if ADC_ADJUSTEMENT_SELECTOR_msk == ADC_RIGHT_ADJUSTED
	return ADCLH_REG;
	#elif ADC_ADJUSTEMENT_SELECTOR_msk == ADC_LEFT_ADJUSTED
	ADCLH_REG = ADCLH_REG << 6;
	return ADCLH_REG;
	#endif
	
}