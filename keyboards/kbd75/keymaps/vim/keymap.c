#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "vim.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
#define _______ KC_TRNS
#define X_____X KC_TRNS
#define KC_ATM LGUI(LSFT(KC_P))
#define KC_ATP LGUI(LCTL(KC_P))
#define TO_NORM TO(NORMAL_MODE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Normal Mode
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │PRSCR│PAUSE│ DEL │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     │     │     │     │     │     │     │     │     │BKSPC █████│HOME │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ TAB │     │VIM_W│VIM_E│     │     │VIM_Y│VIM_U│VIM_I│VIM_O│VIM_P│     │     │      █████│PG_UP│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ CAPS│VIM_A│VIM_S│VIM_D│     │     │VIM_H│VIM_J│VIM_K│VIM_L│     │     │▒▒▒▒▒│ENTER│█████│PG_DN│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSHFT│▒▒▒▒▒│     │VIM_X│VIM_C│VIM_V│VIM_B│     │     │     │     │     │▒▒▒▒▒│RSHFT│ UP  │ END │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTRL│L_GUI│L_GUI│█████│█████│ SPC │ SPC │ SPC │█████│█████│R_ALT│FUNC │RCTRL│LEFT │DOWN │RIGHT│
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* Normal mode
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |  TAB   |      | WORD |  END |      |      |      |           |      | YANK | UNDO |      | OPEN |  PUT |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |    ⎋   |      |      |  DEL |      |      |------|           |------|  ←   |  ↓   |  ↑   |  →   |      |    ⎋   |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * | SHIFT  |      |      |      |VISUAL| BACK |      |           |      |      |      |      |      |      | SHIFT  |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |SPACE |DELETE|------|       |------|ENTER |BACKSP|
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
//   [NORMAL_MODE] = LAYOUT_ergodox(
//     // Layer 2 Left Hand
//     X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
//     KC_TAB ,X_____X,VIM_W,  VIM_E  ,X_____X,X_____X,X_____X,
//     X_____X,VIM_A  ,VIM_S  ,VIM_D  ,X_____X,X_____X,
//     KC_LSFT,X_____X,VIM_X  ,VIM_C  ,VIM_V  ,VIM_B  ,X_____X,
//     KC_LCTL,KC_LALT,X_____X,X_____X,X_____X,

//                                             KC_HOME,KC_END ,
//                                             TO(SYMB),
//                                             GUI_T(KC_SPC),  KC_ESC ,_______,


//     // Layer 2 Right Hand
//                               X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
//                               X_____X,VIM_Y  ,VIM_U  ,VIM_I  ,VIM_O  ,VIM_P  ,X_____X,
//                                       VIM_H  ,VIM_J  ,VIM_K  ,VIM_L  ,X_____X,X_____X,
//                               X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,KC_LSFT,
//                                               X_____X,X_____X,X_____X,KC_RALT,KC_RCTL,

//     KC_PGUP,  KC_PGDN,
//     TO(SYMB),
//     KC_DEL , KC_ENT, GUI_T(KC_BSPC)
// ),
  [NORMAL_MODE] = LAYOUT(
    X_____X,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  MO(TMP_LAYER),    KC_DEL,
    X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  X_____X,  KC_BSPC,  KC_HOME,
    KC_TAB,   X_____X,  VIM_W,    VIM_E,    X_____X,  X_____X,  VIM_Y,    VIM_U,    VIM_I,    VIM_O,    VIM_P,    X_____X,  X_____X,  X_____X,            KC_PGUP,
    X_____X,  VIM_A,    VIM_S,    VIM_D,    X_____X,  X_____X,  VIM_H,    VIM_J,    VIM_K,    VIM_L,    X_____X,  X_____X,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  MO(TMP_LAYER),    X_____X,  VIM_X,    VIM_C,    VIM_V,    VIM_B,    X_____X,  X_____X,  X_____X,  X_____X,  KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   MO(TMP_LAYER),   KC_SPC,                       KC_RALT,  MO(TMP_LAYER),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
  /* Insert Mode
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │PRSCR│PAUSE│ DEL │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │BKSPC █████│HOME │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  \   █████│PG_UP│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ CAPS│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ENTER│█████│PG_DN│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│ UP  │ END │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTRL│L_GUI│L_GUI│█████│█████│ SPC │ SPC │ SPC │█████│█████│R_ALT│FUNC │RCTRL│LEFT │DOWN │RIGHT│
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  /* Insert mode
  *
  * ,--------------------------------------------------------------------------------------.
  * |  ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
  * |-------+------+------+------+------+------+------+------+------+------+------+--------|
  * |   `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -    |
  * |-------+------+------+------+------+-------------+------+------+------+------+--------|
  * |  TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [    |
  * |-------+------+------+------+------+------|------+------+------+------+------+--------|
  * | CAPS  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '    |
  * |-------+------+------+------+------+------|------+------+------+------+------+--------|
  * | SHIFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | SHIFT  |
  * `-------+------+------+------+------+-------------+------+------+------+------+--------'
  *   |  ⌃  |   ⌥  |  (   |  [   |   {  |                                       |  }   |  ]   |   )  |   ⌥   |   ⌃  |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        | HOME | END  |       | PGDN | PGUP |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |SPACE |      |      |       |      |      | BSPC |
  *                                 |      |NORMAL|------|       |------| ENTER|      |
  *                                 |   ⌘  |      |      |       |      |      |   ⌘  |
  *                                 `--------------------'       `--------------------'
  */

  /* Insert mode
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * | NORMAL |   1  |   2  |   3  |   4  |   5  | ⇧⌘P  |           | PROJ |   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |    ⇥   |   Q  |   W  |   E  |   R  |   T  |  `   |           |   -  |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |    ⎋   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  * |--------+------+------+------+------+------|   =  |           |   +  |------+------+------+------+------+--------|
  * |   L⇧   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   R⇧   |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |  ⌃  |   ⌥  |  (   |  [   |   {  |                                       |  }   |  ]   |   )  |   ⌥   |   ⌃  |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        | HOME | END  |       | PGDN | PGUP |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |SPACE |      |      |       |      |      | BSPC |
  *                                 |      |NORMAL|------|       |------| ENTER|      |
  *                                 |   ⌘  |      |      |       |      |      |   ⌘  |
  *                                 `--------------------'       `--------------------'
  */
  // [0] = LAYOUT(
  //   KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  MO(1),    KC_DEL,
  //   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
  //   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
  //   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
  //   KC_LSFT,  MO(1),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
  //   KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  // ),
  [TMP_LAYER] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  KC_BTN1,  KC_BTN3,  KC_BTN2,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,                      _______,  _______,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),
  [INSERT_MODE] = LAYOUT(
    NOR_MOD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  MO(TMP_LAYER),    KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  MO(1),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   MO(TMP_LAYER),   KC_SPC,                       KC_RALT,  MO(TMP_LAYER),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),


  // [INSERT_MODE] = LAYOUT_ergodox(
  //   // Left Hand
  //   NOR_MOD,KC_1,   KC_2,   KC_3,    KC_4,   KC_5, KC_ATM,
  //   KC_TAB ,KC_Q,   KC_W,   KC_E,    KC_R,   KC_T, KC_GRV,
  //   KC_ESC ,KC_A,   KC_S,   KC_D,    KC_F,   KC_G,
  //   KC_LSFT,KC_Z,   KC_X,   KC_C,    KC_V,   KC_B, KC_EQL,
  //   KC_LCTL,KC_LALT,KC_LPRN,KC_LBRC, KC_LCBR,

  //                                           KC_HOME,KC_END ,
  //                                           TO(SYMB),
  //                                           GUI_T(KC_SPC),KC_ESC ,TO_NORM,


  //   // Right Hand
  //                             KC_ATP , KC_6, KC_7,   KC_8,    KC_9,   KC_0,   KC_MINS,
  //                             KC_MINS, KC_Y, KC_U,   KC_I,    KC_O,   KC_P,   KC_BSLS,
  //                                      KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN,KC_QUOT,
  //                             KC_PLUS, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,KC_RSFT,
  //                                            KC_RCBR,KC_RBRC, KC_RPRN,KC_RALT,KC_RCTL,

  //   KC_PGUP,  KC_PGDN,
  //   TO(SYMB),
  //   MO(MOUSE) , KC_ENT, GUI_T(KC_BSPC)
  // ),

  /* [SYMB] = LAYOUT_ergodox( */
    /* // Left Hand */
    /* NOR_MOD,KC_1,   KC_2,   KC_3,    KC_4,   KC_5, KC_ATM, */
    /* KC_TAB ,KC_Q,   KC_W,   KC_E,    KC_R,   KC_T, KC_GRV, */
    /* _______,KC_A,   KC_S,   KC_D,    KC_F,   KC_G, */
    /* KC_LSFT,KC_Z,   KC_X,   KC_C,    KC_V,   KC_B, KC_EQL, */
    /* KC_LCTL,KC_LALT,KC_LPRN,KC_LBRC, KC_LCBR, */

                                                                /* _______,_______, */
                                                                        /* _______, */
                                                        /* _______,_______,TO_NORM, */

    /* // Right Hand */
                              /* KC_ATP , KC_6, KC_7,   KC_8,    KC_9,   KC_0,   KC_MINS, */
                              /* KC_MINS, KC_Y, KC_U,   KC_I,    KC_O,   KC_P,   KC_BSLS, */
                                       /* KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN,KC_QUOT, */
                              /* KC_PLUS, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,KC_RSFT, */
                                             /* KC_RCBR,KC_RBRC, KC_RPRN,KC_RALT,KC_RCTL, */

    /* _______,_______, */
    /* _______, */
    /* _______,_______,_______ */
  /* ), */

//   [MOUSE] = LAYOUT_ergodox(
//     // Left Hand
//     _______,_______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,

//                                                                 _______,_______,
//                                                                         _______,
//                                                         _______,_______,_______,

//     // Right Hand
//                               _______,_______,_______,_______,_______,_______,_______,
//                               _______,_______,KC_BTN1,KC_BTN3,KC_BTN2,_______,_______,
//                                       KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______,
//                               _______,_______,_______,_______,_______,_______,_______,
//                                               _______,_______,_______,_______,_______,

//     _______,_______,
//     _______,
//     _______,_______,_______
//   ),
};

bool is_normal_mode(void);
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case 0:
        if (record->event.pressed) { SEND_STRING (VERSION_STRING); }
        break;
  }
return MACRO_NONE;
};

bool is_normal_mode() {
  return IS_LAYER_ON(NORMAL_MODE) && IS_LAYER_OFF(INSERT_MODE) && IS_LAYER_OFF(TMP_LAYER);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
                 (keyboard_report->mods & MOD_BIT(KC_RSFT));
  if (is_normal_mode()) {
    print("yes");
  }

  switch (keycode) {

    case VIM_A:
      if (record->event.pressed) { SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND(); }
      return false;

    case VIM_B:
      if (record->event.pressed) {
        switch(VIM_QUEUE.keycode) {
          case KC_NO: VIM_BACK(); break;
          case VIM_C: VIM_CHANGE_BACK(); break;
          case VIM_D: VIM_DELETE_BACK(); break;
          case VIM_V: VIM_VISUAL_BACK(); break;
        }
      }
      return false;

    case VIM_C:
      if (record->event.pressed) {
        switch(VIM_QUEUE.keycode) {
          case KC_NO: SHIFTED ? VIM_CHANGE_LINE() : VIM_LEADER(VIM_C); break;
          case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_D:
      if (record->event.pressed) {
        switch(VIM_QUEUE.keycode) {
          case KC_NO: SHIFTED ? VIM_DELETE_LINE() : VIM_LEADER(VIM_D); break;
          case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_E:
      if (record->event.pressed) {
        switch (VIM_QUEUE.keycode) {
          case KC_NO: VIM_END(); break;
          case VIM_C: VIM_CHANGE_END(); break;
          case VIM_D: VIM_DELETE_END(); break;
          case VIM_V: VIM_VISUAL_END(); break;
        }
      }
      return false;

    case VIM_H:
      if (record->event.pressed) {
        switch (VIM_QUEUE.keycode) {
          case KC_NO: VIM_LEFT(); break;
          case VIM_C: VIM_CHANGE_LEFT(); break;
          case VIM_D: VIM_DELETE_LEFT(); break;
          case VIM_V: VIM_VISUAL_LEFT(); break;
        }
      }
      return false;

    case VIM_I:
      if (record->event.pressed) {
        switch (VIM_QUEUE.keycode) {
          case KC_NO: layer_on(INSERT_MODE); break;
          case VIM_C: VIM_LEADER(VIM_CI); break;
          case VIM_D: VIM_LEADER(VIM_DI); break;
          case VIM_V: VIM_LEADER(VIM_VI); break;
        }
      }
      return false;

    case VIM_J:
      if (record->event.pressed) {
        switch (VIM_QUEUE.keycode) {
          case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break;
          case VIM_C: VIM_CHANGE_DOWN(); break;
          case VIM_D: VIM_DELETE_DOWN(); break;
          case VIM_V: VIM_VISUAL_DOWN(); break;
        }
      }
      return false;

    case VIM_K:
      if (record->event.pressed) {
        switch (VIM_QUEUE.keycode) {
          case KC_NO: VIM_UP(); break;
          case VIM_C: VIM_CHANGE_UP(); break;
          case VIM_D: VIM_DELETE_UP(); break;
          case VIM_V: VIM_VISUAL_UP(); break;
        }
      }
      return false;

    case VIM_L:
      if (record->event.pressed) {
        switch (VIM_QUEUE.keycode) {
          case KC_NO: VIM_RIGHT(); break;
          case VIM_C: VIM_CHANGE_RIGHT(); break;
          case VIM_D: VIM_DELETE_RIGHT(); break;
          case VIM_V: VIM_VISUAL_RIGHT(); break;
        }
      }
      return false;

    case VIM_O:
      if (record->event.pressed) { SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN(); }
      return false;

    case VIM_P:
      if (record->event.pressed) { SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT(); }
      return false;

    case VIM_S:
      if (record->event.pressed) { SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE(); }
      return false;

    case VIM_U:
      if (record->event.pressed) { VIM_UNDO(); }
      return false;

    case VIM_V:
      if (record->event.pressed) { VIM_LEADER(VIM_V); }
      return false;

    case VIM_W:
      if (record->event.pressed) {
        switch (VIM_QUEUE.keycode) {
          case KC_NO: VIM_WORD(); break;
          case VIM_C: VIM_CHANGE_WORD(); break;
          case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
          case VIM_D: VIM_DELETE_WORD(); break;
          case VIM_DI: VIM_DELETE_INNER_WORD(); break;
          case VIM_V: VIM_VISUAL_WORD(); break;
          case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
        }
      }
      return false;

    case VIM_X:
      if (record->event.pressed) { VIM_CUT(); }
      return false;

    case VIM_Y:
      if (record->event.pressed)  // { SHIFTED ? VIM_YANK_LINE() : VIM_YANK(); }
        switch(VIM_QUEUE.keycode) {
          case KC_NO: SHIFTED ? VIM_YANK_LINE() : VIM_YANK(); break;
          case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
        }
      return false;

  //   // dynamically generate these.
  //   case EPRM:
  //     if (record->event.pressed) { eeconfig_init(); }
  //     return false;
  //   case VRSN:
  //     if (record->event.pressed) { SEND_STRING(VERSION_STRING); }
  //     return false;
  //   case RGB_SLD:
  //     if (record->event.pressed) { rgblight_mode(1); }
  //     return false;
  }

  // End by clearing the queue unless keycode is a
  // if ((record->event.pressed) &&
  //     (keycode != VIM_I ||
  //     keycode != VIM_C ||
  //     keycode != VIM_D ||
  //     keycode != VIM_V)) {
  //   VIM_LEADER(KC_NO);
  // }

  return true;
};

void matrix_init_user(void) {
  debug_enable = true;
  VIM_LEADER(KC_NO);
};

// void matrix_scan_user(void) {
//     uint8_t layer = biton32(layer_state);

//     ergodox_board_led_off();
//     ergodox_right_led_1_off();
//     ergodox_right_led_2_off();
//     ergodox_right_led_3_off();
//     switch (layer) {
//         case 1:
//             ergodox_right_led_1_on();
//             break;
//         case 2:
//             ergodox_right_led_2_on();
//             break;
//         case 3:
//             ergodox_right_led_3_on();
//             break;
//         case 4:
//             ergodox_right_led_1_on();
//             ergodox_right_led_2_on();
//             break;
//         case 5:
//             ergodox_right_led_1_on();
//             ergodox_right_led_3_on();
//             break;
//         case 6:
//             ergodox_right_led_2_on();
//             ergodox_right_led_3_on();
//             break;
//         case 7:
//             ergodox_right_led_1_on();
//             ergodox_right_led_2_on();
//             ergodox_right_led_3_on();
//             break;
//         default:
//             break;
//     }

// };
