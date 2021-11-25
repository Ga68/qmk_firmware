// Originally started from Miryoku: https://github.com/manna-harbour/miryoku

#pragma once

#include QMK_KEYBOARD_H

#define _____ KC_TRANSPARENT
#define __x__ KC_NO

#define U_CUT   LCMD(KC_X)
#define U_COPY  LCMD(KC_C)
#define U_PASTE LCMD(KC_V)

#define U_IQUES LSA(KC_SLSH) // ¿

#define U_WD_LEFT RALT(KC_LEFT)
#define U_WD_RGHT RALT(KC_RGHT)
