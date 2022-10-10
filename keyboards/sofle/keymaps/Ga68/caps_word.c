#include "caps_word.h"
#include "layers.h"
#include "keymap.h"

caps_word_mode_t g_caps_word_mode = CAPS_WORD_MODE_DEFAULT;

bool caps_word_press_user(uint16_t keycode) {
    switch(g_caps_word_mode) {
        case CWMODE_NORMAL:
            switch (keycode) {
                // Keycodes that continue Caps Word, with shift applied.
                case KC_A ... KC_Z:
                    add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
                    return true;

                // Keycodes that continue Caps Word, without shifting.
                case KC_1 ... KC_0:
                case KC_BSPC:
                case KC_MINS:
                case KC_UNDS:
                    return true;

                default:
                    return false;  // Deactivate Caps Word.
            }
        case CWMODE_NUM_LOCK:
            switch (keycode) {
                // Keycodes that continue Caps Word, without shifting.
                case KC_1 ... KC_0:
                case KC_PERIOD:
                case KC_COMMA:
                case KC_BSPC:
                    return true;

                default:
                    return false;  // Deactivate Caps Word.
            }
        case CWMODE_ARROW_SHIFT:
            switch (keycode) {
                // Keycodes that continue Caps Word, without shifting.
                case KC_LEFT:
                case KC_RIGHT:
                case KC_UP:
                case KC_DOWN:
                case A(KC_LEFT):
                case A(KC_RIGHT):
                case A(KC_UP):
                case A(KC_DOWN):
                case G(KC_LEFT):
                case G(KC_RIGHT):
                case G(KC_UP):
                case G(KC_DOWN):
                    add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
                    return true;

                default:
                    return false;  // Deactivate Caps Word.
            }

        default:
            return false;
    }
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        layer_on(_CAPS_WORD);
        autoshift_disable();
    } else {
        // Do something when Caps Word deactivates.
        layer_off(_CAPS_WORD);
        autoshift_enable();
        // If leaving the num_lock mode, then we need to exit that layer
        if (g_caps_word_mode == CWMODE_NUM_LOCK) {
            layer_off(_LOWER);  // leave the numbers layer
        }
        // Go back to make sure that when it turns on next without any sepcification (ex. through
        // the CAPS_WORD key), it's in the default caps_word mode
        g_caps_word_mode = CAPS_WORD_MODE_DEFAULT;
    }
}

// Toggles caps word for the given mode. If that mode is already on, then it's getting turned off.
// If it's a new mode (or caps word isn't on at all), the old one will cycle off, then the new
// one will turn on. Returns true if caps word (in any mode) is on after the call.
bool toggle_caps_word_mode(caps_word_mode_t new_mode) {
    // remember the old settings before we turn it off since that will clear these values
    bool caps_word_was_off = !is_caps_word_on();
    caps_word_mode_t prior_mode = g_caps_word_mode;
    // want to cycle it off, regardless of whether we're going to turn something else on, so that
    // any "wrap up code" (ex. function caps_word_set_user) can execute between the change.
    caps_word_off();
    // if it wasn't on (and thus we're toggling it on) or we're going into a new mode
    if (caps_word_was_off || prior_mode != new_mode) {
        caps_word_on();
        g_caps_word_mode = new_mode;
        // if we're going into num_lock, then switch into the numbers layer
        if (g_caps_word_mode == CWMODE_NUM_LOCK) {
            layer_on(_LOWER);
        }
    }
    return is_caps_word_on();
}
