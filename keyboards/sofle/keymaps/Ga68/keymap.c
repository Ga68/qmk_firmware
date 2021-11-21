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

enum tap_dance_key_codes {
    TD_ESC_CAPS,
    TD_COLN_SCLN,
    TD_LEFT_HOME,
    TD_RGHT_END,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        TD(TD_ESC_CAPS), KC_1, KC_2, KC_3, KC_4, KC_5,                 KC_6, KC_7, KC_8   , KC_9  , KC_0   , TD(TD_COLN_SCLN),
        U_IQUES        , KC_Q, KC_W, KC_F, KC_P, KC_G,                 KC_J, KC_L, KC_U   , KC_Y  , KC_MINS, KC_QUES         ,
        KC_TAB         , KC_A, KC_R, KC_S, KC_T, KC_D,                 KC_H, KC_N, KC_E   , KC_I  , KC_O   , KC_QUOT         ,
        TO(_NAV)       , KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, _____, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT          ,
        
                 KC_LCTL, KC_LALT, KC_LGUI, TO(_NMSY), KC_BSPC, KC_SPC, OSM(MOD_RSFT), KC_RGUI, KC_RALT, KC_RCTL
    ),

    [_NUMPADSYM] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,               KC_F7  , KC_F8, KC_F9, KC_F10, KC_F11 , KC_F12 ,
        KC_TILD, KC_GRV , KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,               KC_SLSH, KC_7 , KC_8 , KC_9  , KC_EQL , KC_PIPE,
        KC_LBRC, KC_RBRC, KC_DLR , KC_PERC, KC_CIRC, KC_LCBR,               KC_ASTR, KC_4 , KC_5 , KC_6  , KC_MINS, KC_PLUS,
        KC_UNDS, KC_BSLS, KC_EXLM, KC_AT  , KC_HASH, KC_RCBR, _____, _____, KC_0   , KC_1 , KC_2 , KC_3  , KC_DOT , KC_ENT ,

                       KC_LCTL, KC_LALT, KC_LGUI, TO(_NAV), KC_BSPC, TO(_BASE), OSM(MOD_RSFT), KC_RGUI, KC_RALT, KC_RCTL
        ),

    [_NAV] = LAYOUT(
        RESET, SGUI(KC_1) , SGUI(KC_2) , SGUI(KC_3) , _____      , _____     ,               _____        , _____           , _____  , _____  , _____          , _____        ,
        _____, _____      , HYPR(KC_P7), HYPR(KC_P8), HYPR(KC_P9), _____     ,               KC_BTN1      , KC_MS_L         , KC_MS_D, KC_MS_U, KC_MS_R        , KC_BTN2      ,
        _____, _____      , HYPR(KC_P4), HYPR(KC_P5), HYPR(KC_P6), _____     ,               RALT(KC_LEFT), TD(TD_LEFT_HOME), KC_DOWN, KC_UP  , TD(TD_RGHT_END), RALT(KC_RGHT),
        _____, HYPR(KC_P0), HYPR(KC_P1), HYPR(KC_P2), HYPR(KC_P3), HYPR(KC_M), _____, _____, _____        , KC_WH_L         , KC_WH_D, KC_WH_U, KC_WH_R        , KC_ENT       ,

                                       KC_LCTL, KC_LALT, KC_LGUI, TO(_NMSY), KC_BSPC, TO(_BASE), OSM(MOD_RSFT), KC_RGUI, KC_RALT, KC_RCTL
        ),

    [_ZOOM] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO     , KC_NO , KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO     , KC_NO , KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO     , KC_NO , KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SGUI(KC_V), KC_NO , KC_NO, KC_NO, KC_NO, KC_NO,

                 KC_NO, KC_NO, KC_NO, TO(_BASE), KC_SPC, TO(_BASE), SGUI(KC_A), KC_SPC, SGUI(KC_S), SGUI(KC_W)
        ),

    [_NUMSYM] = LAYOUT(
        KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,               KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 ,
        KC_UNDS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO,
        _____  , KC_BSLS, KC_PIPE, KC_EQL , KC_PLUS, KC_NO  , KC_NO, KC_NO, KC_DOT , KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_ENT ,
        
                       KC_LCTL, KC_LALT, KC_LGUI, TO(_NAV), KC_BSPC, TO(_BASE), OSM(MOD_RSFT), KC_RGUI, KC_RALT, KC_RCTL) 

};

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
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NUMSYM:
        case _NUMPADSYM:
            oled_write_P(PSTR("NumSy"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav"), false);
            break;
        case _ZOOM:
            oled_write_P(PSTR("Zoom\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

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

// --- --------- ---
// --- Tap Dance ---
// --- --------- ---

extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

uint8_t dance_standard_double_step(qk_tap_dance_state_t *state);
uint8_t dance_standard_double_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

// --- Colon, Semi Colon ---
void on_dance_coln_scln(qk_tap_dance_state_t *state, void *user_data);
void dance_coln_scln_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_coln_scln_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_coln_scln(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}
void dance_coln_scln_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_standard_double_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(KC_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}
void dance_coln_scln_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCLN); break;
    }
    dance_state.step = 0;
}

// --- Left, Home ---
void on_dance_left_home(qk_tap_dance_state_t *state, void *user_data);
void dance_left_home_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_left_home_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_left_home(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}
void dance_left_home_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_standard_double_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}
void dance_left_home_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HOME); break;
    }
    dance_state.step = 0;
}

// --- Right, End ---
void on_dance_rght_end(qk_tap_dance_state_t *state, void *user_data);
void dance_rght_end_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_rght_end_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_rght_end(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RGHT);
        tap_code16(KC_RGHT);
        tap_code16(KC_RGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RGHT);
    }
}
void dance_rght_end_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_standard_double_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_RGHT); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_RGHT); register_code16(KC_RGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RGHT); register_code16(KC_RGHT);
    }
}
void dance_rght_end_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_RGHT); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_RGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_END); break;
    }
    dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    // Colon tap, Semi-Colon hold
    [TD_COLN_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_coln_scln, dance_coln_scln_finished, dance_coln_scln_reset),
    // Left tap, Home hold
    [TD_LEFT_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_left_home, dance_left_home_finished, dance_left_home_reset),
    // Right tap, End hold
    [TD_RGHT_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_rght_end, dance_rght_end_finished, dance_rght_end_reset),
};

