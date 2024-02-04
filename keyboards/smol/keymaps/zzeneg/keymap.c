// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number { _QWERTY = 0, _GAME, _EU, _NAV, _NUMBER, _SYMBOL, _FUNC, _SYS };

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
#define SYM_SPC LT(_SYMBOL, KC_SPC)
#define NUM_TAB LT(_NUMBER, KC_TAB)
#define FUNC_ESC LT(_FUNC, KC_ESC)
#define FUNC_ENT LT(_FUNC, KC_ENT)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define EU_DEL LT(_EU, KC_DEL)

// game layer mods
#define LCTL_ESC LCTL_T(KC_ESC)
#define LSFT_Q LSFT_T(KC_Q)
#define LALT_P LALT_T(KC_P)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .----------------------------------.                    ,----------------------------------.
     * |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |
     * .------+------+------+------+------|                    |------+------+------+------+------.
     * |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |
     * |------+------+------+------+------|                    |------+------+------+------+------|
     * |   Z  |   X  |   C  |   V  |   B  |________.  .________|   N  |   M  |   ,  |   .  |   /  |
     * `----------------------------------/       /    \       \----------------------------------'
     *                  | Esc  | Tab  |  / Space /      \ Enter \  | Bsps | Del  |
     *                  |_FUNC | _NUM | /_SYMBOL/        \ _FUNC \ | _NAV | RAlt |
     *                  `-------------''-------'          '-------''-------------'
     */
    // clang-format off
    [_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,               KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                        FUNC_ESC,  NUM_TAB,  SYM_SPC,      FUNC_ENT,  NAV_BSPC,  EU_DEL
    ),

    [_GAME] = LAYOUT(
        LSFT_Q,  KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,     KC_O,    LALT_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
                        LCTL_ESC,  NUM_TAB,  SYM_SPC,      FUNC_ENT,  NAV_BSPC,  EU_DEL
    ),

    [_EU] = LAYOUT(
        XXXXXXX,     XXXXXXX,     RALT(KC_E),  XXXXXXX,  XXXXXXX,             XXXXXXX,     RALT(KC_U),  XXXXXXX,  RALT(KC_O),  XXXXXXX,
        RALT(KC_A),  RALT(KC_S),  KC_MINS,     KC_LSFT,  XXXXXXX,             XXXXXXX,     KC_RSFT,     KC_QUOT,  RALT(KC_L),  XXXXXXX,
        RALT(KC_Z),  RALT(KC_X),  RALT(KC_C),  XXXXXXX,  XXXXXXX,             RALT(KC_N),  XXXXXXX,     XXXXXXX,  XXXXXXX,     XXXXXXX,
                                          KC_ESC,   KC_TAB,   KC_SPC,      XXXXXXX,  KC_BSPC,   _______
    ),

    [_NAV] = LAYOUT(
        XXXXXXX,  DT_UP,    DT_DOWN,  DT_PRNT,  XXXXXXX,             KC_BSPC,        KC_CAPS,  KC_PGDN,  KC_PGUP,  KC_PAUS,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,             LALT(KC_UP),    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             LALT(KC_DOWN),  KC_HOME,  KC_END,   KC_INS,   KC_APP,
                                KC_ESC,   KC_TAB,   KC_SPC,      XXXXXXX,  _______,  KC_DEL
    ),

    [_NUMBER] = LAYOUT(
        KC_LCTL,  KC_7,   KC_8,   KC_9,   KC_PLUS,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_0,     KC_4,   KC_5,   KC_6,   KC_DOT,              XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,
        KC_ENT,   KC_1,   KC_2,   KC_3,   KC_COMM,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        KC_BSPC,  _______,  TG(_GAME),      KC_ENT,  KC_BSPC,  KC_DEL
    ),

    [_SYMBOL] = LAYOUT(
        KC_PIPE,  KC_PERC,  KC_ASTR,  KC_LCBR,  KC_RCBR,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_DLR,   KC_EXLM,  KC_AMPR,  KC_LPRN,  KC_RPRN,            XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,
        KC_CIRC,  KC_HASH,  KC_AT,    KC_LBRC,  KC_RBRC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                              MO(_SYS),  KC_BSPC,  _______,      KC_ENT,  KC_BSPC,  KC_DEL
    ),

    [_FUNC] = LAYOUT(
        KC_LCTL,  KC_F7,   KC_F8,   KC_F9,   KC_BSLS,            RGB_TOG,  RGB_M_P,  RGB_RMOD,  RGB_MOD,  RGB_SPI,
        KC_F11,   KC_F4,   KC_F5,   KC_F6,   KC_F12,             RGB_M_R,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,
        KC_F10,   KC_F1,   KC_F2,   KC_F3,   KC_TILD,            RGB_M_SW,  RGB_M_B,  RGB_HUI,  RGB_SAI,  RGB_VAI,
                               _______,  KC_MNXT,  KC_MPLY,     _______,  XXXXXXX,  MO(_SYS)
    ),

    [_SYS] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  _______, QK_BOOT, _______,     _______, QK_BOOT, _______
    )
    // clang-format on
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    // different tapping term for different fingers
    switch (keycode) {
        // pinkies
        case HOME_A:
        case HOME_SCLN:
            return 250;
        // ring
        case HOME_S:
        case HOME_L:
            return 200;
        // middle
        case HOME_D:
        case HOME_K:
            return 170;
        // index
        case HOME_F:
        case HOME_J:
            return 150;
        // thumb and game
        default:
            return TAPPING_TERM;
    }
}

#ifdef CAPS_WORD_ENABLE

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_RSFT:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

#endif // CAPS_WORD_ENABLE

#ifdef COMBO_ENABLE

enum combos {
    // clang-format off
    WE_MINS,
    XC_UNDS,
    CV_EQL,
    IO_DQUO,
    MCOMM_GRV,
    COMMDOT_QUOT,
    COMBO_LENGTH
    // clang-format on
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM we_combo[]      = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM xc_combo[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[]      = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM io_combo[]      = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM mcomm_combo[]   = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    // clang-format off
    [WE_MINS] = COMBO(we_combo, KC_MINS),
    [XC_UNDS] = COMBO(xc_combo, KC_UNDS),
    [CV_EQL] = COMBO(cv_combo, KC_EQL),
    [IO_DQUO] = COMBO(io_combo, KC_DQUO),
    [MCOMM_GRV] = COMBO(mcomm_combo, KC_GRV),
    [COMMDOT_QUOT] = COMBO(commdot_combo, KC_QUOT)
    // clang-format on
};

#endif // COMBO_ENABLE

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // clang-format off
    [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_GAME] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_EU] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAV] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NUMBER] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYMBOL] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FUNC] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYS] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}};
// clang-format on
#endif // ENCODER_MAP_ENABLE

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

const rgblight_segment_t PROGMEM        game_layer[]         = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_ORANGE});
const rgblight_segment_t PROGMEM        capslock_layer[]     = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_PURPLE});
const rgblight_segment_t PROGMEM        capslockword_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_MAGENTA});
const rgblight_segment_t* const PROGMEM rgb_layers[]         = RGBLIGHT_LAYERS_LIST(game_layer, capslock_layer, capslockword_layer);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _GAME));
    return state;
}

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(2, active);
}

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

#endif // defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
