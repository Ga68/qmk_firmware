#pragma once

enum th_keycodes {
    TH_STARTING_POINT = MAX_USER_KEYCODE,
    
    UKC_TH_NAV_ZOOM,

    UKC_TH_BACKSPACE,
    
    UKC_TH_ESC_GRAVE,
    UKC_TH_F1_ESC,
    UKC_TH_COLON_SEMICOLON,
    UKC_TH_DOT_INV_QUES,
    UKC_TH_TILDE_EMDASH,
    UKC_TH_TAB_CAPS,
    
    UKC_TH_SQUARE_BRACES,
    UKC_TH_CURLY_BRACES,
    UKC_TH_ANGLED_BRACES,
        
    UKC_TH_0,
    UKC_TH_1,
    UKC_TH_2,
    UKC_TH_3,
    UKC_TH_4,
    UKC_TH_5,
    UKC_TH_6,
    UKC_TH_7,
    UKC_TH_8,
    UKC_TH_9,
};

// ----------------
// --- Tap Hold ---
// ----------------
// This will use the Mod-Tap intercept "trick" (as documented by QMK) to provide customizable
//   behavior on any key's hold. The DEFINEs are to help with code legibility.
//   https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap#changing-both-tap-and-hold
// See process_tap_hold_keycode_user to see these keycodes' implementation.

#define TH_NAV_ZOOM LT(_BASE, UKC_TH_NAV_ZOOM)

#define TH_BSPACE LT(_BASE, UKC_TH_BACKSPACE)

#define TH_ESC_GRV   LT(_BASE, UKC_TH_ESC_GRAVE      )
#define TH_F1_ESC    LT(_BASE, UKC_TH_F1_ESC         )
#define TH_COLN_SCLN LT(_BASE, UKC_TH_COLON_SEMICOLON)
#define TH_DOT_IQUS  LT(_BASE, UKC_TH_DOT_INV_QUES   )
#define TH_TILD_MDSH LT(_BASE, UKC_TH_TILDE_EMDASH   )
#define TH_TAB_CAPS  LT(_BASE, UKC_TH_TAB_CAPS       )

#define TH_SQ_BRCS   LT(_NMSY, UKC_TH_SQUARE_BRACES)
#define TH_CUR_BRCS  LT(_NMSY, UKC_TH_CURLY_BRACES )
#define TH_ANG_BRCS  LT(_NMSY, UKC_TH_ANGLED_BRACES)

#define WINDOW_HOTKEY MEH
#define TH_0 LT(_NMSY, UKC_TH_0)
#define TH_1 LT(_NMSY, UKC_TH_1)
#define TH_2 LT(_NMSY, UKC_TH_2)
#define TH_3 LT(_NMSY, UKC_TH_3)
#define TH_4 LT(_NMSY, UKC_TH_4)
#define TH_5 LT(_NMSY, UKC_TH_5)
#define TH_6 LT(_NMSY, UKC_TH_6)
#define TH_7 LT(_NMSY, UKC_TH_7)
#define TH_8 LT(_NMSY, UKC_TH_8)
#define TH_9 LT(_NMSY, UKC_TH_9)

typedef struct _tap_hold_keycode_t {
    uint16_t keymap_keycode;
    uint16_t tap_keycode;
    uint16_t hold_keycode;
} tap_hold_keycode_t;

tap_hold_keycode_t custom_tap_hold_keys[] = {

    { TH_ESC_GRV  , KC_ESCAPE, KC_GRAVE         },
    { TH_F1_ESC   , KC_F1    , KC_ESCAPE        },
    { TH_COLN_SCLN, KC_COLON , KC_SEMICOLON     },
    { TH_DOT_IQUS , KC_PERIOD, UKC_INV_QUESTION },
    { TH_TILD_MDSH, KC_TILDE , UKC_EMDASH       },
    { TH_TAB_CAPS , KC_TAB   , KC_CAPS          },

    { TH_SQ_BRCS , KC_LEFT_BRACE      , KC_RIGHT_BRACE       },
    { TH_CUR_BRCS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE },
    { TH_ANG_BRCS, KC_LEFT_ANGLE_BRACE, KC_RIGHT_ANGLE_BRACE },

    { TH_0, KC_0, WINDOW_HOTKEY(KC_0) },
    { TH_1, KC_1, WINDOW_HOTKEY(KC_1) },
    { TH_2, KC_2, WINDOW_HOTKEY(KC_2) },
    { TH_3, KC_3, WINDOW_HOTKEY(KC_3) },
    { TH_4, KC_4, WINDOW_HOTKEY(KC_4) },
    { TH_5, KC_5, WINDOW_HOTKEY(KC_5) },
    { TH_6, KC_6, WINDOW_HOTKEY(KC_6) },
    { TH_7, KC_7, WINDOW_HOTKEY(KC_7) },
    { TH_8, KC_8, WINDOW_HOTKEY(KC_8) },
    { TH_9, KC_9, WINDOW_HOTKEY(KC_9) },

};
uint8_t CUSTOM_TAP_HOLD_KEY_COUNT = sizeof(custom_tap_hold_keys) / sizeof(tap_hold_keycode_t);

#ifdef TAPPING_TERM_PER_KEY
    uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case TH_NAV_ZOOM:
            case TH_TAB_CAPS:
                return TAPPING_TERM + 150;
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
        if (keycode == custom_tap_hold_keys[i].keymap_keycode) {
            tap_custom_tap_hold(custom_tap_hold_keys[i].tap_keycode, custom_tap_hold_keys[i].hold_keycode, record);
            return false;
        }
    }
    
    uint8_t mod_state = get_mods();
    switch (keycode) {
        case TH_NAV_ZOOM:
            if (record->tap.count && record->event.pressed) { // tap
                layer_on(_NAV);
            } else if (record->event.pressed) { // hold
                layer_on(_ZOOM);
            }
            return false;
        case TH_BSPACE:
            // CTRL = Delete and no-CTRL = Backspace
            // HOLD = whole word (ALT) and TAP = normal key press
            {
                uint16_t kc = (mod_state & MOD_MASK_CTRL) ? KC_DELETE : KC_BACKSPACE;

                del_mods(MOD_MASK_CTRL);
                if (record->tap.count && record->event.pressed) { // tap
                    tap_code(kc);
                } else if (record->event.pressed) { // hold
                    tap_code16(LALT(kc));
                }
                set_mods(mod_state);

                return false;
            }
    }
    
    return true;
}
