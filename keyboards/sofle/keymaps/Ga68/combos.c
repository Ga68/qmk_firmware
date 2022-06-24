#include "combos.h"
#include "keymap.h"


#ifdef COMBO_TERM_PER_COMBO
    uint16_t get_combo_term(uint16_t index, combo_t *combo) {
        switch (combo->keycode) {
            case LCMD(KC_N):            // cmd-n is also 'in', which is such a commond word, the
                return .8 * COMBO_TERM; // combo term needs to be extra short
            case UKC_APP_SWITCH:  // These ones are less frequent bi(tri)grams, so can afford
            case UKC_SELECT_ALL:  // to have a longer combo term with fear of mis-fires
            case UKC_ALFRED:
            case KC_GRAVE:
            case KC_TILDE:
            case UKC_NEXT_WINDOW:
            case UKC_PASTE:
            case UKC_SUPER_APP_SWITCH:
            case KC_SEMICOLON:
            case UKC_LEADER:
                return 1.7 * COMBO_TERM;
        }
        return COMBO_TERM;
    }
#endif

// Left hand, top row
const uint16_t PROGMEM combo_tilde                  [] = { CB_LT4, CB_LT3,                 CB___ };
const uint16_t PROGMEM combo_grave                  [] = { CB_LT4,         CB_LT2,         CB___ };
const uint16_t PROGMEM combo_next_window            [] = { CB_LT4,                 CB_LT1, CB___ };
const uint16_t PROGMEM combo_escape                 [] = {         CB_LT3, CB_LT2,         CB___ };
const uint16_t PROGMEM combo_app_switch             [] = {         CB_LT3,         CB_LT1, CB___ };
const uint16_t PROGMEM combo_alfred                 [] = {                 CB_LT2, CB_LT1, CB___ };
const uint16_t PROGMEM combo_screen_capture         [] = { CB_LT4, CB_LT3, CB_LT2,         CB___ };
const uint16_t PROGMEM combo_window_management      [] = {         CB_LT3, CB_LT2, CB_LT1, CB___ };
const uint16_t PROGMEM combo_leader                 [] = { CB_LT4, CB_LT3, CB_LT2, CB_LT1, CB___ };

// Right hand, top row
const uint16_t PROGMEM combo_double_quote           [] = { CB_RT1, CB_RT2,                 CB___ };
const uint16_t PROGMEM combo_plus                   [] = { CB_RT1,         CB_RT3,         CB___ };
const uint16_t PROGMEM combo_semicolon              [] = { CB_RT1,                 CB_RT4, CB___ };
const uint16_t PROGMEM combo_caps_word              [] = {         CB_RT2, CB_RT3,         CB___ };
const uint16_t PROGMEM combo_caps_lock              [] = {         CB_RT2, CB_RT3, CB_RT4, CB___ };

// Left hand, bottom row
const uint16_t PROGMEM combo_undo                   [] = { CB_LB4, CB_LB3,                 CB___ };
const uint16_t PROGMEM combo_redo                   [] = { CB_LB4, CB_LB3, CB_LB2,         CB___ };
const uint16_t PROGMEM combo_cut                    [] = { CB_LB4,         CB_LB2,         CB___ };
const uint16_t PROGMEM combo_copy                   [] = {         CB_LB3, CB_LB2,         CB___ };
const uint16_t PROGMEM combo_paste                  [] = {                 CB_LB2, CB_LB1, CB___ };
const uint16_t PROGMEM combo_super_app_switch       [] = {         CB_LB3,         CB_LB1, CB___ };
const uint16_t PROGMEM combo_paste_plain            [] = {         CB_LB3, CB_LB2, CB_LB1, CB___ };
const uint16_t PROGMEM combo_select_all             [] = { CB_LB4,                 CB_LB1, CB___ };
const uint16_t PROGMEM combo_lock_computer          [] = { CB_LB4, CB_LB3, CB_LB2, CB_LB1, CB___ };

// Right hand, bottom row
const uint16_t PROGMEM combo_inverted_question_mark [] = { CB_RB1, CB_RB2,                 CB___ };
const uint16_t PROGMEM combo_question_mark          [] = {                 CB_RB3, CB_RB4, CB___ };
const uint16_t PROGMEM combo_left_angle_brace       [] = { CB_RB1,         CB_RB3,         CB___ };
const uint16_t PROGMEM combo_right_angle_brace      [] = {         CB_RB2, CB_RB3,         CB___ };
const uint16_t PROGMEM combo_left_square_brace      [] = { CB_RB1,                 CB_RB4, CB___ };
const uint16_t PROGMEM combo_right_square_brace     [] = {         CB_RB2,         CB_RB4, CB___ };
const uint16_t PROGMEM combo_left_curly_brace       [] = { CB_RB1, CB_RB2, CB_RB3,         CB___ };
const uint16_t PROGMEM combo_right_curly_brace      [] = {         CB_RB2, CB_RB3, CB_RB4, CB___ };
const uint16_t PROGMEM combo_bootloader             [] = { CB_RB1, CB_RB2, CB_RB3, CB_RB4, CB___ };

// Left hand, home row
const uint16_t PROGMEM combo_cmd_t                  [] = {         CB_LH3,         CB_LH1, CB___ };

// Right hand, home row
const uint16_t PROGMEM combo_cmd_n                  [] = { CB_RH1,         CB_RH3,         CB___ };

// Left hand, multi row
const uint16_t PROGMEM combo_cmd_p                  [] = {         CB_LH3,         CB_LT1, CB___ };
const uint16_t PROGMEM combo_cmd_shift_p            [] = {         CB_LH3, CB_LT2, CB_LT1, CB___ };
const uint16_t PROGMEM combo_cmd_shift_f            [] = {         CB_LH3, CB_LT2, CB_LH1, CB___ };

// Right hand, multi row
const uint16_t PROGMEM combo_cmd_l                  [] = { CB_RT1,         CB_RH3,         CB___ };

combo_t key_combos[] = {

    COMBO(combo_grave,             KC_GRAVE),
    COMBO(combo_tilde,             KC_TILDE),
    COMBO(combo_next_window,       UKC_NEXT_WINDOW),
    COMBO(combo_escape,            KC_ESCAPE),
    COMBO(combo_app_switch,        UKC_APP_SWITCH),
    COMBO(combo_alfred,            UKC_ALFRED),
    COMBO(combo_screen_capture,    UKC_SCREEN_CAPTURE),
    COMBO(combo_window_management, OSL(_WINDOW)),
    COMBO(combo_leader,            UKC_LEADER),


    COMBO(combo_semicolon,    KC_SEMICOLON),
    COMBO(combo_double_quote, KC_DOUBLE_QUOTE),
    COMBO(combo_plus,         KC_PLUS),
    COMBO(combo_caps_word,    UKC_CAPS_WORD),
    COMBO(combo_caps_lock,    KC_CAPS_LOCK),


    COMBO(combo_undo,             UKC_UNDO),
    COMBO(combo_redo,             UKC_REDO),
    COMBO(combo_cut,              UKC_CUT),
    COMBO(combo_copy,             UKC_COPY),
    COMBO(combo_paste,            UKC_PASTE),
    COMBO(combo_paste_plain,      UKC_PLAIN_PASTE),
    COMBO(combo_select_all,       UKC_SELECT_ALL),
    COMBO(combo_super_app_switch, UKC_SUPER_APP_SWITCH),
    COMBO(combo_lock_computer,    UKC_LOCK_COMPUTER),


    COMBO(combo_inverted_question_mark, UKC_INV_QUESTION),
    COMBO(combo_question_mark,          KC_QUESTION),
    COMBO(combo_left_angle_brace,       KC_LEFT_ANGLE_BRACE),
    COMBO(combo_right_angle_brace,      KC_RIGHT_ANGLE_BRACE),
    COMBO(combo_left_square_brace,      KC_LEFT_SQUARE_BRACE),
    COMBO(combo_right_square_brace,     KC_RIGHT_SQUARE_BRACE),
    COMBO(combo_left_curly_brace,       KC_LEFT_CURLY_BRACE),
    COMBO(combo_right_curly_brace,      KC_RIGHT_CURLY_BRACE),
    COMBO(combo_bootloader,             QK_BOOTLOADER),
    

    COMBO(combo_cmd_t, LCMD(KC_T)),


    COMBO(combo_cmd_n, LCMD(KC_N)),


    COMBO(combo_cmd_p,       LCMD(KC_P)),
    COMBO(combo_cmd_shift_p, LCMD(LSFT(KC_P))),
    COMBO(combo_cmd_shift_f, LCMD(LSFT(KC_F))),

    COMBO(combo_cmd_l, LCMD(KC_L)),

};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }
    return true;
}

