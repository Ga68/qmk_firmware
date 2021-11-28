#pragma once

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

#ifdef TAPPING_TERM_PER_KEY
    uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case TH_NAV_ZOOM:
                return TAPPING_TERM + 1000;
            case TH_ESC_CAPS:
                return TAPPING_TERM + 500;
            case TH_P0:
            case TH_P1:
            case TH_P2:
            case TH_P3:
            case TH_P4:
            case TH_P5:
            case TH_P6:
            case TH_P7:
            case TH_P8:
            case TH_P9:
                return TAPPING_TERM + 250;
            default:
                return TAPPING_TERM;
        }
    }
#endif

bool process_tap_hold_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_NAV_ZOOM:
            if (record->tap.count && record->event.pressed) {
                layer_on(_NAV);
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

        case TH_P0:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P0);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P0));
            }
            return false;
        case TH_P1:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P1);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P1));
            }
            return false;
        case TH_P2:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P2);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P2));
            }
            return false;
        case TH_P3:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P3);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P3));
            }
            return false;
        case TH_P4:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P4);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P4));
            }
            return false;
        case TH_P5:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P5);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P5));
            }
            return false;
        case TH_P6:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P6);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P6));
            }
            return false;
        case TH_P7:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P7);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P7));
            }
            return false;
        case TH_P8:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P8);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P8));
            }
            return false;
        case TH_P9:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P9);
            } else if (record->event.pressed) {
                tap_code16(MEH(KC_P9));
            }
            return false;
    }
    return true;
}
