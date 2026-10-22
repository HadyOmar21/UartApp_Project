
#ifndef UART_H
#define UART_H

#ifndef F_CPU
#define F_CPU    16000000UL      /* Arduino Uno clock = 16 MHz */
#endif



/* Section: Function Declarations */
void Uart_Init(void);

void Uart_SetBaudRate(unsigned short BuadRate);

void Uart_SendChar(unsigned char DataByte);

unsigned char  Uart_IsDataAvailable(void);

unsigned char Uart_ReadData();

void Uart_SendString(char DataString[], unsigned char Size);


#endif  /* UART_H */
