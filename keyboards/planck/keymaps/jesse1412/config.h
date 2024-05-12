#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

/*
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
*/
#endif

#define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 1

#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_MOVE_DELTA 8
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_DECELERATED_SPEED 250

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
/*
#define MIDI_BASIC
*/
/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
/*
#define ENCODER_RESOLUTION 4
*/

