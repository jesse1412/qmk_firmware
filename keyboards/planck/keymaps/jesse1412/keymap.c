/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "keymap_uk.h"

enum planck_layers { _COLEMAK, _QWERTY, _OSRS, _NAV, _KEYPAD, _KEYPAD_SHIFT, _LOWER, _RAISE, _MOUSE, _ADJUST };

enum planck_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    OSRS,
    CTLSHT,
    SHTCLK
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV MO(_NAV)
#define KP MO(_KEYPAD)
#define KP_SHFT MO(_KEYPAD_SHIFT)
#define TG_ESC TG(_TG_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Blank template
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
/*
[XXX] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
[XXX] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
),
*/

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | NAV  |Lower |    Space    |Raise |Keypad|KPShft|   #  |ENTER |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    UK_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, NAV,     LOWER,   KC_SPC,  KC_SPC,  RAISE,   KP,      KP_SHFT, UK_HASH, KC_ENT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | NAV  |Lower |    Space    |Raise |Keypad|KPShft|   #  |ENTER |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, UK_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, NAV,     LOWER,   KC_SPC,  KC_SPC,  RAISE,   KP,      KP_SHFT, UK_HASH, KC_ENT
),

/* OSRS
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | NAV  |Lower |    Space    |Raise |Keypad|KPShft|   #  |ENTER |
 * `-----------------------------------------------------------------------------------'
 */
[_OSRS] = LAYOUT_planck_grid(
    KC_TAB,   UK_1,    UK_2,    UK_3,    UK_4,    UK_5,    UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    KC_BSPC,
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,
    KC_LSFT,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
    KC_LCTL,  KC_LGUI, KC_LALT, NAV,     LOWER,   KC_SPC,  KC_SPC,  RAISE,   KP,      KP_SHFT, UK_HASH, KC_ENT
),

/* Navigation (Nav)
* ,-----------------------------------------------------------------------------------.
* |      | PGUP | DEL  |  UP  | BKSP | PGDN |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      | HOME | LEFT | DOWN | RIGT | END  |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |CTLSHT| PREV |PLYPAU| NEXT |ENTER |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[_NAV] = LAYOUT_planck_grid(
    _______,  KC_PGUP,  KC_DEL,   KC_UP,   KC_BSPC,  KC_PGDN,  XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,
    _______,  KC_HOME,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_END,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,
    _______,  CTLSHT,   KC_BTN4, KC_MPLY, KC_BTN5, KC_ENT,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,
    _______,  _______,  _______, _______, _______, _______,  _______,   _______,   _______,   _______,   _______,   _______
),

/* Keypad (KP)
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |  7   |  8   |  9   |  -   |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |  4   |  5   |  6   |  +   |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |  1   |  2   |  3   |  /   |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |  0   |      |      |  *   |      |
* `-----------------------------------------------------------------------------------'
*/
[_KEYPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, UK_7, UK_8,    UK_9,    KC_MINS, _______,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, UK_4, UK_5,    UK_6,    KC_PLUS, _______,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, UK_1, UK_2,    UK_3,    KC_SLASH,_______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, UK_0, _______, KC_DOT,  KC_ASTR, _______
),

/* Keypad shifted (KP_SHFT)
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |  &   |  *   |  )   |  _   |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |  $   |  %   |  ^   |  =   |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |  !   |  "   |  £   |  ?   |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |  (   |  .   |      |  *   |      |
* `-----------------------------------------------------------------------------------'
*/
[_KEYPAD_SHIFT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_AMPR,  KC_ASTR, KC_LPRN, KC_UNDS, _______,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_DLR,   KC_PERC, KC_CIRC, KC_EQL,  _______,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_EXLM,  UK_DQUO, S(UK_3), KC_QUES, _______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, KC_RPRN,  KC_DOT,  _______, KC_ASTR, _______
),

/* RAISE
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   [  |   ]  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  |   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   (  |   )  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |   <  |   >  |CapLok|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |   {  |   }  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE,KC_EXLM, UK_DQUO, S(UK_3), KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LBRC, KC_RBRC, KC_BSPC,
    UK_PIPE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LPRN, KC_RPRN, UK_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,    XXXXXXX,    KC_LT,   KC_GT,   KC_CAPS,
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX,    XXXXXXX,    KC_LCBR, KC_RCBR, _______
),

/* Mouse (NAV + Raise).
* ,-----------------------------------------------------------------------------------.
* |      |      |LFTCLK|  UP  |RTCLK |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      | LEFT | DOWN | RIGHT|      |      |ACCL1 |ACCL2 |ACCL3 |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |SHTCLK|      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[_MOUSE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_ACL2, KC_WH_D,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, SHTCLK , KC_BTN4, XXXXXXX, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
),

/* LOWER
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |      |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |CapLok|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRAVE, UK_1,    UK_2,    UK_3,    UK_4,    UK_5,    UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    KC_BSPC,
    UK_BSLS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  XXXXXXX, XXXXXXX, UK_BSLS,
    _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |RGBSPI|RGBSAI|RGBVAI|RGBHUI|      |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |RGBSPD|RGBSAD|RGBVAD|RGBHUD|      |Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |RGBMD+|RGBMD-|      | OSRS |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NKRO |TG_ESC|      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   XXXXXXX, RGB_SPI, RGB_SAI, RGB_VAI, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_DEL ,
    XXXXXXX, XXXXXXX, RGB_SPD, RGB_SAD, RGB_VAD, RGB_HUD, XXXXXXX, QWERTY,  COLEMAK,  XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,RGB_RMOD, RGB_MOD, XXXXXXX, OSRS,    XXXXXXX,  XXXXXXX, XXXXXXX, _______,
    NK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
};

// #ifdef AUDIO_ENABLE
// float tone_startup[][2] = SONG(STARTUP_SOUND);
// float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
// float tone_colemak[][2] = SONG(COLEMAK_SOUND);
// float tone_osrs[][2]    = SONG(SCAPE_MAIN);
// void keyboard_post_init_user(void) { PLAY_SONG(tone_startup); }
// #endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    state = update_tri_layer_state(state, _NAV, _RAISE, _MOUSE);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                //PLAY_SONG(tone_qwerty);
#endif
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                //PLAY_SONG(tone_colemak);
#endif
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case OSRS:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                //PLAY_SONG(tone_osrs);
#endif
                set_single_persistent_default_layer(_OSRS);
            }
            return false;
            break;
        case CTLSHT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case SHTCLK:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_BTN1);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_BTN1);
            }
            return false;
            break;
    }
    return true;
}
