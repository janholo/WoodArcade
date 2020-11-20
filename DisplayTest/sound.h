/*
 * sound.h
 *
 * Created: 18/11/2020 21:49:45
 *  Author: Jan.Reinhardt
 */ 

#include "waves.h"
#include "musicArrays.h"

#ifndef SOUND_H_
#define SOUND_H_

void initSound()
{
	// TIMER0
	
	// non inverting fast pwm
	// prescaling 1
	TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	
	// Use this value to adjust pwm
	OCR0 = 128;
	
	TIMSK |= (1<<TOIE0);
	
	// Set timer/pwm pin as output (OC0)
	DDRB |= (1<<PIN_OC0);
	
	// TIMER 2
	
	// CTC Mode - 128 prescaler
	TCCR2 = (1<<WGM21)|(1<<CS22)|(1<<CS20);
	
	// CTC Mode - 64 prescaler
	//TCCR2 = (1<<WGM21)|(1<<CS22);
	
	//length of note
	OCR2 = 140;
	
	TIMSK |= (1<<OCIE2);
	
}



uint8_t sineWaveCounter = 0;
uint8_t hullCurveCounter = 0;
uint8_t hullCurveValue = 255;
uint8_t noteCounter = 255;
uint8_t noteCounterMax = sizeof(music_null_count);
const uint8_t* currentNote = nullSound;
uint8_t currentNoteCount = sizeof(nullSound);

const uint8_t** currentMusic = music_null;
uint8_t* currentMusicCount = music_null_count;

// 0 -> Only play current note and then null
// 1 -> Only play current music and then null
// 2 -> Loop music forever
uint8_t mode = 0;

void playTetris()
{
	OCR2 = 60;
	currentMusic = tetris;
	currentMusicCount = tetris_count;
	noteCounter = 0;
	noteCounterMax = sizeof(tetris_count);
	hullCurveCounter = 0;
	mode = 2;
}

void playTune(uint8_t tune)
{
	OCR2 = 140;
	currentMusic = music_whiteKeys;
	currentMusicCount = music_whiteKeys_count;
	noteCounter = tune;
	noteCounterMax = sizeof(music_whiteKeys_count);
	hullCurveCounter = 0;
	mode = 0;
}

void playNull()
{
	OCR2 = 140;
	currentMusic = music_null;
	currentMusicCount = music_null_count;
	noteCounter = 0;
	noteCounterMax = sizeof(music_null_count);
	hullCurveCounter = 0;
	mode = 0;	
}

ISR(TIMER2_COMP_vect)
{
	hullCurveCounter++;
	hullCurveValue = hullCurve[hullCurveCounter];
	
	if(hullCurveCounter == 255)
	{
		if(mode == 0)
		{
			playNull();
		}
		else if (mode == 1)
		{
			// TODO
		}
		else if (mode == 2)
		{
			noteCounter++;
			// TODO - remove call to sizeof(tetris_count)
			if(noteCounter >= noteCounterMax)
			{
				noteCounter = 0;
			}			
		}
	}
	
	currentNote = currentMusic[noteCounter];
	currentNoteCount = currentMusicCount[noteCounter];
}

ISR(TIMER0_OVF_vect)
{
	// Somehow adjust OCR0 here...
	sineWaveCounter++;
	sineWaveCounter = sineWaveCounter % currentNoteCount;
	
	uint8_t waveValue = pgm_read_byte(&(currentNote[sineWaveCounter]));
	uint16_t value = waveValue * hullCurveValue;

	if(noteCounter == 255) {
		OCR0 = 0;
	} 
	else
	{
		OCR0 = value>>8;	
	}
}

#endif /* SOUND_H_ */