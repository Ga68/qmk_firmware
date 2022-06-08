#include "leader.h"

void *leader_zoom_func(uint16_t keycode) {
    switch (keycode) {
        case KC_W: // Leave the Zoom meeting
            tap_code16(MEH(KC_Z));  // Switch to Zoom
            DELAY;
            tap_code16(UKC_MENU);   // Move to the menu
            SEND_STRING("win");     // Open the Window menu and move the Zoom Meeting window
            DELAY_SHORT;
            tap_code16(KC_DOWN);
            tap_code16(KC_UP);
            DELAY_SHORT;
            tap_code16(KC_ENTER);
            DELAY_LONG;                      
            tap_code16(LCMD(KC_W)); // Close the window
            return NULL;
    }
    return NULL;
}

void *leader_outlook_func(uint16_t keycode) {
    switch (keycode) {
        case KC_U: // Mark message as unread
            tap_code16(LCMD(LSFT(KC_T)));
            return NULL;
    }
    return NULL;
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_O:
            return leader_outlook_func;
        case KC_Z:
            return leader_zoom_func;
    }
    return NULL;
}

