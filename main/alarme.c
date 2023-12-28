#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "alarme.h"

#define SENSOR_PROXIMIDADE 14
#define LED_1 27
#define BOTAO_EMBUTIDO 0

bool alarmeLigado = false;

void setup()
{
    // Configuração do pino do Sensor de Proximidade
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << SENSOR_PROXIMIDADE),
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
    };
    gpio_config(&io_conf);

    // Configuração do pino do LED
    gpio_config_t led_conf = {
        .pin_bit_mask = (1ULL << LED_1),
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
    };
    gpio_config(&led_conf);

    // Configuração do pino do botão embutido
    gpio_config_t btn_conf = {
        .pin_bit_mask = (1ULL << BOTAO_EMBUTIDO),
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_ANYEDGE, // Detecta bordas de subida e descida
        .pull_down_en = GPIO_PULLDOWN_ENABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
    };
    gpio_config(&btn_conf);
}

void sensor_alarme_main()
{
    setup();

    while (1)
    {
        int estadoSensor = gpio_get_level(SENSOR_PROXIMIDADE);

        // Verifica se o botão embutido foi pressionado
        if (gpio_get_level(BOTAO_EMBUTIDO) == 0)
        {
            // Inverte o estado do alarme
            alarmeLigado = !alarmeLigado;

            // Aguarda um curto período para evitar detecções múltiplas
            vTaskDelay(pdMS_TO_TICKS(200));
        }

        if (estadoSensor == 0 && alarmeLigado)
        {
            printf("Intruso!\n");

            // Piscar o LED por 10 segundos (100 ms * 100 vezes)
            for (int i = 0; i < 100; i++)
            {
                gpio_set_level(LED_1, 1);
                vTaskDelay(pdMS_TO_TICKS(100));
                gpio_set_level(LED_1, 0);
                vTaskDelay(pdMS_TO_TICKS(100));
            }
        }

        // Se o sensor detectar algo e o alarme estiver ligado, acende o LED; caso contrário, apaga o LED
        gpio_set_level(LED_1, (estadoSensor == 0 && alarmeLigado));

        vTaskDelay(pdMS_TO_TICKS(100)); // Atraso de 100 milissegundos (ajuste conforme necessário)
    }
}