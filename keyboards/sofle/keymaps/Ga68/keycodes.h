#pragma once

// ----------------
// --- Mod Taps ---
// ----------------

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
//   CB = Combo
//   UKC = User Keycode
//   ZM = Zoom


// ---------------------
// --- User Keycodes ---
// ---------------------

enum my_keycodes {
    UKC_STARTING_POINT = SAFE_RANGE,

#ifdef COMBO_ENABLE
    // Combos: see implementation in combos.c
    CB_BRACES,       // []
    CB_CURLY_BRACES, // {}
    CB_ANGLE_BRACES, // <>
#endif

    MAX_USER_KEYCODE,
};

#define UKC_CUT         LCMD(KC_X)
#define UKC_COPY        LCMD(KC_C)
#define UKC_PASTE       LCMD(KC_V)
#define UKC_PSTE        UKC_PASTE
#define UKC_PLAIN_PASTE LALT(LSFT(UKC_PASTE)) // Plain Paste = paste a plain copy of the text
#define UKC_PPST        UKC_PLAIN_PASTE
#define UKC_UNDO        LCMD(KC_Z)
#define UKC_REDO        LCMD(LSFT(KC_Z))

#define UKC_CYCLE_INPUT          LCMD(LSFT(KC_1)) // Cycle keyboard input modes
#define UKC_CYC_INPT             UKC_CYCLE_INPUT
#define UKC_INVERT_COLORS        LCMD(LSFT(KC_2)) // Inverst screen colors
#define UKC_INV_CLRS             UKC_INVERT_COLORS
#define UKC_SCREEN_CAP_SELECTION LCMD(LSFT(KC_3)) // Screen capture a portion of the screen
#define UKC_SCCP_SEL             UKC_SCREEN_CAP_SELECTION
#define UKC_SCREEN_CAP_FULL      LCMD(LSFT(KC_4))
#define UKC_SCCP_FULL            UKC_SCREEN_CAP_FULL // Screen capture the full screen

#define UKC_INV_QUESTION LSFT(LALT(KC_SLASH))  // ¿
#define UKC_IQUS         UKC_INV_QUESTION
#define UKC_EMDASH       LSFT(LALT(KC_MINUS))
#define UKC_MDSH         UKC_EMDASH

#define UKC_WD_LEFT RALT(KC_LEFT)
#define UKC_WD_RGHT RALT(KC_RGHT)

#define UKC_TOGGLE_WINDOW_FULL_SCREEN LCMD(LCTL(KC_F))
#define UKC_TOGGLE_WINDOW_FULL        UKC_TOGGLE_WINDOW_FULL_SCREEN
#define UKC_WDW_FULL                  UKC_TOGGLE_WINDOW_FULL_SCREEN
#define UKC_MEH_SPACE                 MT(MOD_MEH, KC_SPACE)


// -------------------------------
// --- Zoom Keyboard Shortcuts ---
// -------------------------------
#define ZM_TG_AUDO  LCMD(LSFT(KC_A))
#define ZM_TG_VIDO  LCMD(LSFT(KC_V))
#define ZM_TG_VIEW  LCMD(LSFT(KC_W))
#define ZM_CLS_MEET LCMD(KC_W)
#define ZM_WDW_FULL UKC_TOGGLE_WINDOW_FULL_SCREEN
#define ZM_WDW_HALF MEH(KC_6)
#define ZM_FOCUS    MEH(KC_Z)


// ---------------
// --- Clarity ---
// ---------------
// Some more verbose/clear keycode names (aliases), simply as a personal preference for legibility
// when help is needed and/or space isn't the primary concern.

#define KC_CARROT KC_CIRCUMFLEX
#define KC_CROT   KC_CARROT

#define _____ KC_TRANSPARENT
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
#define KC_RIGHT_CURLY_BRACKET KC_RIGHT_CURLY_BRACE
#define KC_LEFT_CURLY_BRACKET  KC_LEFT_CURLY_BRACE
#define KC_RIGHT_ANGLE_BRACE   KC_RIGHT_ANGLE_BRACKET
#define KC_LEFT_ANGLE_BRACE    KC_LEFT_ANGLE_BRACKET
