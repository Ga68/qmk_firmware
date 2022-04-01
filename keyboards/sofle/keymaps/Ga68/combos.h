#pragma once
#include QMK_KEYBOARD_H

// L/R Left/Right hand
// B/T Bottom/Top row
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
#define CB_RT4 KC_SEMICOLON

#define CB_X_ COMBO_END

bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record);
