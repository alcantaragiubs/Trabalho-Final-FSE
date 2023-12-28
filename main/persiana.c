// #include <stdio.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <driver/gpio.h>
// #include <driver/touch_pad.h>
// #include "variaveisglobais.h"

// void rgb_led_init() {
//     gpio_config_t io_conf = {
//         .pin_bit_mask = (1ULL << RED_P) | (1ULL << GREEN_P) | (1ULL << BLUE_P),
//         .mode = GPIO_MODE_OUTPUT,
//     };
//     gpio_config(&io_conf);
// }

// void set_rgb_color(uint8_t red, uint8_t green, uint8_t blue) {
//     gpio_set_level(RED_P, red);
//     gpio_set_level(GREEN_P, green);
//     gpio_set_level(BLUE_P, blue);
// }

// void touch_sensor_init() {
//     touch_pad_init();
//     touch_pad_config(TOUCH_PAD_PIN_PERSIANA, 0);

//     // Calibração básica do sensor de toque
//     touch_pad_set_thresh(TOUCH_PAD_PIN_PERSIANA, TOUCH_THRESHOLD);
// }

// void simula_subida() {
//     static uint8_t intensity = 0;  // Inicializa a intensidade
//     printf("Simulando subida da persiana! \n");

//     // Aumenta a intensidade gradualmente
//     for (int i = 0; i <= MAX_INTENSITY; i ++) {
//         intensity = i;
//         set_rgb_color(intensity, 0, 0);
//         printf("Porcentagem subida: %.2f%%\n", (float)i / MAX_INTENSITY * 100.0);
//         vTaskDelay(150 / portTICK_PERIOD_MS);  // Pequeno atraso para controlar a taxa de aumento
//     }

//     // Define a luz como totalmente intensificada
//     set_rgb_color(0, 0, 0);
// }

// void simula_descida() {
//     static uint8_t intensity = MAX_INTENSITY;  // Inicializa a intensidade no máximo
//     printf("Simulando descida da persiana! \n");

//     // Aumenta a intensidade gradualmente
//     for (int i = MAX_INTENSITY; i >= 0; i--) {
//         intensity = i;
//         set_rgb_color(0, intensity, 0);
//         printf("Porcentagem descida: %.2f%%\n", (float)i / MAX_INTENSITY * 100.0);
//         vTaskDelay(150 / portTICK_PERIOD_MS);  // Pequeno atraso para controlar a taxa de aumento
//     }

//     // Define a luz como totalmente intensificada
//     set_rgb_color(0, 0, 0);
// }

// void persiana() {
//     // Inicialização do LED RGB
//     rgb_led_init();
//     touch_sensor_init();

//     while (1) {
//         // Verifica se o sensor de toque foi tocado
//         uint16_t touch_value;
//         esp_err_t res = touch_pad_read(TOUCH_PAD_PIN_PERSIANA, &touch_value);

//         if (res == ESP_OK) {
//             if (touch_value < TOUCH_THRESHOLD) {
//                 // Se o sensor de toque foi tocado, alterna entre subida e descida
//                 static int direction = 1;  // 1 para subida, -1 para descida
//                 direction = -direction;

//                 if (direction > 0) {
//                     simula_subida();
//                 } else {
//                     simula_descida();
//                 }
//             }
//         } else {
//             // Lida com o erro (caso necessário)
//             printf("Erro ao ler o sensor de toque: %s\n", esp_err_to_name(res));
//         }

//         vTaskDelay(portTICK_PERIOD_MS / portTICK_PERIOD_MS);  // Pequeno atraso para evitar leituras rápidas consecutivas
//     }
// }