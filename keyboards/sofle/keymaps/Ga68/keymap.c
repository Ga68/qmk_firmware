#include QMK_KEYBOARD_H
#include "keymap.h"

// --------------
// --- Layers ---
// --------------

enum my_layers {
    _COLEMAK,
    _NUMPADSYM,
    _NAV,
    _ZOOM,
};
#define _BASE _COLEMAK
#define _NMSY _NUMPADSYM


// -----------------------
// --- Custom Keycodes ---
// -----------------------
//   CB = Combo
//   TH = Tap Hold
//   UKC = User Keycode
//   ZM = Zoom

#define _____ KC_TRANSPARENT
#define __x__ KC_NO

enum my_keycodes {
    // Combos
    //   See process_combo_keycode_user to see these keycodes' implementation.
    CB_PARENS = SAFE_RANGE, // ()
    CB_BRACES, // []
    CB_CURLY_BRACES, // {}
    CB_ANGLE_BRACES, // <>
    // Other
    UKC_QUESTION,
        // Using this as a substitute for a KC_QUESTION tap-hold since the KC_QUESTION keycode
        // overlaps with KC_SLASH, since KC_QUESTION = LSHFT(KC_SLASH)
};

#define UKC_CUT         LCMD(KC_X)
#define UKC_COPY        LCMD(KC_C)
#define UKC_PASTE       LCMD(KC_V)
#define UKC_PSTE        UKC_PASTE
#define UKC_PLAIN_PASTE LALT(LSFT(UKC_PASTE)) // Plain Paste = paste a plain copy of the text
#define UKC_PPST        UKC_PLAIN_PASTE
#define UKC_UNDO        LCMD(KC_Z)
#define UKC_REDO        LCMD(LSFT(KC_Z))

#define UKC_INV_QUESTION LSFT(LALT(KC_SLASH))  // ¿
#define UKC_IQUS         UKC_INV_QUESTION

#define UKC_WD_LEFT RALT(KC_LEFT)
#define UKC_WD_RGHT RALT(KC_RGHT)

// Custom Tap-Hold behaviors
// This will use the Mod-Tap intercept "trick" (as documented by QMK) to provide customizable
//   behavior on any key's hold. The DEFINEs are to help with code legibility.
//   https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap#changing-both-tap-and-hold
// See process_tap_hold_keycode_user to see these keycodes' implementation.
#define TH_Z_ZOOM    LT(_BASE, KC_Z)
#define TH_ESC_CAPS  LT(_BASE, KC_ESC)
#define TH_COLN_SCLN LT(_BASE, KC_COLON)
#define TH_MINS_UNDS LT(_BASE, KC_MINUS)
#define TH_QUES_IQUS LT(_BASE, UKC_QUESTION)
#define TH_QUOT_DQUO LT(_BASE, KC_QUOTE)
#define TH_SLSH_BSLS LT(_BASE, KC_SLASH)
#define TH_DOT_RPRN  LT(_BASE, KC_DOT)
#define TH_COMM_LPRN LT(_BASE, KC_COMMA)

#define TH_X_CUT  LT(_BASE, KC_X)
#define TH_C_COPY LT(_BASE, KC_C)
#define TH_V_PSTE LT(_BASE, KC_V)

#define TH_LEFT_GUI  LT(_NAV, KC_LEFT)
#define TH_RGHT_GUI  LT(_NAV, KC_RGHT)
#define TH_UP_GUI    LT(_NAV, KC_UP)
#define TH_DOWN_GUI  LT(_NAV, KC_DOWN)

// Zoom
#define ZM_TG_AUDO  LCMD(LSFT(KC_A))
#define ZM_TG_VIDO  LCMD(LSFT(KC_V))
#define ZM_TG_VIEW  LCMD(LSFT(KC_W))
#define ZM_TG_CAM   LCMD(LSFT(KC_N))
#define ZM_SCR_SHR  LCMD(LSFT(KC_S))
#define ZM_CLS_MEET LCMD(KC_W)
#define ZM_WDW_FULL LCMD(LCTL(KC_F))
#define ZM_WDW_HALF MEH(KC_6)


// --------------
// --- Keymap ---
// --------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        TH_ESC_CAPS , KC_1     , KC_2    , KC_3     , KC_4     , KC_5,                   KC_6, KC_7, KC_8        , KC_9       , KC_0        , __x__       ,
        TH_QUES_IQUS, KC_Q     , KC_W    , KC_F     , KC_P     , KC_G,                   KC_J, KC_L, KC_U        , KC_Y       , TH_COLN_SCLN, TH_MINS_UNDS,
        KC_TAB      , KC_A     , KC_R    , KC_S     , KC_T     , KC_D,                   KC_H, KC_N, KC_E        , KC_I       , KC_O        , TH_QUOT_DQUO,
        TO(_NAV)    , TH_Z_ZOOM, TH_X_CUT, TH_C_COPY, TH_V_PSTE, KC_B, KC_MUTE, KC_MUTE, KC_K, KC_M, TH_COMM_LPRN, TH_DOT_RPRN, TH_SLSH_BSLS, KC_ENT      ,
        
                                 KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, TO(_NMSY), OSM(MOD_RSFT), KC_SPC, KC_RGUI, KC_RALT, KC_RCTL
    ),

    [_NUMPADSYM] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,               KC_F7  , KC_F8, KC_F9, KC_F10, KC_F11 , KC_F12 ,
        KC_LCBR, KC_RCBR, KC_AMPR, KC_ASTR, KC_GRV , KC_TILD,               KC_SLSH, KC_7 , KC_8 , KC_9  , KC_EQL , KC_MINS,
        KC_LT  , KC_GT  , KC_DLR , KC_PERC, KC_CIRC, KC_PIPE,               KC_ASTR, KC_4 , KC_5 , KC_6  , KC_MINS, KC_PLUS,
        KC_LBRC, KC_RBRC, KC_EXLM, KC_AT  , KC_HASH, __x__  , _____, _____, __x__  , KC_1 , KC_2 , KC_3  , KC_DOT , KC_ENT ,

                       KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, TO(_NAV), OSM(MOD_RSFT), TO(_BASE), KC_RGUI, KC_RALT, KC_RCTL
        ),

    [_NAV] = LAYOUT(
        __x__      , __x__      , __x__     , __x__      , __x__      , __x__      ,               __x__   , __x__   , __x__   , __x__  , __x__   , __x__  ,
        __x__      , SGUI(KC_1) , SGUI(KC_2), SGUI(KC_3) , SGUI(KC_4) , __x__      ,               __x__   , KC_WH_R , KC_WH_U , KC_WH_D, KC_WH_L , __x__  ,
        UKC_WD_LEFT, TH_LEFT_GUI, TH_UP_GUI , TH_DOWN_GUI, TH_RGHT_GUI, UKC_WD_RGHT,               KC_BTN1 , KC_MS_L , KC_MS_D , KC_MS_U, KC_MS_R , KC_BTN2,
        __x__      , UKC_UNDO   , UKC_CUT   , UKC_COPY   , UKC_PSTE   , UKC_REDO   , _____, _____, UKC_REDO, UKC_PSTE, UKC_COPY, UKC_CUT, UKC_UNDO, KC_ENT ,

                                             KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, TO(_NMSY), OSM(MOD_RSFT), TO(_BASE), KC_RGUI, KC_RALT, KC_RCTL
        ),

    [_ZOOM] = LAYOUT(
        __x__, __x__, __x__, __x__, __x__, __x__,               __x__     , __x__ , __x__, __x__      , __x__      , __x__      ,
        __x__, __x__, __x__, __x__, __x__, __x__,               __x__     , __x__ , __x__, __x__      , __x__      , __x__      ,
        __x__, __x__, __x__, __x__, __x__, __x__,               ZM_TG_CAM , __x__ , __x__, __x__      , __x__      , ZM_CLS_MEET,
        __x__, __x__, __x__, __x__, __x__, __x__, _____, _____, ZM_TG_VIEW, __x__ , __x__, ZM_WDW_FULL, ZM_WDW_HALF, KC_ENT     ,

                __x__, __x__, __x__, KC_SPC, ZM_TG_VIDO, ZM_TG_AUDO, TO(_BASE), ZM_TG_VIDO, ZM_SCR_SHR, KC_SPC
        ),
};

// --------------
// --- Combos ---
// --------------
#ifdef COMBO_ENABLE

    const uint16_t PROGMEM combo_parentheses[] = {KC_DOT, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM combo_braces[] = {KC_LEFT_BRACE, KC_RIGHT_BRACE, COMBO_END};
    const uint16_t PROGMEM combo_curly_braces[] = {KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, COMBO_END};
    const uint16_t PROGMEM combo_less_than_greater_than[] = {KC_LT, KC_GT, COMBO_END};
    const uint16_t PROGMEM combo_paste_plain[] = {KC_C, KC_V, COMBO_END};

    uint16_t COMBO_LEN = 5;
    combo_t key_combos[] = {
        COMBO(combo_parentheses, CB_PARENS),
        COMBO(combo_braces, CB_BRACES),
        COMBO(combo_curly_braces, CB_CURLY_BRACES),
        COMBO(combo_less_than_greater_than, CB_ANGLE_BRACES),
        COMBO(combo_paste_plain, UKC_PLAIN_PASTE),
    };

    bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case CB_PARENS:
                if (record->event.pressed) {
                    tap_code16(KC_LEFT_PAREN);
                    tap_code16(KC_RIGHT_PAREN);
                    tap_code(KC_LEFT);
                }
                return false;
            case CB_BRACES:
                if (record->event.pressed) {
                    tap_code16(KC_LEFT_BRACE);
                    tap_code16(KC_RIGHT_BRACE);
                    tap_code(KC_LEFT);
                }
                return false;
            case CB_CURLY_BRACES:
                if (record->event.pressed) {
                    tap_code16(KC_LEFT_CURLY_BRACE);
                    tap_code16(KC_RIGHT_CURLY_BRACE);
                    tap_code(KC_LEFT);
                }
                return false;
            case CB_ANGLE_BRACES:
                if (record->event.pressed) {
                    tap_code16(KC_LEFT_ANGLE_BRACE);
                    tap_code16(KC_RIGHT_ANGLE_BRACE);
                    tap_code(KC_LEFT);
                }
                return false;
        }
        return true;
    }

#endif

// -----------------
// --- Overrides ---
// -----------------

#ifdef KEY_OVERRIDE_ENABLE

    // Shift Backspace = Delete
    const key_override_t delete_key_override_shift = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE);
    // Ctrl Backspace = Delete
    const key_override_t delete_key_override_ctrl = ko_make_basic(MOD_MASK_CTRL, KC_BACKSPACE, KC_DELETE);

    const key_override_t **key_overrides = (const key_override_t *[]){
        &delete_key_override_shift,
        &delete_key_override_ctrl,
        NULL // Terminate the array of overrides
    };

#endif

// ---------------
// --- Tapping ---
// ---------------
// Some of the below could be accomplished with Auto Shift (KC_MINS - KC_UNDS); however, most of
//   them cannot as they're custom (ex. the KC_COLN - KC_SCLN inversion). So rather than
//   mix-and-matching Auto-Shift and Tap-Hold, I'm going just with Tap-Hold. Plus, enabling
//   Auto Shift for just a few keys comes with a lot of overhead (bytes).

bool process_tap_hold_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_Z_ZOOM:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_Z);
            } else if (record->event.pressed) {
                layer_on(_ZOOM);
            }
            return false;
        case TH_ESC_CAPS:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_ESC);
            } else if (record->event.pressed) {
                tap_code(KC_CAPSLOCK);
            }
            return false;
        case TH_COLN_SCLN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLON);
            } else if (record->event.pressed) {
                tap_code(KC_SEMICOLON);
            }
            return false;
        case TH_MINS_UNDS:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_MINUS);
            } else if (record->event.pressed) {
                tap_code16(KC_UNDERSCORE);
            }
            return false;
        case TH_QUES_IQUS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUESTION);
            } else if (record->event.pressed) {
                tap_code16(UKC_INV_QUESTION);
            }
            return false;
        case TH_QUOT_DQUO:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_QUOTE);
            } else if (record->event.pressed) {
                tap_code16(KC_DOUBLE_QUOTE);
            }
            return false;
        case TH_SLSH_BSLS:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_SLASH);
            } else if (record->event.pressed) {
                tap_code16(KC_BACKSLASH);
            }
            return false;
        case TH_DOT_RPRN:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_DOT);
            } else if (record->event.pressed) {
                tap_code16(KC_RIGHT_PAREN);
            }
            return false;
        case TH_COMM_LPRN:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_COMMA);
            } else if (record->event.pressed) {
                tap_code16(KC_LEFT_PAREN);
            }
            return false;
        case TH_LEFT_GUI:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_LEFT);
            } else if (record->event.pressed) {
                tap_code16(LGUI(KC_LEFT));
            }
            return false;
        case TH_RGHT_GUI:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_RIGHT);
            } else if (record->event.pressed) {
                tap_code16(LGUI(KC_RIGHT));
            }
            return false;
        case TH_UP_GUI:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_UP);
            } else if (record->event.pressed) {
                tap_code16(LGUI(KC_UP));
            }
            return false;
        case TH_DOWN_GUI:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_DOWN);
            } else if (record->event.pressed) {
                tap_code16(LGUI(KC_DOWN));
            }
            return false;
        case TH_X_CUT:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_X);
            } else if (record->event.pressed) {
                tap_code16(UKC_CUT);
            }
            return false;
        case TH_C_COPY:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_C);
            } else if (record->event.pressed) {
                tap_code16(UKC_COPY);
            }
            return false;
        case TH_V_PSTE:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_V);
            } else if (record->event.pressed) {
                tap_code16(UKC_PASTE);
            }
            return false;
    }
    return true;
}

#ifdef TAPPING_TERM_PER_KEY
    uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case TH_Z_ZOOM:
                return TAPPING_TERM + 1000;
            case TH_ESC_CAPS:
                return TAPPING_TERM + 500;
            default:
                return TAPPING_TERM;
        }
    }
#endif


// ----------------
// --- Encoders ---
// ----------------

#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        if (index == 0 || index == 1) {
            // For now I'm doing the same thing for both encoders
            if (clockwise) {
                tap_code(KC_AUDIO_VOL_UP);
            } else {
                tap_code(KC_AUDIO_VOL_DOWN);
            }
        }
        return true;
    }
#endif


// ---------------------------
// --- process_record_user ---
// ---------------------------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tap_hold_keycode_user(keycode, record)) {
        return false;
    }
    if (!process_combo_keycode_user(keycode, record)) {
        return false;
    }
    return true;
}


// -------------
// --- OLEDs ---
// -------------

#ifdef OLED_ENABLE
    static void render_logo(void) {
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,
            0x91,0x92,0x93,0x94,0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,
            0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,
            0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
        };

        oled_write_P(qmk_logo, false);
    }

    static void print_status_narrow(void) {
        // Print current layer
        oled_write_P(PSTR("\n\n"), false);
        int ls = get_highest_layer(layer_state);
        oled_write_P(PSTR("Base\n\n"), ls==_BASE);
        oled_write_P(PSTR("NumSy\n"), ls==_NMSY);
        oled_write_P(PSTR("Nav\n\n"), ls==_NAV);
        oled_write_P(PSTR("Zoom\n\n"), ls==_ZOOM);

        // Caps Lock
        oled_write_P(PSTR("\n\n"), false);
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    }

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master()) {
            return OLED_ROTATION_270;
        }
        return rotation;
    }

    void oled_task_user(void) {
        if (is_keyboard_master()) {
            print_status_narrow();
        } else if (false) {
        // leaving it this way, false, so it'll never run, but the compiler doesn't error on me by
        // saying that "render_logo" is never used. I may want to use it in the future.
            render_logo();
        }
    }
#endif
