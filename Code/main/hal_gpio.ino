/*
 * File:   hal_gpio.c
 * Brief:  GPIO driver (digital input / output pins) for ATmega328P
 */

#include "hal_gpio.h"

/* Reference to the Data Direction Registers (index = port_index_t) */
static volatile unsigned char * const ddr_registers[]  = {&DDRB,  &DDRC,  &DDRD};
/* Reference to the Port Registers : output level / pull-up */
static volatile unsigned char * const port_registers[] = {&PORTB, &PORTC, &PORTD};
/* Reference to the Pin Registers : read the pin level */
static volatile unsigned char * const pin_registers[]  = {&PINB,  &PINC,  &PIND};


void gpio_pin_direction_initialize(const pin_config_t * pin_config){
   
        switch( pin_config->direction){
            case GPIO_DIRECTION_OUTPUT :
                SET_BIT(*ddr_registers[ pin_config->port],  pin_config->pin);
                                break;

                
            case GPIO_DIRECTION_INPUT :
                CLEAR_BIT(*ddr_registers[ pin_config->port],  pin_config->pin);
                                break;

        }
}


void gpio_pin_write_logic(const pin_config_t * pin_config, logic_t logic){

        switch(logic){
            case GPIO_LOW :
                CLEAR_BIT(*port_registers[ pin_config->port],  pin_config->pin);
                break;
            case GPIO_HIGH :
                SET_BIT(*port_registers[ pin_config->port],  pin_config->pin);
                                break;

        }
}


void gpio_pin_read_logic(const pin_config_t * pin_config, logic_t *logic)
{

        *logic = (READ_BIT(*pin_registers[ pin_config->port],  pin_config->pin) );

}


void gpio_pin_toggle_logic(const pin_config_t * pin_config){

        TOGGLE_BIT(*port_registers[ pin_config->port],  pin_config->pin);
    
}

void gpio_pin_initialize(const pin_config_t * pin_config){

        gpio_pin_write_logic( pin_config,  pin_config->logic);
        gpio_pin_direction_initialize( pin_config);
        
    
}

