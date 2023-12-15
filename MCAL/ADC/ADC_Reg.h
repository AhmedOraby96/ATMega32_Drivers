/*
 * ADC_Reg.h
 *
 * Created: 7/27/2023 5:45:12 PM
 *  Author: ORABY
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX_REG		*((volatile u8*) 0x27)
#define ADCSRA_REG		*((volatile u8*) 0x26)
#define SFIOR_REG		*((volatile u8*) 0x50)
#define ADCH_REG		*((volatile u8*) 0x25)
#define ADCL_REG		*((volatile u8*) 0x24)
#define ADCLH_REG		*((volatile u16*) 0x24)



#endif /* ADC_REG_H_ */