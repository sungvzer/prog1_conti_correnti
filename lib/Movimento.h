/**
 * Questo file contiene le definizioni necessarie per descrivere struttura e
 * funzionalità di un movimento bancario
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once

#include <Data.h>
#include <Definizioni.h>

/**
 * Un movimento bancario
 * @param importo l'importo del movimento
 * @param beneficiario il beneficiario del movimento
 * @param causale la causale del movimento
 * @param data la data del movimento
 */
typedef struct {
  // Nel mondo reale, per questa categoria di applicazioni il tipo più adatto
  // sarebbe un tipo intero in quanto non permette gli errori di arrotondamento
  // tipici dei tipi a virgola mobile
  float importo;
  Data data;
  char beneficiario[DimensioneStringa];
  char causale[DimensioneStringa];
} Movimento;

/**
 * Stampa a video un singolo movimento
 * @param movimento il movimento da visualizzare
 */
void stampa_movimento(Movimento movimento);
