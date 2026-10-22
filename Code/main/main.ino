#include "uart.h"       // UART functions (this file also sets F_CPU = 16 MHz)
#include <util/delay.h> // Provide delay functions
#include "hal_gpio.h"  // Read the button pin
#include "led.h"       // Control the LED

/* Button on PD4 (Arduino digital pin 4): external 10k pull-down resistor. */
static const pin_config_t button_pin = {
    PORTD_INDEX,
    GPIO_PIN4,
    GPIO_DIRECTION_INPUT,
    GPIO_LOW
};

/* LED on PB3 (Arduino digital pin 11): resistor in series with LED to GND. */
static const pin_config_t led_pin = {
    PORTB_INDEX,
    GPIO_PIN3,
    GPIO_DIRECTION_OUTPUT,
    GPIO_LOW
};

static logic_t previous_button_state = GPIO_LOW;
static logic_t current_button_state = GPIO_LOW;
static char command[8];
static unsigned char command_length = 0U;
static unsigned char line_too_long = 0U;
static unsigned char received;

unsigned char Cmd_compare(const char str1[], const char str2[])
{
    unsigned char i;

    for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    Uart_Init();
    led_initialize(&led_pin);
    gpio_pin_initialize(&button_pin);
    gpio_pin_read_logic(&button_pin, &previous_button_state);



    /* Check button state */
    gpio_pin_read_logic(&button_pin, &current_button_state);

    while(1)
    {
    if (current_button_state != previous_button_state)
    {
        _delay_ms(20);
        gpio_pin_read_logic(&button_pin, &current_button_state);

        if (current_button_state != previous_button_state)
        {
            if (current_button_state == GPIO_HIGH)
            {
                Uart_SendString("button_pressed\r\n", 16);
            }
            else
            {
                Uart_SendString("button_released\r\n", 17);
            }

            previous_button_state = current_button_state;
        }
    }

    /* Receive and process UART commands */
    while (Uart_IsDataAvailable())
    {
        received = Uart_ReadData();

        if (received == '\r' || received == '\n')
        {
            if (line_too_long == 0U)
            {
                command[command_length] = '\0';

                if (Cmd_compare(command, "led_on"))
                {
                    led_turn_on(&led_pin);
                    Uart_SendString("led_on_ok\r\n", 11);
                }
                else if (Cmd_compare(command, "led_off"))
                {
                    led_turn_off(&led_pin);
                    Uart_SendString("led_off_ok\r\n", 12);
                }
            }

            command_length = 0U;
            line_too_long = 0U;
        }
        else if (command_length < sizeof(command) - 1U && line_too_long == 0U)
        {
            command[command_length] = received;
            command_length++;
        }
        else
        {
            line_too_long = 1U;
        }
    }

    }

    
}