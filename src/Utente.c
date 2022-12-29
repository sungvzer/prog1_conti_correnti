/**
 * Questo file contiene l'implementazione delle funzionalità di un utente
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Definizioni.h>
#include <Random.h>
#include <Utente.h>
#include <stdlib.h>
#include <string.h>

Utente *crea_utente(char *nome, char *cognome) {
  Utente *nuovo_utente = malloc(sizeof(Utente));

  nuovo_utente->numero_movimenti = 0;

  genera_stringa_randomica(nuovo_utente->codice, DimensioneCodiceUnivoco - 1);

  strncpy(nuovo_utente->nome, nome, DimensioneStringa);
  strncpy(nuovo_utente->cognome, cognome, DimensioneStringa);

  return nuovo_utente;
}
int cerca_utente_nome_cognome(Utente *utenti[], int numero_utenti, char *nome,
                              char *cognome) {
  for (int i = 0; i < numero_utenti; i++) {
    Utente *utente = utenti[i];
    if (strncmp(utente->nome, nome, DimensioneStringa) != 0) {
      // Se i nomi differiscono, continua la ricerca
      continue;
    }
    if (strncmp(utente->cognome, cognome, DimensioneStringa) != 0) {
      // Se i cognomi differiscono, continua la ricerca
      continue;
    }

    // L'utente è stato trovato, ritorna l'indice corretto
    return i;
  }
  return -1;
}

int cerca_utente_codice(Utente *utenti[], int numero_utenti, char *codice) {
  for (int i = 0; i < numero_utenti; i++) {
    Utente *utente = utenti[i];
    if (strncmp(utente->codice, codice, DimensioneStringa) == 0) {
      // Se i codici sono uguali, ritorna l'indice corretto
      return i;
    }
  }
  return -1;
}

void elimina_utenti(Utente *utenti[], int numero_utenti) {
  for (int i = 0; i < numero_utenti; i++) {
    free(utenti[i]);
    utenti[i] = NULL;
  }
}
