#ifndef __BOARD_H
#define __BOARD_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"

#ifndef KEY_Pin
#define KEY_Pin GPIO_PIN_13
#endif
#ifndef KEY_GPIO_Port
#define KEY_GPIO_Port GPIOC
#endif

//#define STM32G431CxT6
//#define STM32G431CxB6

#if defined(STM32G431CxB6)
#define LED_Pin GPIO_PIN_6
#define LED_GPIO_Port GPIOC
#define LED_GPIO_Port_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#elif defined(STM32G431CxT6)
#define LED_Pin GPIO_PIN_8
#define LED_GPIO_Port GPIOA
#define LED_GPIO_Port_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#else
#error "STM32G431CxB6 or STM32G431CxT6 need defined"
#endif

    void board_button_init(void);
    uint8_t board_button_getstate(void);
    void board_led_init(void);
    void board_led_toggle(void);
    void board_led_set(uint8_t set);

#ifdef __cplusplus
}
#endif

#endif
