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
	void Set(int8_t x, int8_t y, char displayData[])
	{
		if(x >= 0 && x < 32 && y >= 0 && y < 8)
		{
			SetPixel(x, 7-y, displayData);	
		}
	}
	bool Get(char x, char y, char displayData[])
	{
		if(x >= 0 && x < 32 && y >= 0 && y < 8)
		{	
			return GetPixel(x, 7-y, displayData);
		}
		
		return false;
	}
	void DrawPlayer(char x, char y, char displayData[])
	{
		Set(x-1,   y,   displayData);
		Set(x+1,   y,   displayData);
		Set(x,   y+1, displayData);
		Set(x,   y+2, displayData);
		Set(x,   y+3, displayData);
		Set(x-1,   y+2, displayData);
		Set(x+1,   y+2, displayData);
	}
	bool CheckPlayer(char x, char y, char displayData[])
	{
		return Get(x-1,   y,   displayData) ||
		Get(x+1,   y,   displayData) ||
		Get(x,   y+1, displayData) ||
		Get(x,   y+2, displayData) ||
		Get(x,   y+3, displayData) ||
		Get(x-1,   y+2, displayData) ||
		Get(x+1,   y+2, displayData);
	}
	void DrawEnemy(char x, char y, char displayData[])
	{
		Set(x+1,   y,   displayData);
		Set(x+1,   y+1,   displayData);
		Set(x,     y+1, displayData);
		Set(x-1,   y+1, displayData);
		Set(x-1,   y, displayData);
		Set(x-2,   y+2, displayData);
	}

	void CheckJoystick(uint8_t debounce[])
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
	uint16_t fasterCounter;
	uint8_t tickLength;
	int8_t playerX;
	int16_t playerY;
	int8_t playerVelocityY;
	uint8_t debounce[4] = {0};
	bool isGameOver;
	int8_t obstacle1;
	
	public:
	virtual void load()
	{
		isGameOver = false;
		counter = 0;
		fasterCounter = 0;
		tickLength = 25;
		playerX = 4;
		playerY = 0;
		playerVelocityY = 0;
		
		obstacle1 = 20;
		
				
		debounce[0] = 0;
		debounce[1] = 0;
		debounce[2] = 0;
		debounce[3] = 0;
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
			if(playerY == 0)
			{
				playerVelocityY = 127;
				playJump();
			}
		}
		if(debounce[2] == DEBOUNCE_VALUE)
		{
		
		}
		if(debounce[1] == DEBOUNCE_VALUE)
		{
		
		}
		
		ClearDisplay(displayData);

		// Obstacles
		counter++;
		if(counter >= tickLength)
		{
			counter = 0;
			fasterCounter++;
			if(fasterCounter > 40 && tickLength > 1)
			{
				fasterCounter = 0;
				tickLength--;
			}
			//next tick
			
			obstacle1--;
			if(obstacle1 < -4)
			{
				obstacle1 = 36;
			}
		}
		
		DrawEnemy(obstacle1, 0, displayData);
		
		// Player
		playerY += playerVelocityY;
		if(counter % 3 != 0)
		{
			playerVelocityY -= 1;	
		}
		
		if(playerVelocityY < -120)
		{
			playerVelocityY = -120;
		}
		if(playerY < 0)
		{
			playerY = 0;
			playerVelocityY = 0;
		}
		
		int8_t displayPlayerY = playerY >> 11;
		
		if(CheckPlayer(playerX, displayPlayerY, displayData))
		{
			playGameOver();
			isGameOver = true;
		}
		
		DrawPlayer(playerX, displayPlayerY, displayData);
		
		WriteDisplay(displayData);

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