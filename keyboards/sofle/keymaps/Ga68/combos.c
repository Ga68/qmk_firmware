#pragma once

// CB_xxx key codes are defined in keycodes.h since they have to be consolidated with others
//   to respect SAFE_RANGE

const uint16_t PROGMEM combo_braces[]       = {KC_LEFT_BRACE      , KC_RIGHT_BRACE      , COMBO_END};
const uint16_t PROGMEM combo_curly_braces[] = {KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, COMBO_END};
const uint16_t PROGMEM combo_angle_braces[] = {KC_LEFT_ANGLE_BRACE, KC_RIGHT_ANGLE_BRACE, COMBO_END};

uint16_t COMBO_LEN = 3;
combo_t key_combos[] = {
    COMBO(combo_braces, CB_BRACES),
    COMBO(combo_curly_braces, CB_CURLY_BRACES),
    COMBO(combo_angle_braces, CB_ANGLE_BRACES),
};

bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
