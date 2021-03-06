/*
 * DisplayTest.cpp
 *
 * Created: 08/07/2020 09:46:36
 * Author : Jan.Reinhardt
 */ 

#define F_CPU 8000000UL

#define PIN_OC0                    PORTB3

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "DisplayHelper.h"
#include "ModuleInterface.h"
#include "DefaultModule.h"
#include "BatteryModule.h"
#include "TetrisModule.h"
#include "JumpModule.h"
#include "BoxHelper.h"
#include "sound.h"


void init() 
{
	// Button Lights (As Output and Switch Off)
	DDRC = 0xFF;
	PORTC = 0xFF;
	
	// Buttons (Input, PullUp deactivated)
	DDRD = 0x00;
	PORTD = 0x00;
	
	// Joystick & Switches (Pull Ups)
	DDRA = 0x00;
	PORTA = 0b11111110;
	
	DDRB = 0b00000000;
	PORTB = 0b00000111;

	SPI_MasterInit();
	
	initSound();
}

void reset() 
{
	char displayData[32];
	ClearDisplay(displayData);
	
	WriteIntensity(0x00);
	WriteScanLimit(0x07);
	WriteDisplayData(0, 0);
	WriteDisplayData(1, 0);
	WriteDisplayData(2, 0);
	WriteDisplayData(3, 0);
	WriteDisplayData(4, 0);
	WriteDisplayData(5, 0);
	WriteDisplayData(6, 0);
	WriteDisplayData(7, 0);
	WriteNormalMode();

	WriteButton(0, false);
	WriteButton(1, false);
	WriteButton(2, false);
	WriteButton(3, false);
	WriteButton(4, false);
	WriteButton(5, false);
	WriteButton(6, false);
	WriteButton(7, false);
}

int main(void)
{
	init();
	
	sei();
	
	reset();
	
	DefaultModule defaultModule;
	BatteryModule batteryModule;
	TetrisModule tetrisModule;
	JumpModule jumpModule;
	IModule* module = &defaultModule;
	module->load();
	
	char oldSwitches = 0;

	while(1)
	{
		char switches = ReadSwitches();
		if(oldSwitches != switches)
		{
			module->unload();
			
			if(switches == 0b00100000)
			{
				module = &batteryModule;
			}
			else if(switches == 0b00010000)
			{
				module = &tetrisModule;
			}
			else if(switches == 0b00001000)
			{
				module = &jumpModule;
			}
			else
			{
				module = &defaultModule;
			}
			
			reset();
			module->load();
			oldSwitches = switches;
		}
		
		module->update();
	}
}