#pragma once

// --- ------- ---
// --- Tapping ---
// --- ------- ---
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// --- ----- ---
// --- Mouse ---
// --- ----- ---
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY       0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL    16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED   6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

// --- -------- ---
// --- Encoders ---
// --- -------- ---
#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4 // One click of the encoder is one unit on my system works when 4
#define ENCODER_DIRECTION_FLIP

// --- ---------- ---
// --- Auto Shift ---
// --- ---------- ---
#define NO_AUTO_SHIFT_SPECIAL
// #define NO_AUTO_SHIFT_NUMERIC
// #define NO_AUTO_SHIFT_ALPHA

#define AUTO_SHIFT_TIMEOUT TAPPING_TERM

// --- ------------ ---
// --- Space Saving ---
// --- ------------ ---
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DISABLE_LEADER

#ifndef NO_DEBUG
  #define NO_DEBUG
#endif
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
  #define NO_PRINT
#endif
