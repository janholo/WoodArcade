/*
 * BatteryModule.h
 *
 * Created: 10/08/2020 23:35:39
 *  Author: Jan.Reinhardt
 */ 


#ifndef BATTERYMODULE_H_
#define BATTERYMODULE_H_

class BatteryModule: public IModule 
{
	private:
	char backgroundData[32] = 
	{
		0b01111111, 0xFF, 0xFF, 0xFF,
		0b01000000, 0x00, 0x00, 0x01,
		0b11000000, 0x00, 0x00, 0x01,
		0b10000000, 0x00, 0x00, 0x01,
		0b10000000, 0x00, 0x00, 0x01,
		0b11000000, 0x00, 0x00, 0x01,
		0b01000000, 0x00, 0x00, 0x01,
		0b01111111, 0xFF, 0xFF, 0xFF
	};
	void AddBatteryLevel(char level, char displayData[])
	{
		char xMax = 33 - 4*level;
		char xMin = 31 - 4*level;
		
		for(char x = xMin; x <= xMax; x++)
		{
			for(char y = 2; y <= 5; y++)
			{
				SetPixel(x, y, displayData);
			}
		}
	}
	uint16_t ReadBatteryValue()
	{
		int16_t accumulatedValue = 0;
		
		for(int i = 0; i < 16; i++)
		{
			ADCSRA |= (1 << ADSC);
		
			while(ADCSRA & (1 << ADSC))
			{
				// Wait for conversion to complete
			}
			
			accumulatedValue += ADC;
		}
						
		return (accumulatedValue >> 4);
	}
	char ReadBatteryLevel()
	{
		// Level 0 ... 7
		
		//Vref = 9.95V
		//Full = 2*4.0V = 8.0V => 823
		//Low  = 2*3.4V = 6.8V => 700
				
		// 123 Schritte
		
			
		uint16_t value = ReadBatteryValue();
		
		if(value <= 700)
		{
			return 0;
		}
		else if(value < 820)
		{
			char diff = value - 700;
			return (diff / 20) + 1;
		}
		else
		{
			//Value >= 820
			return 7;
		}
	}
	public:
	virtual void load()
	{
		// REFS0 = 1, REFS1 = 0 => Use AVCC as Voltage Reference
		// ADLAR = 0 => Right Adjusted result
		// MUXn = 0 => Select ADC0
		ADMUX = (0 << MUX0) | (0 << MUX1) | (0 << MUX2) | (1 << REFS0);
		
		// ADEN = 1 => enable ADC
		// ADSC = 1 => Start conversion
		// ADATE = 0 => Auto Trigger disabled
		// ADIF => read only, is set on interupt
		// ADIE = 0 => disable interupts
		// ADPS0 = 0, ADPS1 = 1, ADPS2 = 1 => Prscaler (8000000 / 64 = 125.000Hz)
		ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADPS2) | (1 << ADPS1);
		
		// SFIOR no need to write this register
	}
	virtual void update()
	{
		char displayData[32] = {0};
		
		char level = ReadBatteryLevel();
		
		for(int i = 1; i <= level; i++)
		{
			AddBatteryLevel(i, displayData);	
		}
			
		for(int i = 0; i < 32; i++)
		{
			displayData[i] |= backgroundData[i];
		}
	
		WriteDisplay(displayData);

		for(int j = 0; j < 8; j++)
		{
			WriteButton(j, ReadButton(j));
		}
	}
	
	virtual void unload()
	{
		// Disable ADC
		ADCSRA = 0x00;
	}
};



#endif /* BATTERYMODULE_H_ */