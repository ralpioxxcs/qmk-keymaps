#pragma once

#include_next <mcuconf.h>

// used for audio
#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE
