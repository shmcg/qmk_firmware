#include QMK_KEYBOARD_H

enum qfr_layers {
    _QWERTY,
    _APPLE,
    _ADJUST
};

enum qfr_keycodes {
    QWERTY = SAFE_RANGE,
    APPLE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_tkl_ansi(\
                 KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, \
                 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, \
                 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN, \
                 KC_LCTL,KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, \
                 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, \
                 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_HYPR, LT(ADJUST, KC_MENU), KC_MEH, KC_LEFT, KC_DOWN, KC_RGHT ),

[_APPLE] = LAYOUT_tkl_ansi(\
                 KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, \
                 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, \
                 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN, \
                 KC_LCTL,KC_S, KC_A, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, \
                 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, \
                 KC_LCTL, KC_LALT, KC_LALT, KC_SPC, KC_RALT, KC_HYPR, LT(ADJUST, KC_MENU), KC_MEH, KC_LEFT, KC_DOWN, KC_RGHT ),

[_ADJUST] = LAYOUT_tkl_ansi(\
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
                 KC_NO, QWERTY, KC_NO, EEP_RST, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
                 KC_NO, APPLE, KC_NO, DEBUG, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_APP, KC_NO, KC_NO, KC_NO, KC_NO )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("Mode: QWERTY\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case APPLE:
            if (record->event.pressed) {
                print("Mode: APPLE\n");
                set_single_persistent_default_layer(_APPLE);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                print("ADJUST ON\n");
                layer_on(_ADJUST);
            } else {
                print("ADJUST OFF\n");
                layer_off(_ADJUST);
            }
            return false;
            break;
        }
        return true;
    }
