// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#include <dt-bindings/pwm/pwm.h>
#include <dt-bindings/zmk/backlight.h>

#define CONFIG_ZMK_BACKLIGHT y
#define CONFIG_PWM y
#define CONFIG_LED_PWM y

#define config LED_GPIO default y


#define MIRYOKU_LAYER_MEDIA \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              &bl BL_TOG,        &bl BL_CYCLE,          U_NA,              U_NA,              U_NA,         \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              U_EP_TOG,          &kp C_PREV,        &kp C_VOL_DN,      &kp C_VOL_UP,      &kp C_NEXT,        \
U_NA,              &kp RALT,          &u_to_U_FUN,       &u_to_U_MEDIA,     U_NA,              &u_out_tog,        &u_bt_sel_0,       &u_bt_sel_1,       &u_bt_sel_2,       &u_bt_sel_3,       \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp C_STOP,        &kp C_PP,          &kp C_MUTE,        U_NP,              U_NP


/ {
	chosen {
        zmk,backlight = &pwm_leds;
    };
	
    pwm_leds: pwm_leds {
        compatible = "pwm-leds";
        pwm_led_0 {
			status = "okay";
            pwms = <&pwm0 0 PWM_MSEC(1) PWM_POLARITY_NORMAL>;
			label = "PWM_LED";
        };
    };
};


&pinctrl {
    // Other pinctrl definitions for other hardware
    pwm0_default: pwm0_default {
        group1 {
            psels = <NRF_PSEL(PWM_OUT0, 1, 12)>;
        };
    };
    pwm0_sleep: pwm0_sleep {
        group1 {
            psels = <NRF_PSEL(PWM_OUT0, 1, 12)>;
            low-power-enable;
        };
    };
};

&pwm0 {
    status = "okay";
    pinctrl-0 = <&pwm0_default>;
    pinctrl-1 = <&pwm0_sleep>;
    pinctrl-names = "default", "sleep";
};



&spi2_default {
	group1 {
		psels = <NRF_PSEL(SPIM_SCK, 1, 13)>,
			<NRF_PSEL(SPIM_MOSI, 1, 15)>;
	};
};

&spi2_sleep {
	group1 {
		psels = <NRF_PSEL(SPIM_SCK, 1, 13)>,
			<NRF_PSEL(SPIM_MOSI, 1, 15)>;
	};
};
