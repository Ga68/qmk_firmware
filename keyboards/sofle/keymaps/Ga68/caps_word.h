#pragma once

#include QMK_KEYBOARD_H

bool process_caps_word(uint16_t keycode, keyrecord_t* record);
void toggle_caps_word_status(void);

bool g_caps_word_enabled = false;
bool g_caps_word_shifted = false;
