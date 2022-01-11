#pragma once

enum tap_hold_actions { THA_TAP, THA_HOLD, THA_OTHER };

enum tap_hold_actions tap_hold_action(keyrecord_t *record);
