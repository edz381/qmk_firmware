#include QMK_KEYBOARD_H

  // Friendly layer names
  enum alt_layers {
    DEF = 0,
    FUNC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [DEF] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,            KC_F5,   KC_F6,   KC_F7,   KC_F8,           KC_F9,  KC_F10,   KC_F11,  KC_F12,    KC_PSCR,
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,            KC_PGUP,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,            KC_PGDN,
    KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,                      KC_INS,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,      KC_RSFT,               KC_UP,    KC_DEL,
    KC_LCTL,  KC_LGUI, KC_LALT,                       KC_SPC,                        KC_RALT, MO(FUNC),                  KC_LEFT,  KC_DOWN,  KC_RGHT),
  
  [FUNC] = LAYOUT(
    _______,  KC_BRID, KC_BRIU, _______, _______,          _______, _______, KC_MPRV, KC_MPLY,          KC_MNXT,  KC_MUTE, KC_VOLD, KC_VOLU, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
    _______,  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, _______,           _______,
    _______,  _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______,                    KC_HOME,
    _______,  _______, _______, KC_CALC, _______, _______, AG_NORM, AG_SWAP, _______, _______, _______,           _______,        _______,   KC_END,
    _______,  _______, _______,                       _______,                        RGB_TOG, _______,                  _______, _______,  _______),  

};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
      rgb_matrix_set_color(57, 255, 0, 0);
    }
    return false;
}

// use indicators without RGB matrix effects
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

