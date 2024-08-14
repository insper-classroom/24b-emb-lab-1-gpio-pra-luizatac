/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN_W =28;
const int BTN_PIN = 11;

const int MOT_1 =16;
const int MOT_2 =17;
const int MOT_3 =15;
const int MOT_4 =14;

const int volta = 512;


int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);



    gpio_init(LED_PIN_W);
    gpio_set_dir(LED_PIN_W, GPIO_OUT);

    gpio_init(MOT_1);
    gpio_set_dir(MOT_1, GPIO_OUT);

    gpio_init(MOT_2);
    gpio_set_dir(MOT_2, GPIO_OUT);

    gpio_init(MOT_3);
    gpio_set_dir(MOT_3, GPIO_OUT);

    gpio_init(MOT_4);
    gpio_set_dir(MOT_4, GPIO_OUT);


    gpio_put(MOT_1, 0);
    gpio_put(MOT_2, 0);
    gpio_put(MOT_3, 0);
    gpio_put(MOT_4, 0);
    gpio_put(LED_PIN_W, 0);


    while (true) {
    //if confere se o botao ja foi apertado
    if (!gpio_get(BTN_PIN)) {
      //conferre se led esta apagado
      if (!gpio_get(LED_PIN_W)){
        gpio_put(LED_PIN_W, 1);

        for (int i = 0; i <= volta; i++){

          gpio_put(MOT_1, 1);
          sleep_ms(10);
          
          gpio_put(MOT_1, 0);
          gpio_put(MOT_2, 1);
          sleep_ms(10);
          
          gpio_put(MOT_2, 0);
          gpio_put(MOT_3, 1);
          sleep_ms(10);
          
          gpio_put(MOT_3, 0);
          gpio_put(MOT_4, 1);
          sleep_ms(10);

          gpio_put(MOT_4, 0);

          
        }
      }
      gpio_put(LED_PIN_W, 0);

      }
      

    }
}