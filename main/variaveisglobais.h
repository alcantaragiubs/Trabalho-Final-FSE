#ifndef VARIAVEISGLOBAIS_H
#define VARIAVEISGLOBAIS_H

#include <stdbool.h>
#include <freertos/FreeRTOS.h>
#include "freertos/semphr.h"
#include "driver/gpio.h"


extern gpio_num_t BOTAO;
extern gpio_num_t PINO_SENSOR_CHAMAS;
extern gpio_num_t PINO_SENSOR_BUZZER;
extern gpio_num_t PINO_SENSOR_TEMPERATURA;
extern gpio_num_t PINO_SENSOR_TOQUE;
extern int temperatura_ambiente;
extern int temperatura_controleAr;
extern bool statusBuzzer;
extern SemaphoreHandle_t conexaoWifiSemaphore;
extern SemaphoreHandle_t conexaoMQTTSemaphore;


#endif  