#pragma once

#include QMK_KEYBOARD_H

bool process_caps_word(uint16_t keycode, keyrecord_t* record);

bool CAPS_WORD_caps_word_enabled = false;
