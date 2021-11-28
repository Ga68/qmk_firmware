#pragma once

// Shift/Control Backspace = Delete
const key_override_t delete_key_override_shift = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE);
const key_override_t delete_key_override_ctrl  = ko_make_basic(MOD_MASK_CTRL , KC_BACKSPACE, KC_DELETE);

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override_shift,
    &delete_key_override_ctrl,
    NULL // Terminate the array of overrides
};
