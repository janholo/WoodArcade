/*
 * sound.h
 *
 * Created: 18/11/2020 21:49:45
 *  Author: Jan.Reinhardt
 */ 

#include "waves.h"

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
	OCR2 = 60;
	
	TIMSK |= (1<<OCIE2);
	
}

const uint8_t* music_all[] = {
	sineWave_H2_123,
	sineWave_C3_131,
	sineWave_Cs3_139,
	sineWave_D3_147,
	sineWave_Ds3_156,
	sineWave_E3_165,
	sineWave_F3_175,
	sineWave_Fs3_185,
	sineWave_G3_196,
	sineWave_Gs3_208,
	sineWave_A3_220,
	sineWave_As3_233,
	sineWave_H3_247,
	sineWave_C4_262,
	sineWave_Cs4_277,
	sineWave_D4_294,
	sineWave_Ds4_311,
	sineWave_E4_330,
	sineWave_F4_349,
	sineWave_Fs4_370,
	sineWave_G4_392,
	sineWave_Gs4_415,
	sineWave_A4_440,
	sineWave_As4_466,
	sineWave_H4_494,
	sineWave_C5_523,
};

uint8_t music_count_all[] = {
	sizeof(sineWave_H2_123),
	sizeof(sineWave_C3_131),
	sizeof(sineWave_Cs3_139),
	sizeof(sineWave_D3_147),
	sizeof(sineWave_Ds3_156),
	sizeof(sineWave_E3_165),
	sizeof(sineWave_F3_175),
	sizeof(sineWave_Fs3_185),
	sizeof(sineWave_G3_196),
	sizeof(sineWave_Gs3_208),
	sizeof(sineWave_A3_220),
	sizeof(sineWave_As3_233),
	sizeof(sineWave_H3_247),
	sizeof(sineWave_C4_262),
	sizeof(sineWave_Cs4_277),
	sizeof(sineWave_D4_294),
	sizeof(sineWave_Ds4_311),
	sizeof(sineWave_E4_330),
	sizeof(sineWave_F4_349),
	sizeof(sineWave_Fs4_370),
	sizeof(sineWave_G4_392),
	sizeof(sineWave_Gs4_415),
	sizeof(sineWave_A4_440),
	sizeof(sineWave_As4_466),
	sizeof(sineWave_H4_494),
	sizeof(sineWave_C5_523),
};

const uint8_t* music[] = {
	sineWave_C3_131,
	//sineWave_Cs3_139,
	sineWave_D3_147,
	//sineWave_Ds3_156,
	sineWave_E3_165,
	sineWave_F3_175,
	//sineWave_Fs3_185,
	sineWave_G3_196,
	//sineWave_Gs3_208,
	sineWave_A3_220,
	//sineWave_As3_233,
	sineWave_H3_247,
	sineWave_C4_262
};

uint8_t music_count[] = {
	sizeof(sineWave_C3_131),
	//sizeof(sineWave_Cs3_139),
	sizeof(sineWave_D3_147),
	//sizeof(sineWave_Ds3_156),
	sizeof(sineWave_E3_165),
	sizeof(sineWave_F3_175),
	//sizeof(sineWave_Fs3_185),
	sizeof(sineWave_G3_196),
	//sizeof(sineWave_Gs3_208),
	sizeof(sineWave_A3_220),
	//sizeof(sineWave_As3_233),
	sizeof(sineWave_H3_247),
	sizeof(sineWave_C4_262)
};

const uint8_t nullSound[] PROGMEM =
{
	0,
	0,
	0,
	0
};

const uint8_t* tetris[] = {
	sineWave_E4_330,
	nullSound,
	sineWave_H3_247,
	sineWave_C4_262,
	sineWave_D4_294,
	nullSound,
	sineWave_C4_262,
	sineWave_H3_247,
	
	sineWave_A3_220,
	nullSound,
	sineWave_A3_220,
	sineWave_C4_262,
	sineWave_E4_330,
	nullSound,
	sineWave_D4_294,
	sineWave_C4_262,
	
	sineWave_H3_247,
	nullSound,
	sineWave_H3_247,
	sineWave_C4_262,
	sineWave_D4_294,
	nullSound,
	sineWave_E4_330,
	nullSound,
	
	sineWave_C4_262,
	nullSound,
	sineWave_A3_220,
	nullSound,
	sineWave_A3_220,
	nullSound,
	nullSound,
	nullSound,
	
	
	nullSound,
	sineWave_D4_294,
	nullSound,
	sineWave_F4_349,
	sineWave_A4_440,
	nullSound,
	sineWave_G4_392,
	sineWave_F4_349,
	
	sineWave_E4_330,
	nullSound,
	nullSound,
	sineWave_C4_262,
	sineWave_E4_330,
	nullSound,
	sineWave_D4_294,
	sineWave_C4_262,
	
	sineWave_H3_247,
	nullSound,
	sineWave_H3_247,
	sineWave_C4_262,
	sineWave_D4_294,
	nullSound,
	sineWave_E4_330,
	nullSound,
	
	sineWave_C4_262,
	nullSound,
	sineWave_A3_220,
	nullSound,
	sineWave_A3_220,
	nullSound,
	nullSound,
	nullSound,
};

const uint8_t tetris_count[] = {
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	sizeof(sineWave_H3_247),
	sizeof(sineWave_C4_262),
	sizeof(sineWave_D4_294),
	sizeof(nullSound),
	sizeof(sineWave_C4_262),
	sizeof(sineWave_H3_247),
	
	sizeof(sineWave_A3_220),
	sizeof(nullSound),
	sizeof(sineWave_A3_220),
	sizeof(sineWave_C4_262),
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	sizeof(sineWave_D4_294),
	sizeof(sineWave_C4_262),
	
	sizeof(sineWave_H3_247),
	sizeof(nullSound),
	sizeof(sineWave_H3_247),
	sizeof(sineWave_C4_262),
	sizeof(sineWave_D4_294),
	sizeof(nullSound),
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	
	sizeof(sineWave_C4_262),
	sizeof(nullSound),
	sizeof(sineWave_A3_220),
	sizeof(nullSound),
	sizeof(sineWave_A3_220),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	
	
	sizeof(nullSound),
	sizeof(sineWave_D4_294),
	sizeof(nullSound),
	sizeof(sineWave_F4_349),
	sizeof(sineWave_A4_440),
	sizeof(nullSound),
	sizeof(sineWave_G4_392),
	sizeof(sineWave_F4_349),
	
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(sineWave_C4_262),
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	sizeof(sineWave_D4_294),
	sizeof(sineWave_C4_262),
	
	sizeof(sineWave_H3_247),
	sizeof(nullSound),
	sizeof(sineWave_H3_247),
	sizeof(sineWave_C4_262),
	sizeof(sineWave_D4_294),
	sizeof(nullSound),
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	
	sizeof(sineWave_C4_262),
	sizeof(nullSound),
	sizeof(sineWave_A3_220),
	sizeof(nullSound),
	sizeof(sineWave_A3_220),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
};


uint8_t waveCounter = 0;
uint8_t hullCurveCounter = 0;
uint8_t hullCurveValue = 255;
uint8_t noteCounter = 255;
const uint8_t* currentNote = nullSound;
uint8_t currentNoteCount = sizeof(nullSound);

ISR(TIMER2_COMP_vect)
{
	hullCurveCounter++;
	hullCurveValue = hullCurve[hullCurveCounter];
	
	if(hullCurveCounter == 255)
	{
		noteCounter++;
		if(noteCounter >= sizeof(tetris_count) >> 1)
		{
			noteCounter = 0;
		}
	}
	

	//
	//if(hullCurveCounter == 255) {
		//noteCounter = 255;
	//}
	
	currentNoteCount = tetris_count[noteCounter];
	currentNote = tetris[noteCounter];
}

ISR(TIMER0_OVF_vect)
{
	// Somehow adjust OCR0 here...
	waveCounter++;
	waveCounter = waveCounter % currentNoteCount;
	
	uint8_t waveValue = pgm_read_byte(&(currentNote[waveCounter]));
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