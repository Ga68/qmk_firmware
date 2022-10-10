#pragma once
#include QMK_KEYBOARD_H

typedef enum {
    CWMODE_NORMAL = 0,
    CWMODE_NUM_LOCK,
    CWMODE_ARROW_SHIFT
} caps_word_mode_t;

caps_word_mode_t g_caps_word_mode;
#define CAPS_WORD_MODE_DEFAULT CWMODE_NORMAL;

bool toggle_caps_word_mode(caps_word_mode_t new_mode);
