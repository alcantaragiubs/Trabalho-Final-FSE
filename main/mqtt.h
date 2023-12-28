#ifndef MQTT_H
#define MQTT_H

#include "variaveisglobais.h"
void mqtt_start();

void mqtt_envia_mensagem(char * topico, char * mensagem);
void trataComunicacaoComServidor(void *params);

#endif