#include QMK_KEYBOARD_H
#include "keymap.h"


#ifdef AUTO_SHIFT_TIMEOUT_PER_KEY
    uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
        switch(keycode) {
            case KC_MINUS:
                return 0.8 * get_generic_autoshift_timeout();
            default:
                return get_generic_autoshift_timeout();
        }
    }
#endif


bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_MINUS:
        case KC_SLASH:
        case KC_QUOTE:
        case KC_ENTER:
        case KC_GRAVE:
        case KC_LEFT_SQUARE_BRACE:
        case KC_LEFT_CURLY_BRACE:
        case KC_LEFT_PAREN:
        case UKC_INV_QUESTION:
        case KC_LEFT_ANGLE_BRACE:
        case KC_RIGHT_ANGLE_BRACE:
        case MT_LC(KC_A):
        case MT_LA(KC_R):
        case MT_LS(KC_S):
        case MT_LG(KC_T):
        case MT_RG(KC_N):
        case MT_RS(KC_E): 
        case MT_RA(KC_I):
        case MT_RC(KC_O):
        case UKC_DOLLAR_M:
        case UKC_DOLLAR_K:
        case UKC_DOLLAR_B:
            return true;
    }
    return false;
}


// code extended from the example on the QMK docs
// https://docs.qmk.fm/#/feature_auto_shift?id=custom-shifted-values
void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case UKC_DOLLAR_M:
            if (shifted) {
                SEND_STRING("$M");
            }
            else {
                SEND_STRING("M");
            }
            break;
        case UKC_DOLLAR_K:
            if (shifted) {
                SEND_STRING("$K");
            }
            else {
                SEND_STRING("K");
            }
            break;
        case UKC_DOLLAR_B:
            if (shifted) {
                SEND_STRING("$B");
            }
            else {
                SEND_STRING("B");
            }
            break;
        case KC_SLASH:
            register_code16((!shifted) ? KC_SLASH : KC_BSLS);
            break;
        case KC_GRAVE:
            if (shifted) {
                SEND_STRING("```");
            }
            else {
                register_code16(KC_GRAVE);
            }
            break;            break;
        case KC_ENTER:
            if (shifted) {
                tap_code16(RALT(KC_ENTER));
            }
            else {
                register_code16(KC_ENTER);
            }
            break;
        case KC_LEFT_SQUARE_BRACE:
            if (shifted) {
                SEND_STRING("[]"SS_TAP(X_LEFT));
            }
            else {
                register_code16(KC_LEFT_SQUARE_BRACE);
            }
            break;
        case KC_LEFT_CURLY_BRACE:
            if (shifted) {
                SEND_STRING("{}"SS_TAP(X_LEFT));
            }
            else {
                register_code16(KC_LEFT_CURLY_BRACE);
            }
            break;
        case KC_LEFT_PAREN:
            if (shifted) {
                SEND_STRING("()"SS_TAP(X_LEFT));
            }
            else {
                register_code16(KC_LEFT_PAREN);
            }
            break;
        case UKC_INV_QUESTION:
            tap_code16(UKC_INV_QUESTION);
            if (shifted) {
                tap_code16(KC_QUESTION);
                tap_code16(KC_LEFT);
            }
            break;
        case KC_LEFT_ANGLE_BRACE:
            if (shifted) {
                SEND_STRING("<=");
            }
            else {
                register_code16(KC_LEFT_ANGLE_BRACE);
            }
            break;
        case KC_RIGHT_ANGLE_BRACE:
            if (shifted) {
                SEND_STRING(">=");
            }
            else {
                register_code16(KC_RIGHT_ANGLE_BRACE);
            }
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}


void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_SLASH:
            unregister_code16((!shifted) ? KC_SLASH : KC_BSLS);
            break;
        case KC_ENTER:
            if (!shifted) {
                unregister_code16(KC_ENTER);
            }
        case KC_GRAVE:
            if (!shifted) {
                unregister_code16(KC_GRAVE);
            }
        case KC_LEFT_SQUARE_BRACE:
            if (!shifted) {
                unregister_code16(KC_LEFT_SQUARE_BRACE);
            }
        case KC_LEFT_CURLY_BRACE:
            if (!shifted) {
                unregister_code16(KC_LEFT_CURLY_BRACE);
            }
        case KC_LEFT_PAREN:
            if (!shifted) {
                unregister_code16(KC_LEFT_PAREN);
            }
        case KC_LEFT_ANGLE_BRACE:
            if (!shifted) {
                unregister_code16(KC_LEFT_ANGLE_BRACE);
            }
        case KC_RIGHT_ANGLE_BRACE:
            if (!shifted) {
                unregister_code16(KC_RIGHT_ANGLE_BRACE);
            }
        case UKC_INV_QUESTION:
        case UKC_DOLLAR_M:
        case UKC_DOLLAR_K:
        case UKC_DOLLAR_B:
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

