/**
 * Questo file contiene le definizioni necessarie all'I/O da terminale
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */
#pragma once

#include <Data.h>

/**
 * I vari colori ANSI utilizzabili nel terminale
 */
#define ANSI_RESET "\x1b[0m"
#define ANSI_NERO "\x1b[30m"
#define ANSI_ROSSO "\x1b[31m"
#define ANSI_VERDE "\x1b[32m"
#define ANSI_GIALLO "\x1b[33m"
#define ANSI_BLU "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CIANO "\x1b[36m"

/**
 * Chiede all'utente di selezionare una voce dal menù
 * @param selezione il puntatore al buffer della selezione
 */
void prompt(int* selezione);

/**
 * Prende in input una stringa (compresa di spazi) dall'utente.
 *
 * Da usare preferibilmente come *unico* metodo di input al posto di scanf().
 *
 * Da `man 3 fgets`: It is not advisable to mix calls to input functions from
 * the stdio library with low-level calls to read(2) for the file descriptor
 * associated with the input stream; the results will be undefined and very
 * probably not what you want.
 * @param stringa la stringa presa in input, correttamente terminata
 * @param lunghezza la lunghezza totale della stringa
 */
void input_stringa(char* stringa, int lunghezza);

/**
 * Prende in input una data.
 *
 * @param data un puntatore alla data da leggere
 */
void input_data(Data* data);
