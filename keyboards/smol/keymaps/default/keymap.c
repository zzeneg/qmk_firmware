// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    // clang-format off
    _QWERTY = 0,
    _SYM,
    _NAV,
    _NUM
    // clang-format on
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_QWERTY] = LAYOUT(
        KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,         KC_S,    KC_D,    KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        LSFT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,                                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                        LCTL_T(KC_ESC), LT(_NUM, KC_TAB), LT(_NAV, KC_SPC),     KC_ENT, LT(_SYM, KC_BSPC), LALT_T(KC_DEL)
    ),
    [_SYM] = LAYOUT(
        KC_GRV , KC_CIRC,   KC_AT,  KC_DLR, KC_TILD,                                KC_AMPR, KC_EXLM, KC_PIPE, KC_UNDS, KC_HASH,
        KC_SLSH, KC_LBRC, KC_LCBR, KC_LPRN,  KC_EQL,                                KC_ASTR, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS,
        _______, KC_QUES, KC_PLUS, KC_PERC, XXXXXXX,                                XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX,     _______, XXXXXXX, QK_BOOT
    ),
    [_NAV] = LAYOUT(
        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,                                XXXXXXX, KC_PGDN,   KC_UP, KC_PGUP,  KC_DEL,
        KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, XXXXXXX,                                KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        QK_BOOT, XXXXXXX, _______,      XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT(
        XXXXXXX,  KC_F9, KC_F10, KC_F11, KC_F12,                                    KC_PPLS,  KC_P7,  KC_P8,  KC_P9, KC_PSLS,
        XXXXXXX,  KC_F5,  KC_F6,  KC_F7,  KC_F8,                                    KC_P0,  KC_P4,  KC_P5,  KC_P6, KC_PDOT,
        XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F4,                                    KC_PMNS,  KC_P1,  KC_P2,  KC_P3, KC_PAST,
                                        XXXXXXX, _______, XXXXXXX,      KC_PEQL, KC_PENT, XXXXXXX
    )
    // clang-format on
};
