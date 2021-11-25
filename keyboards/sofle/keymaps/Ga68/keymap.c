#include QMK_KEYBOARD_H
#include "keymap.h"

enum sofle_layers {
    _COLEMAK,
    _NUMPADSYM,
    _NAV,
    _ZOOM,
    _NUMSYM,
};

#define _BASE _COLEMAK
#define _NMSY _NUMPADSYM

// Custom Tap-Hold behaviors
// This will use the Mod-Tap intercept "trick" (as documented by QMK) to provide customizable
//   behavior on any key. The DEFINEs are just to help with code legibility.
// 
//   https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap#changing-both-tap-and-hold
#define TH_Z_ZOOM LT(0, KC_Z)
#define TH_ESC_CAPS LT(0, KC_ESC)
#define TH_COLN_SCLN LT(0, KC_COLN)
#define TH_LEFT_HOME LT(0, KC_LEFT)
#define TH_RGHT_END LT(0, KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        TH_ESC_CAPS, KC_1     , KC_2, KC_3, KC_4, KC_5,                 KC_6, KC_7, KC_8   , KC_9  , KC_0   , TH_COLN_SCLN,
        U_IQUES    , KC_Q     , KC_W, KC_F, KC_P, KC_G,                 KC_J, KC_L, KC_U   , KC_Y  , KC_MINS, KC_QUES     ,
        KC_TAB     , KC_A     , KC_R, KC_S, KC_T, KC_D,                 KC_H, KC_N, KC_E   , KC_I  , KC_O   , KC_QUOT     ,
        TO(_NAV)   , TH_Z_ZOOM, KC_X, KC_C, KC_V, KC_B, KC_MUTE, _____, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT      ,
        
                  KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, TO(_NMSY), OSM(MOD_RSFT), KC_SPC, KC_RGUI, KC_RALT, KC_RCTL
    ),

    [_NUMPADSYM] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,               KC_F7  , KC_F8, KC_F9, KC_F10, KC_F11 , KC_F12 ,
        KC_TILD, KC_GRV , KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,               KC_SLSH, KC_7 , KC_8 , KC_9  , KC_EQL , KC_PIPE,
        KC_LBRC, KC_RBRC, KC_DLR , KC_PERC, KC_CIRC, KC_LCBR,               KC_ASTR, KC_4 , KC_5 , KC_6  , KC_MINS, KC_PLUS,
        KC_UNDS, KC_BSLS, KC_EXLM, KC_AT  , KC_HASH, KC_RCBR, _____, _____, KC_0   , KC_1 , KC_2 , KC_3  , KC_DOT , KC_ENT ,

                       KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, TO(_NAV), OSM(MOD_RSFT), TO(_BASE), KC_RGUI, KC_RALT, KC_RCTL
        ),

    [_NAV] = LAYOUT(
        RESET, SGUI(KC_1) , SGUI(KC_2) , SGUI(KC_3) , _____      , _____     ,               _____        , _____       , _____  , _____  , _____      , _____        ,
        _____, _____      , HYPR(KC_P7), HYPR(KC_P8), HYPR(KC_P9), _____     ,               KC_BTN1      , KC_MS_L     , KC_MS_D, KC_MS_U, KC_MS_R    , KC_BTN2      ,
        _____, _____      , HYPR(KC_P4), HYPR(KC_P5), HYPR(KC_P6), _____     ,               RALT(KC_LEFT), TH_LEFT_HOME, KC_DOWN, KC_UP  , TH_RGHT_END, RALT(KC_RGHT),
        _____, HYPR(KC_P0), HYPR(KC_P1), HYPR(KC_P2), HYPR(KC_P3), HYPR(KC_M), _____, _____, _____        , KC_WH_R     , KC_WH_U, KC_WH_D, KC_WH_L    , KC_ENT       ,

                                       KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, TO(_NMSY), OSM(MOD_RSFT), TO(_BASE), KC_RGUI, KC_RALT, KC_RCTL
        ),

    [_ZOOM] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO     , KC_NO , KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO     , KC_NO , KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO     , KC_NO , KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SGUI(KC_V), KC_NO , KC_NO, KC_NO, KC_NO, KC_NO,

                KC_NO, KC_NO, KC_NO, KC_SPC, SGUI(KC_V), SGUI(KC_A), TO(_BASE), KC_SPC, SGUI(KC_S), SGUI(KC_W)
        ),

    [_NUMSYM] = LAYOUT(
        KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,               KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 ,
        KC_UNDS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO,
        _____  , KC_BSLS, KC_PIPE, KC_EQL , KC_PLUS, KC_NO  , KC_NO, KC_NO, KC_DOT , KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_ENT ,
        
                       KC_LCTL, KC_LALT, KC_LGUI, TO(_NAV), KC_BSPC, TO(_BASE), OSM(MOD_RSFT), KC_RGUI, KC_RALT, KC_RCTL) 

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_Z_ZOOM:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_Z);
            } else if (record->event.pressed) {
                layer_on(_ZOOM);
            }
            return false;
        case TH_ESC_CAPS:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_ESC);
            } else if (record->event.pressed) {
                tap_code(KC_CAPSLOCK);
            }
            return false;
        case TH_COLN_SCLN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
            } else if (record->event.pressed) {
                tap_code(KC_SCLN);
            }
            return false;
        case TH_LEFT_HOME:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_LEFT);
            } else if (record->event.pressed) {
                tap_code16(LGUI(KC_LEFT));
            }
            return false;
        case TH_RGHT_END:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RGHT);
            } else if (record->event.pressed) {
                tap_code16(LGUI(KC_RGHT));
            }
            return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_Z_ZOOM:
            return TAPPING_TERM + 1000;
        case TH_ESC_CAPS:
            return TAPPING_TERM + 500;
        default:
            return TAPPING_TERM;
    }
}

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current layer
    oled_write_P(PSTR("\n\n"), false);
    int ls = get_highest_layer(layer_state);
    oled_write_P(PSTR("Base\n\n"), ls==_BASE);
    oled_write_P(PSTR("NumSy\n"), ls==_NMSY);
    oled_write_P(PSTR("Nav\n\n"), ls==_NAV);
    oled_write_P(PSTR("Zoom\n\n"), ls==_ZOOM);

    // Caps Lock
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else if (false) {
    // leaving it this way, false, so it'll never run, but the compiler doesn't error on me by
    // saying that "render_logo" is never used. I may want to use it in the future.
        render_logo();
    }
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // if (clockwise) {
        //     tap_code(KC_PGDOWN);
        // } else {
        //     tap_code(KC_PGUP);
        // }
    }
    return true;
}

#endif


// --- ---------- ---
// --- Auto Shift ---
// --- ---------- ---

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COMM:
        case KC_DOT:
        case KC_QUOT:
        case KC_A ... KC_Y:
            return true;
    }
    return false;
}
