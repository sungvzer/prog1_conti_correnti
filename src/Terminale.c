/**
 * Questo file contiene l'implementazione delle funzionalità di I/O da terminale
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */
#include <Data.h>
#include <Definizioni.h>
#include <Terminale.h>
#include <stdio.h>
#include <string.h>

void prompt(int* selezione) {
  char input_utente[DimensioneStringa];
  do {
    // Separatore
    printf("-------------------------\n");

    printf("Conti correnti v1.0\n");
    printf("Selezionare l'operazione:\n");
    printf("1: Visualizzare utenti\n");
    printf("2: Aggiungere utente\n");
    printf("3: Ricercare utente per nome e cognome\n");
    printf("4: Ricercare utente per codice\n");
    printf("5: Aggiungere movimento a utente per codice\n");
    printf("0: Uscire\n");
    printf("> ");

    fgets(input_utente, DimensioneStringa, stdin);
    sscanf(input_utente, "%d", selezione);
  } while (*selezione < 0 || *selezione > 5);
}

void input_stringa(char* stringa, int lunghezza) {
  // Dal `man 3 fgets`: "fgets() reads in at most one less than size", quindi
  // non si rischia un overflow involontario fino a che la lunghezza è corretta
  fgets(stringa, lunghezza, stdin);

  // Sostituisce '\0' ad '\n' nella stringa
  stringa[strlen(stringa) - 1] = '\0';
}

void input_data(Data* data) {
  char buffer[DimensioneStringa];
  unsigned int anno, mese, giorno;

  do {
    printf("Giorno: ");
    input_stringa(buffer, DimensioneStringa);
    sscanf(buffer, "%u", &giorno);

    printf("Mese: ");
    input_stringa(buffer, DimensioneStringa);
    sscanf(buffer, "%u", &mese);

    printf("Anno: ");
    input_stringa(buffer, DimensioneStringa);
    sscanf(buffer, "%u", &anno);

    *data = crea_data(giorno, mese, anno);
  } while (!data->valida);
}
