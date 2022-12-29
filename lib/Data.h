/**
 * Questo file contiene le definizioni necessarie per descrivere struttura e
 * funzionalità di una data semplificata formata da giorno mese e anno
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#pragma once

/**
 * Una data semplificata formata da giorno mese e anno. È consigliato usare la
 * funzione `crea_data()` al posto di istanziare direttamente la struttura in
 * quanto all'interno della funzione vengono validati giorno e mese
 * @param giorno il giorno del mese
 * @param mese il mese
 * @param anno l'anno
 * @param valida se la data è una data valida
 */
typedef struct {
  unsigned int giorno;
  unsigned int mese;
  unsigned int anno;
  int valida;
} Data;

/**
 * Crea una nuova data e la controlla
 * @param giorno il giorno del mese (da 1 a 31)
 * @param mese il mese (da 1 a 12)
 * @param anno l'anno
 * @returns la nuova data, col campo `valida` impostato ad 1 se la data è
 * valida, altrimenti 0
 */
Data crea_data(unsigned int giorno, unsigned int mese, unsigned int anno);

/**
 * Controlla se la data è una data valida
 * @param data la data da controllare
 * @returns 1 se la data è valida, altrimenti 0
 */
int controlla_data(Data data);

/**
 * Compara due date
 * @param prima la prima data
 * @param seconda la seconda
 * @returns 0 se le date sono uguali, -1 se la prima data è antecedente alla
 * seconda, altrimenti 1
 */
int compara_date(Data *prima, Data *seconda);

/**
 * @param anno l'anno da controllare
 * @returns 1 se l'anno è bisestile, altrimenti 0
 */
int bisestile(int anno);
