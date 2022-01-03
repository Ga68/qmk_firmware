#include QMK_KEYBOARD_H
#include "keycodes.h"

// --------------
// --- Layers ---
// --------------

enum my_layers {
    _BASE,
    _NUM,
    _SYM,
    _NAV,
    _MOUSE,
    _ZOOM,
};

#define MT_LG(k) MT(MOD_LGUI, k)
#define MT_LA(k) MT(MOD_LALT, k)
#define MT_LC(k) MT(MOD_LCTL, k)
#define MT_LS(k) MT(MOD_LSFT, k)
#define MT_RG(k) MT(MOD_RGUI, k)
#define MT_RA(k) MT(MOD_RALT, k)
#define MT_RC(k) MT(MOD_RCTL, k)
#define MT_RS(k) MT(MOD_RSFT, k)

// ----------------
// --- Features ---
// ----------------

#include "tapping.c"
#include "caps_word.c"

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

    [_BASE] = LAYOUT(
        TH_ZOOM     , KC_1       , KC_2       , KC_3       , KC_4       , KC_5,                   KC_6, KC_7       , KC_8       , KC_9       , KC_0        , KC_CAPS     ,
        KC_GRAVE    , KC_Q       , KC_W       , KC_F       , KC_P       , KC_G,                   KC_J, KC_L       , KC_U       , KC_Y       , TH_COLN_SCLN, KC_EQL      ,
        KC_MINS     , MT_LC(KC_A), MT_LA(KC_R), MT_LS(KC_S), MT_LG(KC_T), KC_D,                   KC_H, MT_RG(KC_N), MT_RS(KC_E), MT_RA(KC_I), MT_RC(KC_O) , KC_QUOT     ,
        TH_OPEN_BRCS, KC_Z       , KC_X       , KC_C       , KC_V       , KC_B, KC_MUTE, KC_MUTE, KC_K, KC_M       , KC_COMM    , TH_DOT_IQUS, KC_SLASH    , TH_CLOS_BRCS,
        
            __x__, __x__, LT(_NAV, KC_DELETE), LT(_NUM, KC_BACKSPACE), LT(_SYM, KC_TAB), MT(MOD_MEH, KC_ENTER), LT(_NAV, KC_SPACE), LT(_MOUSE, KC_ESC), __x__, __x__
    ),

    [_NUM] = LAYOUT(
        __x__, __x__  , __x__  , __x__    , __x__  , __x__,               __x__ , __x__, __x__, __x__, __x__  , __x__   ,
        __x__, __x__  , __x__  , __x__    , __x__  , __x__,               __x__ , TH_7 , TH_8 , TH_9 , __x__  , __x__   ,
        __x__, KC_LCTL, KC_LALT, KC_LSHIFT, KC_LGUI, __x__,               TH_EQL, TH_4 , TH_5 , TH_6 , KC_PLUS, KC_MINS ,
        __x__, __x__  , __x__  , __x__    , __x__  , __x__, __x__, __x__, __x__ , TH_1 , TH_2 , TH_3 , KC_ASTR, KC_SLASH,

                                _____, _____, _____, _____, _____, UKC_WDW_FULL, TH_0, KC_DOT, _____, _____
        ),

    [_SYM] = LAYOUT(
        __x__, __x__  , __x__  , __x__    , __x__  , __x__,               __x__, __x__  , __x__  , __x__  , __x__    , __x__,
        __x__, __x__  , __x__  , __x__    , __x__  , __x__,               __x__, S(KC_7), S(KC_8), __x__  , __x__    , __x__,
        __x__, KC_LCTL, KC_LALT, KC_LSHIFT, KC_LGUI, __x__,               __x__, S(KC_4), S(KC_5), S(KC_6), KC_PIPE  , __x__,
        __x__, __x__  , __x__  , __x__    , __x__  , __x__, __x__, __x__, __x__, S(KC_1), S(KC_2), S(KC_3), KC_BSLS, __x__,

                                _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
        ),

    [_NAV] = LAYOUT(
        __x__, __x__      , __x__  , __x__   , __x__   , __x__      ,               __x__  , __x__  , __x__  , __x__  , __x__   , __x__,
        __x__, __x__      , __x__  , KC_UP   , __x__   , __x__      ,               __x__  , __x__  , __x__  , __x__  , __x__   , __x__,
        __x__, UKC_WD_LEFT, KC_LEFT, KC_DOWN , KC_RIGHT, UKC_WD_RGHT,               __x__  , KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL , __x__,
        __x__, UKC_UNDO   , UKC_CUT, UKC_COPY, UKC_PSTE, UKC_REDO   , _____, _____, __x__  , __x__  , __x__  , __x__  , __x__   , __x__,

                                          _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
        ),

    [_MOUSE] = LAYOUT(
        __x__, __x__   , __x__  , __x__   , __x__   , __x__   ,               __x__  , __x__  , __x__  , __x__  , __x__   , __x__  ,
        __x__, __x__   , KC_MS_U, KC_WH_R , KC_WH_D , KC_WH_L ,               __x__  , __x__  , __x__  , __x__  , __x__   , __x__  ,
        __x__, KC_MS_L , KC_MS_D, KC_MS_R , KC_WH_U , __x__   ,               __x__  , KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL , __x__  ,
        __x__, UKC_UNDO, UKC_CUT, UKC_COPY, UKC_PSTE, UKC_REDO, _____, _____, __x__, __x__  , __x__  , __x__    , __x__  , __x__,

                                _____, _____, _____, KC_BTN1, KC_BTN2, _____, _____, _____, _____, _____
        ),

    [_ZOOM] = LAYOUT(
        TO(_BASE), __x__, __x__, __x__, __x__, __x__,               __x__     , __x__, __x__, __x__      , __x__      , TO(_BASE)  ,
        __x__    , __x__, __x__, __x__, __x__, __x__,               __x__     , __x__, __x__, __x__      , __x__      , __x__      ,
        __x__    , __x__, __x__, __x__, __x__, __x__,               __x__     , __x__, __x__, __x__      , __x__      , ZM_CLS_MEET,
        __x__    , __x__, __x__, __x__, __x__, __x__, _____, _____, ZM_TG_VIEW, __x__, __x__, ZM_WDW_FULL, ZM_WDW_HALF, KC_ENTER   ,

                          _____, _____, _____, _____, _____, ZM_TG_AUDO, ZM_TG_VIDO, KC_SPC, __x__, __x__
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
