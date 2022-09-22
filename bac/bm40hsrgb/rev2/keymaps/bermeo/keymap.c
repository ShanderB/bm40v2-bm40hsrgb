/* Copyright 2020 tominabox1
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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUMP
};

uint8_t mod_state;

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    CEDILHA,            // ç direct key
    AO,                 // ã direct key
    ASPAS,              // " direct key

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | F3  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Grave |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | GUI  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Left | Down | Ctrl  | GUI  |Lower |    Space    |Bksp | Raise |Shift|  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    LCTL_T(KC_F3),   KC_Q, KC_W,    KC_E,    KC_R,    KC_T,KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_GRAVE,
    LALT_T(KC_TAB),  KC_A, KC_S,    KC_D,    KC_F,    KC_G, KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_ENTER,
    LSFT_T(KC_LEFT), KC_Z, KC_X,    KC_C,    KC_V,    KC_B,  KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, RGUI_T(KC_RIGHT),
    KC_LEFT, KC_DOWN, KC_LCTL, KC_LGUI, MO(1), KC_SPC,    KC_BSPC,  MO(2),  KC_RSFT, KC_UP, KC_RIGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F5  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0 |  ESC  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Emoji | Left | Down | Up  | Right|Enter |  [  |   ]  |   \  |   '  |   :   | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Alt+L |brigDown|brigUp|    |      | Bkspc|  -  |  =   |  <   |   >  |   ?   | GUI  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Alt+L |pgDown|      |      |      |            |LALT(KC_BSPC)| TG(3) ||pgUp|Alt+R |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(

    LCTL_T(KC_F5), KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_ESCAPE,
    LCTL(LGUI(KC_SPC)), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENT,KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_COLON, KC_ENT,
    LALT(KC_LEFT), KC_F1, KC_F2,    KC_C,    KC_V,   KC_BSPC,KC_MINS, KC_EQL,   KC_LT,   KC_GT, KC_QUESTION, LALT(KC_RIGHT),
    LALT(KC_LEFT), KC_PAGE_DOWN,  _______, _______, _______, _______,LALT(KC_BSPC), TG(3),  _______, KC_PAGE_UP,LALT(KC_RIGHT)

),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F4  |  !   |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  AO  |      |      |      |      |  {  |   }  |   pipe  |   "  |   :  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt+L|      |      |  ç   |      |      |   _   |  + |    <    |   >  |  ?   | Alt+R|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt+L| END  |      |      | TG(3) |             | DEL |        |      | HOME | Alt+R|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    LCTL_T(KC_F4), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILDE,
    _______, AO,  _______,_______,_______,_______,  KC_LCBR, KC_RCBR, KC_PIPE,  ASPAS,  KC_COLON, KC_ENT,
    LALT(KC_LEFT), _______,_______, CEDILHA, _______,_______,  KC_UNDS, KC_PLUS,  KC_LT,    KC_GT, KC_QUESTION, LALT(KC_RIGHT),
    LALT(KC_LEFT), KC_END,  _______, _______, TG(3), _______, KC_DEL, _______, _______, KC_HOME, LALT(KC_RIGHT)

),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |  RGB | Debug|      |      |      |      |      |   7  |   8  |   9  |   *  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGBMOD |HUE+| SAT+ |BRGTH+|      |      |      |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |HUE-  | SAT- |BRGTH-|      |      |   ,  |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|      |      |      | TG(3)|    TG(3)    |      | TG(3)|    0 |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMP] = LAYOUT_ortho_4x12_1x2uC(

    RGB_TOG,  DEBUG, _______, _______, _______, _______, _______,  KC_P7,   KC_P8,  KC_P9,  KC_PAST, KC_PSLS,
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______,  KC_P4,   KC_P5,  KC_P6,  KC_PMNS,  KC_ENT,
    _______,   RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, KC_PDOT,  KC_P1,   KC_P2,  KC_P3,  KC_PPLS,   KC_NO,
    RESET, _______, _______, _______, TG(3),    TG(3),  _______,  TG(3),     KC_P0,   _______, _______


)

};

//Per key lights
void rgb_matrix_indicators_user(void) {
#ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            mod_state  = get_mods();
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                if (mod_state & MOD_MASK_SHIFT) {

                    rgb_matrix_set_color(23, 255, 255, 255);
                    rgb_matrix_set_color(i, 255, 150, 0);
                } else if (mod_state & MOD_MASK_GUI || mod_state & MOD_MASK_CTRL) {

                    rgb_matrix_set_color(15, 255, 0, 0);
                    switch (i) {

                        case 5:                                  // cmd + T white (new tab)
                        case 11:                                 // cmd + F white (find)
                        case 18:                                 // cmd + W white (close tab)
                        case 14:                                 // cmd + S white (save)
                        case 25:                                 // cmd + Z white (undo)
                        case 13:                                 // cmd + A white (select all)
                        case 34:                                 // cmd + / white (comment line)
                            rgb_matrix_set_color(i, 255, 255, 255); // white
                            break;
                        case 41:                                  // space bar off
                        case 0|12|24|36|37|38|11|23|35|44|45|46: // columns off
                        case 42:                                 // backspace off
                            rgb_matrix_set_color(i, 0, 0, 0);    //off
                            break;
                    }
                    if (mod_state & MOD_MASK_GUI) {
                        rgb_matrix_set_color(28, 255, 255, 255); // white V key
                        rgb_matrix_set_color(27, 255, 255, 255); // white C key
                        rgb_matrix_set_color(26, 255, 255, 255); // white X key
                    } else {
                    }
                } else if (mod_state & MOD_MASK_ALT) {

                } else {
                    rgb_matrix_set_color(39, 0, 0, 0);          // command key off
                }
            }

                rgb_matrix_set_color(36, 0, 0, 0); // down alfas off left
                rgb_matrix_set_color(37, 0, 0, 0); // down alfas off left
                rgb_matrix_set_color(38, 0, 0, 0); // down alfas off left
                rgb_matrix_set_color(45, 0, 0, 0); // down alfas off right
                rgb_matrix_set_color(46, 0, 0, 0); // down alfas off right

            rgb_matrix_set_color(40, 23, 181, 255);             // cyan layer
            rgb_matrix_set_color(43, 255, 33, 0);               // orange layer
            break;

        case _RAISE:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                switch (i) {
                    case 29:                                     // B key off
                    case 17:                                     // G key off
                    case 16:                                    // F key off
                    case 28:                                    // V key off
                    case 15:                                    // D key off
                    case 14:                                    // S key off
                    case 26:                                   // X key off
                    case 25:                                    // Z key off
                    case 12:                                    // tab key off
                    case 24:                                    // shift key off
                    case 0|12|24|36|37|38|11|23|35|46|45:   // alfas off
                        rgb_matrix_set_color(i, 0, 0, 0);       // off
                        break;
                    case 27:                                    // Ç key
                    case 13:                                    // Ã key
                    case 0:                                    // Launch (F4)
                    case 43:                                    // Active layer
                        rgb_matrix_set_color(i, 255, 255, 255); // white
                        break;
                    case 40:                                    // active layer
                        rgb_matrix_set_color(i, 0, 255, 0);     // green
                        break;
                    case 22:                                    // , shifted key
                    case 32 ... 34:                             // . / ; shifted keys
                        rgb_matrix_set_color(i, 255, 214, 0);   // yellow
                        break;
                    default:
                        rgb_matrix_set_color(i, 255, 33, 0);    // orange
                }
            }
            break;

        case _LOWER:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                switch (i) {
                    case 29:                                     // Delete key
                    case 11:                                    // ESC key
                        rgb_matrix_set_color(i, 255, 0, 0);     // red
                        break;
                    case 25 ... 28:                             //ZXCV keys off
                    case 24|36|37|38|23|35|46|45:   // alfas off
                        rgb_matrix_set_color(i, 0, 0, 0);       // off
                        break;
                    case 13 ... 16:                                    // Arrow keys white
                    case 40:                                    // Active layer
                    case 0:                                    // Print
                        rgb_matrix_set_color(i, 255, 255, 255); // white
                        break;
                    case 17:                                     // Enter key
                    case 43:                                    // Activate Numpad
                        rgb_matrix_set_color(i, 0, 255, 0);     // green
                        break;
                    case 22:                                    // , shifted key
                    case 12:                                    // opens emoji dialog (on macOS)
                    case 32 ... 34:                             // . / ; shifted keys
                        rgb_matrix_set_color(i, 255, 214, 0);   // yellow
                        break;
                    default:
                        rgb_matrix_set_color(i, 23, 181, 255);  // cyan
                }
            }

            break;

        case _NUMP:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                switch (i) {
                    case 25 ... 28:                             //ZXCV keys
                    case 22:                                    // Numpad -
                    case 11:                                    // Numpad /
                        rgb_matrix_set_color(i, 255, 0, 0);     // red
                        break;

                        case 1 ... 6:                            // qwerty keys off
                    case 17:                                      // G off
                    case 12:                                    // Tab off
                    case 24:                                    // LShift off
                    case 18:                                    // H off
                    case 35:                                    // RGUI off
                    case 0|12|24|36|37|38|11|23|35|46|45:   // alfas off
                        rgb_matrix_set_color(i, 0, 0, 0);       // off
                        break;
                    case 41:                                     // Space bar off
                    case 40:                                    // Return to default layer
                    case 15:                                    // RGB brigthness+
                    case 0:                                    // RGB toggle
                    case 7 ... 9:                             // uio Numpad numbers
                    case 19 ... 21:                             // jkl Numpad numbers
                    case 31 ... 33:                             // m,. Numpad numbers
                    case 23:                                    // Enter key
                        rgb_matrix_set_color(i, 255, 255, 255); // white
                        break;
                    case 14:                                    // RGB saturation+
                    case 13:                                    // RGB hue+
                    case 34:                                    // Numpad +
                        rgb_matrix_set_color(i, 0, 255, 0);     // green
                        break;
                    case 30:                                    // . numpad key
                        rgb_matrix_set_color(i, 255, 214, 0);   // yellow
                        break;
                }
                rgb_matrix_set_color(40, 23, 181, 255);         // Activate cyan layer
                rgb_matrix_set_color(43, 255, 33, 0);           // Activate orange layer
                rgb_matrix_set_color(10, 0, 33, 255);           // Numpad *
                rgb_matrix_set_color(39, 0, 255, 0);            // Green layer active
            }
    }
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // ç key
        case CEDILHA:
            if (record->event.pressed) {
                register_code(KC_QUOT);
                unregister_code(KC_QUOT);
                register_code(KC_C);
                unregister_code(KC_C);
            }
            break;
            return false;

        // ã key
        case AO:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_GRV);
                unregister_code(KC_LSFT);
                unregister_code(KC_GRV);
                register_code(KC_A);
                unregister_code(KC_A);
            }
            break;
            return false;

        // direct " key
        case ASPAS:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_QUOT);
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                unregister_code(KC_QUOT);
                unregister_code(KC_LSFT);
            }
            break;
            return false;
    }
    return true;
}


// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _NUMP);
// }

