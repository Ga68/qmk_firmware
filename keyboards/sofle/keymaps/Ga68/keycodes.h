// ----------------------
// --- Keycode Legend ---
// ----------------------
//   CB = Combo
//   TH = Tap Hold
//   UKC = User Keycode
//   ZM = Zoom


// ---------------------
// --- User Keycodes ---
// ---------------------

enum my_keycodes {
    UKC_QUESTION  = SAFE_RANGE,
        // Using this as a substitute for a KC_QUESTION tap-hold since the KC_QUESTION keycode
        // overlaps with KC_SLASH, since KC_QUESTION = LSHFT(KC_SLASH).
    UKC_NAV, // Same as UKC_QUESTION, but for the Nav-Zoom layers tap-hold

    // Combos
    //   See process_combo_keycode_user to see these keycodes' implementation.
    CB_BRACES, // []
    CB_CURLY_BRACES, // {}
    CB_ANGLE_BRACES, // <>
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

#define UKC_WD_LEFT RALT(KC_LEFT)
#define UKC_WD_RGHT RALT(KC_RGHT)

#define UKC_TOGGLE_WINDOW_FULL_SCREEN LCMD(LCTL(KC_F))
#define UKC_TOGGLE_WINDOW_FULL        UKC_TOGGLE_WINDOW_FULL_SCREEN
#define UKC_WDW_FULL                  UKC_TOGGLE_WINDOW_FULL_SCREEN


// ----------------
// --- Tap Hold ---
// ----------------
// This will use the Mod-Tap intercept "trick" (as documented by QMK) to provide customizable
//   behavior on any key's hold. The DEFINEs are to help with code legibility.
//   https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap#changing-both-tap-and-hold
// See process_tap_hold_keycode_user to see these keycodes' implementation.
#define TH_NAV_ZOOM  LT(_BASE, UKC_NAV)
#define TH_ESC_CAPS  LT(_BASE, KC_ESC)
#define TH_COLN_SCLN LT(_BASE, KC_COLON)
#define TH_MINS_UNDS LT(_BASE, KC_MINUS)
#define TH_SLSH_BSLS LT(_BASE, KC_SLASH)
#define TH_QUES_IQUS LT(_BASE, UKC_QUESTION)
#define TH_QUOT_DQUO LT(_BASE, KC_QUOTE)
#define TH_DOT_RPRN  LT(_BASE, KC_DOT)
#define TH_COMM_LPRN LT(_BASE, KC_COMMA)

#define TH_LEFT_GUI  LT(_NAV, KC_LEFT)
#define TH_RGHT_GUI  LT(_NAV, KC_RIGHT)
#define TH_UP_GUI    LT(_NAV, KC_UP)
#define TH_DOWN_GUI  LT(_NAV, KC_DOWN)

#define TH_P0 LT(_NMSY, KC_P0)
#define TH_P1 LT(_NMSY, KC_P1)
#define TH_P2 LT(_NMSY, KC_P2)
#define TH_P3 LT(_NMSY, KC_P3)
#define TH_P4 LT(_NMSY, KC_P4)
#define TH_P5 LT(_NMSY, KC_P5)
#define TH_P6 LT(_NMSY, KC_P6)
#define TH_P7 LT(_NMSY, KC_P7)
#define TH_P8 LT(_NMSY, KC_P8)
#define TH_P9 LT(_NMSY, KC_P9)


// -------------------------------
// --- Zoom Keyboard Shortcuts ---
// -------------------------------
#define ZM_TG_AUDO  LCMD(LSFT(KC_A))
#define ZM_TG_VIDO  LCMD(LSFT(KC_V))
#define ZM_TG_VIEW  LCMD(LSFT(KC_W))
#define ZM_TG_CAM   LCMD(LSFT(KC_N))
#define ZM_SCR_SHR  LCMD(LSFT(KC_S))
#define ZM_CLS_MEET LCMD(KC_W)
#define ZM_WDW_FULL UKC_TOGGLE_WINDOW_FULL_SCREEN
#define ZM_WDW_HALF MEH(KC_6)


// ---------------
// --- Clarity ---
// ---------------
// Some more verbose/clear keycode names (aliases), simply as a personal preference for legibility
// when help is needed and/or space isn't the primary concern.

#define _____ KC_TRANSPARENT
#define __x__ KC_NO

#define KC_BACKSPACE KC_BSPACE
#define KC_SEMICOLON KC_SCOLON
#define KC_BACKSLASH KC_BSLASH
#define KC_PERIOD    KC_DOT

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
