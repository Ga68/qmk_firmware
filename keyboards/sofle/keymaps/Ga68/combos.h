#pragma once
#include QMK_KEYBOARD_H

// L/R   Left/Right hand
// B/T/H Bottom/Top/Home row
// 1 = index finger ... 4 = pinky

#define CB_LB1 KC_V
#define CB_LB2 KC_C
#define CB_LB3 KC_X
#define CB_LB4 KC_Z

#define CB_LT1 KC_P
#define CB_LT2 KC_F
#define CB_LT3 KC_W
#define CB_LT4 KC_Q

#define CB_RB1 KC_M
#define CB_RB2 KC_COMMA
#define CB_RB3 KC_DOT
#define CB_RB4 KC_SLASH

#define CB_RT1 KC_L
#define CB_RT2 KC_U
#define CB_RT3 KC_Y
#define CB_RT4 KC_COLON

#define CB_LH1 MT_LG(KC_T)
#define CB_LH2 MT_LS(KC_S)
#define CB_LH3 MT_LA(KC_R)
#define CB_LH4 MT_LC(KC_A)

#define CB_RH1 MT_RG(KC_N)
#define CB_RH2 MT_RS(KC_E)
#define CB_RH3 MT_RA(KC_I)
#define CB_RH4 MT_RC(KC_O)

#define CB_LX0 LT(_NAV, KC_BACKSPACE) // Left thumb home position

#define CB___  COMBO_END

bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record);
