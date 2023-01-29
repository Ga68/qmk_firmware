#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"


#define DELAY_LONG  wait_ms(900)
#define DELAY       wait_ms(600)
#define DELAY_SHORT wait_ms(300)


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


// ---------------------
// --- User Keycodes ---
// ---------------------

enum my_keycodes {
    UKC_SUPER_APP_SWITCH = SAFE_RANGE,
    UKC_LEADER,
    UKC_ARROW_SHIFT_LOCK,
    UKC_TOGGLE_NUM_LOCK,

    UKC_DOLLAR,
    UKC_DOLLAR_M,
    UKC_DOLLAR_K,
    UKC_DOLLAR_B,
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

#define UKC_APP_SWITCH        LCMD(KC_TAB)
#define UKC_ALFRED            LCMD(KC_SPACE)
#define UKC_CLIPBOARD_HISTORY LALT(UKC_ALFRED)
#define UKC_CPBD_HIST         UKC_CLIPBOARD_HISTORY
#define UKC_SCREEN_CAPTURE    LCMD(LSFT(KC_3))
#define UKC_MENU              LSFT(LCMD(KC_GRAVE))
#define UKC_NEXT_WINDOW       LCMD(KC_GRAVE)
#define UKC_HELP_MENU         LSFT(LCMD(KC_SLASH))

#define UKC_LOCK_COMPUTER LCMD(LCTL(KC_Q))

#define UKC_FIND_MOUSE MEH(KC_F12)

// ---------------
// --- Clarity ---
// ---------------
// Some more verbose/clear keycode names (aliases), simply as a personal preference for legibility
// when help is needed and/or space isn't the primary concern.

#define KC_CARROT KC_CIRCUMFLEX
#define KC_CROT   KC_CARROT
#define KC_KROT   KC_CARROT
#define KC_PERIOD KC_DOT
#define KC_DASH   KC_MINUS
#define KC_TACK   KC_MINUS
#define KC_STAR   KC_ASTERISK
#define KC_BANG   KC_EXCLAIM
#define KC_LPAREN KC_LEFT_PAREN
#define KC_RPAREN KC_RIGHT_PAREN


#define _____ KC_TRANSPARENT
#define __o__ KC_TRANSPARENT
#define _LYR_ KC_TRANSPARENT  // Used for indicating (in code) which key is being held for the layer
#define __x__ KC_NO
#define _XIT_ TO(_BASE)       // To "exit" a layer


// Space Cadet Shifts
#ifdef SPACE_CADET_ENABLE
    #define KC_LSFT_LPRN KC_LSPO
    #define KC_RSFT_RPRN KC_RSPC
#endif


// Allow for "brace" and "bracket" to be used interchangeably
//   Braces [ ], Curly Braces { }, Angled Braces < >
#define KC_RIGHT_BRACE         KC_RIGHT_BRACKET
#define KC_LEFT_BRACE          KC_LEFT_BRACKET
#define KC_RIGHT_SQUARE_BRACE  KC_RIGHT_BRACKET
#define KC_LEFT_SQUARE_BRACE   KC_LEFT_BRACKET
#define KC_RIGHT_CURLY_BRACKET KC_RIGHT_CURLY_BRACE
#define KC_LEFT_CURLY_BRACKET  KC_LEFT_CURLY_BRACE
#define KC_RIGHT_ANGLE_BRACE   KC_RIGHT_ANGLE_BRACKET
#define KC_LEFT_ANGLE_BRACE    KC_LEFT_ANGLE_BRACKET
