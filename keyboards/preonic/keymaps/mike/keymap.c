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

#include "preonic.h"
#include "action_layer.h"

enum preonic_layers {
  _COLEMAK,
  _QWERTY,
  _WINCMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SPACE_FN,
  _NUMBER,
  _MOUSE
};

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  WINCMAK,
  LOWER,
  RAISE,
  BACKLIT
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_LCAG LCAG_T(XXXXXXX)
#define CTL_ESC LCTL_T(KC_ESC)
#define ALT_TAB LALT_T(KC_TAB)
#define SFT_GRV LSFT_T(KC_GRV)
#define ENT_GUI RGUI_T(KC_ENT)
#define SPCE_FN LT(_SPACE_FN, KC_SPC)
#define NUMBER MO(_NUMBER)
#define MOUSE MO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |AltTab|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftGrv|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAG  | Nmbr | Alt  | GUI  | Shft |Lower |Raise | Spce | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  /* {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS}, */
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {ALT_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   KC_H,   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {SFT_GRV,	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_GUI},
  {KC_LCAG,	NUMBER,  KC_LALT, KC_LGUI, KC_LSFT, LOWER,  RAISE,  SPCE_FN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |AltTab|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftGrv|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAG  | Nmbr | Alt  | GUI  | Shft |Lower |Raise | Spce | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {ALT_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {SFT_GRV,	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_GUI},
  {KC_LCAG,	NUMBER,  KC_LALT, KC_LGUI, KC_LSFT, LOWER,   RAISE,   SPCE_FN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak (Windows Mods)
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |AltTab|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftGrv|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAG  | Nmbr | Alt  | GUI  | Shft |Lower |Raise | Spce | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WINCMAK] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {ALT_TAB,	KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {SFT_GRV,	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCAG,	NUMBER,  KC_LGUI, KC_LALT, KC_LSFT, LOWER,   RAISE,   SPCE_FN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower - Numbers
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  +   |  -   |  *   |  /   |  =   |XXXXXX|XXXXXX|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_F11 , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12},
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL,  XXXXXXX, XXXXXXX, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise -  Symbols
 * ,-----------------------------------------------------------------------------------.
 * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |XXXXXX|  /   |  {   |  [   |  -   |   +  |   ]  |  }   |  \   |  |   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|  _   |   =  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, XXXXXXX, KC_SLSH, KC_LCBR, KC_LBRC, KC_MINS, KC_PLUS, KC_RBRC, KC_RCBR, KC_BSLS, KC_PIPE, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* SPACE - Control
 * ,-----------------------------------------------------------------------------------.
 * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | PGUP | HOME |  UP  | END  | PGDN |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX| Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |XXXXXX| LEFT | DOWN | RGHT |XXXXXX|XXXXXX| Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | MUTE | VOL- | VOL+ |XXXXXX|XXXXXX|XXXXXX|XXXXXX|Brght-|Brght+|XXXXXX|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev | Play | Next | Stop |
 * `-----------------------------------------------------------------------------------'
 */
[_SPACE_FN] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL},
  {_______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______},
  {_______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP}
},

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|  *   |  4   |  5   |  6   |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|  /   |  1   |  2   |  3   |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |  .   |  =   |XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = {
  {KC_F11 , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F12},
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,   KC_9,   KC_0,    _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_4,    KC_5,   KC_6,   KC_PMNS, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_1,    KC_2,   KC_3,   KC_PPLS, _______},
  {MOUSE,   _______, _______, _______, _______, _______, _______, _______, KC_0,   KC_DOT, KC_EQL,  XXXXXXX}
},

/* MOUSE - mouse/left nav
 * ,-----------------------------------------------------------------------------------.
 * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | PGUP | HOME |  UP  | END  | PGDN | WhDwn| LClck|  MUp | RClck|XXXXXX|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |XXXXXX| LEFT | DOWN | RGHT |XXXXXX| WhUp | MLeft| MDown| MRght|XXXXXX|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX| WLeft| MClck| WRght|XXXXXX|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, KC_WH_D, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, _______},
  {_______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_BTN3, KC_WH_R, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      | Sleep|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TERM_ON, TERM_OFF,XXXXXXX, XXXXXXX, KC_SLEP},
  {_______, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, WINCMAK, XXXXXXX, KC_BSLS},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case WINCMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_WINCMAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            PORTE &= ~(1<<6);
          } else {
            unregister_code(KC_RSFT);
            PORTE |= (1<<6);
          }
          return false;
          break;
      }
    return true;
};
