/**
 * Questo file contiene l'implementazione delle funzioni per la generazione di
 * stringhe casuali
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Random.h>
#include <stdlib.h>

void genera_stringa_randomica(char *output, int numero_caratteri) {
  static const char alfabeto[] = "0123456789abcdef";
  for (int i = 0; i < numero_caratteri; i++) {
    // Inserisci un carattere casuale dall'alfabeto
    output[i] = alfabeto[rand() % 16];
  }

  // Inserisci terminatore della stringa
  output[numero_caratteri] = '\0';
}
