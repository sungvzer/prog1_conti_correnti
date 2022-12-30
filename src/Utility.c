/**
 * Questo file contiene l'implementazione di funzionalità extra del programma
 * Salvatore Gargano  <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Data.h>
#include <Utente.h>
#include <Utility.h>

int filtra_movimenti_data(Utente* utente, Data data, Movimento output[],
                          int dim_output) {
  int indice_output = 0;

  // Finché non ho raggiunto la dimensione dell'output o il numero di
  // movimenti dell'utente
  for (int i = 0; i < utente->numero_movimenti && indice_output < dim_output;
       i++) {
    Movimento mov = utente->movimenti[i];

    // Se la data del movimento e la data richiesta sono uguali, aggiungo il
    // movimento all'output
    int comparazione = compara_date(&mov.data, &data);
    if (comparazione == 0) {
      output[indice_output] = mov;
      indice_output++;
    }
  }
  return indice_output;
}

int lista_movimenti_per_data_codice(Utente* utenti[], int numero_utenti,
                                    char* codice, Data data,
                                    Movimento movimenti[],
                                    int dimensione_movimenti) {
  int indice = cerca_utente_codice(utenti, numero_utenti, codice);
  if (indice == -1) {
    return -1;
  }

  return filtra_movimenti_data(utenti[indice], data, movimenti,
                               dimensione_movimenti);
}

int lista_movimenti_per_data_nome_cognome(Utente* utenti[], int numero_utenti,
                                          char* nome, char* cognome, Data data,
                                          Movimento movimenti[],
                                          int dimensione_movimenti) {
  int indice = cerca_utente_nome_cognome(utenti, numero_utenti, nome, cognome);
  if (indice == -1) {
    return -1;
  }
  return filtra_movimenti_data(utenti[indice], data, movimenti,
                               dimensione_movimenti);
}
