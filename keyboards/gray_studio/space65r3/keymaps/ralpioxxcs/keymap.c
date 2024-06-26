// Copyright 2022 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0
#include "keycodes.h"
#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#include "audio.h"
#include "quantum/audio/song_list.h"
#include "quantum/audio/musical_notes.h"
#endif

#include "process_tap_dance.h"

#ifdef AUDIO_ENABLE
float mySong[][2] = SONG(QWERTY_SOUND);
#endif

enum custom_keycodes {
    PLAY_AUDIO = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PLAY_AUDIO:
      if (record->event.pressed) {
        send_string("play audio");
#ifdef AUDIO_ENABLE
        PLAY_SONG(mySong);
#endif
      }
      return false;
    default:
      return true;
  }

}

enum {
    TD_QQ,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_QQ] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_3),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───────────┬──────┬───┬───┬───┬───┬───┬───┬──────┬───────┬───┬───┬──────┬──────┐
//    │ `esc │     1     │  2   │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │  9   │   0   │ - │ = │ bspc │ del  │
//    ├──────┼───────────┼──────┼───┼───┼───┼───┼───┼───┼──────┼───────┼───┼───┼──────┼──────┤
//    │ tab  │ TD(TD_QQ) │  w   │ e │ r │ t │ y │ u │ i │  o   │   p   │ [ │ ] │ bsls │ home │
//    ├──────┼───────────┼──────┼───┼───┼───┼───┼───┼───┼──────┼───────┼───┼───┴──────┼──────┤
//    │ caps │     a     │  s   │ d │ f │ g │ h │ j │ k │  l   │   ;   │ ' │   ent    │ pgup │
//    ├──────┼───────────┼──────┼───┼───┼───┼───┼───┼───┼──────┼───────┼───┴───┬──────┼──────┤
//    │ lsft │     z     │  x   │ c │ v │ b │ n │ m │ , │  .   │   /   │ rsft  │     │ pgdn │
//    ├──────┼───────────┼──────┼───┴───┼───┴───┼───┴───┼──────┼───────┼───┬───┼──────┼──────┤
//    │ lctl │          │ lalt │       │ spcb  │       │ ralt │ MO(1) │   │  │     │     │
//    └──────┴───────────┴──────┘       └───────┘       └──────┴───────┘   └───┴──────┴──────┘
[0] = LAYOUT_65_ansi_blocker(
  QK_GESC , KC_1      , KC_2    , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8    , KC_9    , KC_0    , KC_MINUS , KC_EQUAL , KC_BSPC , KC_DEL ,
  KC_TAB  , TD(TD_QQ) , KC_W    , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I    , KC_O    , KC_P    , KC_LBRC  , KC_RBRC  , KC_BSLS , KC_HOME,
  KC_CAPS , KC_A      , KC_S    , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K    , KC_L    , KC_SCLN , KC_QUOTE ,             KC_ENT , KC_PGUP,
  KC_LSFT , KC_Z      , KC_X    , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM , KC_DOT  , KC_SLSH ,             KC_RSFT , KC_UP   , KC_PGDN,
  KC_LCTL , KC_LGUI   , KC_LALT ,                 KC_SPC    ,                  KC_RALT , MO(1)   ,            KC_LEFT  , KC_DOWN , KC_RGHT
),

//    ┌──────┬────────────────────┬─────────────────────┬──────────────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────┬─────┬─────┬─────┬─────┐
//    │ boot │         f1         │         f2          │        f3        │   f4    │   f5    │   f6    │   f7    │   f8    │ f9  │ f10 │ f11 │ f12 │     │     │
//    ├──────┼────────────────────┼─────────────────────┼──────────────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │      │      RGB_TOG       │       RGB_MOD       │     RGB_HUI      │ RGB_HUD │ RGB_SAI │ RGB_SAD │ RGB_VAI │ RGB_VAD │     │     │     │     │     │     │
//    ├──────┼────────────────────┼─────────────────────┼──────────────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┼─────┼─────┴─────┼─────┤
//    │      │   RGB_MODE_PLAIN   │  RGB_MODE_BREATHE   │ RGB_MODE_RAINBOW │         │         │         │         │         │     │     │     │           │     │
//    ├──────┼────────────────────┼─────────────────────┼──────────────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┼─────┴─────┬─────┼─────┤
//    │      │    QK_AUDIO_ON     │    QK_AUDIO_OFF     │    PLAY_AUDIO    │         │         │ NK_TOGG │         │         │     │     │           │     │     │
//    ├──────┼────────────────────┼─────────────────────┼──────────────────┴─────────┼─────────┴─────────┼─────────┴─────────┼─────┼─────┼─────┬─────┼─────┼─────┤
//    │      │ QK_AUDIO_CLICKY_ON │ QK_AUDIO_CLICKY_OFF │                            │QK_AUDIO_CLICKY_boot│                   │     │     │     │     │     │     │
//    └──────┴────────────────────┴─────────────────────┘                            └───────────────────┘                   └─────┴─────┘     └─────┴─────┴─────┘
[1] = LAYOUT_65_ansi_blocker(
  QK_BOOT , KC_F1              , KC_F2               , KC_F3            , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______,
  _______ , RGB_TOG            , RGB_MOD             , RGB_HUI          , RGB_HUD , RGB_SAI , RGB_SAD , RGB_VAI , RGB_VAD , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , RGB_MODE_PLAIN     , RGB_MODE_BREATHE    , RGB_MODE_RAINBOW , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,           _______ , _______,
  _______ , QK_AUDIO_ON        , QK_AUDIO_OFF        , PLAY_AUDIO       , _______ , _______ , NK_TOGG , _______ , _______ , _______ , _______ ,           _______ , _______ , _______,
  _______ , QK_AUDIO_CLICKY_ON , QK_AUDIO_CLICKY_OFF ,                              QK_AUDIO_CLICKY_RESET ,                     _______ , _______ ,           _______ , _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
//    │     │     │     │     │     │     │     │     │     │     │     │     │           │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┬─────┼─────┤
//    │     │     │     │     │     │     │     │     │     │     │     │           │     │     │
//    ├─────┼─────┼─────┼─────┴─────┼─────┴─────┼─────┴─────┼─────┼─────┼─────┬─────┼─────┼─────┤
//    │     │     │     │           │           │           │     │     │     │     │     │     │
//    └─────┴─────┴─────┘           └───────────┘           └─────┴─────┘     └─────┴─────┴─────┘
[2] = LAYOUT_65_ansi_blocker(
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,           _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______,
  _______ , _______ , _______ ,                          _______      ,                     _______ , _______ ,           _______ , _______ , _______
)
};
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,2, HSV_WHITE}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
