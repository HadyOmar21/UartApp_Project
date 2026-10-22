#include "led.h"


void led_initialize(const pin_config_t *led_pin)
{
    gpio_pin_initialize(led_pin);
}


void led_turn_on(const pin_config_t *led_pin)
{
    gpio_pin_write_logic(led_pin, GPIO_HIGH);
}

void led_turn_off(const pin_config_t *led_pin)
{
    gpio_pin_write_logic(led_pin, GPIO_LOW);
}
