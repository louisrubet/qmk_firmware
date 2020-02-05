#include QMK_KEYBOARD_H

#include "keymap_french.h"

enum ctrl_keycodes {
    U_T_AGCR = SAFE_RANGE, //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

// My layers
enum {
    MAIN,   // English (US) layout, same as default keymap layer 0
    CTRL,   // Standard CTRL layer for LED, same as default keymap layer 1
    ACC,    // French accentuated chars mapping, euro and mouse
    SCC,    // French accentuated chars mapping (uppercase)
} layers;

// French accentuated chars
enum {
    /* à */ A_G     = UC(0xE0),   /* â */ A_C     = UC(0xE2),   /* æ */ AE      = UC(0xE6), 
    /* À */ A_G_M   = UC(0xC0),   /* Â */ A_C_M   = UC(0xC2),   /* Æ */ AE_M    = UC(0xC6), 
    /* é */ E_A     = UC(0xE9),   /* è */ E_G     = UC(0xE8),   /* ê */ E_C     = UC(0xEA), 
    /* ë */ E_T     = UC(0xEB),   /* É */ E_A_M   = UC(0xC9),   /* È */ E_G_M   = UC(0xC8), 
    /* Ê */ E_C_M   = UC(0xCA),   /* Ë */ E_T_M   = UC(0xCB),   /* ï */ I_T     = UC(0xEF), 
    /* î */ I_C     = UC(0xEE),   /* Ï */ I_T_M   = UC(0xCF),   /* Î */ I_C_M   = UC(0xCE), 
    /* ç */ C_C     = UC(0xE7),   /* Ç */ C_C_M   = UC(0xC7),   /* ô */ O_C     = UC(0xF4), 
    /* œ */ OE      = UC(0x153),  /* Ô */ O_C_M   = UC(0xD4),   /* Œ */ OE_M    = UC(0x152),
    /* ù */ U_G     = UC(0xF9),   /* û */ U_C     = UC(0xFB),   /* ü */ U_T     = UC(0xFC), 
    /* Ù */ U_G_M   = UC(0xD9),   /* Û */ U_C_M   = UC(0xDB),   /* Ü */ U_T_M   = UC(0xDC), 
    /* Ÿ */ Y_T_M   = UC(0x178),  /* ÿ */ Y_T     = UC(0xFF),   /* € */ EURO    = UC(0x20AC)
} unicode_accents;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAIN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             MO(ACC), MO(CTRL),KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [CTRL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    /* layer ACC (ACCent)is accessed by holding right Alt in main layer */
    [ACC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, EURO   , _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, E_A    , E_G    , E_C    , E_T    , U_C    , U_T    , U_G    , Y_T    , _______, _______, _______,   KC_BTN1, KC_BTN2, KC_BTN3, \
        _______, A_G    , A_C    , AE     , _______, _______, _______, I_T    , I_C    , _______, _______, _______, _______, \
        MO(SCC), _______, _______, C_C    , _______, _______, O_C    , OE     , _______, _______, _______, MO(SCC),                              KC_MS_U, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            KC_MS_L, KC_MS_D, KC_MS_R \
    ),
    /* layer SCC (SHIFT ACCent) is accessed by holding right Alt + shift in main layer */
    [SCC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, E_A_M  , E_G_M  , E_C_M  , E_T_M  , U_C_M  , U_T_M  , U_G_M  , Y_T_M  , _______, _______, _______,   _______, _______, _______, \
        _______, A_G_M  , A_C_M  , AE_M   , _______, _______, _______, I_T_M  , I_C_M  , _______, _______, _______, _______, \
        _______, _______, _______, C_C_M  , _______, _______, O_C_M  , OE_M   , _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
};

// Set an RGB mode (horrible hack)
static void rgb_matrix_set(int mode) {
  extern rgb_config_t rgb_matrix_config;
  extern void eeconfig_update_rgb_matrix(void);

  rgb_matrix_config.mode = mode;  
  eeconfig_update_rgb_matrix();
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // Linux Unicode input mode
    set_unicode_input_mode(UC_LNX);

    // Set a nice RGB mode at startup
    rgb_matrix_set(RGB_MATRIX_JELLYBEAN_RAINDROPS);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
