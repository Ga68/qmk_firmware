// Originally started from Miryoku: https://github.com/manna-harbour/miryoku

#pragma once

#include QMK_KEYBOARD_H

#define ____ KC_NO
#define ___  KC_NO

#define U_REDO  SCMD(KC_Z)
#define U_PASTE LCMD(KC_V)
#define U_COPY  LCMD(KC_C)
#define U_CUT   LCMD(KC_X)
#define U_UNDO  LCMD(KC_Z)

#define U_INVQUS LSA(KC_SLSH) // ¿
