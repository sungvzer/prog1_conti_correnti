/**
 * Questo file contiene le definizioni necessarie per la generazione di stringhe
 * casuali
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */
#pragma once

/**
 * Genera una stringa randomica formata da caratteri esadecimali.
 *
 * Il numero dei caratteri dev'essere al più la dimensione del buffer - 1, in
 * quanto viene inserito un terminatore alla fine della stringa generata.
 * @param output la stringa finale
 * @param numero_caratteri la dimensione della stringa finale
 */
void genera_stringa_randomica(char *output, int numero_caratteri);
