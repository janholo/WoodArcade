/*
 * DisplayTest.cpp
 *
 * Created: 08/07/2020 09:46:36
 * Author : Jan.Reinhardt
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define PIN_SCK                   PORTB7
#define PIN_MOSI                  PORTB5
#define PIN_SS                    PORTB4

#define MAX7219_LOAD1             PORTB |= (1<<PIN_SS)
#define MAX7219_LOAD0             PORTB &= ~(1<<PIN_SS)


void SPI_MasterInit(void)
{
	/* Set MOSI(5), SS(4) and SCK(7) output, all others input */
	DDRB |= (1<<PIN_SCK)|(1<<PIN_SS)|(1<<PIN_MOSI);
	
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}

void MAX7219_writeData(char data_register, char data)
{
	MAX7219_LOAD0;
	
	int i = 0;
	for(i = 0; i <4; i++)
	{
		// Send the register where the data will be stored
		SPI_MasterTransmit(data_register);
		// Send the data to be stored
		SPI_MasterTransmit(data);
	}
	MAX7219_LOAD1;
}

void WriteDecodeMode(char data)
{
	MAX7219_writeData(0x09, data);
}

// 0x0 ... 0x0F
void WriteIntensity(char data)
{
	MAX7219_writeData(0x0A, data);
}

// 0x07 to enable all digits
void WriteScanLimit(char data)
{
	MAX7219_writeData(0x0B, data);
}

void WriteShutdownMode()
{
	MAX7219_writeData(0x0C, 0x0);
}

void WriteNormalMode()
{
	MAX7219_writeData(0x0C, 0x01);
}

void WriteDisplayTest(char data)
{
	MAX7219_writeData(0x0F, data);
}

void WriteDisplayData(char digit, char data)
{
	MAX7219_writeData(digit+1, data);
}

bool ReadButton(char num)
{
	char mapping[] = {6,7,5,4,2,3,0,1};
	char mapped = mapping[num];

	return (PIND >> mapped) & 1U;
}

void WriteButton(char num, bool val)
{
	char mapping[] = {6,7,5,4,2,3,0,1};
	char mapped = mapping[num];
	
	if(!val)
	{
		PORTC |= (1<<mapped);
	}
	else
	{
		PORTC &= ~(1UL << mapped);		
	}
}

bool ReadSwitch(char num)
{
	switch(num)
	{
		case 0:
			return !((PINB >> 0) & 1U);
		case 1:
			return !((PINB >> 1) & 1U);
		case 2:
			return !((PINB >> 2) & 1U);
		case 3:
			return !((PINA >> 3) & 1U);
		case 4:
			return !((PINA >> 1) & 1U);
		case 5:
			return !((PINA >> 2) & 1U);
	}
	
	return false;
}

int ReadJoystickX()
{
	if(!((PINA >> 4) & 1U))
	{
		return 1;
	}
	
	if(!((PINA >> 5) & 1U))
	{
		return -1;
	}
	
	return 0;
}

int ReadJoystickY()
{
	if(!((PINA >> 7) & 1U))
	{
		return 1;
	}
	
	if(!((PINA >> 6) & 1U))
	{
		return -1;
	}
	
	return 0;	
}

int main(void)
{
	// Button Lights (As Output and Switch Off)
	DDRC = 0xFF;
	PORTC = 0xFF;
	
	// Buttons (Input, PullUp deactivated)
	DDRD = 0x00;
	PORTD = 0x00;
	
	// Joystick & Switches (Pull Ups)
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0x00;
	PORTB = 0xFF;

	SPI_MasterInit();
	_delay_ms(100);
	WriteIntensity(0x01);
	_delay_ms(100);
	WriteScanLimit(0x07);
	_delay_ms(100);
	WriteNormalMode();
	_delay_ms(100);
	WriteDisplayData(0, 0b01010101);
	WriteDisplayData(1, 0b01010101);
	WriteDisplayData(2, 0b01010101);
	WriteDisplayData(3, 0b01010101);
	WriteDisplayData(4, 0b01010101);
	WriteDisplayData(5, 0b01010101);
	WriteDisplayData(6, 0b01010101);
	WriteDisplayData(7, 0b01010101);

	WriteButton(0, false);
	WriteButton(1, false);
	WriteButton(2, false);
	WriteButton(3, false);
	WriteButton(4, false);
	WriteButton(5, false);
	WriteButton(6, false);
	WriteButton(7, false);

	while(1) 
	{
	
	}

}

