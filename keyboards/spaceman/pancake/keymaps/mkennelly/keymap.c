#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
  _NUMBER,
  _MOUSE
};

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  FAT_ARW,
  SLM_ARW,
  PIPE_OP,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_LCAG LCAG_T(XXXXXXX)
#define CTL_ESC LCTL_T(KC_ESC)
#define ALT_TAB LALT_T(KC_TAB)
#define SFT_GRV LSFT_T(KC_GRV)
#define ENT_GUI RGUI_T(KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)
#define ENT_NAV LT(_NAV, KC_ENT)
#define NUMBER MO(_NUMBER)
#define MOUSE MO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |AltTab|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftGrv|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAG  | Nmbr | Alt  | GUI  | Shft |Lower |Raise | Spce | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
  ALT_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  CTL_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   KC_H,   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  SFT_GRV,	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_GUI,
  KC_LCAG,	MOUSE,   KC_LALT, KC_LGUI, KC_LSFT, LOWER,  RAISE,  SPC_NAV, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |AltTab|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftGrv|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAG  | Nmbr | Alt  | GUI  | Shft |Lower |Raise | Spce | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  ALT_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_GRV,	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_GUI,
  KC_LCAG,	MOUSE,   KC_LALT, KC_LGUI, KC_LSFT, LOWER,   RAISE,   SPC_NAV, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower - Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  +   |  -   |  *   |  /   |  =   |XXXXXX|XXXXXX|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL,  XXXXXXX, XXXXXXX, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise -  Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |XXXXXX|  [   |  {   |  (   |  -   |   =  |   )  |  }   |  ]   |  \   |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|  _   |   +  |XXXXXX|  ->  |  =>  |  |>  |XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, XXXXXXX, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, KC_PIPE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX, SLM_ARW, FAT_ARW, PIPE_OP, _______,
  _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, _______, _______
),

/* NAV - Control/nav
 * ,-----------------------------------------------------------------------------------.
 * |      | PGUP | HOME |  UP  | END  | PGDN |XXXXXX|XXXXXX|  Up  |XXXXXX|XXXXXX| Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |XXXXXX| LEFT | DOWN | RGHT |XXXXXX|XXXXXX| Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | MUTE | VOL- | VOL+ |XXXXXX|XXXXXX|XXXXXX|XXXXXX|Brght-|Brght+|XXXXXX|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev | Play | Next | Stop |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_ortho_4x12(
  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_DEL,
  _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______,
  _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|  *   |  4   |  5   |  6   |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|  /   |  1   |  2   |  3   |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |  .   |  =   |XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_ortho_4x12(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,   KC_9,   KC_0,    _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_4,    KC_5,   KC_6,   KC_PMNS, _______,
  _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_PSLS, KC_1,    KC_2,   KC_3,   KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0,   KC_DOT, KC_EQL,  XXXXXXX
),

/* MOUSE - mouse/left nav
 * ,-----------------------------------------------------------------------------------.
 * |      | PGUP | HOME |  UP  | END  | PGDN | WhDwn| LClck|  MUp | RClck|XXXXXX|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |XXXXXX| LEFT | DOWN | RGHT |XXXXXX| WhUp | MLeft| MDown| MRght|XXXXXX|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX| WLeft| MClck| WRght|XXXXXX|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12(
  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, KC_WH_D, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, _______,
  _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______,
  _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_BTN3, KC_WH_R, XXXXXXX, _______,
  NUMBER,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Reset| Debug|Aud on|AudOff|AGnorm|AGswap|Colemk|Qwerty|      |      | Sleep|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |TermOn|TermOf|      |      |      |      |DM1REC|DM1PLY|DM2REC|DM2PLY|DMSTOP|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, COLEMAK, QWERTY,  XXXXXXX, XXXXXXX, KC_SLEP,
  _______, TERM_ON, TERM_OFF,XXXXXXX, OUT_AUTO,OUT_BT,  OUT_USB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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
    case FAT_ARW:
      if (record->event.pressed) {
        SEND_STRING(" => ");
      }
      return false;
      break;
    case SLM_ARW:
      if (record->event.pressed) {
        SEND_STRING(" -> ");
      }
      return false;
      break;
    case PIPE_OP:
      if (record->event.pressed) {
        SEND_STRING("|> ");
      }
      return false;
      break;
  }
  return true;
};
