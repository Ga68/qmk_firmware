#pragma once


// ---------------
// --- Tapping ---
// ---------------

// Configure the global tapping term (default: 200ms)
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// ----------------
// --- Encoders ---
// ----------------
#ifdef ENCODER_ENABLE
  
  #define ENCODER_DIRECTION_FLIP

  // One click of the encoder is one unit on my system works when 4
  #undef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4

#endif

// ------------------
// --- Auto Shift ---
// ------------------
// See the get_auto_shifted_key function in autoshift.c for per-key settings as well
#ifdef AUTO_SHIFT_ENABLE

  #define AUTO_SHIFT_TIMEOUT 160

  #define NO_AUTO_SHIFT_SPECIAL

  // Lets mod-taps get used in auto-shift, but not if held for a long time (ex. mouse clicks)
  #define RETRO_SHIFT 500

#endif

#ifdef OLED_ENABLE
  // --- ------- ---
  // --- Display ---
  // --- ------- ---

  #define OLED_CUSTOM_TIMEOUT
  #define OLED_BRIGHTNESS 10
  #define SPLIT_LAYER_STATE_ENABLE
  #define SPLIT_LED_STATE_ENABLE
#endif

#ifdef MOUSEKEY_ENABLE
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
#endif

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
