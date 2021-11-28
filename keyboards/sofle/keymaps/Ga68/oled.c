#pragma once

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,
        0x91,0x92,0x93,0x94,0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,
        0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,
        0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Prints all the layers, and "highlights" (inverted printing) the active layer
    oled_write_P(PSTR("\n\n"), false);
    int ls = get_highest_layer(layer_state);
    oled_write_P(PSTR("Base\n\n"), ls==_BASE);
    oled_write_P(PSTR("NumSy\n"), ls==_NMSY);
    oled_write_P(PSTR("Nav\n\n"), ls==_NAV);
    oled_write_P(PSTR("Zoom\n\n"), ls==_ZOOM);

    // Caps Lock
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else if (false) {
    // leaving it this way, false, so it'll never run, but the compiler doesn't error on me by
    // saying that "render_logo" is never used. I may want to use it in the future.
        render_logo();
    }
}
