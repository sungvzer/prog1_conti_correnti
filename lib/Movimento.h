/**
 * Questo file contiene le definizioni necessarie per descrivere struttura e
 * funzionalità di un movimento bancario
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once

#include <Definizioni.h>

typedef struct {
  // Nel mondo reale, per questa categoria di applicazioni il tipo più adatto
  // sarebbe un tipo intero in quanto non permette gli errori di arrotondamento
  // tipici dei tipi a virgola mobile
  float importo;
  char destinatario[DimensioneCodiceUnivoco];
  char descrizione[DimensioneStringa];
} Movimento;
