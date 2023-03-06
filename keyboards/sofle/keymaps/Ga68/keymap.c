#include "keymap.h"
#include "leader.h"

#ifdef COMBO_ENABLE
    #include "combos.h"
#endif // COMBO_ENABLE

#ifdef CAPS_WORD_ENABLE
    #include "caps_word.h"
#endif // CAPS_WORD_ENABLE


// ------------------------
// --- Super App Switch ---
// ------------------------

uint16_t super_app_switch_time_out = 1500;

bool is_super_app_switch_active = false;
uint16_t super_app_switch_timer = 0;

// ---------------------------------
// --- Keymap and Key Processing ---
// ---------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_MEDIA_PLAY_PAUSE, KC_1       , KC_2       , KC_3       , KC_4       , KC_5,                   KC_6, KC_7       , KC_8       , KC_9       , KC_0       , __x__         ,
        KC_DELETE          , KC_Q       , KC_W       , KC_F       , KC_P       , KC_G,                   KC_J, KC_L       , KC_U       , KC_Y       , KC_COLON   , KC_EQL        ,
        KC_TACK            , MT_LC(KC_A), MT_LA(KC_R), MT_LS(KC_S), MT_LG(KC_T), KC_D,                   KC_H, MT_RG(KC_N), MT_RS(KC_E), MT_RA(KC_I), MT_RC(KC_O), KC_QUOT       ,
        KC_LEFT_PAREN      , KC_Z       , KC_X       , KC_C       , KC_V       , KC_B, KC_MUTE, KC_MUTE, KC_K, KC_M       , KC_COMMA   , KC_DOT     , KC_SLASH   , KC_RIGHT_PAREN,
        
                   __x__, __x__, MEH_T(UKC_LEADER), LT(_NAV, KC_BACKSPACE), LT(_MOUSE, KC_TAB), KC_ENTER, LT(_NUMBERS, KC_SPACE), MEH_T(UKC_LEADER), __x__, __x__
    ),

    [_NUMBERS] = LAYOUT(
        __x__   , __x__     , __x__       , __x__       , __x__       , __x__  ,               __x__  , __x__  , __x__  , __x__  , __x__, __x__  ,
        KC_SPACE, S(KC_1)   , S(KC_2)     , S(KC_3)     , S(KC_4)     , S(KC_5),               S(KC_6), S(KC_7), S(KC_8), KC_PIPE, __o__, __o__  ,
        __o__   , KC_1      , KC_2        , KC_3        , KC_4        , KC_5   ,               KC_6   , KC_7   , KC_8   , KC_9   , KC_0 , KC_PLUS,
        __o__   , UKC_DOLLAR, UKC_DOLLAR_K, UKC_DOLLAR_M, UKC_DOLLAR_B, __x__  , __x__, __x__, __x__  , __x__  , __o__  , __o__  , __o__, __o__  ,

                                             __x__, __x__, __x__, KC_BACKSPACE, KC_TAB, KC_ENTER, KC_SPACE, __x__, __x__, __x__
    ),

    [_NUMPAD] = LAYOUT(
        _XIT_   , __x__     , __x__       , __x__       , __x__       , __x__     ,               __x__   , __x__, __x__, __x__, __x__ , _XIT_   ,
        KC_EQUAL, KC_BANG   , KC_CARROT   , KC_COLON    , KC_DOLLAR   , KC_PERCENT,               KC_SPACE, KC_7 , KC_8 , KC_9 , __o__ , __o__   ,
        __o__   , KC_SLASH  , KC_COMMA    , KC_STAR     , KC_PLUS     , KC_SPACE  ,               KC_PLUS , KC_4 , KC_5 , KC_6 , KC_0  , KC_MINS ,
        __o__   , UKC_DOLLAR, UKC_DOLLAR_K, UKC_DOLLAR_M, UKC_DOLLAR_B, KC_RPAREN , __x__, __x__, KC_STAR , KC_1 , KC_2 , KC_3 , KC_DOT, KC_SLASH,

                                                __x__, __x__, __x__, KC_BACKSPACE, KC_TAB, KC_ENTER, KC_0, KC_COMMA, __x__, __x__
    ),

    [_NAV] = LAYOUT(
        __x__   , __x__     , __x__   , __x__     , __x__      , __x__               ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__       ,
        __o__   , G(KC_LEFT), G(KC_UP), G(KC_DOWN), G(KC_RIGHT), __x__               ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__       ,
        KC_ENTER, KC_LEFT   , KC_UP   , KC_DOWN   , KC_RIGHT   , UKC_ARROW_SHIFT_LOCK,               __x__, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, KC_BACKSPACE,
        KC_SPACE, A(KC_LEFT), A(KC_UP), A(KC_DOWN), A(KC_RIGHT), KC_BACKSPACE        , __x__, __x__, __x__, __x__  , __x__  , __x__  , __x__  , KC_DELETE   ,

                                                           __x__, __x__, __x__, _LYR_, __x__, KC_ENTER, KC_SPACE, UKC_LEADER, __x__, __x__
    ),

    [_WINDOW] = LAYOUT(
        __x__ , __x__    , __x__    , __x__    , __x__    , __x__      ,               __x__    , __x__    , __x__    , __x__    , __x__      , __x__,
        __x__ , __x__    , MEH(KC_7), MEH(KC_8), MEH(KC_9), __x__      ,               __x__    , MEH(KC_7), MEH(KC_8), MEH(KC_9), __x__      , __x__,
        __x__ , MEH(KC_0), MEH(KC_4), MEH(KC_5), MEH(KC_6), MEH(KC_DOT),               MEH(KC_0), MEH(KC_4), MEH(KC_5), MEH(KC_6), MEH(KC_DOT), __x__,
        __x__ , __x__    , MEH(KC_1), MEH(KC_2), MEH(KC_3), __x__      , __x__, __x__, __x__    , MEH(KC_1), MEH(KC_2), MEH(KC_3), __x__      , __x__,

                            __x__, __x__, MEH(KC_0), UKC_WDW_FULL, MEH(KC_DOT), MEH(KC_0), UKC_WDW_FULL, MEH(KC_DOT), __x__, __x__
    ),

    [_MOUSE] = LAYOUT(
        __x__   , __x__          , __x__         , __x__   , __x__   , __x__         ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__       ,
        __x__   , KC_WH_R        , KC_WH_D       , KC_WH_U , KC_WH_L , __x__         ,               __x__, __x__  , __x__  , __x__  , __x__  , __x__       ,
        KC_ENTER, KC_MS_L        , KC_MS_U       , KC_MS_D , KC_MS_R , UKC_FIND_MOUSE,               __x__, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, KC_BACKSPACE,
        KC_SPACE, OSL(_MOUSE_POS), UKC_FIND_MOUSE, KC_BTN1 , KC_BTN2 , __x__         , __x__, __x__, __x__, __x__  , __x__  , __x__  , __x__  , KC_DELETE   ,

                                                           __x__, __x__, __x__, __x__, _LYR_, KC_BTN1, KC_BTN1, KC_BTN2, __x__, __x__
    ),

    [_MOUSE_POS] = LAYOUT(
        __x__ , __x__      , __x__     , __x__     , __x__     , __x__      ,               __x__      , __x__     , __x__     , __x__     , __x__      , __x__,
        __x__ , __x__      , MEH(KC_F7), MEH(KC_F8), MEH(KC_F9), __x__      ,               __x__      , MEH(KC_F7), MEH(KC_F8), MEH(KC_F9), __x__      , __x__,
        __x__ , MEH(KC_F10), MEH(KC_F4), MEH(KC_F5), MEH(KC_F6), MEH(KC_F11),               MEH(KC_F10), MEH(KC_F4), MEH(KC_F5), MEH(KC_F6), MEH(KC_F11), __x__,
        __x__ , __x__      , MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), __x__      , __x__, __x__, __x__      , MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), __x__      , __x__,

                                      __x__, __x__, MEH(KC_F10), __x__, MEH(KC_F11), MEH(KC_F10), __x__, MEH(KC_F11), __x__, __x__
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
        if (layer == _BASE) {
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
    if (!process_leader(keycode, record))    { return false; }

    #ifdef COMBO_ENABLE
        if (!process_combo_keycode_user(keycode, record)) { return false; }
    #endif

    switch (keycode) {
        case UKC_SUPER_APP_SWITCH:
            if (record->event.pressed) {
                if (!is_super_app_switch_active) {
                    is_super_app_switch_active = true;
                    register_code(KC_LCMD);
                }
                super_app_switch_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case UKC_LEADER:
        case MEH_T(UKC_LEADER):
            if (
                // must be pressed and...
                // either it's just the raw keycode (not-MEH) or it is the MEH_T version, in which
                // case we need to make sure of the tap.count
                record->event.pressed &&
                (keycode != MEH_T(UKC_LEADER) || record->tap.count)
            ) {
                start_leading();
                return false;
            }
            break;
        case UKC_ARROW_SHIFT_LOCK:
            if (record->event.pressed) {
                toggle_caps_word_mode(CWMODE_ARROW_SHIFT);
                return false;
            }
            break;
        case CAPS_WORD:
            if (record->event.pressed) {
                toggle_caps_word_mode(CAPS_WORD_MODE_DEFAULT);
                return false;
            }
            break;
        case UKC_TOGGLE_NUM_LOCK:
            if (record->event.pressed) {
                layer_invert(_NUMPAD);
                return false;
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_super_app_switch_active) {
        if (timer_elapsed(super_app_switch_timer) >= super_app_switch_time_out) {
            unregister_code(KC_LCMD);
            is_super_app_switch_active = false;
        }
    }
}
