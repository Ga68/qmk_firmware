#include "combos.h"
#include "keymap.h"

// L/R   Left/Right hand
// B/T/H Bottom/Top/Home row
// 1 = index finger ... 4 = pinky

#define CB_LB1 KC_V
#define CB_LB2 KC_C
#define CB_LB3 KC_X
#define CB_LB4 KC_Z

#define CB_LT1 KC_P
#define CB_LT2 KC_F
#define CB_LT3 KC_W
#define CB_LT4 KC_Q

#define CB_RB1 KC_M
#define CB_RB2 KC_COMMA
#define CB_RB3 KC_DOT
#define CB_RB4 KC_SLASH

#define CB_RT1 KC_L
#define CB_RT2 KC_U
#define CB_RT3 KC_Y
#define CB_RT4 KC_COLON

#define CB_LH1 MT_LG(KC_T)
#define CB_LH2 MT_LS(KC_S)
#define CB_LH3 MT_LA(KC_R)

#define CB_X_ COMBO_END

// Left hand, top row
const uint16_t PROGMEM combo_grave                  [] = {CB_LT4, CB_LT3,                 CB_X_};
const uint16_t PROGMEM combo_tilde                  [] = {CB_LT4,         CB_LT2,         CB_X_};
const uint16_t PROGMEM combo_next_window            [] = {CB_LT4,                 CB_LT1, CB_X_};
const uint16_t PROGMEM combo_escape                 [] = {        CB_LT3, CB_LT2,         CB_X_};
const uint16_t PROGMEM combo_app_switch             [] = {        CB_LT3,         CB_LT1, CB_X_};
const uint16_t PROGMEM combo_alfred                 [] = {                CB_LT2, CB_LT1, CB_X_};
const uint16_t PROGMEM combo_screen_capture         [] = {CB_LT4, CB_LT3, CB_LT2,         CB_X_};
const uint16_t PROGMEM combo_window_management      [] = {        CB_LT3, CB_LT2, CB_LT1, CB_X_};

// Right hand, top row
const uint16_t PROGMEM combo_double_quote           [] = {CB_RT1,         CB_RT3,         CB_X_};
const uint16_t PROGMEM combo_plus                   [] = {CB_RT1,                 CB_RT4, CB_X_};
const uint16_t PROGMEM combo_semicolon              [] = {                CB_RT3, CB_RT4, CB_X_};
const uint16_t PROGMEM combo_caps_word              [] = {        CB_RT2, CB_RT3,         CB_X_};
const uint16_t PROGMEM combo_caps_lock              [] = {        CB_RT2, CB_RT3, CB_RT4, CB_X_};

// Left hand, bottom row
const uint16_t PROGMEM combo_undo                   [] = {CB_LB4, CB_LB3,                 CB_X_};
const uint16_t PROGMEM combo_redo                   [] = {CB_LB4, CB_LB3, CB_LB2,         CB_X_};
const uint16_t PROGMEM combo_cut                    [] = {CB_LB4,         CB_LB2,         CB_X_};
const uint16_t PROGMEM combo_copy                   [] = {        CB_LB3, CB_LB2,         CB_X_};
const uint16_t PROGMEM combo_paste                  [] = {                CB_LB2, CB_LB1, CB_X_};
const uint16_t PROGMEM combo_paste_plain            [] = {        CB_LB3, CB_LB2, CB_LB1, CB_X_};
const uint16_t PROGMEM combo_select_all             [] = {CB_LB4,                 CB_LB1, CB_X_};
const uint16_t PROGMEM combo_cmd_t                  [] = {        CB_LB3,         CB_LB1, CB_X_};

// Right hand, bottom row
const uint16_t PROGMEM combo_inverted_question_mark [] = {CB_RB1, CB_RB2,                 CB_X_};
const uint16_t PROGMEM combo_question_mark          [] = {                CB_RB3, CB_RB4, CB_X_};
const uint16_t PROGMEM combo_left_angle_brace       [] = {CB_RB1,         CB_RB3,         CB_X_};
const uint16_t PROGMEM combo_right_angle_brace      [] = {        CB_RB2, CB_RB3,         CB_X_};
const uint16_t PROGMEM combo_left_square_brace      [] = {CB_RB1,                 CB_RB4, CB_X_};
const uint16_t PROGMEM combo_right_square_brace     [] = {        CB_RB2,         CB_RB4, CB_X_};
const uint16_t PROGMEM combo_left_curly_brace       [] = {CB_RB1, CB_RB2, CB_RB3,         CB_X_};
const uint16_t PROGMEM combo_right_curly_brace      [] = {        CB_RB2, CB_RB3, CB_RB4, CB_X_};

// Left hand, multi row
const uint16_t PROGMEM combo_cmd_p                  [] = {        CB_LH3,         CB_LT1, CB_X_};
const uint16_t PROGMEM combo_cmd_shift_p            [] = {        CB_LH3, CB_LH2, CB_LT1, CB_X_};
const uint16_t PROGMEM combo_cmd_shift_f            [] = {        CB_LH3, CB_LT2, CB_LH1, CB_X_};

combo_t key_combos[] = {

    COMBO(combo_grave, KC_GRAVE),
    COMBO(combo_tilde, KC_TILDE),
    COMBO(combo_next_window, UKC_NEXT_WINDOW),
    COMBO(combo_escape, KC_ESCAPE),
    COMBO(combo_app_switch, UKC_APP_SWITCH),
    COMBO(combo_alfred, UKC_ALFRED),
    COMBO(combo_screen_capture, UKC_SCREEN_CAPTURE),
    COMBO(combo_window_management, OSL(_WINDOW)),

    COMBO(combo_semicolon, KC_SEMICOLON),
    COMBO(combo_double_quote, KC_DOUBLE_QUOTE),
    COMBO(combo_plus, KC_PLUS),
    COMBO(combo_caps_word, UKC_CAPS_WORD),
    COMBO(combo_caps_lock, KC_CAPS_LOCK),

    COMBO(combo_undo, UKC_UNDO),
    COMBO(combo_redo, UKC_REDO),
    COMBO(combo_cut, UKC_CUT),
    COMBO(combo_copy, UKC_COPY),
    COMBO(combo_paste, UKC_PASTE),
    COMBO(combo_paste_plain, UKC_PLAIN_PASTE),
    COMBO(combo_select_all, UKC_SELECT_ALL),
    COMBO(combo_cmd_t, LCMD(KC_T)),

    COMBO(combo_inverted_question_mark, UKC_INV_QUESTION),
    COMBO(combo_question_mark, KC_QUESTION),
    COMBO(combo_left_angle_brace, KC_LEFT_ANGLE_BRACE),
    COMBO(combo_right_angle_brace, KC_RIGHT_ANGLE_BRACE),
    COMBO(combo_left_square_brace, KC_LEFT_SQUARE_BRACE),
    COMBO(combo_right_square_brace, KC_RIGHT_SQUARE_BRACE),
    COMBO(combo_left_curly_brace, KC_LEFT_CURLY_BRACE),
    COMBO(combo_right_curly_brace, KC_RIGHT_CURLY_BRACE),

    COMBO(combo_cmd_p, LCMD(KC_P)),
    COMBO(combo_cmd_shift_p, LCMD(LSFT(KC_P))),
    COMBO(combo_cmd_shift_f, LCMD(LSFT(KC_F))),

};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }
    return true;
}
