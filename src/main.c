/**
 * @file main.c
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Blink Example
 * @version 0.1
 * @date 2022-10-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO GPIO_NUM_25

int led_level = 0;

void app_main(void)
{
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (true)
    {
        /* Toggle the LED state */
        gpio_set_level(BLINK_GPIO, led_level);
        led_level = !led_level;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}