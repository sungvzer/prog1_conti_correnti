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

    printf("%sConti correnti v1.0%s\n", ANSI_VERDE, ANSI_RESET);
    printf("Selezionare l'operazione:\n");
    printf("%s1%s: Visualizzare utenti\n", ANSI_VERDE, ANSI_RESET);
    printf("%s2%s: Aggiungere utente\n", ANSI_VERDE, ANSI_RESET);
    printf("%s3%s: Ricercare utente per nome e cognome\n", ANSI_VERDE,
           ANSI_RESET);
    printf("%s4%s: Ricercare utente per codice\n", ANSI_VERDE, ANSI_RESET);
    printf("%s5%s: Aggiungere movimento a utente per codice\n", ANSI_VERDE,
           ANSI_RESET);
    printf("%s6%s: Aggiungere movimento a utente per nome e cognome\n",
           ANSI_VERDE, ANSI_RESET);
    printf("%s7%s: Lista movimenti per data per codice\n", ANSI_VERDE,
           ANSI_RESET);
    printf("%s8%s: Lista movimenti per data per nome e cognome\n", ANSI_VERDE,
           ANSI_RESET);
    printf("%s0%s: Uscire\n", ANSI_VERDE, ANSI_RESET);
    printf("> ");

    input_stringa(input_utente, DimensioneStringa);
    sscanf(input_utente, "%d", selezione);
  } while (*selezione < 0 || *selezione > 8);
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
