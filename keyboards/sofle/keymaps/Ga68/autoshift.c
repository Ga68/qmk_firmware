#pragma once

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_MINUS:
        case KC_QUOTE:
            return true;
    }
    return false;
}
