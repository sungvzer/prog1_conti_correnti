/**
 * Questo file contiene le definizioni necessarie per descrivere funzionalità
 * extra del programma
 * Salvatore Gargano  <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once

#include <Data.h>
#include <Movimento.h>
#include <Utente.h>

/**
 * Restituisce la lista movimenti di un dato correntista (dati nome e cognome)
 * in una fissata data
 * @param utenti la lista di utenti
 * @param numero_utenti la dimensione della lista di utenti
 * @param nome il nome del correntista
 * @param cognome il cognome del correntista
 * @param data la data per la quale filtrare i movimenti
 * @param movimenti il vettore di output dei movimenti trovati
 * @param dimensione_movimenti la dimensione del vettore di output
 * @returns il numero di movimenti trovati ed inseriti nel vettore di output, -1
 * se l'utente non è stato trovato
 */
int lista_movimenti_per_data_nome_cognome(Utente* utenti[], int numero_utenti,
                                          char* nome, char* cognome, Data data,
                                          Movimento movimenti[],
                                          int dimensione_movimenti);

/**
 * Restituisce la lista movimenti di un dato correntista (dato il codice conto)
 * in una fissata data
 * @param utenti la lista di utenti
 * @param numero_utenti la dimensione della lista di utenti
 * @param codice il codice univoco del conto
 * @param data la data per la quale filtrare i movimenti
 * @param movimenti il vettore di output dei movimenti trovati
 * @param dimensione_movimenti la dimensione del vettore di output
 * @returns il numero di movimenti trovati ed inseriti nel vettore di output, -1
 * se l'utente non è stato trovato
 */
int lista_movimenti_per_data_codice(Utente* utenti[], int numero_utenti,
                                    char* codice, Data data,
                                    Movimento movimenti[],
                                    int dimensione_movimenti);
