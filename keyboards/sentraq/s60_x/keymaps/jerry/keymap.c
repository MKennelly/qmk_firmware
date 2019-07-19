// Can reset with either SPACE + b on plug in or RESET key
#include QMK_KEYBOARD_H
#include "s60_x.h"

enum s60_layers {
  _QWERTY,
  _COLEMAK,
  _RAISE,
  _LOWER,
  _ADJUST
};

enum keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  HIJERRY,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Random aliases
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define CTL_ESC LCTL_T(KC_ESC)
#define SPC_FN LT(_RAISE, KC_SPC)

// Enable/disable win key aliases
#define NO_WIN MAGIC_NO_GUI
#define YES_WIN MAGIC_UNNO_GUI

// Dynamic macro aliases
#define DM_STOP DYN_REC_STOP
#define DM1_REC DYN_REC_START1
#define DM2_REC DYN_REC_START2
#define DM1_PLY DYN_MACRO_PLAY1
#define DM2_PLY DYN_MACRO_PLAY2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ Esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │▒▒▒▒▒│BKSPC│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  \  │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│CL/ES│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ENTER│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│L_ALT│L_CMD│█████│█████│█████│ SPC │█████│█████│█████│R_CMD│R_ALT│Lower│Raise│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
	[_QWERTY] = LAYOUT_60_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, \
        KC_LCTL, KC_LALT, KC_LGUI,                            SPC_FN,                              KC_RGUI, KC_RALT, LOWER,   RAISE    \
	),

    /* Colemak
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ Esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │▒▒▒▒▒│BKSPC│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  Q  │  W  │  F  │  P  │  G  │  J  │  L  │  U  │  Y  │  ;  │  [  │  ]  │  \  │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│CL/ES│  A  │  R  │  S  │  T  │  D  │  H  │  N  │  E  │  I  │  O  │  '  │▒▒▒▒▒│ENTER│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  K  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│L_ALT│L_CMD│█████│█████│█████│ SPC │█████│█████│█████│R_CMD│R_ALT│Mouse│ Fn0 │█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
	[_COLEMAK] = LAYOUT_60_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,     KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, \
        CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,     KC_I,    KC_O,    KC_QUOT,          KC_ENT,  \
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, \
        KC_LCTL, KC_LALT, KC_LGUI,                            SPC_FN,                              KC_RGUI, KC_RALT, LOWER,   RAISE    \
	),

    /* Function Layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │▒▒▒▒▒│ Del │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Caps │PgUp │Home │ Up  | End │PgDwn│     │     │ Psc │ Slk │Pause│ Up  │     │ Ins │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │Left │Down │Right│     │     │     │Home │PgUp │Left │Right│▒▒▒▒▒│     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │▒▒▒▒▒│VolD │VolU │Mute │     │     │     │     │ Br- │ Br+ │Down │▒▒▒▒▒│     │▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │█████│█████│█████│Space│█████│█████│█████│     │     │ MO6 │     │█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [_RAISE] = LAYOUT_60_ansi(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,         KC_DEL, \
        KC_CAPS, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, _______, _______, KC_UP,   _______, _______, KC_UP,   _______, KC_INS, \
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LEFT, KC_RGHT,          _______,\
        _______,          KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_BRID, KC_BRIU, KC_DOWN,          _______,\
        _______, _______, _______,                            _______,                            _______, _______, _______, _______ \
	),

    /* Mouse mode (Semicolon/App)
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │▒▒▒▒▒│     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │WhlD │LClck│ MUp │RClck│     │     │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │Accl0│Accl1│Accl2│     │WhlU │MLeft│MDown│MRght│     │     │▒▒▒▒▒│     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │▒▒▒▒▒│     │     │     │     │     │WhlL │MClck│WhlR │     │     │▒▒▒▒▒│     │▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │RCTRL│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [_LOWER] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          _______, \
        _______, _______, _______, _______, _______, _______, KC_WH_D, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______,\
        _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,          _______,\
        _______,          HIJERRY, _______, _______, _______, _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, _______,          _______,\
        _______, _______, _______,                            _______,                            _______, _______, _______, _______ \
	),
    /* Layer/mode adjust
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ QW  │ CM  │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│RESET│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │     │     │     │     │     │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │MAC1R│MAC1P│MAC2R│MAC2P│     │     │     │     │     │     │     │▒▒▒▒▒│MCSET│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │▒▒▒▒▒│     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │ WIN │ CMD │█████│█████│█████│     │█████│█████│█████│WINOF│WINON│     │     │█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
    */
    [_ADJUST] = LAYOUT_60_ansi(
    QWERTY,  COLEMAK,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,  \
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
	_______, DM1_REC, DM1_PLY, DM2_REC, DM2_PLY, _______, _______, _______, _______, _______, _______, _______,          DM_STOP, \
	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
	_______, AG_SWAP, AG_NORM,                            _______,                            NO_WIN,  YES_WIN, _______, _______  \
	),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
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
    case HIJERRY:
      if (record->event.pressed) {
        SEND_STRING("Hi Jerry!");
      }
      return false;
      break;
  }
  return true;
};
