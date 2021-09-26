/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap.h"

enum layers {
    BASE = 0, //
    NAV,      //
    SYM,      //
    NUM,      //
    MOUSE,    //
    MEDIA,
    WINDOW,   //
    FKEY,     //
};

// Putting the homerow mods here to make it easier to change them
// Read as "Finger 1(index)/2/3/4(pinky) Left/Right [Mod Tap]"
#define F4LT LCTL_T
#define F4L  KC_LCTL
#define F3LT LALT_T
#define F3L  KC_LALT
#define F2LT LSFT_T
#define F2L  KC_LSFT
#define F1LT LGUI_T
#define F1L  KC_LGUI

#define F4RT RCTL_T
#define F4R  KC_RCTL
#define F3RT RALT_T
#define F3R  KC_RALT
#define F2RT RSFT_T
#define F2R  KC_RSFT
#define F1RT RGUI_T
#define F1R  KC_RGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_WRAPPER(
                KC_Q  ,      KC_W  ,            KC_F    ,         KC_P     ,         KC_G    ,  /**/            KC_J    ,         KC_L    ,         KC_U      ,      KC_Y   ,      KC_QUOT , ___ ,
     ___ , F4LT(KC_A) , F3LT(KC_R) ,       F2LT(KC_S)   ,    F1LT(KC_T)    ,         KC_D    ,  /**/            KC_H    ,    F1RT(KC_N)   ,    F2RT(KC_E)     , F3RT(KC_I)  , F4RT(KC_O)   , ___ ,
     ___ ,      KC_Z  ,      KC_X  ,            KC_C    ,         KC_V     ,         KC_B    ,  /**/            KC_K    ,         KC_M    ,         KC_COMM   ,      KC_DOT ,      KC_SLSH , ___ ,
                                     LT(WINDOW, KC_DEL) , LT(NUM, KC_BSPC) , LT(SYM, KC_ENT) ,  /**/  LT(MOUSE, KC_TAB) , LT(NAV, KC_SPC) , LT(MEDIA, KC_ESC)
    ),

    [NAV] = LAYOUT_WRAPPER(
           KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_INS  ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
     ___ , KC_LEFT , KC_UP   , KC_DOWN , KC_RGHT , KC_CAPS ,  /**/  ___ , F1R , F2R , F3R , F4R , ___ ,
     ___ ,  U_UND  ,  U_CUT  ,  U_CPY  ,  U_PST  ,  U_RDO  ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
                                KC_DEL  , KC_BSPC , KC_ENT ,  /**/  ___ , ___ , ___
    ),

    [MOUSE] = LAYOUT_WRAPPER(
           KC_WH_R , KC_WH_D , KC_WH_U , KC_WH_L ,  ____   ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
     ___ , KC_MS_L , KC_MS_U , KC_MS_D , KC_MS_R ,  ____   ,  /**/  ___ , F1R , F2R , F3R , F4R , ___ ,
     ___ ,  U_UND  ,  U_CUT  ,  U_CPY  ,  U_PST  ,  U_RDO  ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
                               KC_BTN3 , KC_BTN1 , KC_BTN2 ,  /**/  ___ , ___ , ___
    ),

    [MEDIA] = LAYOUT_WRAPPER(
           SGUI(KC_1) ,   KC_MPRV  ,   KC_MPLY  ,   KC_MNXT  , SGUI(KC_2) ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
     ___ , HYPR(KC_A) , HYPR(KC_B) , HYPR(KC_C) , HYPR(KC_D) ,   KC_BRIU  ,  /**/  ___ , F1R , F2R , F3R , F4R , ___ ,
     ___ , HYPR(KC_E) , HYPR(KC_F) , HYPR(KC_G) , HYPR(KC_H) ,   KC_BRID  ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
                                       KC_VOLD  ,   KC_MUTE  ,   KC_VOLU  ,  /**/  ___ , ___ , ___
    ),

    [NUM] = LAYOUT_WRAPPER(
                ___ , ___ , ___ , ___ , ___ ,  /**/  KC_LBRC , KC_7 , KC_8   , KC_9, KC_RBRC , ___ ,
     MO(FKEY) , F4L , F3L , F2L , F1L , ___ ,  /**/  KC_EQL  , KC_4 , KC_5   , KC_6, KC_SCLN , ___ ,
        ____  , ___ , ___ , ___ , ___ , ___ ,  /**/  KC_BSLS , KC_1 , KC_2   , KC_3, KC_GRV  , ___ ,
                            ___ , ___ , ___ ,  /**/  KC_MINS , KC_0 , KC_DOT
    ),

    [FKEY] = LAYOUT_WRAPPER(
           ___ , ___ , ___ , ___ , ___ ,  /**/  KC_PSCR , KC_F7  , KC_F8  , KC_F9, KC_F12 , ___ ,
     ___ , F4L , F3L , F2L , F1L , ___ ,  /**/  KC_SLCK , KC_F4  , KC_F5  , KC_F6, KC_F11 , ___ ,
     ___ , ___ , ___ , ___ , ___ , ___ ,  /**/  KC_PAUS , KC_F1  , KC_F2  , KC_F3, KC_F10 , ___ ,
                       ___ , ___ , ___ ,  /**/  KC_TAB  , KC_SPC , KC_ESC
    ),

    [SYM] = LAYOUT_WRAPPER(
           ___ , ___ , ___ , ___ , ___ ,  /**/  KC_LCBR , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR , ___ ,
     ___ , F4L , F3L , F2L , F1L , ___ ,  /**/  KC_PLUS , KC_DLR  , KC_PERC , KC_CIRC , KC_COLN , ___ ,
     ___ , ___ , ___ , ___ , ___ , ___ ,  /**/  KC_PIPE , KC_EXLM , KC_AT   , KC_HASH , KC_TILD , ___ ,
                       ___ , ___ , ___ ,  /**/  KC_UNDS , KC_LPRN , KC_RPRN
    ),

    [WINDOW] = LAYOUT_WRAPPER(
           ___ , ___ , ___ , ___ , ___ ,  /**/  ___ , HYPR(KC_7) , HYPR(KC_8) , HYPR(KC_9),         ____  , ___ ,
     ___ , F4L , F3L , F2L , F1L , ___ ,  /**/  ___ , HYPR(KC_4) , HYPR(KC_5) , HYPR(KC_6), HYPR(KC_MINS) , ___ ,
     ___ , ___ , ___ , ___ , ___ , ___ ,  /**/  ___ , HYPR(KC_1) , HYPR(KC_2) , HYPR(KC_3),         ____  , ___ ,
                       ___ , ___ , ___ ,  /**/  ___ , HYPR(KC_0) ,      ____
    ),

    // Template
    // [_XXX_] = LAYOUT_WRAPPER(
    //        ___ , ___ , ___ , ___ , ___ ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
    //  ___ , ___ , ___ , ___ , ___ , ___ ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
    //  ___ , ___ , ___ , ___ , ___ , ___ ,  /**/  ___ , ___ , ___ , ___ , ___ , ___ ,
    //                    ___ , ___ , ___ ,  /**/  ___ , ___ , ___
    // ),



};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */
