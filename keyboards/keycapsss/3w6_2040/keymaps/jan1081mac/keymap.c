// Copyright 2021 weteor | 2022 Conor Burns (@Conor-Burns)
// Copyright 2023 Ben Roe (@keycapsss)
// Copyright 2023 Tom Barnes (@keyboard-magpie)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// #include "keymap_german.h"
#include "keymap_german_mac_iso.h"

// macOS DE
#include "keycodes.h"
// #define DE_UDIA KC_LBRC // Ü
// #define DE_ODIA KC_SCLN // Ö
// #define DE_ADIA KC_QUOT // Ä

// #define DE_LPRN S(DE_8)    // (
// #define DE_RPRN S(DE_9)    // )

// #define DE_LBRC A(DE_5)    // [
// #define DE_RBRC A(DE_6)    // ]

// #define DE_LCBR A(DE_8)    // {
// #define DE_RCBR A(DE_9)    // }

// #define DE_PIPE A(DE_7) // |

// #define DE_QUOT S(DE_HASH) // '
// #define DE_DQUO S(DE_2)    // "
// #define DE_GRV  S(DE_ACUT) // ` (dead)




#include "oneshot.h"
#include "swapper.h"


#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TABL G(S(KC_LBRC))
#define TABR G(S(KC_RBRC))
#define SPCL A(G(KC_LEFT))
#define SPC_R A(G(KC_RGHT))


#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define LA_NUM MO(_NUM)




enum layers {
    _DEF,
    _SYM,
    _NAV,
    _NUM,
    _CFG,
    _XXX,
};



enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off

    [_DEF] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,           KC_J,    KC_L,    KC_U,    KC_Y,    DE_UDIA,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,           KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,           KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_ENT,
                          LA_SYM,  LA_NUM,  LA_NAV,         OS_SHFT, KC_SPC,  KC_BSPC
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        DE_QUOT, DE_LBRC, DE_RBRC, KC_PLUS, KC_PAST,        KC_TILD, KC_UNDS, KC_BSLS, DE_PIPE, XXXXXXX,
        DE_DQUO, DE_LPRN, DE_RPRN, KC_PMNS, KC_PSLS,        KC_AT  , OS_CMD , OS_CTRL, OS_ALT , XXXXXXX,
        DE_GRV , DE_LCBR, DE_RCBR, KC_EQL , KC_HASH,        KC_LABK, KC_RABK, KC_QUES, KC_EXLM, XXXXXXX,
                          _______, _______, _______,        _______, _______, _______
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_ESC,        XXXXXXX, KC_PGDN, XXXXXXX, KC_PGUP,  KC_DEL,
        XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,        KC_HOME, _______, _______, _______,  KC_END,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, _______,       _______, _______, _______
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX,  KC_F9, KC_F10, KC_F11, KC_F12,                                    KC_PPLS,  KC_P7,  KC_P8,  KC_P9, KC_PSLS,
        XXXXXXX,  KC_F5,  KC_F6,  KC_F7,  KC_F8,                                    KC_P0,  KC_P4,  KC_P5,  KC_P6, KC_PDOT,
        XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F4,                                    KC_PMNS,  KC_P1,  KC_P2,  KC_P3, KC_PAST,
                                        XXXXXXX, _______, XXXXXXX,      KC_PEQL, KC_PENT, XXXXXXX
    ),
    [_CFG] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, DF(_DEF), DF(_SYM),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,        _______, XXXXXXX, XXXXXXX
    ),
    [_XXX] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,        _______, XXXXXXX, XXXXXXX
    )
    // clang-format on
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case LA_NUM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case LA_NUM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}