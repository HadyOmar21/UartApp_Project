#ifndef HAL_GPIO_H
#define HAL_GPIO_H

/* Section : Includes */
#include <avr/io.h>
#include <stddef.h>               

/* Section: Macro Declarations */
#define BIT_MASK             (unsigned char)1
#define PORT_PIN_MAX_NUMBER  8      /* pins per port  */
#define PORT_MAX_NUMBER      3      /* ports B, C, D  */

/* Section: Macro Functions Declarations */
#define SET_BIT(REG, BIT_POSN)     ((REG) |= (unsigned char)(BIT_MASK << (BIT_POSN)))
#define CLEAR_BIT(REG, BIT_POSN)   ((REG) &= (unsigned char)~(BIT_MASK << (BIT_POSN)))
#define TOGGLE_BIT(REG, BIT_POSN)  ((REG) ^= (unsigned char)(BIT_MASK << (BIT_POSN)))
#define READ_BIT(REG, BIT_POSN)    ((unsigned char)(((REG) >> (BIT_POSN)) & BIT_MASK))

/* Section: Data Type Declarations */
typedef enum{
    GPIO_LOW = 0,
    GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_DIRECTION_INPUT = 0,       
    GPIO_DIRECTION_OUTPUT          
}direction_t;

/* GPIO_ prefix: PIN0 ... PIN7 are already defined as numbers by avr/io.h */
typedef enum{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;

typedef enum{
    PORTB_INDEX = 0,
    PORTC_INDEX,
    PORTD_INDEX
}port_index_t;

typedef struct{
    port_index_t port;         
    pin_index_t  pin;          
    direction_t  direction;     
    logic_t      logic;        
                            
}pin_config_t;


/* Section: Function Declarations */
void gpio_pin_direction_initialize(const pin_config_t *pin_config);
void gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic);
void gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic);
void gpio_pin_toggle_logic(const pin_config_t *pin_config);
void gpio_pin_initialize(const pin_config_t *pin_config);


#endif  /* HAL_GPIO_H */
