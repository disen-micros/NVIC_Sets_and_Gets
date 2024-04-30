#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "fsl_gpio.h"
#include "GPIO.h"
#include "NVIC.h"
#include "Bits.h"

#include "MK64F12.h"



extern uint8_t g_flag_port_C;
extern uint8_t g_flag_port_A;


int main(void) {


	GPIO_init();

	/**Sets the threshold for interrupts, if the interrupt has higher priority constant that the BASEPRI, the interrupt will not be attended*/
	NVIC_set_basepri_threshold(PRIORITY_10);
	/**Enables and sets a particular interrupt and its priority*/
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ,PRIORITY_5);
	/**Enables and sets a particular interrupt and its priority*/
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ,PRIORITY_4);

	NVIC_global_enable_interrupts;


    while(1) {
    	if(TRUE == GPIO_get_irq_status(GPIO_C)){
			GPIO_PortToggle(GPIOB, 1 << 22);
			GPIO_clear_irq_status(GPIO_C);
		}


		if(TRUE == GPIO_get_irq_status(GPIO_A)){
			GPIO_PortToggle(GPIOB, 1 << 21);
			GPIO_clear_irq_status(GPIO_A);
		}
    }
    return 0 ;
}
