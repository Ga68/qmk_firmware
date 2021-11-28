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
#define TH_SLSH_BSLS LT(_BASE, KC_SLASH)
#define TH_QUES_IQUS LT(_BASE, UKC_QUESTION)
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

bool was_left_shift_pressed;
bool was_right_shift_pressed;
bool is_one_shot_shift_active;
// The goal of this function is to send the keycode parameter if tapped, or send the alt_keycode
//   parameter if the held or tapped with shift active. Shift can be active by a shift key being
//   held, or via one-shot-mods. This should be true no matter what the keycode and alt_keycode
//   parameters are.
// It gets a bit tricky when you want to mix and match what's typically shifted or not. For example,
//   you're trying to invert colon and semi-colon. Semi-colon is the unshifted keycode. Your keyboard
//   doesn't actually send a colon keycode, KC_COLON is just an alias for S(KC_SEMICOLON) (shift and
//   semicolon). So the reason there's so much handling below, is to make sure that if you're holding
//   shift (or using a one shot mod), and you want to send a typically-unshifted keycode (like
//   semicolon), then you have to get out of the shifted state first.
void tap_custom_shifted_tap_hold_key(uint16_t keycode, uint16_t alt_keycode, keyrecord_t *record) {
    was_left_shift_pressed = get_mods() & MOD_BIT(KC_LEFT_SHIFT);
    was_right_shift_pressed = get_mods() & MOD_BIT(KC_RIGHT_SHIFT);
    
    // see if a OSM for shift and only shift is active
    is_one_shot_shift_active = (\
        (get_oneshot_mods() & MOD_BIT(KC_RIGHT_SHIFT)) == MOD_BIT(KC_RIGHT_SHIFT))\
        || ((get_oneshot_mods() & MOD_BIT(KC_LEFT_SHIFT)) == MOD_BIT(KC_LEFT_SHIFT)\
    );
    
    // If this is a press event (not hold)
    if (record->tap.count && record->event.pressed) {
        if (is_one_shot_shift_active) {
            clear_oneshot_mods();
            tap_code16(alt_keycode);
        }
        else if (was_left_shift_pressed || was_right_shift_pressed) {
            unregister_code(KC_LEFT_SHIFT);
            unregister_code(KC_RIGHT_SHIFT);
            tap_code16(alt_keycode);
            if (was_left_shift_pressed ) { register_code(KC_LEFT_SHIFT); }
            if (was_right_shift_pressed) { register_code(KC_RIGHT_SHIFT); }
        }
        else {
            tap_code16(keycode); // Note that this is the ONLY branch with "keycode"
        }
    // If this is a hold event (not press)
    } else if (record->event.pressed) {
        tap_code16(alt_keycode);
    }
}


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
            // tap_custom_shifted_tap_hold_key(KC_ESC, KC_CAPSLOCK, record);
            // I'd have thought the above would work; however, CAPS doesn't seem to play along
            //   with tapcode16 for some reason. https://www.reddit.com/r/olkb/comments/r4224m

            if (record->tap.count && record->event.pressed) {
                tap_code(KC_ESC);
            } else if (record->event.pressed) {
                tap_code(KC_CAPSLOCK);
            }
            return false;

        case TH_COLN_SCLN:
            tap_custom_shifted_tap_hold_key(KC_COLON, KC_SEMICOLON, record);
            return false;
        case TH_QUES_IQUS:
            tap_custom_shifted_tap_hold_key(KC_QUESTION, UKC_INV_QUESTION, record);
            return false;
        case TH_SLSH_BSLS:
            tap_custom_shifted_tap_hold_key(KC_SLASH, KC_BACKSLASH, record);
            return false;
        case TH_DOT_RPRN:
            tap_custom_shifted_tap_hold_key(KC_DOT, KC_RIGHT_PAREN, record);
            return false;
        case TH_COMM_LPRN:
            tap_custom_shifted_tap_hold_key(KC_COMMA, KC_LEFT_PAREN, record);
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
