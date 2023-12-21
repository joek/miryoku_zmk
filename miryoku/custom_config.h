// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

#include <dt-bindings/zmk/backlight.h>



#define MIRYOKU_LAYER_MEDIA \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              &bl BL_TOG,        &bl BL_CYCLE,          U_NA,              U_NA,              U_NA,         \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              U_EP_TOG,          &kp C_PREV,        &kp C_VOL_DN,      &kp C_VOL_UP,      &kp C_NEXT,        \
U_NA,              &kp RALT,          &u_to_U_FUN,       &u_to_U_MEDIA,     U_NA,              &u_out_tog,        &u_bt_sel_0,       &u_bt_sel_1,       &u_bt_sel_2,       &u_bt_sel_3,       \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp C_STOP,        &kp C_PP,          &kp C_MUTE,        U_NP,              U_NP



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
