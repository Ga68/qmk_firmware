#pragma once

enum my_layers {
    _BASE = 0,
    _LOWER,
    _NAV,
    _WINDOW,
    _MOUSE,
    _MOUSE_POS,
    _CAPS_WORD,
    // if you need more than 8 layers, you need to remove
    //   #define LAYER_STATE_8BIT
    // from config.h, which is there for space saving
};
