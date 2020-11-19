/*
 * TetrisModule.h
 *
 * Created: 12/08/2020 22:54:58
 *  Author: Jan.Reinhardt
 */ 


#ifndef JUMPMODULE_H_
#define JUMPMODULE_H_

#define DEBOUNCE_VALUE 8

class JumpModule: public IModule
{
	private:
	void DrawPlayer(char x, char y, char displayData[])
	{
		SetPixel(x,   y,   displayData);
		SetPixel(x,   y+1, displayData);
		SetPixel(x+1, y,   displayData);
		SetPixel(x+1, y+1, displayData);
	}

	void CheckJoystick(char debounce[])
	{
		int8_t x = ReadJoystickX();
		int8_t y = ReadJoystickY();
		if(x == 1)
		{
			debounce[1]++;
			debounce[3] = 0;
			
			if(debounce[1] > 30)
			{
				debounce[1] = 0;
			}
		}
		else if(x == -1)
		{
			debounce[3]++;
			debounce[1] = 0;
			
			if(debounce[3] > 100)
			{
				debounce[3] = 0;
			}
		}
		else
		{
			debounce[1] = 0;
			debounce[3] = 0;
		}
		if(y == 1)
		{
			debounce[0]++;
			debounce[2] = 0;
			
			if(debounce[0] > 50)
			{
				debounce[0] = 0;
			}
		}
		else if(y == -1)
		{
			debounce[2]++;
			debounce[0] = 0;
			
			if(debounce[2] > 50)
			{
				debounce[2] = 0;
			}			
		}
		else
		{
			debounce[0] = 0;
			debounce[2] = 0;
		}
	}
	uint16_t counter;
	char playingField[32] = {0};
	char pieceType;
	char pieceRotation;
	int8_t pieceX;
	char pieceY;
	char debounce[4] = {0};
	bool isGameOver;
	char rowToRemove;
	int16_t removeCounter;

	public:
	virtual void load()
	{
		isGameOver = false;
		counter = 0;
		ClearDisplay(playingField);
		pieceType = 0;
		pieceRotation = 0;
		pieceX = 2;
		pieceY = 0;
		debounce[0] = 0;
		debounce[1] = 0;
		debounce[2] = 0;
		debounce[3] = 0;
		removeCounter = 0;
	}
	virtual void update()
	{
		if(isGameOver)
		{
			return;
		}
		
		char displayData[32] = {0};
		
		CheckJoystick(debounce);
		
		if(debounce[3] == DEBOUNCE_VALUE)
		{
		}
		if(debounce[0] == DEBOUNCE_VALUE)
		{
		
		}
		if(debounce[2] == DEBOUNCE_VALUE)
		{
		
		}
		if(debounce[1] == DEBOUNCE_VALUE)
		{
		
		}
		
		ClearDisplay(displayData);

		
		counter++;
		if(counter > 512)
		{
			counter = 0;
			//next tick
			

		}
		

		for(int8_t j = 0; j < 8; j++)
		{
			WriteButton(j, ReadButton(j));
		}
	}
	
	virtual void unload()
	{
	}
};

#endif /* TETRISMODULE_H_ */