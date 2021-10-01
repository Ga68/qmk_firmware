// Originally started from Miryoku: https://github.com/manna-harbour/miryoku

#pragma once

#include QMK_KEYBOARD_H

#define ____ KC_NO
#define ___  KC_NO

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

#define U_IQUS LSA(KC_SLSH) // ¿


#define LAYOUT_EXT_THUMBS( \
     /**/ K01, K02, K03, K04, K05,                        K06, K07, K08, K09, K0A, K0B, \
     K10, K11, K12, K13, K14, K15,                        K16, K17, K18, K19, K1A, K1B, \
     K20, K21, K22, K23, K24, K25,                        K26, K27, K28, K29, K2A, K2B, \
                              K30, K31, K32,    K33, K34, K35 \
) \
LAYOUT( \
     ___, K01, K02, K03, K04, K05,                        K06, K07, K08, K09, K0A, K0B, \
     K10, K11, K12, K13, K14, K15,                        K16, K17, K18, K19, K1A, K1B, \
     K20, K21, K22, K23, K24, K25, ___, ___,    ___, ___, K26, K27, K28, K29, K2A, K2B, \
                    ___, ___, K30, K31, K32,    K33, K34, K35, ___, ___ \
)

#define LAYOUT_STD_THUMBS( \
     /**/ K01, K02, K03, K04, K05,              K06, K07, K08, K09, K0A, K0B, \
     K10, K11, K12, K13, K14, K15,              K16, K17, K18, K19, K1A, K1B, \
     K20, K21, K22, K23, K24, K25,              K26, K27, K28, K29, K2A, K2B, \
                         K30, K31, K32,    K33, K34, K35 \
) \
LAYOUT( \
     ___, K01, K02, K03, K04, K05,                        K06, K07, K08, K09, K0A, K0B, \
     K10, K11, K12, K13, K14, K15,                        K16, K17, K18, K19, K1A, K1B, \
     K20, K21, K22, K23, K24, K25, ___, ___,    ___, ___, K26, K27, K28, K29, K2A, K2B, \
                    ___, K30, K31, K32, ___,    ___, K33, K34, K35, ___ \
)
