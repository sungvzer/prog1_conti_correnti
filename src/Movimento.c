/**
 * Questo file contiene l'implementazione delle funzionalità di un movimento
 * bancario
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */
#include <Movimento.h>
#include <Terminale.h>
#include <stdio.h>

void stampa_movimento(Movimento movimento) {
  const char* colore = ANSI_RESET;

  if (movimento.importo > 0)
    colore = ANSI_VERDE;
  else if (movimento.importo < 0)
    colore = ANSI_ROSSO;

  printf("Movimento {\n");
  printf("  causale: %s,\n", movimento.causale);
  printf("  destinatario: %s,\n", movimento.destinatario);
  printf("  importo: %s%.02f%s,\n", colore, movimento.importo, ANSI_RESET);
  printf("}\n");
}
