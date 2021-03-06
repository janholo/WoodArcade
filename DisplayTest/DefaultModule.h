/*
 * DefaultModule.h
 *
 * Created: 10/08/2020 22:27:29
 *  Author: Jan.Reinhardt
 */ 

#include "BoxHelper.h"
#include "sound.h"

#ifndef DEFAULTMODULE_H_
#define DEFAULTMODULE_H_

#define SHIFT 6

class DefaultModule: public IModule {
	private:
		int16_t x;
		int16_t y;
		char displayData[32];
		bool lastButtons[8];
	public:
		virtual void load() 
		{
			x = 15 << SHIFT;
			y = 3 << SHIFT;
			ClearDisplay(displayData);
		}
		virtual void update() 
		{
			
			x += ReadJoystickX();
			if(x < 0) x = 0;
			if(x > (30 << SHIFT)) x = 30 << SHIFT;
			y -= ReadJoystickY();
			if(y < 0) y = 0;
			if(y > (6 << SHIFT)) y = 6 << SHIFT;

			ClearDisplay(displayData);
			
			int realX = x >> SHIFT;
			int realY = y >> SHIFT;

			SetPixel(realX, realY, displayData);
			SetPixel(realX, realY + 1, displayData);
			SetPixel(realX + 1, realY, displayData);
			SetPixel(realX + 1, realY + 1, displayData);
			
			WriteDisplay(displayData);

			for(int j = 0; j < 8; j++)
			{
				bool b = ReadButton(j);
				
				if(!lastButtons[j] && b)
				{
					playTune(j);
				}
				lastButtons[j] = b;
				
				WriteButton(j, b);
			}
		}
		
		virtual void unload() 
		{
			
		}
};



#endif /* DEFAULTMODULE_H_ */