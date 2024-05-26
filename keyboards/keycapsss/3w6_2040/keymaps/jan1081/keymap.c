// HOWTO COMPILE FIRMWARE LOCAL:
// qmk compile -kb keycapsss/3w6_2040 -km jan1081

// LINKS:
// --> Keycodes:                      https://docs.qmk.fm/#/keycodes
// --> Basic Keycodes:                https://docs.qmk.fm/#/keycodes_basic
// --> Advanced Keycodes:             https://docs.qmk.fm/#/feature_advanced_keycodes
// --> Language Specific Keycodes:    https://github.com/qmk/qmk_firmware/tree/master/quantum/keymap_extras
// --> Callum style layer (original): https://github.com/qmk/qmk_firmware/blob/user-keymaps-still-present/users/callum/callum.c
// --> Callum style layer (36 key):   https://github.com/braindefender/wellum

#include QMK_KEYBOARD_H
#include "oneshot.h"
#include "swapper.h"

#include "keymap_german_mac_iso.h" // MAC LAYOUT
// #include "keymap_german.h"      // WIN LAYOUT

// Windows keys that different from Mac start with "W_"
#define W_SUP2 ALGR(DE_2)    // ²
#define W_SUP3 ALGR(DE_3)    // ³
#define W_LCBR ALGR(DE_7)    // {
#define W_RCBR ALGR(DE_0)    // }
#define W_LBRC ALGR(DE_8)    // [
#define W_RBRC ALGR(DE_9)    // ]
#define W_BSLS ALGR(DE_SS)   // (backslash)
#define W_AT ALGR(DE_Q)      // @
#define W_EURO ALGR(DE_E)    // €
#define W_TILD ALGR(DE_PLUS) // ~
#define W_PIPE ALGR(DE_LABK) // |
#define W_MICR ALGR(DE_M)    // µ

// MacOS shortcuts start with "M_":
#define M_UNDO G(DE_Z)
#define M_CUT G(DE_X)
#define M_COPY G(DE_C)
#define M_PSTE G(DE_V)
#define M_SELA G(DE_A)
#define M_FIND G(DE_F)
#define M_SAVE G(DE_S)
#define M_RCAST G(KC_SPC) // Raycast
#define M_RGPT G(DE_DOT)  // Raycast GPT
#define HOME G(KC_LEFT)   // moving the cursor to the beginning of the line
#define END G(KC_RGHT)    // moving the cursor to the end of the line
// #define FWD   G(KC_RBRC)    // browser forward in history
// #define BACK  G(KC_LBRC)    // browser back in history
// #define TABL  G(S(KC_LBRC)) // ?
// #define TABR  G(S(KC_RBRC)) // ?
// #define SPCL  A(G(KC_LEFT)) // ?
// #define SPC_R A(G(KC_RGHT)) // ?
// #define TAB_L G(S(KC_LBRC))
// #define TAB_R G(S(KC_RBRC))
// #define WS_L A(S(KC_LEFT))  // select word left
// #define WS_R A(S(KC_RIGHT)) // select word right
// #define W_L A(KC_LEFT)      // move word left
// #define W_R A(KC_RIGHT)     // move word right
// #define LAU LGUI(KC_SPC)    // launcher (cmd+spc)

// Windows specific shortcuts start with "W_" (from:
#define W_UNDO C(DE_Z)
#define W_CUT C(DE_X)
#define W_COPY C(DE_C)
#define W_PSTE C(DE_V)
#define W_SELA C(DE_A)
#define W_FIND C(DE_F)
#define W_SAVE C(DE_S)

// Layer Modifiers:
#define M_NAV MO(_MAC_NAV) // Layer MAC
#define M_SYM MO(_MAC_SYM)
#define M_NUM MO(_MAC_NUM)
#define M_FNU MO(_MAC_FNU)
#define W_NAV MO(_WIN_NAV) // Layer WIN
#define W_SYM MO(_WIN_SYM)
#define W_NUM MO(_WIN_NUM)
#define W_FNU MO(_WIN_FNU)

// LAYERS:
enum layers {
    _MAC_DEF, // Default Layer for Mac
    _WIN_DEF, // Default Layer for Windows

    _MAC_NAV,
    _WIN_NAV,

    _MAC_SYM,
    _WIN_SYM,

    _MAC_NUM,
    _WIN_NUM,

    _MAC_FNU,
    _WIN_FNU,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    // Switch to next window (cmd-tab)
    SW_WIN,

    // Custom keycodes for sending strings, SS = send string
    SS_HELL,
    SS_MAIL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
    [_MAC_DEF] = LAYOUT_split_3x5_3(
        DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,          DE_J,    DE_L,    DE_U,    DE_Y,    XXXXXXX,
        DE_A,    DE_R,    DE_S,    DE_T,    DE_G,          DE_M,    DE_N,    DE_E,    DE_I,    DE_O,
        DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,          DE_K,    DE_H,    DE_COMM, DE_DOT,  DE_UNDS,
                          M_SYM,   M_NUM,   M_NAV,         KC_LSFT, KC_SPC,  KC_BSPC
    ),
    [_WIN_DEF] = LAYOUT_split_3x5_3(
        DE_Q,    DE_Q,    DE_F,    DE_P,    DE_B,          DE_Q,    DE_Q,    DE_U,    DE_Y,    XXXXXXX,
        DE_A,    DE_R,    DE_S,    DE_T,    DE_G,          DE_M,    DE_N,    DE_E,    DE_I,    DE_O,
        DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,          DE_K,    DE_H,    DE_COMM, DE_DOT,  DE_UNDS,
                          W_SYM,   W_NUM,   W_NAV,         KC_LSFT, KC_SPC,  KC_BSPC
    ),
    [_MAC_NAV] = LAYOUT_split_3x5_3(
        KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,        XXXXXXX, HOME,    KC_UP,   END,     XXXXXXX,
        OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT, KC_TAB,        SW_WIN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
        M_SELA,  M_CUT,   M_COPY,  M_PSTE,  KC_ENT,        M_UNDO,  M_SAVE,  M_FIND,  XXXXXXX, M_RGPT,
                          M_SYM,   M_NUM,   M_NAV,         KC_LSFT, M_RCAST, KC_DEL
    ),
    [_WIN_NAV] = LAYOUT_split_3x5_3(
        KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,        XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,
        OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, KC_TAB,        SW_WIN, KC_LEFT,  KC_DOWN, KC_RGHT, XXXXXXX,
        W_SELA,  W_CUT,   W_COPY,  W_PSTE,  KC_ENT,        W_UNDO,  W_SAVE,  W_FIND,  XXXXXXX, XXXXXXX,
                          W_SYM,   W_NUM,   W_NAV,         KC_LSFT, XXXXXXX, XXXXXXX
    ),
    [_MAC_SYM] = LAYOUT_split_3x5_3(
        DE_QUOT, DE_LBRC, DE_RBRC, DE_PLUS, DE_ASTR,       DE_TILD, DE_BSLS, DE_PIPE, DE_AMPR, XXXXXXX,
        DE_DQUO, DE_LPRN, DE_LPRN, DE_LPRN, DE_SLSH,       DE_AT,   OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL,
        DE_GRV,  DE_LCBR, DE_RCBR, DE_EQL,  DE_HASH,       DE_LABK, DE_RABK, DE_QUES, DE_EXLM, XXXXXXX,
                          M_SYM,   M_NUM,   M_NAV,         KC_LSFT, XXXXXXX, XXXXXXX
    ),
    [_WIN_SYM] = LAYOUT_split_3x5_3(
        DE_QUOT, W_LBRC,  W_RBRC,  DE_PLUS, DE_ASTR,       W_TILD,  W_BSLS,  W_PIPE,  DE_AMPR, XXXXXXX,
        DE_DQUO, DE_LPRN, DE_LPRN, DE_LPRN, DE_SLSH,       W_AT,    OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,
        DE_GRV, W_LCBR,   W_RCBR,  DE_EQL,  DE_HASH,       DE_LABK, DE_RABK, DE_QUES, DE_EXLM, XXXXXXX,
                          W_SYM,   W_NUM,   W_NAV,         KC_LSFT, XXXXXXX, XXXXXXX
    ),
    [_MAC_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX,  DE_7,   DE_8,    DE_9,    DE_COMM,       DE_SECT, DE_ADIA, DE_UDIA, DE_ODIA, DE_SS,
        XXXXXXX,  DE_4,   DE_5,    DE_6,    DE_0,          DE_CIRC, OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL,
        XXXXXXX,  DE_1,   DE_2,    DE_3,    DE_DOT,        DE_DLR,  DE_EURO, DE_PERC, DE_DEG,  DE_MICR,
                          M_SYM,   M_NUM,   M_NAV,         KC_LSFT, M_FNU,   XXXXXXX
    ),
    [_WIN_NUM] = LAYOUT_split_3x5_3(
        W_SUP3,   DE_7,   DE_8,    DE_9,    DE_COMM,       DE_SECT, DE_ADIA, DE_UDIA, DE_ODIA, DE_SS,
        W_SUP2,   DE_4,   DE_5,    DE_6,    DE_0,          DE_CIRC, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,
        XXXXXXX,  DE_1,   DE_2,    DE_3,    DE_DOT,        DE_DLR,  W_EURO,  DE_PERC, DE_DEG, W_MICR,
                          W_SYM,   W_NUM,   W_NAV,         KC_LSFT, W_FNU,   XXXXXXX
    ),
    [_MAC_FNU] = LAYOUT_split_3x5_3(
        XXXXXXX,  KC_F7,  KC_F8,   KC_F9,   KC_F12,        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, DF(_WIN_DEF),
        XXXXXXX,  KC_F4,  KC_F5,   KC_F6,   KC_F11,        XXXXXXX, SS_HELL, SS_MAIL, XXXXXXX, XXXXXXX,
        XXXXXXX,  KC_F1,  KC_F2,   KC_F3,   KC_F10,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          M_SYM,   M_NUM,   M_NAV,         XXXXXXX, M_FNU,   XXXXXXX
    ),
    [_WIN_FNU] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, DF(_MAC_DEF),
        XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          W_SYM,   W_NUM,   W_NAV,         XXXXXXX, W_FNU,   XXXXXXX
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
        case KC_LSFT: // Normal Shift
        case OS_SHFT: // One Shot Shift
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

bool sw_win_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_WIN, keycode, record);
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);
    switch (keycode) {
        // Additional processing logic for sending strings
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
                layer_state_set(1 << _MAC_DEF);
            }
            return false;
        case DF(_WIN_DEF):
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN_DEF);
                layer_state_set(1 << _WIN_DEF);
            }
            return false;
    }
    return true;
}

// --- RGB LIGHTING ------------------------------

// HSV_AZURE       132, 102, 255
// HSV_BLACK         0,   0,   0
// HSV_WHITE         0,   0, 255
// HSV_RED           0, 255, 255 *
// HSV_CORAL        11, 176, 255
// HSV_ORANGE       21, 255, 255
// HSV_GOLDENROD    30, 218, 218
// HSV_YELLOW       43, 255, 255
// HSV_GOLD         36, 255, 255 *
// HSV_CHARTREUSE   64, 255, 255
// HSV_GREEN        85, 255, 255 *
// HSV_SPRINGGREEN 106, 255, 255
// HSV_TURQUOISE   123,  90, 112
// HSV_CYAN        128, 255, 255
// HSV_TEAL        128, 255, 128
// HSV_BLUE        170, 255, 255 *
// HSV_PURPLE      191, 255, 255 *
// HSV_MAGENTA     213, 255, 255 *
// HSV_PINK        234, 128, 255

const rgblight_segment_t PROGMEM LED_MAC_DEF[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_YELLOW});
// const rgblight_segment_t PROGMEM LED_WIN_DEF[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 0, 255, 50} // HSV_RED darker
// );
// const rgblight_segment_t PROGMEM LED_NAV[]     = RGBLIGHT_LAYER_SEGMENTS({0, 1, 36, 255, 50} // HSV_GOLD darker
//     );
// const rgblight_segment_t PROGMEM LED_SYM[]     = RGBLIGHT_LAYER_SEGMENTS({0, 1, 191, 255, 50} // HSV_PURPLE darker
//     );
// const rgblight_segment_t PROGMEM LED_NUM[]     = RGBLIGHT_LAYER_SEGMENTS({0, 1, 85, 255, 50} // HSV_GREEN darker
//     );
// const rgblight_segment_t PROGMEM LED_FNU[]     = RGBLIGHT_LAYER_SEGMENTS({0, 1, 213, 255, 50} // HSV_MAGENTA darker
//     );

// const rgblight_segment_t *const PROGMEM my_led_layers[] = RGBLIGHT_LAYERS_LIST(LED_MAC_DEF, LED_WIN_DEF, LED_NAV, LED_SYM, LED_NUM, LED_FNU);

// void keyboard_post_init_user(void) {
//     rgblight_layers = my_led_layers; // Enable the LED layers
// }

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(0, layer_state_cmp(state, _MAC_DEF));
//     rgblight_set_layer_state(1, layer_state_cmp(state, _WIN_DEF));
//     return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(2, layer_state_cmp(state, _MAC_NAV) || layer_state_cmp(state, _WIN_NAV));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _MAC_NUM) || layer_state_cmp(state, _WIN_NUM));
//     rgblight_set_layer_state(4, layer_state_cmp(state, _MAC_SYM) || layer_state_cmp(state, _WIN_SYM));
//     rgblight_set_layer_state(5, layer_state_cmp(state, _MAC_FNU) || layer_state_cmp(state, _WIN_FNU));
//     return state;
// }

// --- PUFFER ------------------------------

// --- RESET EEPROM (persistent storage, also after flashing a new firmware) for default layer:
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case DF(0):
//             if (record->event.pressed) {
//                 set_single_persistent_default_layer(0);
//             }
//             return false;
//     }
//     return true;
// }

// --- TRI LAYER not used:
// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _NAV, _SYM, _FNU);
// }a
