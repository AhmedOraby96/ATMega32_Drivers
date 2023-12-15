/*
 * ADC_Types.h
 *
 * Created: 7/27/2023 5:44:54 PM
 *  Author: ORABY
 */ 


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

/* ADC Voltage Select*/
#define ADC_VOLTAGE_REF_clr_msk					0b00111111
#define ADC_VOLTAGE_REF_AREF					0b00000000
#define ADC_VOLTAGE_REF_AVCC					0b01000000
#define ADC_VOLTAGE_REF_2_56V					0b11000000

/*ADC Channel clear mask*/
#define ADC_PIN_SELECTOR_clr_msk				0b11100000

/* ADC Adjust Select*/
#define ADC_RIGHT_ADJUSTED						0
#define ADC_LEFT_ADJUSTED						1

/* ADC Mode Select*/
#define ADC_MODE_AUTO_TRIGGER					1
#define ADC_MODE_SINGLE_CONVERSION				0

/* ADC Prescaler Select*/
#define ADC_PRESCALER_clr_msk					0b11111000
#define ADC_PRESCALER_2_msk						0b00000000
#define ADC_PRESCALER_4_msk						0b00000010
#define ADC_PRESCALER_8_msk						0b00000110
#define ADC_PRESCALER_16_msk					0b00000100
#define ADC_PRESCALER_32_msk					0b00000101
#define ADC_PRESCALER_64_msk					0b00000110
#define ADC_PRESCALER_128_msk					0b00000111

/* ADC Auto Trigger Select*/
#define ADC_AUTO_TRIG_SRC_clr_msk				0b00011111
#define ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk		0b00000000
#define ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk		0b00100000
#define ADC_AUTO_TRIG_SRC_EXTI0_msk				0b01000000
#define ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk		0b01100000
#define ADC_AUTO_TRIG_SRC_TIMER0_OVF_msk		0b10000000
#define ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk		0b10100000
#define ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk		0b11000000
#define ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk		0b11100000


#endif /* ADC_TYPES_H_ */