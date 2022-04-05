#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"

// ------------
// --- Mods ---
// ------------

#define MT_LG(k) MT(MOD_LGUI, k)
#define MT_LA(k) MT(MOD_LALT, k)
#define MT_LC(k) MT(MOD_LCTL, k)
#define MT_LS(k) MT(MOD_LSFT, k)
#define MT_RG(k) MT(MOD_RGUI, k)
#define MT_RA(k) MT(MOD_RALT, k)
#define MT_RC(k) MT(MOD_RCTL, k)
#define MT_RS(k) MT(MOD_RSFT, k)

// ----------------------
// --- Keycode Legend ---
// ----------------------
//   UKC = User Keycode
//   ZM = Zoom

// ---------------------
// --- User Keycodes ---
// ---------------------

enum my_keycodes {
    UKC_STARTING_POINT = SAFE_RANGE,

    UKC_CAPS_WORD,
    UKC_OSM_S,
    UKC_ZOOM_LAYER,
};

#define UKC_CUT         LCMD(KC_X)
#define UKC_COPY        LCMD(KC_C)
#define UKC_PASTE       LCMD(KC_V)
#define UKC_PSTE        UKC_PASTE
#define UKC_PLAIN_PASTE LALT(LSFT(UKC_PASTE)) // Plain Paste = paste a plain copy of the text
#define UKC_PPST        UKC_PLAIN_PASTE
#define UKC_UNDO        LCMD(KC_Z)
#define UKC_REDO        LSFT(UKC_UNDO)
#define UKC_SELECT_ALL  LCMD(KC_A)

#define UKC_INV_QUESTION LSFT(LALT(KC_SLASH))  // ¿
#define UKC_IQUS         UKC_INV_QUESTION
#define UKC_EMDASH       LSFT(LALT(KC_MINUS))
#define UKC_MDSH         UKC_EMDASH

#define UKC_TOGGLE_WINDOW_FULL_SCREEN LCMD(LCTL(KC_F))
#define UKC_TOGGLE_WINDOW_FULL        UKC_TOGGLE_WINDOW_FULL_SCREEN
#define UKC_WDW_FULL                  UKC_TOGGLE_WINDOW_FULL_SCREEN
#define UKC_WINDOW_SWAP_SCREENS       MEH(KC_0)
#define UKC_WDW_SWAP                  UKC_WINDOW_SWAP_SCREENS
#define UKC_WINDOW_RIGHT_HALF         MEH(KC_6)
#define UKC_WDW_RH                    UKC_WINDOW_RIGHT_HALF

#define UKC_APP_SWITCH     LGUI(KC_TAB)
#define UKC_ALFRED         LGUI(KC_SPACE)
#define UKC_SCREEN_CAPTURE LGUI(LSFT(KC_3))

// -------------------------------
// --- Zoom Keyboard Shortcuts ---
// -------------------------------
#define ZM_TG_AUDO  MEH(KC_A)
#define ZM_TG_VIDO  LCMD(LSFT(KC_V))
#define ZM_TG_VIEW  LCMD(LSFT(KC_W))
#define ZM_CLS_MEET LCMD(KC_W)
#define ZM_FOCUS    MEH(KC_Z)


// ---------------
// --- Clarity ---
// ---------------
// Some more verbose/clear keycode names (aliases), simply as a personal preference for legibility
// when help is needed and/or space isn't the primary concern.

#define KC_CARROT KC_CIRCUMFLEX
#define KC_CROT   KC_CARROT

#define _____ KC_TRANSPARENT
#define __o__ KC_TRANSPARENT
#define __x__ KC_NO

#define KC_PERIOD KC_DOT

// Space Cadet Shifts
#ifdef SPACE_CADET_ENABLE
    #define KC_LSFT_LPRN KC_LSPO
    #define KC_RSFT_RPRN KC_RSPC
#endif

// Allow for "brace" and "bracket" to be used interchangeably
//   Braces [ ], Curly Braces { }, Angled Braces < >
#define KC_RIGHT_BRACE         KC_RBRACKET
#define KC_LEFT_BRACE          KC_LBRACKET
#define KC_RIGHT_SQUARE_BRACE  KC_RBRACKET
#define KC_LEFT_SQUARE_BRACE   KC_LBRACKET
#define KC_RIGHT_CURLY_BRACKET KC_RIGHT_CURLY_BRACE
#define KC_LEFT_CURLY_BRACKET  KC_LEFT_CURLY_BRACE
#define KC_RIGHT_ANGLE_BRACE   KC_RIGHT_ANGLE_BRACKET
#define KC_LEFT_ANGLE_BRACE    KC_LEFT_ANGLE_BRACKET
