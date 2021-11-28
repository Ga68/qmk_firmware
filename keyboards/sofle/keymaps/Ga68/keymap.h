// Originally started from Miryoku: https://github.com/manna-harbour/miryoku

#pragma once

#include QMK_KEYBOARD_H

// -----------------
// --- Verbosity ---
// -----------------
// Some more verbose keycode names (aliases), simply as a personal preference for legibility when
// space isn't the primary concern.

#define KC_BACKSPACE           KC_BSPACE
#define KC_SEMICOLON           KC_SCOLON
#define KC_BACKSLASH           KC_BSLASH
#define KC_PERIOD              KC_DOT

// Allow for "brace" and "bracket" to be used interchangeably
//   Braces [ ], Curly Braces { }, Angled Braces < >
#define KC_RIGHT_BRACKET       KC_RBRACKET
#define KC_RIGHT_BRACE         KC_RBRACKET
#define KC_LEFT_BRACKET        KC_LBRACKET
#define KC_LEFT_BRACE          KC_LBRACKET
#define KC_RIGHT_CURLY_BRACKET KC_RIGHT_CURLY_BRACE
#define KC_LEFT_CURLY_BRACKET  KC_LEFT_CURLY_BRACE
#define KC_RIGHT_ANGLE_BRACE   KC_RIGHT_ANGLE_BRACKET
#define KC_LEFT_ANGLE_BRACE    KC_LEFT_ANGLE_BRACKET
