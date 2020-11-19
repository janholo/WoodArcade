/*
 * BoxHelper.h
 *
 * Created: 10/08/2020 22:38:20
 *  Author: Jan.Reinhardt
 */ 


#ifndef BOXHELPER_H_
#define BOXHELPER_H_

bool ReadButton(char num)
{
	char mapping[] = {6,7,5,4,2,3,0,1};
	char mapped = mapping[(int)num];

	return (PIND >> mapped) & 1U;
}

void WriteButton(char num, bool val)
{
	char mapping[] = {6,7,5,4,2,3,0,1};
	char mapped = mapping[(int)num];
	
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

char ReadSwitches()
{
	char val = 0;
	for(int i = 0; i < 6; i++)
	{
		val = val << 1;	
		val |= ReadSwitch(i);	
	}
	return val;
}

int8_t ReadJoystickX()
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

int8_t ReadJoystickY()
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


#endif /* BOXHELPER_H_ */