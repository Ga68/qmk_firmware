#pragma once
#include QMK_KEYBOARD_H

#define SHORT_COMBO_TERM (0.8 * COMBO_TERM)
#define LONG_COMBO_TERM  (2.3 * COMBO_TERM)

// L/R   Left/Right hand
// B/T/H Bottom/Top/Home row
// 1 = index finger ... 4 = pinky

#define CB_LB0 KC_B
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

#define CB_LH0 KC_D
#define CB_LH1 MT_LG(KC_T)
#define CB_LH2 MT_LS(KC_S)
#define CB_LH3 MT_LA(KC_R)
#define CB_LH4 MT_LC(KC_A)

#define CB_RH0 KC_H
#define CB_RH1 MT_RG(KC_N)
#define CB_RH2 MT_RS(KC_E)
#define CB_RH3 MT_RA(KC_I)
#define CB_RH4 MT_RC(KC_O)

// "Pollex" is the medical term for "thumb", since T, B, and H would
// be confusing (for top, bottom, and home)
#define CB_LPR LT(_MOUSE, KC_TAB)

#define CB___  COMBO_END

bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record);
