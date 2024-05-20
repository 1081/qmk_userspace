// Copyright 2021 weteor | 2022 Conor Burns (@Conor-Burns)
// Copyright 2023 Ben Roe (@keycapsss)
// Copyright 2023 Tom Barnes (@keyboard-magpie)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "oneshot.h"
#include "swapper.h"

// --- SETUP FOR MAC LAYOUT
#include "keymap_german_mac_iso.h" // <-- UNCOMMENT THIS LINE
// --- Aliases:
// --- DE_CIRC KC_GRV        // ^ (dead)
// --- DE_1    KC_1          // 1
// --- DE_2    KC_2          // 2
// --- DE_3    KC_3          // 3
// --- DE_4    KC_4          // 4
// --- DE_5    KC_5          // 5
// --- DE_6    KC_6          // 6
// --- DE_7    KC_7          // 7
// --- DE_8    KC_8          // 8
// --- DE_9    KC_9          // 9
// --- DE_0    KC_0          // 0
// --- DE_SS   KC_MINS       // ß
// --- DE_ACUT KC_EQL        // ´ (dead)
// --- DE_Q    KC_Q          // Q
// --- DE_W    KC_W          // W
// --- DE_E    KC_E          // E
// --- DE_R    KC_R          // R
// --- DE_T    KC_T          // T
// --- DE_Z    KC_Y          // Z
// --- DE_U    KC_U          // U
// --- DE_I    KC_I          // I
// --- DE_O    KC_O          // O
// --- DE_P    KC_P          // P
// --- DE_UDIA KC_LBRC       // Ü
// --- DE_PLUS KC_RBRC       // +
// --- DE_A    KC_A          // A
// --- DE_S    KC_S          // S
// --- DE_D    KC_D          // D
// --- DE_F    KC_F          // F
// --- DE_G    KC_G          // G
// --- DE_H    KC_H          // H
// --- DE_J    KC_J          // J
// --- DE_K    KC_K          // K
// --- DE_L    KC_L          // L
// --- DE_ODIA KC_SCLN       // Ö
// --- DE_ADIA KC_QUOT       // Ä
// --- DE_HASH KC_NUHS       // #
// --- DE_LABK KC_NUBS       // <
// --- DE_Y    KC_Z          // Y
// --- DE_X    KC_X          // X
// --- DE_C    KC_C          // C
// --- DE_V    KC_V          // V
// --- DE_B    KC_B          // B
// --- DE_N    KC_N          // N
// --- DE_M    KC_M          // M
// --- DE_COMM KC_COMM       // ,
// --- DE_DOT  KC_DOT        // .
// --- DE_MINS KC_SLSH       // -
// --- DE_DEG  S(DE_CIRC)    // °
// --- DE_EXLM S(DE_1)       // !
// --- DE_DQUO S(DE_2)       // "
// --- DE_SECT S(DE_3)       // §
// --- DE_DLR  S(DE_4)       // $
// --- DE_PERC S(DE_5)       // %
// --- DE_AMPR S(DE_6)       // &
// --- DE_SLSH S(DE_7)       // /
// --- DE_LPRN S(DE_8)       // (
// --- DE_RPRN S(DE_9)       // )
// --- DE_EQL  S(DE_0)       // =
// --- DE_QUES S(DE_SS)      // ?
// --- DE_GRV  S(DE_ACUT)    // ` (dead)
// --- DE_ASTR S(DE_PLUS)    // *
// --- DE_QUOT S(DE_HASH)    // '
// --- DE_RABK S(DE_LABK)    // >
// --- DE_SCLN S(DE_COMM)    // ;
// --- DE_COLN S(DE_DOT)     // :
// --- DE_UNDS S(DE_MINS)    // _
// --- DE_DLQU A(DE_CIRC)    // „
// --- DE_IEXL A(DE_1)       // ¡
// --- DE_LDQU A(DE_2)       // “
// --- DE_PILC A(DE_3)       // ¶
// --- DE_CENT A(DE_4)       // ¢
// --- DE_LBRC A(DE_5)       // [
// --- DE_RBRC A(DE_6)       // ]
// --- DE_PIPE A(DE_7)       // |
// --- DE_LCBR A(DE_8)       // {
// --- DE_RCBR A(DE_9)       // }
// --- DE_NEQL A(DE_0)       // ≠
// --- DE_IQUE A(DE_SS)      // ¿
// --- DE_LDAQ A(DE_Q)       // «
// --- DE_NARS A(DE_W)       // ∑
// --- DE_EURO A(DE_E)       // €
// --- DE_REGD A(DE_R)       // ®
// --- DE_DAGG A(DE_T)       // †
// --- DE_OMEG A(DE_Z)       // Ω
// --- DE_DIAE A(DE_U)       // ¨ (dead)
// --- DE_FRSL A(DE_I)       // ⁄
// --- DE_OSTR A(DE_O)       // Ø
// --- DE_PI   A(DE_P)       // π
// --- DE_BULT A(DE_UDIA)    // •
// --- DE_PLMN A(DE_PLUS)    // ±
// --- DE_ARNG A(DE_A)       // Å
// --- DE_SLQU A(DE_S)       // ‚
// --- DE_PDIF A(DE_D)       // ∂
// --- DE_FHK  A(DE_F)       // ƒ
// --- DE_COPY A(DE_G)       // ©
// --- DE_FORD A(DE_H)       // ª
// --- DE_MORD A(DE_J)       // º
// --- DE_INCR A(DE_K)       // ∆
// --- DE_AT   A(DE_L)       // @
// --- DE_OE   A(DE_ODIA)    // Œ
// --- DE_AE   A(DE_ADIA)    // Æ
// --- DE_LSQU A(DE_HASH)    // ‘
// --- DE_LTEQ A(DE_LABK)    // ≤
// --- DE_YEN  A(DE_Y)       // ¥
// --- DE_AEQL A(DE_X)       // ≈
// --- DE_CCCE A(DE_C)       // Ç
// --- DE_SQRT A(DE_V)       // √
// --- DE_INTG A(DE_B)       // ∫
// --- DE_TILD A(DE_N)       // ~ (dead)
// --- DE_MICR A(DE_M)       // µ
// --- DE_INFN A(DE_COMM)    // ∞
// --- DE_ELLP A(DE_DOT)     // …
// --- DE_NDSH A(DE_MINS)    // –
// --- DE_NOT  S(A(DE_1))    // ¬
// --- DE_RDQU S(A(DE_2))    // ”
// --- DE_PND  S(A(DE_4))    // £
// --- DE_FI   S(A(DE_5))    // ﬁ
// --- DE_BSLS S(A(DE_7))    // (backslash)
// --- DE_STIL S(A(DE_8))    // ˜
// --- DE_MDDT S(A(DE_9))    // ·
// --- DE_MACR S(A(DE_0))    // ¯
// --- DE_DOTA S(A(DE_SS))   // ˙
// --- DE_RNGA S(A(DE_ACUT)) // ˚
// --- DE_RDAQ S(A(DE_Q))    // »
// --- DE_PERM S(A(DE_E))    // ‰
// --- DE_CEDL S(A(DE_R))    // ¸
// --- DE_DACU S(A(DE_T))    // ˝
// --- DE_CARN S(A(DE_Z))    // ˇ
// --- DE_AACU S(A(DE_U))    // Á
// --- DE_UCIR S(A(DE_I))    // Û
// --- DE_NARP S(A(DE_P))    // ∏
// --- DE_APPL S(A(DE_PLUS)) //  (Apple logo)
// --- DE_IACU S(A(DE_S))    // Í
// --- DE_TM   S(A(DE_D))    // ™
// --- DE_IDIA S(A(DE_F))    // Ï
// --- DE_IGRV S(A(DE_G))    // Ì
// --- DE_OACU S(A(DE_H))    // Ó
// --- DE_DLSI S(A(DE_J))    // ı
// --- DE_FL   S(A(DE_L))    // ﬂ
// --- DE_GTEQ S(A(DE_LABK)) // ≥
// --- DE_DDAG S(A(DE_Y))    // ‡
// --- DE_UGRV S(A(DE_X))    // Ù
// --- DE_LOZN S(A(DE_V))    // ◊
// --- DE_LSAQ S(A(DE_B))    // ‹
// --- DE_RSAQ S(A(DE_N))    // ›
// --- DE_BREV S(A(DE_M))    // ˘
// --- DE_OGON S(A(DE_COMM)) // ˛
// --- DE_DIV  S(A(DE_DOT))  // ÷
// --- DE_MDSH S(A(DE_MINS)) // —


// --- SETUP FOR PC LAYOUT
// #include "keymap_german.h" // <-- UNCOMMENT THIS LINE
// --- Aliases:
// --- DE_CIRC KC_GRV        // ^ (dead)
// --- DE_1    KC_1          // 1
// --- DE_2    KC_2          // 2
// --- DE_3    KC_3          // 3
// --- DE_4    KC_4          // 4
// --- DE_5    KC_5          // 5
// --- DE_6    KC_6          // 6
// --- DE_7    KC_7          // 7
// --- DE_8    KC_8          // 8
// --- DE_9    KC_9          // 9
// --- DE_0    KC_0          // 0
// --- DE_SS   KC_MINS       // ß
// --- DE_ACUT KC_EQL        // ´ (dead)
// --- DE_Q    KC_Q          // Q
// --- DE_W    KC_W          // W
// --- DE_E    KC_E          // E
// --- DE_R    KC_R          // R
// --- DE_T    KC_T          // T
// --- DE_Z    KC_Y          // Z
// --- DE_U    KC_U          // U
// --- DE_I    KC_I          // I
// --- DE_O    KC_O          // O
// --- DE_P    KC_P          // P
// --- DE_UDIA KC_LBRC       // Ü
// --- DE_PLUS KC_RBRC       // +
// --- DE_A    KC_A          // A
// --- DE_S    KC_S          // S
// --- DE_D    KC_D          // D
// --- DE_F    KC_F          // F
// --- DE_G    KC_G          // G
// --- DE_H    KC_H          // H
// --- DE_J    KC_J          // J
// --- DE_K    KC_K          // K
// --- DE_L    KC_L          // L
// --- DE_ODIA KC_SCLN       // Ö
// --- DE_ADIA KC_QUOT       // Ä
// --- DE_HASH KC_NUHS       // #
// --- DE_LABK KC_NUBS       // <
// --- DE_Y    KC_Z          // Y
// --- DE_X    KC_X          // X
// --- DE_C    KC_C          // C
// --- DE_V    KC_V          // V
// --- DE_B    KC_B          // B
// --- DE_N    KC_N          // N
// --- DE_M    KC_M          // M
// --- DE_COMM KC_COMM       // ,
// --- DE_DOT  KC_DOT        // .
// --- DE_MINS KC_SLSH       // -
// --- DE_DEG  S(DE_CIRC)    // °
// --- DE_EXLM S(DE_1)       // !
// --- DE_DQUO S(DE_2)       // "
// --- DE_SECT S(DE_3)       // §
// --- DE_DLR  S(DE_4)       // $
// --- DE_PERC S(DE_5)       // %
// --- DE_AMPR S(DE_6)       // &
// --- DE_SLSH S(DE_7)       // /
// --- DE_LPRN S(DE_8)       // (
// --- DE_RPRN S(DE_9)       // )
// --- DE_EQL  S(DE_0)       // =
// --- DE_QUES S(DE_SS)      // ?
// --- DE_GRV  S(DE_ACUT)    // ` (dead)
// --- DE_ASTR S(DE_PLUS)    // *
// --- DE_QUOT S(DE_HASH)    // '
// --- DE_RABK S(DE_LABK)    // >
// --- DE_SCLN S(DE_COMM)    // ;
// --- DE_COLN S(DE_DOT)     // :
// --- DE_UNDS S(DE_MINS)    // _
// --- DE_SUP2 ALGR(DE_2)    // ²             // different from mac keys
// --- DE_SUP3 ALGR(DE_3)    // ³             // different from mac keys
// --- DE_LCBR ALGR(DE_7)    // {             // different from mac keys
// --- DE_LBRC ALGR(DE_8)    // [             // different from mac keys
// --- DE_RBRC ALGR(DE_9)    // ]             // different from mac keys
// --- DE_RCBR ALGR(DE_0)    // }             // different from mac keys
// --- DE_BSLS ALGR(DE_SS)   // (backslash)   // different from mac keys
// --- DE_AT   ALGR(DE_Q)    // @             // different from mac keys
// --- DE_EURO ALGR(DE_E)    // €             // different from mac keys
// --- DE_TILD ALGR(DE_PLUS) // ~             // different from mac keys
// --- DE_PIPE ALGR(DE_LABK) // |             // different from mac keys
// --- DE_MICR ALGR(DE_M)    // µ             // different from mac keys


// --- Symbols avilable in PC but not in MAC:
// --- DE_SUP2 ALGR(DE_2)    // ²
// --- DE_SUP3 ALGR(DE_3)    // ³


// --> Keycodes:                   https://docs.qmk.fm/#/keycodes
// --> Basic Keycodes:             https://docs.qmk.fm/#/keycodes_basic
// --> Advanced Keycodes:          https://docs.qmk.fm/#/feature_advanced_keycodes
// --> Language Specific Keycodes: https://github.com/qmk/qmk_firmware/tree/master/quantum/keymap_extras


// --- From callum's keymap (https://github.com/qmk/qmk_firmware/blob/user-keymaps-still-present/users/callum/callum.c)
#define HOME  G(KC_LEFT)    // moving the cursor to the beginning of the line
#define END   G(KC_RGHT)    // moving the cursor to the end of the line
// #define FWD   G(KC_RBRC)    // browser forward in history
// #define BACK  G(KC_LBRC)    // browser back in history
#define TABL  G(S(KC_LBRC)) // ?
#define TABR  G(S(KC_RBRC)) // ?
#define SPCL  A(G(KC_LEFT)) // ?
#define SPC_R A(G(KC_RGHT)) // ?

// --- Layer Modifiers
#define M_NAV MO(_MAC_NAV) // Layer MAC
#define M_SYM MO(_MAC_SYM)
#define M_NUM MO(_MAC_NUM)
#define M_FNU MO(_MAC_FNU)
#define W_NAV MO(_WIN_NAV) // Layer WIN
#define W_SYM MO(_WIN_SYM)
#define W_NUM MO(_WIN_NUM)
#define W_FNU MO(_WIN_FNU)

// --- Mac specific shortcuts start with "M_" (from: https://github.com/bsag/qmk_custom/blob/main/mini3x5/keycodes.h#L25)
#define M_UNDO  G(DE_Z)
#define M_CUT   G(DE_X)
#define M_COPY  G(DE_C)
#define M_PSTE  G(DE_V)
#define M_SELA  G(DE_A)
#define M_FIND  G(DE_F)
#define M_SAVE  G(DE_S)
#define M_RCAST G(KC_SPC) // Raycast 
#define M_RGPT  G(DE_DOT) // Raycast GPT
// #define TAB_L G(S(KC_LBRC))
// #define TAB_R G(S(KC_RBRC))
// #define WS_L A(S(KC_LEFT))  // select word left
// #define WS_R A(S(KC_RIGHT)) // select word right
// #define W_L A(KC_LEFT)      // move word left
// #define W_R A(KC_RIGHT)     // move word right
// #define LAU LGUI(KC_SPC)    // launcher (cmd+spc)



// --- Windows specific shortcuts start with "W_" (from:
#define W_UNDO  C(DE_Z)
#define W_CUT   C(DE_X)
#define W_COPY  C(DE_C)
#define W_PSTE  C(DE_V)
#define W_SELA  C(DE_A)
#define W_FIND  C(DE_F)
#define W_SAVE  C(DE_S)
// --- different from mac keys
#define W_SUP2 ALGR(DE_2)    // ²
#define W_SUP3 ALGR(DE_3)    // ³
#define W_LCBR ALGR(DE_7)    // {
#define W_LBRC ALGR(DE_8)    // [
#define W_RBRC ALGR(DE_9)    // ]
#define W_RCBR ALGR(DE_0)    // }
#define W_BSLS ALGR(DE_SS)   // (backslash)
#define W_AT   ALGR(DE_Q)    // @
#define W_EURO ALGR(DE_E)    // €
#define W_TILD ALGR(DE_PLUS) // ~
#define W_PIPE ALGR(DE_LABK) // |
#define W_MICR ALGR(DE_M)    // µ



enum layers {
    _MAC_DEF, // Default Layer for Mac
    _MAC_NAV,
    _MAC_SYM,
    _WIN_NUM,
    _MAC_FNU,
    _WIN_DEF, // Default Layer for Windows
    _WIN_NAV,
    _WIN_SYM,
    _MAC_NUM,
    _WIN_FNU,
};


enum keycodes {
    // --- Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab) --> TODO test
    SW_LANG, // Switch to next input language (ctl-spc) --> TODO delete

    SS_HELL, // SS = send string
    SS_MAIL,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off

    [_MAC_DEF] = LAYOUT_split_3x5_3(
        DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,          DE_J,    DE_L,    DE_U,    DE_Y,    XXXXXXX,
        DE_A,    DE_R,    DE_S,    DE_T,    DE_G,          DE_M,    DE_N,    DE_E,    DE_I,    DE_O,
        DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,          DE_K,    DE_H,    DE_COMM, DE_DOT,  DE_UNDS,
                          M_SYM,   M_NUM,   M_NAV,         OS_SHFT, KC_SPC,  KC_BSPC
    ),
    [_MAC_NAV] = LAYOUT_split_3x5_3(
        KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,        XXXXXXX, HOME,    KC_UP,   END,     XXXXXXX,
        OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT, KC_TAB,        SW_WIN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
        M_SELA,  M_CUT,   M_COPY,  M_PSTE,  KC_ENT,        M_UNDO,  M_SAVE,  M_FIND,  XXXXXXX, M_RGPT,
                          _______, _______, _______,       OS_SHFT, M_RCAST, KC_DEL
    ),
    [_MAC_SYM] = LAYOUT_split_3x5_3(
        DE_QUOT, DE_LBRC, DE_RBRC, DE_PLUS, DE_ASTR,       DE_TILD, DE_BSLS, DE_PIPE, DE_AMPR, XXXXXXX,
        DE_DQUO, DE_LPRN, DE_RPRN, DE_MINS, DE_SLSH,       DE_AT,   OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL,
        DE_GRV,  DE_LCBR, DE_RCBR, DE_EQL,  DE_HASH,       DE_LABK, DE_RABK, DE_QUES, DE_EXLM, XXXXXXX,
                          _______, _______, _______,       OS_SHFT, XXXXXXX, XXXXXXX
    ),
    [_MAC_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX,  DE_7,   DE_8,    DE_9,    DE_COMM,       DE_SECT, DE_ADIA, DE_UDIA, DE_ODIA, DE_SS,
        XXXXXXX,  DE_4,   DE_5,    DE_6,    DE_0,          DE_CIRC, OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL,
        XXXXXXX,  DE_1,   DE_2,    DE_3,    DE_DOT,        DE_DLR,  DE_EURO, DE_PERC, DE_DEG,  DE_MICR,
                          _______, _______, _______,       OS_SHFT, M_FNU,  XXXXXXX
    ),
    [_MAC_FNU] = LAYOUT_split_3x5_3(
        XXXXXXX,  KC_F7,  KC_F8,   KC_F9,   KC_F12,        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, DF(_WIN_DEF),
        XXXXXXX,  KC_F4,  KC_F5,   KC_F6,   KC_F11,        XXXXXXX, SS_HELL, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  KC_F1,  KC_F2,   KC_F3,   KC_F10,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,       XXXXXXX, _______, XXXXXXX
    ),

    // WINDOWS LAYOUT
    [_WIN_DEF] = LAYOUT_split_3x5_3(
        DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,          DE_J,    DE_L,    DE_U,    DE_Y,    XXXXXXX,
        DE_A,    DE_R,    DE_S,    DE_T,    DE_G,          DE_M,    DE_N,    DE_E,    DE_I,    DE_O,
        DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,          DE_K,    DE_H,    DE_COMM, DE_DOT,  DE_UNDS,
                          W_SYM,   W_NUM,   W_NAV,         OS_SHFT, KC_SPC,  KC_BSPC
    ),
    [_WIN_NAV] = LAYOUT_split_3x5_3(
        KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,        XXXXXXX, HOME,    KC_UP,   END,     XXXXXXX,
        OS_CMD,  OS_ALT,  OS_CTRL,  OS_SHFT, KC_TAB,        SW_WIN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
        W_SELA,  W_CUT,   W_COPY,  W_PSTE,  KC_ENT,        W_UNDO,  W_SAVE,  W_FIND,  XXXXXXX, XXXXXXX,
                          _______, _______, _______,       OS_SHFT, XXXXXXX, KC_DEL
    ),
    [_WIN_SYM] = LAYOUT_split_3x5_3(
        DE_QUOT, W_LBRC,  W_RBRC,  DE_PLUS, DE_ASTR,       W_TILD,  W_BSLS,  W_PIPE,  DE_AMPR, XXXXXXX,
        DE_DQUO, DE_LPRN, DE_RPRN, DE_MINS, DE_SLSH,       W_AT,    OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,
        DE_GRV,  W_LCBR,  W_RCBR,  DE_EQL,  DE_HASH,       DE_LABK, DE_RABK, DE_QUES, DE_EXLM, XXXXXXX,
                          _______, _______, _______,       OS_SHFT, XXXXXXX, XXXXXXX
    ),
    [_WIN_NUM] = LAYOUT_split_3x5_3(
        W_SUP3,   DE_7,   DE_8,    DE_9,    DE_COMM,       DE_SECT, DE_ADIA, DE_UDIA, DE_ODIA, DE_SS,
        W_SUP2,   DE_4,   DE_5,    DE_6,    DE_0,          DE_CIRC, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,
        XXXXXXX,  DE_1,   DE_2,    DE_3,    DE_DOT,        DE_DLR,  W_EURO,  DE_PERC, DE_DEG,  W_MICR,
                          _______, _______, _______,       OS_SHFT, W_FNU,   XXXXXXX
    ),
    [_WIN_FNU] = LAYOUT_split_3x5_3(
        XXXXXXX,  KC_F7,  KC_F8,   KC_F9,   KC_F12,        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, DF(_MAC_DEF),
        XXXXXXX,  KC_F4,  KC_F5,   KC_F6,   KC_F11,        XXXXXXX, SS_HELL, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  KC_F1,  KC_F2,   KC_F3,   KC_F10,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______,       XXXXXXX, _______, XXXXXXX
    )

    // clang-format on
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case M_NAV: // Mac
    case M_SYM:
    case M_NUM:
    case W_NAV: // Win
    case W_SYM:
    case W_NUM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case M_NAV: // Mac
    case M_SYM:
    case M_NUM:
    case W_NAV: // Win
    case W_SYM:
    case W_NUM:
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
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

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

    // Additional processing logic for sending strings
    switch (keycode) {
        case SS_HELL:
            if (record->event.pressed) {
                SEND_STRING("Hello, world!\n");
            }
            return false;
        case SS_MAIL:
            if (record->event.pressed) {
                SEND_STRING("mail@mail.com");
            }
            return false;

        // --- Switching default layers
        case DF(_MAC_DEF):
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC_DEF);
            }
            return false;
        case DF(_WIN_DEF):
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN_DEF);
            }
            return false;
    }

    return true;
}

// --- not yet used:
// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _NAV, _SYM, _FNU);
// }