// Copyright 2024 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

typedef enum {
    // clang-format off
    _QWERTY = 0,
    _NAV,
    _NUMBER,
    _SYMBOL,
    _FUNC
    // clang-format on
} layer_number;

typedef enum {
    _TIME = 0xAA, // random value that does not conflict with VIA, must match companion app
    _VOLUME,
    _LAYOUT,
    _MEDIA_ARTIST,
    _MEDIA_TITLE,
} hid_data_type;

void display_process_raw_hid_data(uint8_t *data, uint8_t length);
void display_process_layer_state(uint8_t layer);
