#include "leader.h"


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
            SEND_STRING("calendar requests\n");
            return NULL;        
        case KC_I:
            tap_code16(LCMD(KC_G)); // Go to folder
            SEND_STRING("inbox\n");
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
    }
    return NULL;
}

void *leader_preview_func(uint16_t keycode) {
    switch (keycode) {
        case KC_S: // Sketch mode
            // This relies on a custom made app/service/AppleScript that moves Preview into
            // Sketch mode, since there is no native keyboard shortcut.
            tap_code16(LCMD(LALT(KC_S)));
            return NULL;
    }
    return NULL;
}
void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_O:
            tap_code16(MEH(KC_O));  // Go to Outlook
            return leader_outlook_func;
        case KC_Z:
            tap_code16(MEH(KC_Z));  // Switch to Zoom
            return leader_zoom_func;
        case KC_S:
            tap_code16(MEH(KC_S));    // Open Slack
            return leader_slack_func;
        case KC_C:
            tap_code16(MEH(KC_C));  // Open Calendar
            return leader_calendar_func;
        case KC_P:
            tap_code16(MEH(KC_P));  // Open Preview
            return leader_preview_func;
    }
    return NULL;
}

