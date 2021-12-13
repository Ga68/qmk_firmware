#pragma once

enum th_keycodes {
    TH_STARTING_POINT = MAX_USER_KEYCODE,
    
    UKC_TH_NAV_ZOOM,
    UKC_TH_BACKSPACE,
    UKC_TH_TAB_CAPS,
    UKC_TH_ENT_AENT,
    
    UKC_TH_ESC_GRAVE,
    UKC_TH_ESC_F1,
    UKC_TH_COLON_SEMICOLON,
    UKC_TH_DOT_INV_QUES,
    UKC_TH_TILDE_EMDASH,
    
    UKC_TH_SQUARE_BRACES,
    UKC_TH_CURLY_BRACES,
    UKC_TH_ANGLED_BRACES,
        
    UKC_TH_0,
    UKC_TH_1,
    UKC_TH_2,
    UKC_TH_3,
    UKC_TH_4,
    UKC_TH_5,
    UKC_TH_6,
    UKC_TH_7,
    UKC_TH_8,
    UKC_TH_9,
};

// ----------------
// --- Tap Hold ---
// ----------------
// This will use the Mod-Tap intercept "trick" (as documented by QMK) to provide customizable
//   behavior on any key's hold. The DEFINEs are to help with code legibility.
//   https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap#changing-both-tap-and-hold
// See process_tap_hold_keycode_user to see these keycodes' implementation.

#define TH_NAV_ZOOM LT(0, UKC_TH_NAV_ZOOM )
#define TH_BSPACE   LT(0, UKC_TH_BACKSPACE)
#define TH_TAB_CAPS LT(0, UKC_TH_TAB_CAPS )
#define TH_ENT_AENT LT(0, UKC_TH_ENT_AENT )

#define TH_ESC_GRV   LT(0, UKC_TH_ESC_GRAVE      )
#define TH_ESC_F1    LT(0, UKC_TH_ESC_F1         )
#define TH_COLN_SCLN LT(0, UKC_TH_COLON_SEMICOLON)
#define TH_DOT_IQUS  LT(0, UKC_TH_DOT_INV_QUES   )
#define TH_TILD_MDSH LT(0, UKC_TH_TILDE_EMDASH   )

#define TH_SQ_BRCS   LT(0, UKC_TH_SQUARE_BRACES)
#define TH_CUR_BRCS  LT(0, UKC_TH_CURLY_BRACES )
#define TH_ANG_BRCS  LT(0, UKC_TH_ANGLED_BRACES)

#define WINDOW_HOTKEY MEH
#define TH_0 LT(0, UKC_TH_0)
#define TH_1 LT(0, UKC_TH_1)
#define TH_2 LT(0, UKC_TH_2)
#define TH_3 LT(0, UKC_TH_3)
#define TH_4 LT(0, UKC_TH_4)
#define TH_5 LT(0, UKC_TH_5)
#define TH_6 LT(0, UKC_TH_6)
#define TH_7 LT(0, UKC_TH_7)
#define TH_8 LT(0, UKC_TH_8)
#define TH_9 LT(0, UKC_TH_9)

enum tap_hold_actions { THA_TAP, THA_HOLD, THA_OTHER };
enum tap_hold_key_types {
    // Acts like a key where the normal press is tap and the shifted press is hold, and additionally
    // if you hold the key, it acts like Shift was pressed.
    THT_SHIFT,
    // Acts like a key where the normal press is tap does one key (regardless of mod status) and 
    // hold does the alternative key (again, regardless of mod status).
    THT_TAP_HOLD,
};

typedef struct _tap_hold_keycode_t {
    uint16_t keymap_keycode;
    uint16_t primary_keycode;
    uint16_t alt_keycode;
    int      tap_hold_type;
} tap_hold_keycode_t;

tap_hold_keycode_t custom_tap_hold_keys[] = {

    { TH_ESC_GRV  , KC_ESCAPE, KC_GRAVE        , THT_SHIFT },
    { TH_ESC_F1   , KC_ESCAPE, KC_F1           , THT_SHIFT },
    { TH_COLN_SCLN, KC_COLON , KC_SEMICOLON    , THT_SHIFT },
    { TH_DOT_IQUS , KC_PERIOD, UKC_INV_QUESTION, THT_SHIFT },
    { TH_TILD_MDSH, KC_TILDE , UKC_EMDASH      , THT_SHIFT },

    { TH_SQ_BRCS , KC_LEFT_BRACE      , KC_RIGHT_BRACE      , THT_SHIFT },
    { TH_CUR_BRCS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, THT_SHIFT },
    { TH_ANG_BRCS, KC_LEFT_ANGLE_BRACE, KC_RIGHT_ANGLE_BRACE, THT_SHIFT },

    { TH_TAB_CAPS, KC_TAB  , KC_CAPS       , THT_TAP_HOLD },
    { TH_ENT_AENT, KC_ENTER, LALT(KC_ENTER), THT_TAP_HOLD },

    { TH_0, KC_0, WINDOW_HOTKEY(KC_0), THT_TAP_HOLD },
    { TH_1, KC_1, WINDOW_HOTKEY(KC_1), THT_TAP_HOLD },
    { TH_2, KC_2, WINDOW_HOTKEY(KC_2), THT_TAP_HOLD },
    { TH_3, KC_3, WINDOW_HOTKEY(KC_3), THT_TAP_HOLD },
    { TH_4, KC_4, WINDOW_HOTKEY(KC_4), THT_TAP_HOLD },
    { TH_5, KC_5, WINDOW_HOTKEY(KC_5), THT_TAP_HOLD },
    { TH_6, KC_6, WINDOW_HOTKEY(KC_6), THT_TAP_HOLD },
    { TH_7, KC_7, WINDOW_HOTKEY(KC_7), THT_TAP_HOLD },
    { TH_8, KC_8, WINDOW_HOTKEY(KC_8), THT_TAP_HOLD },
    { TH_9, KC_9, WINDOW_HOTKEY(KC_9), THT_TAP_HOLD },

};
uint8_t CUSTOM_TAP_HOLD_KEY_COUNT = sizeof(custom_tap_hold_keys) / sizeof(tap_hold_keycode_t);

#ifdef TAPPING_TERM_PER_KEY
    uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case TH_NAV_ZOOM:
            case TH_TAB_CAPS:
                return TAPPING_TERM + 150;
            default:
                return TAPPING_TERM;
        }
    }
#endif

int tap_hold_action(keyrecord_t *record) {
    if (record->tap.count && record->event.pressed) {
        return THA_TAP;
    } else if (record->event.pressed) {
        return THA_HOLD;
    }
    return THA_OTHER;
}

// The goal here is to customize how each of four different combinations of key presses work, on
// a single key. It uses the TAP and HOLD tap types, and a mod (CTRL, SHIFT, etc.) applied, or not.
// The mod (ex. MOD_MASK_SHIFT) is removed during the key press action since it's designed to alter
// what happens, not the actual key press itself.
//
// This is like a combination of auto-shift (shift a key when held) and over-rides (output something
// bespoke when a key is pressed with a mod).
void process_custom_tap_hold_mod(uint16_t tap, uint16_t tap_mod, uint16_t hold, uint16_t hold_mod, uint8_t mod_mask, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    int action = tap_hold_action(record);
    bool is_mod_on = (mod_state & mod_mask);

    del_mods(mod_mask); // clear the mod-mask so it doesn't alter the actual key press
    if (action == THA_TAP) {
        if (is_mod_on) { tap_code16_user(tap_mod); }
        else           { tap_code16_user(tap);     }
    }
    else if (action == THA_HOLD) {
        if (is_mod_on) { tap_code16_user(hold_mod); }
        else           { tap_code16_user(hold);     }
    }
    set_mods(mod_state); // restore mods to what they were before we starte         
}

bool process_tap_hold_keycode_user(uint16_t keycode, keyrecord_t *record) {

    for (int i = 0; i < CUSTOM_TAP_HOLD_KEY_COUNT; i = i + 1) {
        if (keycode == custom_tap_hold_keys[i].keymap_keycode) {
            switch (custom_tap_hold_keys[i].tap_hold_type) {
                case THT_SHIFT:
                    process_custom_tap_hold_mod(
                        custom_tap_hold_keys[i].primary_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        MOD_MASK_SHIFT,
                        record
                    );
                    return false;
                case THT_TAP_HOLD:
                    process_custom_tap_hold_mod(
                        custom_tap_hold_keys[i].primary_keycode,
                        custom_tap_hold_keys[i].primary_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        0,
                        record
                    );
                    return false;
            }
        }
    }
    
    switch (keycode) {
        case TH_NAV_ZOOM:
            {
                int action = tap_hold_action(record);
                if      (action == THA_TAP)  { layer_on(_NAV);  }
                else if (action == THA_HOLD) { layer_on(_ZOOM); }
                return false;
            }
        case TH_BSPACE:
            // SHIFT = Delete and no-SHIFT = Backspace
            // HOLD = whole word (ALT) and TAP = normal key press
            process_custom_tap_hold_mod(
                KC_BACKSPACE,
                KC_DELETE,
                LALT(KC_BACKSPACE),
                LALT(KC_DELETE),
                MOD_MASK_SHIFT,
                record
            );
            return false;
    }
    
    return true;
}
