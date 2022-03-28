#include "combos.h"
#include "keymap.h"

// CB_xxx key codes are defined in keymap.h since they have to be consolidated with others
//   to respect SAFE_RANGE

const uint16_t PROGMEM combo_23_left_up[]      = {KC_W    , KC_F    ,       COMBO_END};
const uint16_t PROGMEM combo_23_right_up[]     = {KC_U    , KC_Y    ,       COMBO_END};
const uint16_t PROGMEM combo_23_left_down[]    = {KC_X    , KC_C    ,       COMBO_END};
const uint16_t PROGMEM combo_23_right_down[]   = {KC_COMMA, KC_DOT  ,       COMBO_END};
const uint16_t PROGMEM combo_34_left_down[]    = {KC_Z    , KC_X    ,       COMBO_END};
const uint16_t PROGMEM combo_34_right_down[]   = {KC_DOT  , KC_SLASH,       COMBO_END};
const uint16_t PROGMEM combo_123_right_up[]    = {KC_L    , KC_U    , KC_Y, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_23_left_up     , KC_ESC               ),
    COMBO(combo_23_right_up    , UKC_CAPS_WORD        ),
    COMBO(combo_23_left_down   , KC_LEFT_CURLY_BRACE  ),
    COMBO(combo_23_right_down  , KC_RIGHT_CURLY_BRACE ),
    COMBO(combo_34_left_down   , KC_LEFT_SQUARE_BRACE ),
    COMBO(combo_34_right_down  , KC_RIGHT_SQUARE_BRACE),
    COMBO(combo_123_right_up   , KC_CAPS_LOCK         ),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

bool process_combo_keycode_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }
    return true;
}
