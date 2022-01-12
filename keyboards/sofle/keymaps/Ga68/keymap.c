#include QMK_KEYBOARD_H

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
    _CAPS_WORD,
};

// ----------------
// --- Features ---
// ----------------

#include "keycodes.h"
#include "tapping.c"
#include "caps_word.c"

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
        TH_ZOOM      , KC_1       , KC_2       , KC_3       , KC_4       , KC_5,                   KC_6, KC_7       , KC_8       , KC_9       , KC_0       , KC_CAPS_LOCK  ,
        KC_GRAVE     , KC_Q       , KC_W       , KC_F       , KC_P       , KC_G,                   KC_J, KC_L       , KC_U       , KC_Y       , KC_COLON   , KC_EQL        ,
        KC_MINS      , MT_LC(KC_A), MT_LA(KC_R), MT_LS(KC_S), MT_LG(KC_T), KC_D,                   KC_H, MT_RG(KC_N), MT_RS(KC_E), MT_RA(KC_I), MT_RC(KC_O), KC_QUOT       ,
        KC_LEFT_PAREN, KC_Z       , KC_X       , KC_C       , KC_V       , KC_B, KC_MUTE, KC_MUTE, KC_K, KC_M       , KC_COMMA   , KC_DOT     , KC_SLASH   , KC_RIGHT_PAREN,
        
        __x__, __x__, MT(MOD_MEH, KC_DELETE), LT(_NAV, KC_BACKSPACE), LT(_MOUSE, KC_TAB), LT(_SYM, KC_ENTER), LT(_NUM, KC_SPACE), MEH_T(KC_S), __x__, __x__
    ),                                                                                                                            // MEH on hold, OSM-SHIFT on tap

    [_NUM] = LAYOUT(
        __x__, __x__  , __x__  , __x__    , __x__  , __x__,               __x__       , __x__, __x__, __x__, __x__   , __x__  ,
        __x__, __x__  , __x__  , __x__    , __x__  , __x__,               __x__       , TH_7 , TH_8 , TH_9 , KC_MINS , KC_PLUS,
        __x__, KC_LCTL, KC_LALT, KC_LSHIFT, KC_LGUI, __x__,               KC_EQL      , TH_4 , TH_5 , TH_6 , TH_0    , KC_DOT ,
        __x__, __x__  , __x__  , __x__    , __x__  , __x__, __x__, __x__, UKC_WDW_FULL, TH_1 , TH_2 , TH_3 , KC_SLASH, KC_ASTR,

                                _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
        ),

    [_SYM] = LAYOUT(
        __x__, __x__  , __x__  , __x__    , __x__  , __x__,               __x__, __x__  , __x__  , __x__  , __x__  , __x__,
        __x__, __x__  , __x__  , __x__    , __x__  , __x__,               __x__, S(KC_7), S(KC_8), __x__  , __x__  , __x__,
        __x__, KC_LCTL, KC_LALT, KC_LSHIFT, KC_LGUI, __x__,               __x__, S(KC_4), S(KC_5), S(KC_6), KC_PIPE, __x__,
        __x__, __x__  , __x__  , __x__    , __x__  , __x__, __x__, __x__, __x__, S(KC_1), S(KC_2), S(KC_3), __x__  , __x__,

                                _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
        ),

    [_NAV] = LAYOUT(
        __x__   , __x__        , __x__     , __x__   , __x__      , __x__         ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__,
        __x__   , S(A(KC_LEFT)), S(KC_LEFT), KC_UP   , S(KC_RIGHT), S(A(KC_RIGHT)),               __x__, __x__  , __x__  , __x__  , __x__  , __x__,
        KC_ENTER, A(KC_LEFT)   , KC_LEFT   , KC_DOWN , KC_RIGHT   , A(KC_RIGHT)   ,               __x__, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, __x__,
        KC_SPACE, G(KC_LEFT)   , UKC_CUT   , UKC_COPY, UKC_PSTE   , G(KC_RIGHT)   , __x__, __x__, __x__, __x__  , __x__  , __x__  , __x__  , __x__,

                                                        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
        ),

    [_MOUSE] = LAYOUT(
        __x__  , __x__   , __x__  , __x__   , __x__   , __x__      ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__,
        KC_WH_R, KC_WH_D , KC_WH_L, KC_MS_U , KC_BTN1 , KC_BTN2    ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__,
        __x__  , KC_WH_U , KC_MS_L, KC_MS_D , KC_MS_R , UKC_MS_2CLK,               __x__, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, __x__,
        __x__  , UKC_UNDO, UKC_CUT, UKC_COPY, UKC_PSTE, UKC_REDO   , __x__, __x__, __x__, __x__  , __x__  , __x__  , __x__  , __x__,

                                         _____, _____, _____, _____, _____, UKC_MS_2CLK, KC_BTN1, KC_BTN2, _____, _____
        ),

    [_ZOOM] = LAYOUT(
        TO(_BASE), __x__  , __x__  , __x__    , __x__  , ZM_FOCUS,               ZM_FOCUS    , __x__     , __x__, __x__     , __x__       , TO(_BASE)  ,
        __x__    , __o__  , __o__  , __x__    , __x__  , __x__   ,               __x__       , __x__     , __x__, __x__     , __x__       , __x__      ,
        __x__    , KC_LCTL, KC_LALT, KC_LSHIFT, KC_LGUI, __x__   ,               __x__       , __x__     , __x__, UKC_WDW_RH, UKC_WDW_SWAP, ZM_CLS_MEET,
        __x__    , __o__  , __o__  , __o__    , __o__  , __x__   , __x__, __x__, UKC_WDW_FULL, ZM_TG_VIEW, __x__, __x__     , __x__       , KC_ENTER   ,

                                       _____, _____, _____, _____, _____, ZM_TG_AUDO, KC_SPC, ZM_TG_VIDO, _____, _____
        ),

    // Used to make OLED indication of caps word on the non-master side easier (than custom communication protocols).
    // See caps_word.c for more details.
    [_CAPS_WORD] = LAYOUT(
        _____, _____, _____, _____, _____, _____,               _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____,               _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____,               _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,

                      _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
        ),
};


#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        int layer = get_highest_layer(layer_state);
        if (layer == _ZOOM || layer == _BASE) {
            // For now I'm doing the same thing for both encoders' rotation actions
            if (clockwise) {
                tap_code(KC_AUDIO_VOL_UP);
            } else {
                tap_code(KC_AUDIO_VOL_DOWN);
            }
        }
        return true;
    }
#endif
    

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tap_hold_keycode_user(keycode, record)) { return false; }
    // It's important that caps word comes AFTER tap_hold since the caps word key is on a tap hold.
    // If done the other way around, then you end up double processing the toggle key.
    if (!process_caps_word(keycode, record)) { return false; }

    #ifdef COMBO_ENABLE
        if (!process_combo_keycode_user(keycode, record)) { return false; }
    #endif

    enum tap_hold_actions tha_action = tap_hold_action(record);
    switch (keycode) {
        // Double click for the mouse
        case UKC_MS_2CLK:
            if (tha_action == THA_TAP) {
                tap_code16(KC_BTN1);
                wait_ms(MOUSE_DOUBLE_CLICK_WAIT);
                tap_code16(KC_BTN1);
                return false;
            }
            break;
        // MEH on hold and OSM-SHIFT on tap
        case MEH_T(KC_S):
            if (tha_action == THA_TAP) {
                set_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));
                return false;
            }
            break;
    }

    return true;
}
