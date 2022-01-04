#pragma once

#include "caps_word.h"

bool process_caps_word(uint16_t keycode, keyrecord_t* record) {
  static bool shifted = false;
#ifndef NO_ACTION_ONESHOT
  const uint8_t mods = get_mods() | get_oneshot_mods();
#else
  const uint8_t mods = get_mods();
#endif  // NO_ACTION_ONESHOT

  if (!CAPS_WORD_caps_word_enabled) {
    // Pressing a custom keycode enables caps word.
    if (keycode == UKC_CAPS_WORD) {
      shifted = false;
      CAPS_WORD_caps_word_enabled = true;
      return false;
    }
    return true;
  }

  if (!record->event.pressed) { return true; }

  if (!(mods & ~MOD_MASK_SHIFT)) {
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        // Earlier return if this has not been considered tapped yet.
        if (record->tap.count == 0) { return true; }
        // Get the base tapping keycode of a mod- or layer-tap key.
        keycode &= 0xff;
    }

    switch (keycode) {
      // Letter keys should be shifted.
      case KC_A ... KC_Z:
        if (!shifted) { register_code(KC_LSFT); }
        shifted = true;
        return true;

      // Keycodes that continue caps word but shouldn't get shifted.
      case KC_1 ... KC_0:
      case KC_BSPC:
      case KC_MINS:
      case KC_UNDS:
        if (shifted) { unregister_code(KC_LSFT); }
        shifted = false;
        return true;

      // Any other keycode disables caps word.
    }
  }

  // Disable caps word.
  CAPS_WORD_caps_word_enabled = false;
  if (shifted) { unregister_code(KC_LSFT); }
  shifted = false;
  return true;
}
