// Copyright 2024 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    // clang-format off
    _QWERTY = 0,
    _NAV,
    _NUMBER,
    _SYMBOL,
    _FUNC
    // clang-format on
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// bottom mods
#define SYM_TAB LT(_SYMBOL, KC_TAB)
#define NUM_SPC LT(_NUMBER, KC_SPC)
#define FUNC_ESC LT(_FUNC, KC_ESC)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define RA_DEL RALT_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *               .---------------------------.                        ,---------------------------.
     *               |   W  |   E  |   R  |   T  |                        |   Y  |   U  |   I  |   O  |
     * .-------------+------+------+------+------|                        |------+------+------+------+-------------.
     * |   Q  |   A  |   S  |   D  |   F  |   G  |                        |   H  |   J  |   K  |   L  |   ;  |  P   |
     * `------+------+------+------+------+------|                        |------+------+------+------+------+------'
     *        |   Z  |   X  |   C  |   V  |   B  |                        |   N  |   M  |   ,  |   .  |   /  |
     *        `----------------------------------+ .-------.    .-------. +----------------------------------'
     *                           | Esc  | Space|  /  Tab  /      \ Enter \  | Bsps | Del  |
     *                           |_FUNC | _NUM | /_SYMBOL/        \       \ | _NAV | RAlt |
     *                           `-------------''-------'          '-------''-------------'
     */
    // clang-format off
    [_QWERTY] = LAYOUT(
                            KC_W,     KC_E,     KC_R,     KC_T,                KC_Y,     KC_U,     KC_I,     KC_O,
        KC_Q,     HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,                KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN, KC_P,
                  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                        FUNC_ESC,  NUM_SPC,  SYM_TAB,      KC_ENT,  NAV_BSPC,  RA_DEL
    ),

    [_NAV] = LAYOUT(
                            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  KC_INS,   KC_PGDN,  KC_PGUP,
        XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_CAPS,             XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX,  XXXXXXX,
                                       _______,   _______,   _______,      _______,  _______,  _______
    ),

    [_NUMBER] = LAYOUT(
                            KC_7,     KC_8,     KC_9,     XXXXXXX,             XXXXXXX,  XXXXXXX,  KC_QUOT,  KC_GRV,
        XXXXXXX,  KC_0,     KC_4,     KC_5,     KC_6,     KC_LBRC,             KC_RBRC,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
                  XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,             XXXXXXX,  KC_MINS,  KC_EQL,   KC_BSLS,  XXXXXXX,
                                         _______,  _______,  _______,      _______,  _______,  _______
    ),

    [_SYMBOL] = LAYOUT(
                            KC_AMPR,  KC_ASTR,  KC_LPRN,  XXXXXXX,             XXXXXXX,  XXXXXXX,  KC_DQUO,  KC_TILD,
        XXXXXXX,  KC_RPRN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_LCBR,             KC_RCBR,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
                  XXXXXXX,  KC_EXLM,  KC_AT,    KC_HASH,  XXXXXXX,             XXXXXXX,  KC_UNDS,  KC_PLUS,  KC_PIPE,  XXXXXXX,
                                        _______,  _______,  _______,      _______,  _______,  _______
    ),

    [_FUNC] = LAYOUT(
                            KC_F7,    KC_F8,    KC_F9,    KC_F10,              BL_UP,    KC_PSCR,  KC_SCRL,  KC_PAUS,
        XXXXXXX,  KC_LCTL,  KC_F4,    KC_F5,    KC_F6,    KC_F11,              BL_TOGG,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  XXXXXXX,
                  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F12,              BL_DOWN,  KC_CAPS,  KC_NUM,   XXXXXXX,  XXXXXXX,
                                        _______,  KC_MNXT,  KC_MPLY,      _______,  _______,  _______
    ),
    // clang-format on
};
