#pragma once

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_GRAVE:
        case KC_EQUAL:
        case KC_MINUS:
        case KC_QUOTE:
        case KC_SLASH:
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

// pick up here and look into using custom auto-shift values instead of the tap-hold code
// https://docs.qmk.fm/#/feature_auto_shift?id=custom-shifted-values
