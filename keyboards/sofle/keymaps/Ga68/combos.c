#include "combos.h"
#include "keymap.h"

// CB_xxx key codes are defined in keymap.h since they have to be consolidated with others
//   to respect SAFE_RANGE

const uint16_t PROGMEM combo_23l_up[]   = {KC_W    , KC_F          , COMBO_END};
const uint16_t PROGMEM combo_23r_up[]   = {KC_U    , KC_Y          , COMBO_END};
const uint16_t PROGMEM combo_23l_down[] = {KC_X    , KC_C          , COMBO_END};
const uint16_t PROGMEM combo_23r_down[] = {KC_COMMA, KC_DOT        , COMBO_END};
const uint16_t PROGMEM combo_34l_down[] = {KC_Z    , KC_X          , COMBO_END};
const uint16_t PROGMEM combo_34r_down[] = {KC_DOT  , KC_SLASH      , COMBO_END};
const uint16_t PROGMEM combo_45l_down[] = {KC_Z    , KC_LEFT_PAREN , COMBO_END};
const uint16_t PROGMEM combo_45r_down[] = {KC_SLASH, KC_RIGHT_PAREN, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_23l_up  , KC_ESC               ),
    COMBO(combo_23r_up  , UKC_CAPS_WORD        ),
    COMBO(combo_23l_down, KC_LEFT_ANGLE_BRACE  ),
    COMBO(combo_23r_down, KC_RIGHT_ANGLE_BRACE ),
    COMBO(combo_34l_down, KC_LEFT_CURLY_BRACE  ),
    COMBO(combo_34r_down, KC_RIGHT_CURLY_BRACE ),
    COMBO(combo_45l_down, KC_LEFT_SQUARE_BRACE ),
    COMBO(combo_45r_down, KC_RIGHT_SQUARE_BRACE),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }
    return true;
}
