#pragma once

// TT set to two taps
//#define TAPPING_TOGGLE 2

// tap vs hold time difference
#define TAPPING_TERM 200

// one shot tap settings
#define ONESHOT_TAP_TAGGLE 3
#define ONESHOT_TIMEOUT 1500

#define RGBLIGHT_SLEEP  // allows us to use rgblight_suspend() and rgblight_wakeup() in keymap.c
#define RGBLIGHT_TIMEOUT 900000

// audio features
#ifdef AUDIO_ENABLE
 #define AUDIO_CLICKY
 #define AUDIO_INIT_DELAY
 #define AUDIO_PIN C6
 #define AUDIO_PWM_COMPLEMENTARY_OUTPUT
 #define AUDIO_PWM_DRIVER PWMD1
 #define AUDIO_PWM_CHANNEL 1

 #define AUDIO_ENABLE_TONE_MULTIPLEXING
 #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10

 #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

