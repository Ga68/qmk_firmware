#pragma once

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_GRAVE:
        case KC_EQUAL:
        case KC_MINUS:
        case KC_QUOTE:
        case KC_SLASH:
            return true;
    }
    return false;
}
