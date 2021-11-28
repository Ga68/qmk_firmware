#pragma once

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0 || index == 1) {
        // For now I'm doing the same thing for both encoders' rotation actions
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    }
    return true;
}
