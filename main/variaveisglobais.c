#include "variaveisglobais.h"
#include <stdbool.h>
#include <freertos/FreeRTOS.h>
#include "freertos/semphr.h"
#include "driver/gpio.h"

// #define PIN_RED           23
// #define PIN_GREEN         22
// #define PIN_BLUE          21
// #define TOUCH_PAD_PIN_TV     TOUCH_PAD_NUM0
// #define TOUCH_THRESHOLD   100
// #define DEBOUNCE_DELAY    100  
// #define portTICK_PERIOD_MS 100
// #define MAX_INTENSITY 255
// #define RED_P    01
// #define GREEN_P  03
// #define BLUE_P   19
// #define TOUCH_PAD_PIN_PERSIANA TOUCH_PAD_NUM3

gpio_num_t BOTAO = GPIO_NUM_0; //botão de boot
gpio_num_t PINO_SENSOR_CHAMAS = GPIO_NUM_23;
gpio_num_t PINO_SENSOR_BUZZER = GPIO_NUM_5;
gpio_num_t PINO_SENSOR_TEMPERATURA = GPIO_NUM_19;
gpio_num_t PINO_SENSOR_TOQUE = GPIO_NUM_21;

int temperatura_ambiente = 25;
int temperatura_controleAr = 18;
bool statusBuzzer = false;

SemaphoreHandle_t conexaoWifiSemaphore;
SemaphoreHandle_t conexaoMQTTSemaphore;
