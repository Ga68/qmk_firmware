#pragma once

#include QMK_KEYBOARD_H

bool process_caps_word(uint16_t keycode, keyrecord_t* record);
void toggle_caps_word(void);
void toggle_caps_lock(void);

bool g_caps_word_enabled = false;
