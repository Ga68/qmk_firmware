#pragma once
#include QMK_KEYBOARD_H

typedef enum {
    CWMODE_NORMAL = 0,
    CWMODE_ARROW_SHIFT,
    CWMODE_CONSTANT_CASE,  // CONSTANT_CASE
    CWMODE_CAMEL_CASE,     // camelCase
    CWMODE_SPACE_SUB       // will substitute space with a predefined character. can be used for
                           // kebab-case, snake_case, slash/case (path/to/file), or others.
} caps_word_mode_t;

#define CAPS_WORD_MODE_DEFAULT CWMODE_NORMAL
#define CAPS_WORD_SPACE_SUB_DEFAULT KC_SPACE

caps_word_mode_t g_caps_word_mode;

bool toggle_caps_word_mode(caps_word_mode_t new_mode);
bool toggle_caps_word_space_sub(uint16_t sub_keycode);
