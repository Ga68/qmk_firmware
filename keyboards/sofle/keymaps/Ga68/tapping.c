#pragma once

// ----------------
// --- Tap Hold ---
// ----------------
// This will use the Mod-Tap intercept "trick" (as documented by QMK) to provide customizable
//   behavior on any key's hold. The DEFINEs are to help with code legibility.
//   https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap#changing-both-tap-and-hold
// See process_tap_hold_keycode_user to see these keycodes' implementation.

#define TH_NAV_ZOOM  LT(_BASE, UKC_NAV)
#define TH_GRV_ESC   LT(_BASE, UKC_GRAVE_ESCAPE)
#define TH_F1_ESC    LT(_BASE, UKC_F1_ESCAPE)
#define TH_COLN_SCLN LT(_BASE, KC_COLON)
#define TH_DOT_IQUS  LT(_BASE, KC_DOT)
#define TH_TILD_MDSH LT(_BASE, UKC_TILDE_EMDASH)
#define TH_TAB_CAPS  LT(_BASE, KC_TAB)

#define TH_SQ_BRCS   LT(_NMSY, UKC_SQUARE_BRACES)
#define TH_CUR_BRCS  LT(_NMSY, UKC_CURLY_BRACES)
#define TH_ANG_BRCS  LT(_NMSY, UKC_ANGLE_BRACES)

#define TH_LEFT_GUI  LT(_NAV, KC_LEFT)
#define TH_RGHT_GUI  LT(_NAV, KC_RIGHT)
#define TH_UP_GUI    LT(_NAV, KC_UP)
#define TH_DOWN_GUI  LT(_NAV, KC_DOWN)

#define WINDOW_HOTKEY MEH

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
            case TH_TAB_CAPS:
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
            if (alt_keycode == KC_CAPS) { tap_code(KC_CAPS);       }
            else                        { tap_code16(alt_keycode); }
        }
        else if (was_left_shift_pressed || was_right_shift_pressed) {
            unregister_code(KC_LEFT_SHIFT);
            unregister_code(KC_RIGHT_SHIFT);

            if (alt_keycode == KC_CAPS) { tap_code(KC_CAPS);       }
            else                        { tap_code16(alt_keycode); }

            if (was_left_shift_pressed ) { register_code(KC_LEFT_SHIFT); }
            if (was_right_shift_pressed) { register_code(KC_RIGHT_SHIFT); }
        }
        else {
            // Note that this is the ONLY branch with "keycode"
            if (keycode == KC_CAPS) { tap_code(KC_CAPS);   }
            else                    { tap_code16(keycode); }
        }
    // If this is a hold event (not press)
    } else if (record->event.pressed) {
        if (alt_keycode == KC_CAPS) { tap_code(KC_CAPS);       }
        else                        { tap_code16(alt_keycode); }
    }
}


bool process_tap_hold_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // Custom key combinations
        case TH_NAV_ZOOM:
            if (record->tap.count && record->event.pressed) {
                layer_on(_NAV);
            } else if (record->event.pressed) {
                layer_on(_ZOOM);
            }
            return false;        
        case TH_GRV_ESC:
            tap_custom_shifted_tap_hold_key(KC_GRAVE, KC_ESCAPE, record);
            return false;
        case TH_F1_ESC:
            tap_custom_shifted_tap_hold_key(KC_F1, KC_ESCAPE, record);
            return false;
        case TH_COLN_SCLN:
            tap_custom_shifted_tap_hold_key(KC_COLON, KC_SEMICOLON, record);
            return false;
        case TH_DOT_IQUS:
            tap_custom_shifted_tap_hold_key(KC_PERIOD, UKC_INV_QUESTION, record);
            return false;
        case TH_TILD_MDSH:
            tap_custom_shifted_tap_hold_key(KC_TILDE, UKC_EMDASH, record);
            return false;
        case TH_TAB_CAPS:
            tap_custom_shifted_tap_hold_key(KC_TAB, KC_CAPS, record);
            return false;

        // Braces
        case TH_SQ_BRCS:
            tap_custom_shifted_tap_hold_key(KC_LEFT_BRACE, KC_RIGHT_BRACE, record);
            return false;
        case TH_CUR_BRCS:
            tap_custom_shifted_tap_hold_key(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, record);
            return false;
        case TH_ANG_BRCS:
            tap_custom_shifted_tap_hold_key(KC_LEFT_ANGLE_BRACE, KC_RIGHT_ANGLE_BRACE, record);
            return false;

        // Navigation keys get tap-held to include GUI
        case TH_LEFT_GUI:
            tap_custom_shifted_tap_hold_key(KC_LEFT, LGUI(KC_LEFT), record);
            return false;
        case TH_RGHT_GUI:
            tap_custom_shifted_tap_hold_key(KC_RIGHT, LGUI(KC_RIGHT), record);
            return false;
        case TH_UP_GUI:
            tap_custom_shifted_tap_hold_key(KC_UP, LGUI(KC_UP), record);
            return false;
        case TH_DOWN_GUI:
            tap_custom_shifted_tap_hold_key(KC_DOWN, LGUI(KC_DOWN), record);
            return false;

        // NumPad keys get tap-held to include MEH
        case TH_P0:
            tap_custom_shifted_tap_hold_key(KC_P0, WINDOW_HOTKEY(KC_P0), record);
            return false;
        case TH_P1:
            tap_custom_shifted_tap_hold_key(KC_P1, WINDOW_HOTKEY(KC_P1), record);
            return false;
        case TH_P2:
            tap_custom_shifted_tap_hold_key(KC_P2, WINDOW_HOTKEY(KC_P2), record);
            return false;
        case TH_P3:
            tap_custom_shifted_tap_hold_key(KC_P3, WINDOW_HOTKEY(KC_P3), record);
            return false;
        case TH_P4:
            tap_custom_shifted_tap_hold_key(KC_P4, WINDOW_HOTKEY(KC_P4), record);
            return false;
        case TH_P5:
            tap_custom_shifted_tap_hold_key(KC_P5, WINDOW_HOTKEY(KC_P5), record);
            return false;
        case TH_P6:
            tap_custom_shifted_tap_hold_key(KC_P6, WINDOW_HOTKEY(KC_P6), record);
            return false;
        case TH_P7:
            tap_custom_shifted_tap_hold_key(KC_P7, WINDOW_HOTKEY(KC_P7), record);
            return false;
        case TH_P8:
            tap_custom_shifted_tap_hold_key(KC_P8, WINDOW_HOTKEY(KC_P8), record);
            return false;
        case TH_P9:
            tap_custom_shifted_tap_hold_key(KC_P9, WINDOW_HOTKEY(KC_P9), record);
            return false;
    }
    return true;
}
