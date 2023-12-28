#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "nvs_flash.h"

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "esp_sleep.h"
#include "esp32/rom/uart.h"

#include <freertos/FreeRTOS.h>
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "dht11.h"
#include "gpio_config.h"
#include "arcondicionado.h"
#include "chamas.h"
#include "variaveisglobais.h"

#include "wifi.h"
#include "mqtt.h"
#include "lightsleep.h"

void app_main()
{
  int botaoImprovisado = 0;
  while (1)
  {
    xTaskCreate(sensor_chamas, "TaskSensorChamas", 2048, NULL, 1, NULL);
    if (botaoImprovisado == 0)
    {
      xTaskCreate(lightsleep_mode, "TaskLightSleep", 2048, NULL, 1, NULL);
    }
    else
    {
      // configure nvs
      esp_err_t ret = nvs_flash_init();
      if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
      {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
      }
      ESP_ERROR_CHECK(ret);

      conexaoWifiSemaphore = xSemaphoreCreateBinary();
      conexaoMQTTSemaphore = xSemaphoreCreateBinary();

      wifi_start();

      xTaskCreate(&conectadoWifi, "Conexão ao MQTT", 4096, NULL, 1, NULL);
      xTaskCreate(&trataComunicacaoComServidor, "Comunicação com Broker", 4096, NULL, 1, NULL);

      configura_pinos();

      xTaskCreate(ar_condicionado, "TaskArCondicionado", 2048, NULL, 1, NULL);
    }
    // Aguardar por 1 segundo antes de ler novamente
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}