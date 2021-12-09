#include QMK_KEYBOARD_H
#include "keycodes.h"

// --------------
// --- Layers ---
// --------------

enum my_layers {
    _COLEMAK,
    _NUMPADSYM,
    _NAV,
    _ZOOM,
};
#define _BASE _COLEMAK
#define _NMSY _NUMPADSYM


// ----------------
// --- Features ---
// ----------------

#include "tapping.c"

#ifdef ENCODER_ENABLE
    #include "encoders.c"
#endif
#ifdef OLED_ENABLE
    #include "oled.c"
#endif
#ifdef COMBO_ENABLE
    #include "combos.c"
#endif
#ifdef KEY_OVERRIDE_ENABLE
    #include "overrides.c"
#endif
#ifdef AUTO_SHIFT_ENABLE
    #include "autoshift.c"
#endif


// ---------------------------------
// --- Keymap and Key Processing ---
// ---------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        TH_ESC_GRV  , KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8   , KC_9       , KC_0        , TH_TILD_MDSH,
        TH_TAB_CAPS , KC_Q, KC_W, KC_F, KC_P, KC_G,                   KC_J, KC_L, KC_U   , KC_Y       , TH_COLN_SCLN, KC_MINS     ,
        TH_NAV_ZOOM , KC_A, KC_R, KC_S, KC_T, KC_D,                   KC_H, KC_N, KC_E   , KC_I       , KC_O        , KC_QUOT     ,
        KC_LSFT_LPRN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_MUTE, KC_K, KC_M, KC_COMM, TH_DOT_IQUS, KC_SLASH    , KC_RSFT_RPRN,
        
            KC_LCTL, KC_LALT, KC_LGUI, TO(_NMSY), TH_BSPACE, TH_ENT_AENT, UKC_MEH_SPACE, KC_RGUI, KC_RALT, KC_RCTL
    ),

    [_NUMPADSYM] = LAYOUT(
        TH_ESC_F1   , KC_F2      , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,               KC_F7       , KC_F8, KC_F9, KC_F10, KC_F11, KC_F12      ,
        TH_TAB_CAPS , TH_CUR_BRCS, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,               KC_SLSH     , TH_7 , TH_8 , TH_9  , KC_EQL, KC_MINS     ,
        TH_NAV_ZOOM , TH_ANG_BRCS, KC_DLR , KC_PERC, KC_CROT, KC_BSLS,               KC_ASTR     , TH_4 , TH_5 , TH_6  , TH_0  , KC_PLUS     ,
        KC_LSFT_LPRN, TH_SQ_BRCS , KC_EXLM, KC_AT  , KC_HASH, KC_PIPE, _____, _____, UKC_WDW_FULL, TH_1 , TH_2 , TH_3  , KC_DOT, KC_RSFT_RPRN,

                                        _____, _____, _____, TO(_NAV), _____, _____, TO(_BASE), _____, _____, _____
        ),

    [_NAV] = LAYOUT(
        TH_ESC_GRV  , UKC_CYC_INPT, UKC_INV_CLRS, UKC_SCCP_SEL, UKC_SCCP_FULL, __x__      ,               __x__  , __x__  , __x__  , __x__  , __x__   , __x__  ,
        TH_TAB_CAPS , KC_WH_R     , KC_WH_D     , KC_WH_U     , KC_WH_L      , TH_ENT_AENT,               __x__  , __x__  , __x__  , __x__  , __x__   , __x__  ,
        UKC_WD_LEFT , KC_LEFT     , KC_UP       , KC_DOWN     , KC_RIGHT     , UKC_WD_RGHT,               __x__  , KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT , __x__  ,
        KC_LSFT_LPRN, UKC_UNDO    , UKC_CUT     , UKC_COPY    , UKC_PSTE     , UKC_REDO   , _____, _____, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN2,

                                                            _____, _____, _____, TO(_NMSY), _____, _____, TO(_BASE), _____, _____, _____
        ),

    [_ZOOM] = LAYOUT(
        TH_ESC_GRV , __x__, __x__, __x__, __x__, __x__,               __x__     , __x__ , __x__, __x__      , __x__      , __x__      ,
        TH_TAB_CAPS, __x__, __x__, __x__, __x__, __x__,               __x__     , __x__ , __x__, __x__      , __x__      , __x__      ,
        __x__      , __x__, __x__, __x__, __x__, __x__,               ZM_TG_CAM , __x__ , __x__, __x__      , __x__      , ZM_CLS_MEET,
        __x__      , __x__, __x__, __x__, __x__, __x__, _____, _____, ZM_TG_VIEW, __x__ , __x__, ZM_WDW_FULL, ZM_WDW_HALF, TH_ENT_AENT,

                            _____, _____, _____, __x__, __x__, ZM_TG_AUDO, TO(_BASE), ZM_TG_VIDO, ZM_SCR_SHR, KC_SPC
        ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tap_hold_keycode_user(keycode, record)) {
        return false;
    }

    #ifdef COMBO_ENABLE
        if (!process_combo_keycode_user(keycode, record)) {
            return false;
        }
    #endif

    return true;
}


void tap_code16_user(uint16_t keycode) {
    if (keycode == KC_CAPS) {
        tap_code(KC_CAPS);
    }
    else {
        tap_code16(keycode);
    }
}
