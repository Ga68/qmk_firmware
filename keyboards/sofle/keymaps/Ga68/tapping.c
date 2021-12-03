#pragma once

// ----------------
// --- Tap Hold ---
// ----------------
// This will use the Mod-Tap intercept "trick" (as documented by QMK) to provide customizable
//   behavior on any key's hold. The DEFINEs are to help with code legibility.
//   https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap#changing-both-tap-and-hold
// See process_tap_hold_keycode_user to see these keycodes' implementation.

#define TH_NAV_ZOOM LT(_BASE, UKC_NAV)

#define TH_GRV_ESC   LT(_BASE, UKC_GRAVE_ESCAPE)
#define TH_F1_ESC    LT(_BASE, UKC_F1_ESCAPE)
#define TH_COLN_SCLN LT(_BASE, KC_COLON)
#define TH_DOT_IQUS  LT(_BASE, KC_DOT)
#define TH_TILD_MDSH LT(_BASE, UKC_TILDE_EMDASH)
#define TH_TAB_CAPS  LT(_BASE, KC_TAB)

#define TH_SQ_BRCS   LT(_NMSY, UKC_SQUARE_BRACES)
#define TH_CUR_BRCS  LT(_NMSY, UKC_CURLY_BRACES)
#define TH_ANG_BRCS  LT(_NMSY, UKC_ANGLE_BRACES)

#define TH_LEFT_GUI  LT(_NAV, KC_LEFT)
#define TH_RGHT_GUI  LT(_NAV, KC_RIGHT)
#define TH_UP_GUI    LT(_NAV, KC_UP)
#define TH_DOWN_GUI  LT(_NAV, KC_DOWN)

#define WINDOW_HOTKEY MEH

#define TH_P0 LT(_NMSY, KC_P0)
#define TH_P1 LT(_NMSY, KC_P1)
#define TH_P2 LT(_NMSY, KC_P2)
#define TH_P3 LT(_NMSY, KC_P3)
#define TH_P4 LT(_NMSY, KC_P4)
#define TH_P5 LT(_NMSY, KC_P5)
#define TH_P6 LT(_NMSY, KC_P6)
#define TH_P7 LT(_NMSY, KC_P7)
#define TH_P8 LT(_NMSY, KC_P8)
#define TH_P9 LT(_NMSY, KC_P9)

struct tap_hold_keycode_t {
    uint16_t name;
    uint16_t tap_keycode;
    uint16_t hold_keycode;
};

#define CUSTOM_TAP_HOLD_KEY_COUNT 23
struct tap_hold_keycode_t custom_tap_hold_keys[CUSTOM_TAP_HOLD_KEY_COUNT] = {

    { TH_GRV_ESC  , KC_GRAVE , KC_ESCAPE        },
    { TH_F1_ESC   , KC_F1    , KC_ESCAPE        },
    { TH_COLN_SCLN, KC_COLON , KC_SEMICOLON     },
    { TH_DOT_IQUS , KC_PERIOD, UKC_INV_QUESTION },
    { TH_TILD_MDSH, KC_TILDE , UKC_EMDASH       },
    { TH_TAB_CAPS , KC_TAB   , KC_CAPS          },

    { TH_SQ_BRCS , KC_LEFT_BRACE      , KC_RIGHT_BRACE       },
    { TH_CUR_BRCS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE },
    { TH_ANG_BRCS, KC_LEFT_ANGLE_BRACE, KC_RIGHT_ANGLE_BRACE },

    { TH_LEFT_GUI, KC_LEFT, LGUI(KC_LEFT) },
    { TH_RGHT_GUI, KC_RGHT, LGUI(KC_RGHT) },
    { TH_UP_GUI  , KC_UP  , LGUI(KC_UP)   },
    { TH_DOWN_GUI, KC_DOWN, LGUI(KC_DOWN) },

    { TH_P0, KC_P0, WINDOW_HOTKEY(KC_P0) },
    { TH_P1, KC_P1, WINDOW_HOTKEY(KC_P1) },
    { TH_P2, KC_P2, WINDOW_HOTKEY(KC_P2) },
    { TH_P3, KC_P3, WINDOW_HOTKEY(KC_P3) },
    { TH_P4, KC_P4, WINDOW_HOTKEY(KC_P4) },
    { TH_P5, KC_P5, WINDOW_HOTKEY(KC_P5) },
    { TH_P6, KC_P6, WINDOW_HOTKEY(KC_P6) },
    { TH_P7, KC_P7, WINDOW_HOTKEY(KC_P7) },
    { TH_P8, KC_P8, WINDOW_HOTKEY(KC_P8) },
    { TH_P9, KC_P9, WINDOW_HOTKEY(KC_P9) },

};

#ifdef TAPPING_TERM_PER_KEY
    uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case TH_NAV_ZOOM:
                return TAPPING_TERM + 1000;
            case TH_TAB_CAPS:
            case TH_P0:
            case TH_P1:
            case TH_P2:
            case TH_P3:
            case TH_P4:
            case TH_P5:
            case TH_P6:
            case TH_P7:
            case TH_P8:
            case TH_P9:
                return TAPPING_TERM + 250;
            default:
                return TAPPING_TERM;
        }
    }
#endif

// The goal of this function is to send the keycode parameter if tapped, or send the alt_keycode
//   parameter if the held or tapped with shift active. Shift can be active by a shift key being
//   held, or via one-shot-mods. This should be true no matter what the keycode and alt_keycode
//   parameters are.
// It gets a bit tricky when you want to mix and match what's typically shifted or not. For example,
//   you're trying to invert colon and semi-colon. Semi-colon is the unshifted keycode. Your keyboard
//   doesn't actually send a colon keycode, KC_COLON is just an alias for S(KC_SEMICOLON) (shift and
//   semicolon). So the reason there's so much handling below, is to make sure that if you're holding
//   shift (or using a one shot mod), and you want to send a typically-unshifted keycode (like
//   semicolon), then you have to get out of the shifted state first.
void tap_custom_tap_hold(uint16_t tap_keycode, uint16_t hold_keycode, keyrecord_t *record) {
    bool is_left_shift_pressed = get_mods() & MOD_BIT(KC_LEFT_SHIFT);
    bool is_right_shift_pressed = get_mods() & MOD_BIT(KC_RIGHT_SHIFT);
    
    // see if a OSM for shift and only shift is active
    bool is_one_shot_shift_active = (
        (get_oneshot_mods() & MOD_BIT(KC_RIGHT_SHIFT)) == MOD_BIT(KC_RIGHT_SHIFT))
        || ((get_oneshot_mods() & MOD_BIT(KC_LEFT_SHIFT)) == MOD_BIT(KC_LEFT_SHIFT)
    );
    
    // If this is a press event (not hold)
    if (record->tap.count && record->event.pressed) {
        if (is_one_shot_shift_active) {
            clear_oneshot_mods();
            tap_code16_user(hold_keycode);
        }
        else if (is_left_shift_pressed || is_right_shift_pressed) {
            unregister_code(KC_LEFT_SHIFT);
            unregister_code(KC_RIGHT_SHIFT);

            tap_code16_user(hold_keycode);

            if (is_left_shift_pressed ) { register_code(KC_LEFT_SHIFT); }
            if (is_right_shift_pressed) { register_code(KC_RIGHT_SHIFT); }
        }
        else {
            // Note that this is the ONLY branch with the tap_keycode
            tap_code16_user(tap_keycode);
        }
    // If this is a hold event (not press)
    } else if (record->event.pressed) {
        tap_code16_user(hold_keycode);
    }
}


bool process_tap_hold_keycode_user(uint16_t keycode, keyrecord_t *record) {

    for (int i = 0; i < CUSTOM_TAP_HOLD_KEY_COUNT; i = i + 1) {
        if (keycode == custom_tap_hold_keys[i].name) {
            tap_custom_tap_hold(custom_tap_hold_keys[i].tap_keycode, custom_tap_hold_keys[i].hold_keycode, record);
            return false;
        }
    }
    
    switch (keycode) {
        case TH_NAV_ZOOM:
            if (record->tap.count && record->event.pressed) {
                layer_on(_NAV);
            } else if (record->event.pressed) {
                layer_on(_ZOOM);
            }
            return false;
    }
    
    return true;
}
