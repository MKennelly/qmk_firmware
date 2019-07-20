  /*     _____, _____, _____, _____, _____, _____,                  _____, _____, _____, _____, _____, _____,\ */
  /*     _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, _____,\ */
  /*                                 _____, _____, _____,    _____, _____, _____ \ */

#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _QWERTY 1
#define _NAV 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  COLEMK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST,
  FATARW,
  SLMARW,
  PIPEOP,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_COLEMK COLEMK
#define KC_QWERTY QWERTY
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_FATARW FATARW
#define KC_SLMARW SLMARW
#define KC_PIPEOP PIPEOP
// Light stuff
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
// Custom mod-taps
#define KC_CTLESC CTL_T(KC_ESC)
#define KC_GUIENT GUI_T(KC_ENT)
#define KC_ALTTAB ALT_T(KC_TAB)
#define KC_SFTGRV SFT_T(KC_GRV)
#define KC_SPCNAV LT(_NAV, KC_SPC)
#define KC_LDSUPR LCAG_T(KC_LEAD)
// Dynamic macros
#define KC_DMSTOP DYN_REC_STOP
#define KC_DM1REC DYN_REC_START1
#define KC_DM2REC DYN_REC_START2
#define KC_DM1PLY DYN_MACRO_PLAY1
#define KC_DM2PLY DYN_MACRO_PLAY2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     ALTTAB,     Q,     W,     F,     P,     G,                      J,     L,     U,     Y,  SCLN,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     CTLESC,     A,     R,     S,     T,     D,                      H,     N,     E,     I,     O,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     SFTGRV,     Z,     X,     C,     V,     B,                      K,     M,  COMM,   DOT,  SLSH,GUIENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LGUI,  LSFT, LOWER,    RAISE,SPCNAV,  LEAD \
                              //`--------------------'  `--------------------'
  ),

  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     ALTTAB,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     CTLESC,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     SFTGRV,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,GUIENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LGUI,  LSFT, LOWER,    RAISE,SPCNAV,  LEAD \
                              //`--------------------'  `--------------------'
  ),

  [_NAV] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,  PGUP,  HOME,    UP,   END,  PGDN,                  XXXXX, XXXXX,    UP, XXXXX, XXXXX,   DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  LEFT,  DOWN, RIGHT, XXXXX,                  XXXXX,  LEFT,  DOWN, RIGHT, XXXXX, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  MUTE,  VOLD,  VOLU, XXXXX, XXXXX,                   MPRV,  MPLY,  MNXT,  BRID,  BRIU, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  LBRC,  LCBR,  LPRN,  MINS,                    EQL,  RPRN,  RCBR,  RBRC,  BSLS,  PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX,  UNDS,                   PLUS, XXXXX,SLMARW,FATARW,PIPEOP, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____,   SPC, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        RST,  LRST, XXXXX, XXXXX,COLEMK,QWERTY,                     F1,    F2,    F3,    F4,    F5,    F6,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                     F7,    F8,    F9,   F10,   F11,   F12,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX,DM1REC,DM1PLY,DM2REC,DM2PLY,DMSTOP,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// LEADER KEY STUFF
LEADER_EXTERNS();

void matrix_scan_user(void) {
  // OLED???
  iota_gfx_task();
  // LEADER
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_T) {
      SEND_STRING(SS_LGUI(SS_LSFT("t")));
    }
    SEQ_ONE_KEY(KC_P) {
      SEND_STRING(SS_LGUI(SS_LSFT("p")));
    }
    SEQ_ONE_KEY(KC_N) {
      SEND_STRING(SS_LGUI(SS_LSFT("n")));
    }
    SEQ_ONE_KEY(KC_D) {
      SEND_STRING(SS_LGUI("l")SS_LGUI(SS_LSFT(SS_TAP(X_ENTER))));
    }
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING(SS_LGUI(SS_LSFT("4")));
    }
    SEQ_TWO_KEYS(KC_S, KC_F) {
      SEND_STRING(SS_LGUI(SS_LSFT("3")));
    }
    SEQ_TWO_KEYS(KC_S, KC_S) {
      SEND_STRING(SS_LGUI(SS_LSFT("5")));
    }
  }
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

// CUSTOM KEYCODE STUFF

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case COLEMK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
    case FATARW:
      if (record->event.pressed) {
        SEND_STRING(" => ");
      }
      return false;
      break;
    case SLMARW:
      if (record->event.pressed) {
        SEND_STRING(" -> ");
      }
      return false;
      break;
    case PIPEOP:
      if (record->event.pressed) {
        SEND_STRING("|> ");
      }
      return false;
      break;
  }
  return true;
}

