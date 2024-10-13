/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RALT(KC_W),
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    RALT(KC_Q), RALT(KC_L),
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                                   KC_LGUI, MO(1),   KC_SPC,                    KC_ENT,  MO(2),   KC_BSPC
    ),

    [1] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_PLUS, KC_MINS,                   KC_EQL,  S(KC_QUOT), KC_QUOT, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_TILD, KC_GRV,                    KC_UNDS, KC_COLN, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC,
                                   KC_LGUI, KC_TRNS, KC_SPC,                    KC_ENT,  MO(3),   KC_BSPC
    ),

    [2] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_LEFT, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
        KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_HOME, KC_DOWN, KC_END,  KC_NO,   KC_ESC,
                                   KC_LGUI, MO(3),   KC_SPC,                    KC_ENT,  KC_TRNS, KC_BSPC
    ),

    [3] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_MPRV, KC_MNXT, KC_MPLY, KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_VOLD, KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_NO,   KC_TRNS, KC_NO,                     KC_NO,   KC_TRNS, KC_NO
    )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Left side
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_P(PSTR("Default\n"), false);
                break;
            case 1:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case 2:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case 3:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
        }
    } else {
        // Right side
        oled_write_P(PSTR("daddy"), false);
    }
    return false;
}
#endif
