#include "arcondicionado.h"
#include "gpio_config.h"
#include <freertos/FreeRTOS.h>
#include "freertos/task.h"
#include "variaveisglobais.h"

int useDHT11() {
    DHT11_init(PINO_SENSOR_TEMPERATURA);

    struct dht11_reading reading = DHT11_read();

    if (reading.status == DHT11_OK) {
        return reading.temperature;
    } else if (reading.status == DHT11_CRC_ERROR) {
        printf("Erro de verificação CRC\n");
    } else if (reading.status == DHT11_TIMEOUT_ERROR) {
        printf("Erro de timeout\n");
    } else {
        printf("Erro desconhecido\n");
    }
    return 0;
}

void ar_condicionado() {
    // Temperatura declarada
    while (1) {
        int estado_toque = gpio_get_level(PINO_SENSOR_TOQUE);

        printf("Estado do Sensor de Toque: %d\n", estado_toque);

        // Se o botão de toque estiver pressionado, ajusta a temperatura
        // Substituir por toquebotao3 == 1
        if (estado_toque == 1) {
            printf("Ar condicionado ligado\n");
            temperatura_ambiente = temperatura_controleAr;
        } else {
            printf("Ar condicionado desligado\n");
            temperatura_ambiente = useDHT11(); // Substituir por temperatura_ambiente = temperatura do DHT11
        }

        printf("Temperatura: %d\n", temperatura_ambiente);
        printf("\n");

        // Aguardar por 1 segundo antes de ler novamente
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}