#include "chamas.h"
#include "gpio_config.h"
#include <freertos/FreeRTOS.h>
#include "freertos/task.h"  
#include "variaveisglobais.h"


void sensor_chamas() {
    while (1) {
        // Ler o estado do pino GPIO para o sensor de chamas
        int estado_chamas = gpio_get_level(PINO_SENSOR_CHAMAS);

        // Imprimir o estado na porta serial
        printf("Estado do Sensor de Chamas: %d\n", estado_chamas);

        if (estado_chamas == 1) {
            printf("Chamas detectadas!\n");
            printf("\n");
            statusBuzzer = true; 
            gpio_set_level(PINO_SENSOR_BUZZER, 1); // depois trocar pra 1
        } else {
            printf("Não há chamas!\n");
            printf("\n");
            statusBuzzer = false;
            gpio_set_level(PINO_SENSOR_BUZZER, 0);
        }

        // Aguardar por 1 segundo antes de ler novamente
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}