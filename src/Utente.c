/**
 * Questo file contiene l'implementazione delle funzionalità di un utente
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Definizioni.h>
#include <Movimento.h>
#include <Random.h>
#include <Terminale.h>
#include <Utente.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Utente *crea_utente(char *nome, char *cognome) {
  Utente *nuovo_utente = malloc(sizeof(Utente));

  nuovo_utente->numero_movimenti = 0;

  genera_stringa_randomica(nuovo_utente->codice, DimensioneCodiceUtente - 1);

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

void stampa_movimenti_utente(Utente *utente) {
  printf("Movimenti dell'utente %s %s:\n", utente->nome, utente->cognome);
  for (int i = 0; i < utente->numero_movimenti; i++) {
    stampa_movimento(utente->movimenti[i]);
  }
}

int aggiungi_movimento(Utente *utente, Movimento movimento) {
  if (utente->numero_movimenti == MaxNumeroMovimenti) {
    return -1;
  }

  // Aggiunge il movimento ed incrementa il numero di movimenti dell'utente
  int indice = utente->numero_movimenti;
  utente->movimenti[indice] = movimento;
  utente->numero_movimenti++;
  return indice;
}

float saldo_utente(Utente *utente) {
  float saldo = 0;
  for (int i = 0; i < utente->numero_movimenti; i++) {
    saldo += utente->movimenti[i].importo;
  }
  return saldo;
}

void stampa_utente(Utente *utente) {
  float saldo = saldo_utente(utente);
  printf("Utente n.%s (%s %s):\n", utente->codice, utente->cognome,
         utente->nome);

  char *colore = saldo < 0 ? ANSI_ROSSO : ANSI_VERDE;
  printf("Saldo: %s%.02f%s\n", colore, saldo, ANSI_RESET);

  if (utente->numero_movimenti > 0) {
    stampa_movimenti_utente(utente);
  }
}
