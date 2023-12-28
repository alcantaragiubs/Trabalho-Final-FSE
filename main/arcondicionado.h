#ifndef ARCONDICIONADO_H
#define ARCONDICIONADO_H

#include <stdio.h>
#include "driver/gpio.h"
#include "dht11.h"
#include "variaveisglobais.h"


// Função para usar o sensor DHT11
int useDHT11();

// Função principal do ar condicionado
void ar_condicionado();

#endif
