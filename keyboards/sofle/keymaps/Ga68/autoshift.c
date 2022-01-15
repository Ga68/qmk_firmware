#include QMK_KEYBOARD_H
#include "keymap.h"


bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_GRAVE:
        case KC_EQUAL:
        case KC_MINUS:
        case KC_QUOTE:
        case KC_SLASH:
        case KC_DOT:
        case KC_COMMA:
        case KC_COLON:
        case KC_LEFT_PAREN:
        case KC_RIGHT_PAREN:
        case UKC_ZOOM_LAYER:
        case MT_LC(KC_A):
        case MT_LA(KC_R):
        case MT_LS(KC_S):
        case MT_LG(KC_T):
        case MT_RG(KC_N):
        case MT_RS(KC_E): 
        case MT_RA(KC_I):
        case MT_RC(KC_O):
            return true;
    }
    return false;
}


// code extended from the example on the QMK docs
// https://docs.qmk.fm/#/feature_auto_shift?id=custom-shifted-values
void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_DOT:
            register_code16((!shifted) ? KC_DOT : UKC_INV_QUESTION);
            break;
        case KC_COMMA:
            register_code16((!shifted) ? KC_COMMA : KC_BSLS);
            break;
        case KC_COLON:
            register_code16((!shifted) ? KC_COLON : KC_SEMICOLON);
            break;
        case KC_LEFT_PAREN:
            register_code16((!shifted) ? KC_LEFT_PAREN : KC_LEFT_ANGLE_BRACE);
            break;
        case KC_RIGHT_PAREN:
            register_code16((!shifted) ? KC_RIGHT_PAREN : KC_RIGHT_ANGLE_BRACE);
            break;
        case UKC_ZOOM_LAYER:
            if (shifted) {
                layer_on(_ZOOM);
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
        case KC_DOT:
            unregister_code16((!shifted) ? KC_DOT : UKC_INV_QUESTION);
            break;
        case KC_COMMA:
            unregister_code16((!shifted) ? KC_COMMA : KC_BSLS);
            break;
        case KC_COLON:
            unregister_code16((!shifted) ? KC_COLON : KC_SEMICOLON);
            break;
        case KC_LEFT_PAREN:
            unregister_code16((!shifted) ? KC_LEFT_PAREN : KC_LEFT_ANGLE_BRACE);
            break;
        case KC_RIGHT_PAREN:
            unregister_code16((!shifted) ? KC_RIGHT_PAREN : KC_RIGHT_ANGLE_BRACE);
            break;
        case UKC_ZOOM_LAYER:
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}


#ifdef AUTO_SHIFT_TIMEOUT_PER_KEY
    uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
        switch(keycode) {
            case UKC_ZOOM_LAYER:
                return 2 * get_generic_autoshift_timeout();
            default:
                return get_generic_autoshift_timeout();
        }
    }
#endif
