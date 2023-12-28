#include "config.h"
#include "driver/gpio.h"
#include "variaveisglobais.h"

void configura_pinos() {
    // Configurar o pino GPIO para o sensor de chamas como entrada
    gpio_config_t io_config_chamas = {
        .pin_bit_mask = (1ULL << PINO_SENSOR_CHAMAS),
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_config_chamas);

    // Configurar o pino GPIO para o buzzer como saída
    gpio_config_t io_config_buzzer = {
        .pin_bit_mask = (1ULL << PINO_SENSOR_BUZZER),
        .mode = GPIO_MODE_OUTPUT, 
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_config_buzzer);

    // Configurar o pino GPIO para o sensor de temperatura como entrada
    gpio_config_t io_config_temperatura = {
        .pin_bit_mask = (1ULL << PINO_SENSOR_TEMPERATURA),
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_config_temperatura);

    // Configurar o pino GPIO para o sensor de toque como entrada
    gpio_config_t io_config_toque = {
        .pin_bit_mask = (1ULL << PINO_SENSOR_TOQUE),
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_config_toque);

    // void rgb_led_init() {
    // gpio_config_t io_config_persiana = {
    //     .pin_bit_mask = (1ULL << RED_P) | (1ULL << PIN_GREEN) | (1ULL << PIN_BLUE),
    //     .mode = GPIO_MODE_OUTPUT,
    // };
    // gpio_config(&io_config_persiana);
    // }
}
	