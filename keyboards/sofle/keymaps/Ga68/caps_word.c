/* The general idea is that when you want to do caps word, then toggle on caps lock until a
   breaking character happens, and then turn off caps lock. Despite the mechanism for caps word
   being using caps lock, you should think of them as two separate states. If you're in one, you
   can't be in the other. So if you're in caps word, and then hit caps lock, you move to caps lock
   and remove (disable) caps word. You'll have capital letters until you turn off caps lock, at
   which point you're back to normal (NOT in caps word again).

   If you're going to use this caps word implementation, it's probably best not to use the standard
   KC_CAPS_LOCK key, since simply toggling that will not check, and potentially alter, the caps 
   word status. Instead you'll want to use the toggle_caps_[word/lock] functions to do that. That
   means that if you want to use KC_CAPS_LOCK on a separate key, as opposed to a tap-hold with caps
   word, then you'll likely need to use a custom key code and process_record_user to do this
   properly.
*/

#pragma once

#include "caps_word.h"

void toggle_caps_word(void) {
  led_t led_usb_state = host_keyboard_led_state();
  // toggle the caps_word status
  g_caps_word_enabled = !g_caps_word_enabled;
  // The caps word layer is fully transparent so actually accomplishes nothing, for key presses,
  // however, to get a split keyboard's oled to know state on the non-master side, a layer is 
  // easier to use than custom communication across the halves.
  if (g_caps_word_enabled) { layer_on(_CAPS_WORD); }
  else                     { layer_off(_CAPS_WORD); }

  // if the caps_word status and the caps lack status are out of sync, then toggle caps_lock
  // to re-sync them
  if (g_caps_word_enabled != led_usb_state.caps_lock) { tap_code16(KC_CAPS_LOCK); }
}


void toggle_caps_lock(void) {
  // If we're in caps word and want to move to caps lock, all we have to do is disable caps word
  // (which will mean that a breaking character NO LONGER turns off caps), which will turn off the
  // caps lock mechanism, but then be sure to cycle it right back on. If we weren't in caps word,
  // then we're just toggling caps lock via a key press.
  // Ideally we wouldn't toggle caps off, then right back on when going from caps word into caps
  // caps lock; however, because we have to cycle not just the caps_word_enabled status, but also
  // the layer (for OLED purposes), it seems simpler to just do the extra toggle and keep all that
  // state in sync.
  if (g_caps_word_enabled) { toggle_caps_word(); }
  tap_code16(KC_CAPS_LOCK);
}


bool process_caps_word(uint16_t keycode, keyrecord_t* record) {

  if (!g_caps_word_enabled) { return true; }
  if (!record->event.pressed) { return true; }

  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      // Earlier return if this has not been considered tapped yet.
      if (record->tap.count == 0) { return true; }
      // Get the base tapping keycode of a mod- or layer-tap key.
      keycode &= 0xff;
  }

  switch (keycode) {
    // Letter keys that do NOT turn off caps lock.
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_MINS:
    case KC_UNDS:
      return true;
  }

  // Anything other than the above keys, disables caps word.
  toggle_caps_word();
  return true;
}
