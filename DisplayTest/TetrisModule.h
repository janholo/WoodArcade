/*
 * TetrisModule.h
 *
 * Created: 12/08/2020 22:54:58
 *  Author: Jan.Reinhardt
 */ 


#ifndef TETRISMODULE_H_
#define TETRISMODULE_H_

#define DEBOUNCE_VALUE 8

class TetrisModule: public IModule
{
	private:
	void Set(char x, char y, char displayData[])
	{
		if(x < 8 && y < 32)
		{
			SetPixel(y, 7-x, displayData);
		}
	}
	void Clear(char x, char y, char displayData[])
	{
		if(x < 8 && y < 32)
		{
			ClearPixel(y, 7-x, displayData);
		}
	}	
	bool Get(char x, char y, char displayData[])
	{
		return GetPixel(y, 7-x, displayData);
	}	
	void DrawO(char x, char y, char displayData[])
	{
		Set(x,   y,   displayData);
		Set(x,   y+1, displayData);
		Set(x+1, y,   displayData);
		Set(x+1, y+1, displayData);
	}
	void DrawL(char x, char y, char rotation, char displayData[])
	{
		if(rotation == 0)
		{
			Set(x+1, y,   displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
			Set(x+2, y+2, displayData);				
		}
		else if(rotation == 1)
		{
			Set(x  , y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+2, y+1, displayData);
			Set(x  , y+2, displayData);
		}
		else if(rotation == 2)
		{
			Set(x+1, y,   displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
			Set(x,   y,   displayData);
		}
		else
		{
			Set(x,   y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+2, y+1, displayData);
			Set(x+2, y,   displayData);
		}
	}
	void DrawJ(char x, char y, char rotation, char displayData[])
	{
		if(rotation == 0)
		{
			Set(x+1, y,   displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
			Set(x,   y+2, displayData);
		}
		else if(rotation == 1)
		{
			Set(x,   y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+2, y+1, displayData);
			Set(x,   y,   displayData);
		}
		else if(rotation == 2)
		{
			Set(x+1, y,   displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
			Set(x+2, y,   displayData);
		}
		else
		{
			Set(x,   y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+2, y+1, displayData);
			Set(x+2, y+2, displayData);
		}
	}	
	void DrawI(char x, char y, char rotation, char displayData[])
	{
		if(rotation == 0)
		{
			Set(x+2, y,   displayData);
			Set(x+2, y+1, displayData);
			Set(x+2, y+2, displayData);
			Set(x+2, y+3, displayData);
		}
		else if(rotation == 1)
		{
			Set(x,   y+2, displayData);
			Set(x+1, y+2, displayData);
			Set(x+2, y+2, displayData);
			Set(x+3, y+2, displayData);
		}
		else if(rotation == 2)
		{
			Set(x+1, y,   displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
			Set(x+1, y+3, displayData);
		}
		else
		{
			Set(x,   y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+2, y+1, displayData);
			Set(x+3, y+1, displayData);
		}
	}
	void DrawS(char x, char y, char rotation, char displayData[])
	{
		if(rotation == 0)
		{
			Set(x,   y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y,   displayData);
			Set(x+2, y,   displayData);
		}
		else if(rotation == 1)
		{
			Set(x+1, y,   displayData);
			Set(x+1, y+1, displayData);
			Set(x+2, y+1, displayData);
			Set(x+2, y+2, displayData);
		}
		else if(rotation == 2)
		{
			Set(x,   y+2, displayData);
			Set(x+1, y+2, displayData);
			Set(x+1, y+1, displayData);
			Set(x+2, y+1, displayData);
		}
		else
		{
			Set(x,   y,   displayData);
			Set(x,   y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
		}
	}
	void DrawZ(char x, char y, char rotation, char displayData[])
	{
		if(rotation == 0)
		{
			Set(x+2, y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y,   displayData);
			Set(x,   y,   displayData);
		}
		else if(rotation == 1)
		{
			Set(x+1, y+2, displayData);
			Set(x+1, y+1, displayData);
			Set(x+2, y+1, displayData);
			Set(x+2, y,   displayData);
		}
		else if(rotation == 2)
		{
			Set(x+2, y+2, displayData);
			Set(x+1, y+2, displayData);
			Set(x+1, y+1, displayData);
			Set(x,   y+1, displayData);
		}
		else
		{
			Set(x,   y+2, displayData);
			Set(x,   y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y,   displayData);
		}
	}
	void DrawT(char x, char y, char rotation, char displayData[])
	{
		if(rotation == 0)
		{
			Set(x+2, y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y,   displayData);
			Set(x,   y+1, displayData);
		}
		else if(rotation == 1)
		{
			Set(x+1, y,   displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
			Set(x+2, y+1, displayData);
		}
		else if(rotation == 2)
		{
			Set(x+2, y+1, displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
			Set(x,   y+1, displayData);
		}
		else
		{
			Set(x+1, y,   displayData);
			Set(x+1, y+1, displayData);
			Set(x+1, y+2, displayData);
			Set(x,   y+1, displayData);
		}
	}
	void DrawPiece(char x, char y, char rotation, char type, char displayData[])
	{
		if(type == 0)
		{
			DrawO(x,y,displayData);
		}
		else if(type == 1)
		{
			DrawL(x,y,rotation,displayData);
		}
		else if(type == 2)
		{
			DrawJ(x,y,rotation,displayData);
		}
		else if(type == 3)
		{
			DrawS(x,y,rotation,displayData);
		}
		else if(type == 4)
		{
			DrawZ(x,y,rotation,displayData);
		}
		else if(type == 5)
		{
			DrawI(x,y,rotation,displayData);
		}
		else
		{
			DrawT(x,y,rotation,displayData);
		}	
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
	bool IsGameOver() 
	{
		//If first row is set in playing field -> game over
		for(int8_t i = 0; i < 8; i++)
		{
			if(Get(i, 0, playingField))
			{
				return true;
			}
		}
		
		return false;
	}
	void GetExtendsOfCurrentPiece(char extends[])
	{
		switch(pieceType)
		{
			case 0:
				extends[0] = 0;
				extends[1] = 1;
				extends[2] = 1;
				return;
			case 1:
				switch(pieceRotation)
				{
					case 0:
						extends[0] = 1;
						extends[1] = 2;
						extends[2] = 2;
						return;
					case 1:
						extends[0] = 0;
						extends[1] = 2;
						extends[2] = 2;
						return;
					case 2:
						extends[0] = 0;
						extends[1] = 1;
						extends[2] = 2;
						return;
					case 3:
						extends[0] = 0;
						extends[1] = 2;
						extends[2] = 1;
						return;
				}
			case 2:
				switch(pieceRotation)
				{
					case 0:
						extends[0] = 0;
						extends[1] = 1;
						extends[2] = 2;
						return;
					case 1:
						extends[0] = 0;
						extends[1] = 2;
						extends[2] = 1;
						return;
					case 2:
						extends[0] = 1;
						extends[1] = 2;
						extends[2] = 2;
						return;
					case 3:
						extends[0] = 0;
						extends[1] = 2;
						extends[2] = 2;
						return;
				}			
			case 3:
			case 4:
				switch(pieceRotation)
				{
					case 0:
						extends[0] = 0;
						extends[1] = 2;
						extends[2] = 1;
						return;
					case 1:
						extends[0] = 1;
						extends[1] = 2;
						extends[2] = 2;
						return;
					case 2:
						extends[0] = 0;
						extends[1] = 2;
						extends[2] = 2;
						return;
					case 3:
						extends[0] = 0;
						extends[1] = 1;
						extends[2] = 2;
						return;
				}			
			case 5:
				switch(pieceRotation)
				{
					case 0:
						extends[0] = 2;
						extends[1] = 2;
						extends[2] = 3;
						return;
					case 1:
						extends[0] = 0;
						extends[1] = 3;
						extends[2] = 2;
						return;
					case 2:
						extends[0] = 1;
						extends[1] = 1;
						extends[2] = 3;
						return;
					case 3:
						extends[0] = 0;
						extends[1] = 3;
						extends[2] = 1;
						return;
				}
			case 6:
				switch(pieceRotation)
				{
					case 0:
						extends[0] = 0;
						extends[1] = 2;
						extends[2] = 1;
						return;
					case 1:
						extends[0] = 1;
						extends[1] = 2;
						extends[2] = 2;
						return;
					case 2:
						extends[0] = 0;
						extends[1] = 2;
						extends[2] = 2;
						return;
					case 3:
						extends[0] = 0;
						extends[1] = 1;
						extends[2] = 2;
						return;
				}
		}
	}
	bool HasCollision(char data1[], char data2[])
	{
		for(int8_t i = 0; i < 32; i++)
		{
			if(data1[i] & data2[i])
			{
				return true;
			}
		}
		
		char extends[3] = {0};
		GetExtendsOfCurrentPiece(extends);
		
		if(pieceX + extends[0] < 0)
		{
			return true;
		}
		if(pieceX + extends[1] >= 8)
		{
			return true;
		}
		if(pieceY + extends[2] >= 32)
		{
			return true;
		}
		
		return false;
	}
	bool DoRemoveAnimation() 
	{
		if(removeCounter > 0)
		{
			removeCounter++;
			
			for(int8_t row = rowToRemove; row >= 1; row--)
			{
				for(int8_t i = 0; i < 8; i++)
				{
					if(Get(i, row-1, playingField))
					{
						Set(i, row, playingField);
					}
					else
					{
						Clear(i, row, playingField);
					}
				}
			}
			
			removeCounter = 0;
			
			return true;
		}
		
		for(int8_t outer = 0; outer < 4; outer++)
		{
			char combined = 0xFF;
			for(int8_t i = 0; i < 8; i++)
			{
				combined &= playingField[i*4 + outer];
			}
			
			if(combined)
			{
				//find first 1 bit
				for(int8_t shift = 0; shift < 8; shift++)
				{
					char temp = (combined >> shift) & 1;
					if(temp)
					{
						rowToRemove = (outer + 1) * 8 - shift - 1;
						removeCounter = 1;
						return true;
					}
				}				
			}
		}
		
		return false;
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
		
		if(DoRemoveAnimation())
		{
			return;
		}
		
		char oldPieceRotation = pieceRotation;
		char oldPieceX = pieceX;
		char oldPieceY = pieceY;
		
		char displayData[32] = {0};
		
		CheckJoystick(debounce);
		
		if(debounce[3] == DEBOUNCE_VALUE)
		{
			//turn
			pieceRotation = (pieceRotation + 1) % 4;
		}
		
		if(debounce[0] == DEBOUNCE_VALUE)
		{
			pieceX++;
		}
		if(debounce[2] == DEBOUNCE_VALUE)
		{
			pieceX--;
		}
		
		DrawPiece(pieceX, pieceY, pieceRotation, pieceType, displayData);
		
		// Check collision and revert piece on collision
		if(HasCollision(displayData, playingField))
		{
			// Revert to old position
			pieceRotation = oldPieceRotation;
			pieceX = oldPieceX;
			pieceY = oldPieceY;
		}
		
		ClearDisplay(displayData);

		if(debounce[1] == DEBOUNCE_VALUE)
		{
			pieceY++;
		}
		counter++;
		if(counter > 512)
		{
			counter = 0;
			//next tick
			
			pieceY++;
		}
		
		DrawPiece(pieceX, pieceY, pieceRotation, pieceType, displayData);
		
		//Check for collision with playingField and stick piece on collision
		if(HasCollision(displayData, playingField))
		{
			// Add piece in old position to playingField
			DrawPiece(oldPieceX, oldPieceY, oldPieceRotation, pieceType, playingField);
			
			// Check Game Over
			isGameOver = IsGameOver();
			
			// new piece
			pieceType = (pieceX + pieceY + pieceRotation) % 7;
			pieceRotation = 0;
			pieceX = 2;
			pieceY = 0;	
		}
		else
		{
			for(int8_t i = 0; i < 32; i++)
			{
				displayData[i] |= playingField[i];
			}
		
			WriteDisplay(displayData);			
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