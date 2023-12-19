// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#include <dt-bindings/pwm/pwm.h>
CONFIG_ZMK_BACKLIGHT=y

CONFIG_PWM=y
CONFIG_LED_PWM=y

config LED_GPIO
    default y




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
