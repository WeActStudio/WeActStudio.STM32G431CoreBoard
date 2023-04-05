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
#ifndef LED_Pin
#define LED_Pin GPIO_PIN_6
#endif
#ifndef LED_GPIO_Port
#define LED_GPIO_Port GPIOC
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
