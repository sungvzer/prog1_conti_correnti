/**
 * Questo file contiene le definizioni necessarie per descrivere struttura e
 * funzionalità di un utente
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once
#include <Definizioni.h>
#include <Movimento.h>
#include <strings.h>

/**
 * Un utente possessore di un conto
 * @param nome il nome dell'utente
 * @param cognome il cognome dell'utente
 * @param codice identificativo univoco formato da caratteri esadecimali
 * @param movimenti la lista dei movimenti eseguiti
 * @param numero_movimenti il numero di movimenti eseguiti
 */
typedef struct {
  char nome[DimensioneStringa];
  char cognome[DimensioneStringa];

  // viene usata una stringa per descrivere il codice dell'utente
  char codice[DimensioneCodiceUnivoco];

  Movimento movimenti[MaxNumeroMovimenti];
  int numero_movimenti;

} Utente;

/**
 * Crea un nuovo utente, allocato sull'heap
 * @param nome il nome dell'utente
 * @param cognome il cognome dell'utente
 * @returns un puntatore alla memoria allocata
 */
Utente *crea_utente(char *nome, char *cognome);

/**
 * Libera la memoria allocata per gli utenti
 * @param utenti il vettore di utenti da eliminare
 * @param numero_utenti la dimensione del vettore
 */
void elimina_utenti(Utente *utenti[], int numero_utenti);

/**
 * Cerca un utente all'interno di un vettore per nome e cognome.
 *
 * NOTA: La ricerca è sensibile alla differenza tra lettere maiuscole e
 * minuscole
 *
 * @param utenti il vettore di utenti all'interno del quale effettuare la
 * ricerca
 * @param numero_utenti la dimensione del vettore
 * @param nome il nome dell'utente da cercare
 * @param cognome il cognome dell'utente da cercare
 * @returns -1 se l'utente non è stato trovato, altrimenti l'indice all'interno
 * del vettore
 */
int cerca_utente_nome_cognome(Utente *utenti[], int numero_utenti, char *nome,
                              char *cognome);

/**
 * Cerca un utente all'interno di un vettore per codice univoco.
 *
 * NOTA: La ricerca è sensibile alla differenza tra lettere maiuscole e
 * minuscole
 *
 * @param utenti il vettore di utenti all'interno del quale effettuare la
 * ricerca
 * @param numero_utenti la dimensione del vettore
 * @param codice il codice dell'utente da cercare
 * @returns -1 se l'utente non è stato trovato, altrimenti l'indice all'interno
 * del vettore
 */
int cerca_utente_codice(Utente *utenti[], int numero_utenti, char *codice);

/**
 * Aggiunge un movimento all'utente
 * @param utente l'utente al quale aggiungere un movimento
 * @param movimento il movimento da aggiungere
 * @returns il nuovo indice del movimento, o -1 se il limite di movimenti è
 * stato raggiunto
 */
int aggiungi_movimento(Utente *utente, Movimento movimento);

/**
 * Stampa a video i movimenti dell'utente
 * @param utente l'utente del quale visualizzare i movimenti
 */
void stampa_movimenti_utente(Utente *utente);
