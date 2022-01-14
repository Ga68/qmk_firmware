/* The general idea is that when you want to do caps word, then toggle on caps lock until a
   breaking character happens, and then turn off caps lock. Despite the mechanism for caps word
   being using caps lock, you should think of them as two separate states. If you're in one, you
   can't be in the other. So if you're in caps word, and then hit caps lock, you move to caps lock
   and remove (disable) caps word. You'll have capital letters until you turn off caps lock, at
   which point you're back to normal (NOT in caps word again).

   If you're going to use this caps word implementation, it's probably best not to process
   CAPS_LOCK traditionally. Below you'll find that KC_CAPS_LOCK is intercepted by process_caps_word
   and returns false, thus preventing further processing by the rest of the quanum code.
*/

#include "caps_word.h"
#include "keymap.h"

bool g_caps_word_enabled = false;

void caps_word_on(void) {
  g_caps_word_enabled = true;
  // The caps word layer is fully transparent so actually accomplishes nothing, for key presses,
  // however, to get a split keyboard's oled to know state on the non-master side, a layer is 
  // easier to use than custom communication across the halves.
  layer_on(_CAPS_WORD);
  if (!host_keyboard_led_state().caps_lock) { tap_code16(KC_CAPS_LOCK); }
}


void caps_word_off_lock_untouched(void) {
  g_caps_word_enabled = false;
  layer_off(_CAPS_WORD);
}


void caps_word_off(void) {
  caps_word_off_lock_untouched();
  if (host_keyboard_led_state().caps_lock) { tap_code16(KC_CAPS_LOCK); }
}


void toggle_caps_word(void) {
  g_caps_word_enabled = !g_caps_word_enabled;  // toggle the caps_word status
  if (g_caps_word_enabled) { caps_word_on();  }
  else                     { caps_word_off(); }
}


void toggle_caps_lock(void) {
  // If we're in caps word and want to move to caps lock, all we have to do is disable caps word
  // (which will mean that a breaking character NO LONGER turns off caps), but we don't want to
  // turn off caps lock, since we're going into it. If we're not in caps_word, then just toggle
  // caps_lock as normal with a tap.
  if (g_caps_word_enabled) { caps_word_off_lock_untouched(); }
  else                     { tap_code16(KC_CAPS_LOCK);       }
}


bool process_caps_word(uint16_t keycode, keyrecord_t* record) {

  if (!record->event.pressed) { return true; }

  switch (keycode) {
    case UKC_CAPS_WORD:
      toggle_caps_word();
      return false;
    case KC_CAPS_LOCK:
      toggle_caps_lock();
      return false;
  }
  
  if (!g_caps_word_enabled) { return true; }

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

  // Anything other than the above keys, disables caps word and returns true so that the keypress
  // is handled as normal
  caps_word_off();
  return true;
}
