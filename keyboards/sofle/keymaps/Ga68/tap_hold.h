#pragma once
#include QMK_KEYBOARD_H
#include "keymap.h"

enum th_keycodes {
    TH_STARTING_POINT = MAX_USER_KEYCODE,
    
    UKC_TH_EQL,   
    UKC_TH_0,
    UKC_TH_1,
    UKC_TH_2,
    UKC_TH_3,
    UKC_TH_4,
    UKC_TH_5,
    UKC_TH_6,
    UKC_TH_7,
    UKC_TH_8,
    UKC_TH_9,
};

enum tap_hold_actions { THA_TAP, THA_HOLD, THA_OTHER };

enum tap_hold_actions tap_hold_action(keyrecord_t *record);
bool process_tap_hold_keycode_user(uint16_t keycode, keyrecord_t *record);

// ----------------
// --- Tap Hold ---
// ----------------
// This will use the Mod-Tap intercept "trick" (as documented by QMK) to provide customizable
//   behavior on any key's hold. The DEFINEs are to help with code legibility.
//   https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap#changing-both-tap-and-hold
// See process_tap_hold_keycode_user to see these keycodes' implementation.

#define WINDOW_HOTKEY MEH
#define TH_EQL LT(0, UKC_TH_EQL)
#define TH_0   LT(0, UKC_TH_0)
#define TH_1   LT(0, UKC_TH_1)
#define TH_2   LT(0, UKC_TH_2)
#define TH_3   LT(0, UKC_TH_3)
#define TH_4   LT(0, UKC_TH_4)
#define TH_5   LT(0, UKC_TH_5)
#define TH_6   LT(0, UKC_TH_6)
#define TH_7   LT(0, UKC_TH_7)
#define TH_8   LT(0, UKC_TH_8)
#define TH_9   LT(0, UKC_TH_9)
