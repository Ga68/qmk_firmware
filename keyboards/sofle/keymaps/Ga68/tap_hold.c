#include "tap_hold.h"
#include "keymap.h"


enum tap_hold_key_types {
    // Acts like a key where the normal press is tap and the shifted press is hold, and additionally
    // if you hold the key, it acts like Shift was pressed.
    THT_SHIFT,
    // Acts like a key where the normal press is tap does one key (regardless of mod status) and 
    // hold does the alternative key (again, regardless of mod status).
    THT_TAP_HOLD,
};

typedef struct _tap_hold_keycode_t {
    uint16_t keymap_keycode;
    uint16_t primary_keycode;
    uint16_t alt_keycode;
    enum tap_hold_key_types tap_hold_type;
} tap_hold_keycode_t;

tap_hold_keycode_t custom_tap_hold_keys[] = {
    { TH_0  , KC_0  , WINDOW_HOTKEY(KC_0)  , THT_TAP_HOLD },
    { TH_1  , KC_1  , WINDOW_HOTKEY(KC_1)  , THT_TAP_HOLD },
    { TH_2  , KC_2  , WINDOW_HOTKEY(KC_2)  , THT_TAP_HOLD },
    { TH_3  , KC_3  , WINDOW_HOTKEY(KC_3)  , THT_TAP_HOLD },
    { TH_4  , KC_4  , WINDOW_HOTKEY(KC_4)  , THT_TAP_HOLD },
    { TH_5  , KC_5  , WINDOW_HOTKEY(KC_5)  , THT_TAP_HOLD },
    { TH_6  , KC_6  , WINDOW_HOTKEY(KC_6)  , THT_TAP_HOLD },
    { TH_7  , KC_7  , WINDOW_HOTKEY(KC_7)  , THT_TAP_HOLD },
    { TH_8  , KC_8  , WINDOW_HOTKEY(KC_8)  , THT_TAP_HOLD },
    { TH_9  , KC_9  , WINDOW_HOTKEY(KC_9)  , THT_TAP_HOLD },

};
uint8_t CUSTOM_TAP_HOLD_KEY_COUNT = sizeof(custom_tap_hold_keys) / sizeof(tap_hold_keycode_t);

#ifdef TAPPING_TERM_PER_KEY
    uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            default:
                return TAPPING_TERM;
        }
    }
#endif

enum tap_hold_actions tap_hold_action(keyrecord_t *record) {
    if (record->tap.count && record->event.pressed) {
        return THA_TAP;
    } else if (record->event.pressed) {
        return THA_HOLD;
    }
    
    return THA_OTHER;
}

// The goal here is to customize how each of four different combinations of key presses work, on
// a single key. It uses the TAP and HOLD tap types, and a mod (CTRL, SHIFT, etc.) applied, or not.
// The mod (ex. MOD_MASK_SHIFT) is removed during the key press action since it's designed to alter
// what happens, not the actual key press itself.
//
// This is like a combination of auto-shift (shift a key when held) and over-rides (output something
// bespoke when a key is pressed with a mod).
void process_custom_tap_hold_mod(uint16_t tap, uint16_t tap_mod, uint16_t hold, uint16_t hold_mod, uint8_t mod_mask, keyrecord_t *record) {
    enum tap_hold_actions tha_action = tap_hold_action(record);
    if (tha_action == THA_OTHER) { return; }
    
    uint8_t mod_state = get_mods();
    bool is_mod_on = (mod_state & mod_mask);
    del_mods(mod_mask); // clear the mod-mask so it doesn't alter the actual key press
    if (tha_action == THA_TAP) {
        if (is_mod_on) { tap_code16(tap_mod); }
        else           { tap_code16(tap);     }
    }
    else if (tha_action == THA_HOLD) {
        if (is_mod_on) { tap_code16(hold_mod); }
        else           { tap_code16(hold);     }
    }
    set_mods(mod_state); // restore mods to what they were before we starte         
}


bool process_tap_hold_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }

    // cycle through all the pre-defined codes to see if they've been tapped or held
    for (int i = 0; i < CUSTOM_TAP_HOLD_KEY_COUNT; i = i + 1) {
        if (keycode == custom_tap_hold_keys[i].keymap_keycode) {
            switch (custom_tap_hold_keys[i].tap_hold_type) {
                case THT_SHIFT:
                    process_custom_tap_hold_mod(
                        custom_tap_hold_keys[i].primary_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        MOD_MASK_SHIFT,
                        record
                    );
                    return false;
                case THT_TAP_HOLD:
                    process_custom_tap_hold_mod(
                        custom_tap_hold_keys[i].primary_keycode,
                        custom_tap_hold_keys[i].primary_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        custom_tap_hold_keys[i].alt_keycode,
                        0,
                        record
                    );
                    return false;
            }
        }
    }

    return true;
}
