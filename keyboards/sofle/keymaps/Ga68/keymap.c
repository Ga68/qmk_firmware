#include "keymap.h"
#include "caps_word.h"

#ifdef COMBO_ENABLE
    #include "combos.h"
#endif

// ---------------------------------
// --- Keymap and Key Processing ---
// ---------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        __x__        , KC_1       , KC_2       , KC_3       , KC_4       , KC_5,                   KC_6, KC_7       , KC_8       , KC_9       , KC_0       , UKC_ZOOM_LAYER,
        __x__        , KC_Q       , KC_W       , KC_F       , KC_P       , KC_G,                   KC_J, KC_L       , KC_U       , KC_Y       , KC_COLON   , KC_EQL        ,
        KC_MINS      , MT_LC(KC_A), MT_LA(KC_R), MT_LS(KC_S), MT_LG(KC_T), KC_D,                   KC_H, MT_RG(KC_N), MT_RS(KC_E), MT_RA(KC_I), MT_RC(KC_O), KC_QUOT       ,
        KC_LEFT_PAREN, KC_Z       , KC_X       , KC_C       , KC_V       , KC_B, KC_MUTE, KC_MUTE, KC_K, KC_M       , KC_COMMA   , KC_DOT     , KC_SLASH   , KC_RIGHT_PAREN,
        
        __x__, __x__, MT(MOD_MEH, KC_DELETE), LT(_NAV, KC_BACKSPACE), LT(_MOUSE, KC_TAB), KC_ENTER, LT(_LOWER, KC_SPACE), MEH_T(UKC_APP_SWITCH), __x__, __x__
    ),

    [_LOWER] = LAYOUT(
        __x__    , __x__   , __x__  , __x__  , __x__  , __x__  ,               __x__  , __x__  , __x__  , __x__  , __x__  , __x__  ,
        KC_UNDS  , S(KC_1) , S(KC_2), S(KC_3), S(KC_4), S(KC_5),               S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), __x__  ,
        KC_ENTER , KC_1    , KC_2   , KC_3   , KC_4   , KC_5   ,               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DQUO,
        KC_SPACE , KC_BSLS , KC_PIPE, KC_PLUS, KC_EQL , KC_LCBR, __x__, __x__, KC_RCBR, KC_LT  , KC_GT  , KC_LBRC, KC_RBRC, KC_MINS,

                         __x__, __x__, KC_DELETE, KC_BACKSPACE, KC_TAB, __x__, __o__, __x__, __x__, __x__
        ),

    [_NAV] = LAYOUT(
        __x__   , __x__        , __x__     , __x__   , __x__      , __x__         ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__       ,
        UKC_MENU, S(A(KC_LEFT)), S(KC_LEFT), KC_UP   , S(KC_RIGHT), S(A(KC_RIGHT)),               __x__, __x__  , __x__  , __x__  , __x__  , __x__       ,
        KC_ENTER, A(KC_LEFT)   , KC_LEFT   , KC_DOWN , KC_RIGHT   , A(KC_RIGHT)   ,               __x__, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, KC_BACKSPACE,
        KC_SPACE, G(KC_LEFT)   , UKC_CUT   , UKC_COPY, UKC_PASTE  , G(KC_RIGHT)   , __x__, __x__, __x__, __x__  , __x__  , __x__  , __x__  , KC_DELETE   ,

                                                        __x__, __x__, __x__, __o__, __x__, KC_ENTER, KC_SPACE, UKC_APP_SWITCH, __x__, __x__
        ),

    [_WINDOW] = LAYOUT(
        __x__ , __x__    , __x__    , __x__    , __x__    , __x__      ,               __x__    , __x__    , __x__    , __x__    , __x__      , __x__,
        __x__ , __x__    , MEH(KC_7), MEH(KC_8), MEH(KC_9), __x__      ,               __x__    , MEH(KC_7), MEH(KC_8), MEH(KC_9), __x__      , __x__,
        __x__ , MEH(KC_0), MEH(KC_4), MEH(KC_5), MEH(KC_6), MEH(KC_DOT),               MEH(KC_0), MEH(KC_4), MEH(KC_5), MEH(KC_6), MEH(KC_DOT), __x__,
        __x__ , __x__    , MEH(KC_1), MEH(KC_2), MEH(KC_3), __x__      , __x__, __x__, __x__    , MEH(KC_1), MEH(KC_2), MEH(KC_3), __x__      , __x__,

                            __x__, __x__, MEH(KC_0), UKC_WDW_FULL, MEH(KC_DOT), MEH(KC_0), UKC_WDW_FULL, MEH(KC_DOT), __x__, __x__
        ),

    [_MOUSE] = LAYOUT(
        __x__   , __x__          , __x__  , __x__   , __x__   , __x__   ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__       ,
        __x__   , __x__          , KC_BTN1, KC_MS_U , KC_BTN2 , __x__   ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__       ,
        KC_ENTER, MEH(KC_F12)    , KC_MS_L, KC_MS_D , KC_MS_R , KC_WH_D ,               __x__, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, KC_BACKSPACE,
        KC_SPACE, OSL(_MOUSE_POS), KC_WH_L, __x__   , KC_WH_R , KC_WH_U , __x__, __x__, __x__, __x__  , __x__  , __x__  , __x__  , KC_DELETE   ,

                                              __x__, __x__, __x__, __x__, __o__, KC_BTN1, KC_BTN1, KC_BTN2, __x__, __x__
        ),

    [_MOUSE_POS] = LAYOUT(
        __x__ , __x__      , __x__     , __x__     , __x__     , __x__      ,               __x__      , __x__     , __x__     , __x__     , __x__      , __x__,
        __x__ , __x__      , MEH(KC_F7), MEH(KC_F8), MEH(KC_F9), __x__      ,               __x__      , MEH(KC_F7), MEH(KC_F8), MEH(KC_F9), __x__      , __x__,
        __x__ , MEH(KC_F10), MEH(KC_F4), MEH(KC_F5), MEH(KC_F6), MEH(KC_F11),               MEH(KC_F10), MEH(KC_F4), MEH(KC_F5), MEH(KC_F6), MEH(KC_F11), __x__,
        __x__ , __x__      , MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), __x__      , __x__, __x__, __x__      , MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), __x__      , __x__,

                                                  __x__, __x__, __x__, __x__, __o__, MEH(KC_F10), MEH(KC_F11), MEH(KC_F11), __x__, __x__
        ),

    [_ZOOM] = LAYOUT(
        TO(_BASE), __x__  , __x__  , __x__    , __x__  , ZM_FOCUS,               ZM_FOCUS    , __x__     , __x__, __x__     , __x__       , TO(_BASE)  ,
        __x__    , __x__  , __x__  , __x__    , __x__  , __x__   ,               __x__       , __x__     , __x__, __x__     , __x__       , __x__      ,
        __x__    , KC_LCTL, KC_LALT, KC_LSHIFT, KC_LGUI, __x__   ,               __x__       , __x__     , __x__, UKC_WDW_RH, UKC_WDW_SWAP, ZM_CLS_MEET,
        __x__    , __x__  , __x__  , __x__    , __x__  , __x__   , __x__, __x__, UKC_WDW_FULL, ZM_TG_VIEW, __x__, __x__     , __x__       , KC_ENTER   ,

                                       __x__, __x__, __x__, __x__, __x__, ZM_TG_AUDO, KC_SPC, ZM_TG_VIDO, __x__, __x__
        ),

    // Used to make OLED indication of caps word on the non-master side easier (than custom communication protocols).
    // See caps_word.c for more details.
    [_CAPS_WORD] = LAYOUT(
        __o__, __o__, __o__, __o__, __o__, __o__,               __o__, __o__, __o__, __o__, __o__, __o__,
        __o__, __o__, __o__, __o__, __o__, __o__,               __o__, __o__, __o__, __o__, __o__, __o__,
        __o__, __o__, __o__, __o__, __o__, __o__,               __o__, __o__, __o__, __o__, __o__, __o__,
        __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__,

                      __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__, __o__
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
    if (!process_caps_word(keycode, record)) { return false; }

    #ifdef COMBO_ENABLE
        if (!process_combo_keycode_user(keycode, record)) { return false; }
    #endif

    switch (keycode) {
        case MEH_T(UKC_APP_SWITCH):
            if (record->tap.count && record->event.pressed) {
                tap_code16(UKC_APP_SWITCH);
                return false;
            }
            break;
    }

    return true;
}
