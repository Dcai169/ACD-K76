/* Copyright 2021 Alcidine
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _FN,
    _AG,
    _HY
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    US_FLAG
};

enum unicode_names {
    ALEF, ALFA, BETA, DC, DM, THET, LAMD, MU, PI, SC, SM, OMEG,
    ESZT, NG, SCHW, BANG, CENT, DGRE, SECT, EU, CU, WARN, PM, MP,
    UNKN, CREW, SALL, BISM, SPZR, SKUL, RDIO, BIOH, COMM, NUMR,
    RISA, RISB, RISC, RISD, RISE, RISF, RISG, RISH, RISI,
    RISJ, RISK, RISL, RISM, RISN, RISO, RISP, RISQ, RISR,
    RISS, RIST, RISU, RISV, RISW, RISX, RISY, RISZ
};

const uint32_t PROGMEM unicode_map[] = {
    [ALEF] = 0x05D0,
    [ALFA] = 0x03B1,
    [BETA] = 0x03B2,
    [DC] = 0x0394,
    [DM] = 0x03B4,
    [THET] = 0x03B8,
    [LAMD] = 0x03BB,
    [MU] = 0x03BC,
    [PI] = 0x03C0,
    [SC] = 0x03A3,
    [SM] = 0x03C3,
    [OMEG] = 0x03A9,

    [ESZT] = 0x00DF,
    [NG] = 0x014B,
    [SCHW] = 0x0259,
    [BANG] = 0x203D,
    [CENT] = 0x00A2,
    [DGRE] = 0x00B0,
    [SECT] = 0x00A7,
    [EU] = 0x20AC,
    [CU] = 0x00A4,
    [WARN] = 0x26A0,
    [PM] = 0x00B1,
    [MP] = 0x2213,

    [UNKN] = 0xFFFD,
    [CREW] = 0x0D9E,
    [SALL] = 0xFDFA,
    [BISM] = 0xFDFD,
    [SPZR] = 0x200B,
    [SKUL] = 0x2620,
    [RDIO] = 0x2622,
    [BIOH] = 0x2623,
    [COMM] = 0x262D,
    [NUMR] = 0x2116,

    [RISA] = 0x1F1E6,
    [RISB] = 0x1F1E7,
    [RISC] = 0x1F1E8,
    [RISD] = 0x1F1E9,
    [RISE] = 0x1F1EA,
    [RISF] = 0x1F1EB,
    [RISG] = 0x1F1EC,
    [RISH] = 0x1F1ED,
    [RISI] = 0x1F1EE,
    [RISJ] = 0x1F1EF,
    [RISK] = 0x1F1F0,
    [RISL] = 0x1F1F1,
    [RISM] = 0x1F1F2,
    [RISN] = 0x1F1F3,
    [RISO] = 0x1F1F4,
    [RISP] = 0x1F1F5,
    [RISQ] = 0x1F1F6,
    [RISR] = 0x1F1F7,
    [RISS] = 0x1F1F8,
    [RIST] = 0x1F1F9,
    [RISU] = 0x1F1FA,
    [RISV] = 0x1F1FB,
    [RISW] = 0x1F1FC,
    [RISX] = 0x1F1FD,
    [RISY] = 0x1F1FE,
    [RISZ] = 0x1F1FF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_QWERTY] = LAYOUT(
        KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL ,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_BSPC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_NO  ,          KC_RSFT,
        KC_LCTRL,KC_LGUI, KC_LALT                          , KC_SPC                            , MO(_AG), MO(_FN) , KC_RALT, KC_RCTRL
    ),
    /* Function */
    [_FN] = LAYOUT(
        RESET  , KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS, KC_END , KC_HOME, KC_PWR ,
        DEBUG  , KC_P1  , KC_P2  , KC_P3  , KC_P4  , KC_P5  , KC_P6  , KC_P7  , KC_P8  , KC_P9  , KC_P0  , KC_PGDN, KC_PGUP, KC_EJCT,
        _______, KC_WBAK, KC_UP  , KC_WFWD, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PENT,
        KC_SLCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_NLCK, 
        _______, _______, _______                           , _______                           , _______, _______, _______, _______
    ),
    /* AltGr */
    [_AG] = LAYOUT(
        _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , _______,
        X(SECT), _______, _______, _______,XP(EU,CU), _______, _______, _______, _______, _______, _______,XP(PM,MP), _______, _______,
        UC_MOD , _______, _______, _______, _______, X(THET), _______, X(LAMD), _______, _______, X(PI)  , _______, _______, _______,
        _______, X(ALFA),XP(SM,SC),XP(DM,DC), _______, _______, _______, _______, _______, _______, X(DGRE), X(ESZT),          _______,
        _______, _______, _______, _______, X(CENT), X(OMEG), X(BETA), X(NG)  , X(MU)  , X(SALL), X(BISM), _______,          _______,
        _______, _______, _______                           , X(SPZR)                           , _______, _______, _______, _______
    ),
    /* Hyper */
    [_HY] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        X(UNKN), X(WARN), X(SKUL), X(RDIO), X(BIOH), X(ALEF), X(CREW), X(BANG), X(NUMR), _______, _______, _______, _______, _______,
        _______, X(RISQ), X(RISW), X(RISE), X(RISR), X(RIST), X(RISY), X(RISU), X(RISI), X(RISO), X(RISP), _______, _______, _______,
        _______, X(RISA), X(RISS), X(RISD), X(RISF), X(RISG), X(RISH), X(RISJ), X(RISK), X(RISL), _______, _______,          _______,
        _______, X(RISZ), X(RISX), X(RISC), X(RISV), X(RISB), X(RISN), X(RISM), _______, _______, _______, _______,          _______,
        _______, _______, _______                           , _______                           , _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case US_FLAG:
            // US flag is 2 unicode characters [U][S]
            if (record->event.pressed) {
                // send_unicode_hex_string("1f1fA");
                // send_unicode_hex_string("1f1f8");
            }
            break;
    }
    return true;
}
