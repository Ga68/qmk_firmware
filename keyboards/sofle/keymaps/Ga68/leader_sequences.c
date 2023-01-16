#include "leader.h"
#include "keymap.h"
#include "caps_word.h"

void *leader_zoom_func(uint16_t keycode) {
    switch (keycode) {
        case KC_W: // Leave the Zoom meeting
            tap_code16(UKC_MENU);   // Move to the menu
            SEND_STRING("win");     // Open the Window menu and move the Zoom Meeting window
            tap_code16(KC_ENTER);
            tap_code16(KC_UP);      // Move to the last (bottom) item in the newly openede menu
            tap_code16(KC_ENTER);
            DELAY;                      
            tap_code16(LCMD(KC_W)); // Close the window
            return NULL;
        case KC_R:
            tap_code16(LCMD(LSFT(KC_R))); // toggle video
            tap_code16(LCMD(LSFT(KC_A))); // toggle audio
            return NULL;
        case KC_C:
            tap_code16(LCMD(LSFT(KC_H))); // toggle chat
            return NULL;
    }
    return NULL;
}

void *leader_outlook_func(uint16_t keycode) {
    switch (keycode) {
        case KC_U: // Mark message as unread
            tap_code16(LCMD(KC_T)); // Mark it as read
            DELAY_SHORT;
            tap_code16(LCMD(LSFT(KC_T))); // Mark it as unread
            return NULL;
        case KC_M:
            tap_code16(LCMD(KC_1)); // Mail pane
            return NULL;
        case KC_C:
            tap_code16(LCMD(KC_2)); // Calendarpane
            return NULL;
        case KC_R:
            tap_code16(LCMD(KC_G)); // Go to folder
            SEND_STRING("cal\n");
            return NULL;        
        case KC_I:
            tap_code16(LCMD(KC_G)); // Go to folder
            SEND_STRING("in\n");
            return NULL;
        case KC_S:
            tap_code16(LCMD(KC_G)); // Go to folder
            SEND_STRING("sent\n");
            return NULL;
        case KC_T:
            tap_code16(LCMD(KC_2)); // Calendarpane
            DELAY_SHORT;
            tap_code16(LCMD(KC_T)); // Jump to today
    }
    return NULL;
}

void *leader_slack_func(uint16_t keycode) {
    switch (keycode) {
        case KC_T: // Jump to Slack conversation (reference to the cmd-T keystroke)
            tap_code16(LCMD(KC_T)); // Jump to...
            return NULL;
        case KC_A: // Jump to All Slack conversations (reference to the cmd-shift-A keystroke)
            tap_code16(LCMD(LSFT(KC_A))); // Jump to...
            return NULL;
    }
    return NULL;
}

void *leader_calendar_func(uint16_t keycode) {
    switch (keycode) {
        case KC_T: // Jump to today in Calendar
            tap_code16(LCMD(KC_1)); // Single-day view
            tap_code16(LCMD(KC_T)); // Jump to today
            return NULL;
        case KC_D: // Jump to a day in Calendar
            tap_code16(LCMD(LSFT(KC_T)));
            return NULL;
    }
    return NULL;
}

void *leader_preview_func(uint16_t keycode) {
    switch (keycode) {
        case KC_N: // New doc (from clipboard) and into sketch mode
            tap_code16(LCMD(KC_N));
            // The lack of return NULL is on purpose because I want it to flow into the
            // Sketch Mode sequence below
            DELAY_SHORT;
        case KC_S: // Sketch mode
            // This relies on a custom made app/service/AppleScript that moves Preview into
            // Sketch mode, since there is no native keyboard shortcut.
            tap_code16(LCMD(LALT(KC_S)));
            return NULL;
    }
    return NULL;
}

void *leader_caps_func(uint16_t keycode) {
    switch (keycode) {
        case KC_K:  // K "for" "K"ONSTANT_CASE
            toggle_caps_word_mode(CWMODE_CONSTANT_CASE);
            return NULL;
        case KC_DASH:  // kebab-case
            toggle_caps_word_space_sub(KC_DASH);
            return NULL;
        case KC_U:  // U for underscore ... snake_case
            toggle_caps_word_space_sub(KC_UNDERSCORE);
            return NULL;
        case KC_C:  // C for camelCase
            toggle_caps_word_mode(CWMODE_CAMEL_CASE);
            return NULL;
        case KC_SLASH:  // slash/case (ex. path/to/file)
            toggle_caps_word_space_sub(KC_SLASH);
            return NULL;
    }
    return NULL;
}

#define DELAY_INSTA_PRESET DELAY_LONG; DELAY;
void *leader_insta_func(uint16_t keycode) {
    switch (keycode) {
        case KC_U:  // U just because it's physically close, therefore fast
            DELAY_INSTA_PRESET;
            tap_code16(LALT(KC_1));  // Go to a preset position
            return NULL;
        case KC_Y:  // Y just because it's physically in the "second" position
            DELAY_INSTA_PRESET;
            tap_code16(LALT(KC_2));  // Go to a preset position
            return NULL;
        case KC_N:  // N just because it's below, so convenient relation to L
            DELAY;
            tap_code16(LALT(KC_M));  // Toggle the video image
            return NULL;
    }
    return NULL;
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_C:
            tap_code16(MEH(KC_C));  // Switch to Calendar
            return leader_calendar_func;
        case KC_L:
            tap_code16(MEH(KC_L));  // Switch to Insta360 Link Controller
            return leader_insta_func;
        case KC_O:
            tap_code16(MEH(KC_O));  // Switch to Outlook
            return leader_outlook_func;
        case KC_P:
            tap_code16(MEH(KC_P));  // Switch to Preview
            return leader_preview_func;
        case KC_S:
            tap_code16(MEH(KC_S));    // Switch to Slack
            return leader_slack_func;
        case KC_W:
            return leader_caps_func;
        case KC_Z:
            tap_code16(MEH(KC_Z));  // Switch to Zoom
            return leader_zoom_func;
    }
    return NULL;
}

