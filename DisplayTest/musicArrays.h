/*
 * musicArrays.h
 *
 * Created: 19/11/2020 22:50:53
 *  Author: Jan.Reinhardt
 */ 


#ifndef MUSICARRAYS_H_
#define MUSICARRAYS_H_

const uint8_t nullSound[] PROGMEM =
{
	0,
	0,
	0,
	0
};

const uint8_t* music_null[] = {
	nullSound
};

uint8_t music_null_count[] = {
	sizeof(nullSound)
};

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

uint8_t music_all_count[] = {
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

const uint8_t* music_whiteKeys[] = {
	sineWave_C3_131,
	sineWave_D3_147,
	sineWave_E3_165,
	sineWave_F3_175,
	sineWave_G3_196,
	sineWave_A3_220,
	sineWave_H3_247,
	sineWave_C4_262
};

uint8_t music_whiteKeys_count[] = {
	sizeof(sineWave_C3_131),
	sizeof(sineWave_D3_147),
	sizeof(sineWave_E3_165),
	sizeof(sineWave_F3_175),
	sizeof(sineWave_G3_196),
	sizeof(sineWave_A3_220),
	sizeof(sineWave_H3_247),
	sizeof(sineWave_C4_262)
};

const uint8_t* music_jump[] = {
	sineWave_C3_131,
	sineWave_E3_165,
	sineWave_G3_196,
};

uint8_t music_jump_count[] = {
	sizeof(sineWave_C3_131),
	sizeof(sineWave_E3_165),
	sizeof(sineWave_G3_196),
};

const uint8_t* music_gameOver[] = {
	sineWave_G3_196,
	sineWave_E3_165,
	sineWave_C3_131,
};

uint8_t music_gameOver_count[] = {
	sizeof(sineWave_G3_196),
	sizeof(sineWave_E3_165),
	sizeof(sineWave_C3_131),
};

const uint8_t* tetris[] = {
	// 1. line
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
	
	// 2. line
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

	// 3. line
	sineWave_E4_330,
	nullSound,
	nullSound,
	nullSound,
	sineWave_C4_262,
	nullSound,
	nullSound,
	nullSound,

	sineWave_D4_294,
	nullSound,
	nullSound,
	nullSound,
	sineWave_H3_247,
	nullSound,
	nullSound,
	nullSound,

	sineWave_C4_262,
	nullSound,
	nullSound,
	nullSound,
	sineWave_A3_220,
	nullSound,
	nullSound,
	nullSound,

	sineWave_Gs3_208,
	nullSound,
	nullSound,
	nullSound,
	nullSound,
	nullSound,
	nullSound,
	nullSound,

	// 4. line
	sineWave_E4_330,
	nullSound,
	nullSound,
	nullSound,
	sineWave_C4_262,
	nullSound,
	nullSound,
	nullSound,

	sineWave_D4_294,
	nullSound,
	nullSound,
	nullSound,
	sineWave_H3_247,
	nullSound,
	nullSound,
	nullSound,

	sineWave_C4_262,
	nullSound,
	sineWave_E4_330,
	nullSound,
	sineWave_A4_440,
	nullSound,
	sineWave_A4_440,
	nullSound,

	sineWave_Gs4_415,
	nullSound,
	nullSound,
	nullSound,
	nullSound,
	nullSound,
	nullSound,
	nullSound,
};

uint8_t tetris_count[] = {
	// 1. line
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
	
	// 2. line
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

	// 3. line
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(sineWave_C4_262),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),

	sizeof(sineWave_D4_294),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(sineWave_H3_247),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),

	sizeof(sineWave_C4_262),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(sineWave_A3_220),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),

	sizeof(sineWave_Gs3_208),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),

	// 4. line
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(sineWave_C4_262),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),

	sizeof(sineWave_D4_294),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(sineWave_H3_247),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),

	sizeof(sineWave_C4_262),
	sizeof(nullSound),
	sizeof(sineWave_E4_330),
	sizeof(nullSound),
	sizeof(sineWave_A4_440),
	sizeof(nullSound),
	sizeof(sineWave_A4_440),
	sizeof(nullSound),

	sizeof(sineWave_Gs4_415),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
	sizeof(nullSound),
};

#endif /* MUSICARRAYS_H_ */