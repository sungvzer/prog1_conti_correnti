/**
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Definizioni.h>
#include <Movimento.h>
#include <Terminale.h>
#include <Utente.h>
#include <Utility.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Procedure statiche che evitano ripetizioni nel codice

static void output_movimenti_utente_in_data(Utente* utente) {
  Data data;
  printf("Data da ricercare\n");
  input_data(&data);

  // Viene usato MaxNumeroMovimenti perché è il massimo ottenibile
  Movimento movimenti[MaxNumeroMovimenti];

  int movimenti_filtrati =
      filtra_movimenti_data(utente, data, movimenti, MaxNumeroMovimenti);

  if (movimenti_filtrati == 0) {
    printf("Nessun movimento trovato.\n");
    return;
  }

  for (int i = 0; i < movimenti_filtrati; i++) {
    stampa_movimento(movimenti[i]);
  }
}

static void input_movimento_utente(Utente* utente) {
  char input_utente[DimensioneStringa];

  if (utente->numero_movimenti == MaxNumeroMovimenti) {
    printf("Il massimo numero di movimenti è stato raggiunto.\n");
    return;
  }

  // Input del nuovo movimento
  Data data;
  float importo;
  char beneficiario[DimensioneStringa], causale[DimensioneStringa];
  printf("Data di esecuzione\n");
  input_data(&data);

  // Verifica che la data sia valida - ciò dovrebbe avvenire in input_data
  assert(data.valida);

  printf("Importo: ");
  input_stringa(input_utente, DimensioneStringa);
  sscanf(input_utente, "%f", &importo);

  printf("Beneficiario: ");
  input_stringa(beneficiario, DimensioneStringa);

  printf("Causale: ");
  input_stringa(causale, DimensioneStringa);
  Movimento mov = crea_movimento(importo, beneficiario, causale, data);

  int indice_movimento = aggiungi_movimento(utente, mov);

  // Il controllo del numero di movimenti viene effettuato prima. Se siamo
  // arrivati qui DOBBIAMO aver inserito il movimento.
  assert(indice_movimento >= 0);
}

int main(int argc, char* argv[]) {
  // imposta il seed per il generatore di numeri casuali
  srand(time(0));

  Utente* utenti[NumeroUtenti];
  int utenti_attuali = 0;

  char input_utente[DimensioneStringa];

  // Usata per la navigazione dei menù
  int selezione;

  do {
    prompt(&selezione);

    switch (selezione) {
      case 1: {
        // Visualizzare utenti
        if (utenti_attuali == 0) {
          printf("Non ci sono utenti al momento\n");
          break;
        }
        for (int i = 0; i < utenti_attuali; i++) {
          stampa_utente(utenti[i]);
        }
        break;
      }
      case 2: {
        // Aggiungere utente
        if (utenti_attuali == NumeroUtenti) {
          printf("Raggiunta capacità massima di utenti.\n");
          break;
        }
        char nome[DimensioneStringa];
        char cognome[DimensioneStringa];

        printf("Nome: ");
        input_stringa(nome, DimensioneStringa);

        printf("Cognome: ");
        input_stringa(cognome, DimensioneStringa);

        Utente* nuovo_utente = crea_utente(nome, cognome);

        // Assicuriamoci di aver allocato correttamente l'utente
        assert(nuovo_utente != NULL);

        utenti[utenti_attuali++] = nuovo_utente;
        printf("Aggiunto utente con codice %s\n", nuovo_utente->codice);
        break;
      }

      case 3: {
        // Ricercare utente per nome e cognome
        if (utenti_attuali == 0) {
          printf("Non ci sono utenti al momento\n");
          break;
        }
        char nome[DimensioneStringa];
        char cognome[DimensioneStringa];

        printf("Nome: ");
        input_stringa(nome, DimensioneStringa);

        printf("Cognome: ");
        input_stringa(cognome, DimensioneStringa);

        int indice =
            cerca_utente_nome_cognome(utenti, utenti_attuali, nome, cognome);
        if (indice == -1) {
          printf("Nessun utente %s %s trovato.\n", cognome, nome);
        } else {
          stampa_utente(utenti[indice]);
        }
        break;
      }
      case 4: {
        // Ricercare utente per codice
        if (utenti_attuali == 0) {
          printf("Non ci sono utenti al momento\n");
          break;
        }
        char codice[DimensioneStringa];
        printf("Codice: ");
        input_stringa(codice, DimensioneStringa);

        int indice = cerca_utente_codice(utenti, utenti_attuali, codice);
        if (indice == -1) {
          printf("Nessun utente con codice %s trovato.\n", codice);
        } else {
          stampa_utente(utenti[indice]);
        }

        break;
      }
      case 5: {
        // Aggiungere movimento a utente per codice
        if (utenti_attuali == 0) {
          printf("Non ci sono utenti al momento\n");
          break;
        }

        char codice[DimensioneStringa];
        printf("Codice: ");
        input_stringa(codice, DimensioneStringa);

        int indice = cerca_utente_codice(utenti, utenti_attuali, codice);
        if (indice == -1) {
          printf("Nessun utente con codice %s trovato.\n", codice);
          break;
        }

        Utente* utente = utenti[indice];
        input_movimento_utente(utente);
        break;
      }
      case 6: {
        // Aggiungere movimento a utente per nome e cognome
        if (utenti_attuali == 0) {
          printf("Non ci sono utenti al momento\n");
          break;
        }

        char nome[DimensioneStringa];
        char cognome[DimensioneStringa];
        printf("Nome: ");
        input_stringa(nome, DimensioneStringa);

        printf("Cognome: ");
        input_stringa(cognome, DimensioneStringa);

        int indice =
            cerca_utente_nome_cognome(utenti, utenti_attuali, nome, cognome);
        if (indice == -1) {
          printf("Nessun utente %s %s trovato.\n", cognome, nome);
          break;
        }

        Utente* utente = utenti[indice];
        input_movimento_utente(utente);
        break;
      }
      case 7: {
        // Lista movimenti per data per codice
        if (utenti_attuali == 0) {
          printf("Non ci sono utenti al momento\n");
          break;
        }

        char codice[DimensioneStringa];
        printf("Codice: ");
        input_stringa(codice, DimensioneStringa);

        int indice = cerca_utente_codice(utenti, utenti_attuali, codice);
        if (indice == -1) {
          printf("Nessun utente con codice %s trovato.\n", codice);
          break;
        }

        Data data;
        printf("Data da ricercare\n");
        input_data(&data);

        Utente* utente = utenti[indice];
        output_movimenti_utente_in_data(utente);

        break;
      }
      case 8: {
        // Lista movimenti per data per nome e cognome
        if (utenti_attuali == 0) {
          printf("Non ci sono utenti al momento\n");
          break;
        }

        char nome[DimensioneStringa];
        char cognome[DimensioneStringa];
        printf("Nome: ");
        input_stringa(nome, DimensioneStringa);

        printf("Cognome: ");
        input_stringa(cognome, DimensioneStringa);

        int indice =
            cerca_utente_nome_cognome(utenti, utenti_attuali, nome, cognome);
        if (indice == -1) {
          printf("Nessun utente %s %s trovato.\n", cognome, nome);
          break;
        }

        Utente* utente = utenti[indice];
        output_movimenti_utente_in_data(utente);

        break;
      }
    }

    // Separatore
    printf("-------------------------\n");
  } while (selezione != 0);

  // Pulizia della memoria, usiamo utenti_attuali per capire quanti utenti siano
  // effettivamente allocati
  elimina_utenti(utenti, utenti_attuali);
  return 0;
}
