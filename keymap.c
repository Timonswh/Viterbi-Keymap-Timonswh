#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Esc |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  F5  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | F11  | Shift|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Print| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |  Up  |   \  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |Delete| Ctrl | Win  |Lower | Alt  |Space |Space |      | Bksp | Bksp |AltGr |Raise | Left | Down |Right |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_ESC , KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,
    KC_F5  , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,
    KC_F11 , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_PSCR, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_UP  , KC_BSLS,
    KC_DEL , KC_LCTL, KC_LGUI, LOWER  , KC_LALT, KC_SPC , KC_SPC ,     KC_BSPC, KC_BSPC, KC_ALGR, RAISE  , KC_LEFT, KC_DOWN, KC_RGHT
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |      |      |      |NumLck|      |      |   /  |   *  |   -  | Bksp |      |CpsLck|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   7  |   8  |   9  |   +  |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |      | Mute |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   1  |   2  |   3  |Enter |      | Vol+ |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      | Ctrl | Win  |      | Alt  |      |      |      |   0  |   0  |   .  |Enter | Next | Vol- | Play |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, KC_NLCK,     _______, KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC, _______, KC_CAPS,
    _______, _______, _______, _______, _______, _______, _______,     KC_P7  , KC_P8  , KC_P9  , KC_PPLS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, KC_MUTE, _______,
    _______, _______, _______, _______, _______, _______, _______,     KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______, KC_VOLU, _______,
    _______, KC_LCTL, KC_LGUI, _______, KC_LALT, _______, _______,     KC_P0  , KC_P0  , KC_PDOT, KC_PENT, KC_MNXT, KC_VOLD, KC_MPLY
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |  F1  |  F3  |  F3  |  F4  |      |      |Print |SclLck|Pause |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F5  |  F6  |  F7  |  F8  |      |      |Insert| Home | PgUp |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F9  | F10  | F11  | F12  |      |      |Delete| End  | PgDn |      |      | Mute |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      | Vol+ |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      | Ctrl | Win  |      | Alt  |      |      |      |      |      |      |      | Next | Vol- | Play |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,     KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______,
    _______, _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,     KC_INS , KC_HOME, KC_PGUP, _______, _______, _______, _______,
    _______, _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,     KC_DEL , KC_END , KC_PGDN, _______, _______, KC_MUTE, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_VOLU, _______,
    _______, KC_LCTL, KC_LGUI, _______, KC_LALT, _______, _______,     _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
  ),
  
  [_ADJUST] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )

};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void led_set_keymap(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }
}
