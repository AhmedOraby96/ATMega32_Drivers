/*
 * ACD_Interface.h
 *
 * Created: 7/27/2023 5:42:50 PM
 *  Author: ORABY
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum{
		ADC_PIN0,
		ADC_PIN1,
		ADC_PIN2,
		ADC_PIN3,
		ADC_PIN4,
		ADC_PIN5,
		ADC_PIN6,
		ADC_PIN7
	}ADC_PIN_Types;
	
void ADC_Intitialize(void);
void ADC_StartConversion(ADC_PIN_Types PIN_Type);
u16 ADC_GetResult(void); 



#endif /* ADC_INTERFACE_H_ */