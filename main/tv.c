// #include <stdio.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <driver/gpio.h>
// #include <driver/touch_pad.h>
// #include "variaveisglobais.c"



// int tv_ligada = 0; // 0 representa desligada, 1 representa ligada

// void rgb_led_init() {
//     gpio_config_t io_conf = {
//         .pin_bit_mask = (1ULL << PIN_RED) | (1ULL << PIN_GREEN) | (1ULL << PIN_BLUE),
//         .mode = GPIO_MODE_OUTPUT,
//     };
//     gpio_config(&io_conf);
// }

// void set_rgb_color(uint8_t red, uint8_t green, uint8_t blue) {
//     gpio_set_level(PIN_RED, red);
//     gpio_set_level(PIN_GREEN, green);
//     gpio_set_level(PIN_BLUE, blue);
// }

// void touch_sensor_init() {
//     touch_pad_init();
//     touch_pad_config(TOUCH_PAD_PIN_TV, 0);

//     // Calibração básica do sensor de toque
//     touch_pad_set_thresh(TOUCH_PAD_PIN_TV, TOUCH_THRESHOLD);
// }

// void simula_tv_ligada() {
//     printf("Simulando TV ligada\n");
// }

// void simula_tv_desligada() {
//     printf("Simulando TV desligada\n");
// }

// void tv() {
//     // Inicialização do LED RGB
//     rgb_led_init();
//     touch_sensor_init();

//     TickType_t last_touch_time = 0;

//     while (1) {
//         // Verifica se o sensor de toque foi tocado
//         uint16_t touch_value;
//         esp_err_t res = touch_pad_read(TOUCH_PAD_PIN_TV, &touch_value);

//         if (res == ESP_OK) {
//             if (touch_value < TOUCH_THRESHOLD) {
//                 if ((xTaskGetTickCount() - last_touch_time) > DEBOUNCE_DELAY) {
//                     tv_ligada = !tv_ligada;

//                     if (tv_ligada) {
//                         simula_tv_ligada();
//                         set_rgb_color(255, 0, 0);  // Verde
//                     } else {
//                         simula_tv_desligada();
//                         set_rgb_color(0, 255, 0);  // Vermelho
//                     }

//                     last_touch_time = xTaskGetTickCount();
//                 }
//             }
//         } else {
//             // Lida com o erro (caso necessário)
//             printf("Erro ao ler o sensor de toque: %s\n", esp_err_to_name(res));
//         }

//         vTaskDelay(portTICK_PERIOD_MS);  // Pequeno atraso para evitar leituras rápidas consecutivas
//     }
// }
