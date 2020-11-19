/*
 * DisplayHelper.h
 *
 * Created: 10/08/2020 22:29:56
 *  Author: Jan.Reinhardt
 */ 


#ifndef DISPLAYHELPER_H_
#define DISPLAYHELPER_H_

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

void MAX7219_writeDataArr(char data_register, char data[])
{
	MAX7219_LOAD0;
	
	// Send the register where the data will be stored
	SPI_MasterTransmit(data_register);
	// Send the data to be stored
	SPI_MasterTransmit(data[0]);
	
	SPI_MasterTransmit(data_register);
	SPI_MasterTransmit(data[1]);

	SPI_MasterTransmit(data_register);
	SPI_MasterTransmit(data[2]);

	SPI_MasterTransmit(data_register);
	SPI_MasterTransmit(data[3]);
	
	MAX7219_LOAD1;
}

void MAX7219_writeData(char data_register, char data)
{
	char dataArr[4] = {data, data, data, data};
	
	MAX7219_writeDataArr(data_register, dataArr);
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

void WriteDisplay(char displayData[])
{
	//data0 is left most display
	//left most pixel is MSB of first byte
	for(int i = 0; i < 8; i++)
	{
		MAX7219_writeDataArr(i+1, displayData+i*4);	
	}
}

void ClearDisplay(char displayData[])
{
	for(int i = 0; i < 32; i++)
	{
		displayData[i] = 0;
	}
}

void SetPixel(char x, char y, char displayData[])
{
	int8_t index = (x >> 3) + y * 4;
				
	char temp = displayData[(int)index];
	char bitPos = 7 - (x & 0x07);
	temp |= 1 << bitPos;
	displayData[index] = temp;			
}

void ClearPixel(char x, char y, char displayData[])
{
	int8_t index = (x >> 3) + y * 4;
	
	char temp = displayData[(int)index];
	char bitPos = 7 - (x & 0x07);
	temp &= ~(1 << bitPos);
	displayData[index] = temp;
}

bool GetPixel(char x, char y, char displayData[])
{
	int8_t index = (x >> 3) + y * 4;
	
	char temp = displayData[(int)index];
	temp &= 1 << (7 - (x & 0x07));
	return temp;
}

#endif /* DISPLAYHELPER_H_ */