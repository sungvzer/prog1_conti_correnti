/**
 * Questo file contiene l'implementazione delle funzionalità di una data
 * semplificata
 * Salvatore Gargano <salvatore.gargano001@studenti.uniparthenope.it>
 */

#include <Data.h>

Data crea_data(unsigned int giorno, unsigned int mese, unsigned int anno) {
  Data nuova;
  nuova.anno = anno;
  nuova.mese = mese;
  nuova.giorno = giorno;
  nuova.valida = controlla_data(nuova);

  return nuova;
}

int bisestile(int anno) {
  // Si dice bisestile:
  // 1. un anno non secolare (non divisibile per 100) divisibile per 4
  // 2. un anno secolare divisibile per 400
  return ((anno % 4 == 0) && (anno % 100 != 0)) || (anno % 400 == 0);
}

int controlla_data(Data data) {
  if (data.giorno > 31 || data.giorno < 1) {
    // Ignora casi al 100% non validi
    return 0;
  }

  if (data.mese > 12 || data.mese < 1) {
    // Ignora casi al 100% non validi
    return 0;
  }

  if (data.mese == 2) {
    if (bisestile(data.anno))
      // Se si controlla il febbraio di un anno bisestile controlla se il giorno
      // è minore o uguale a 29
      return data.giorno <= 29;
    else
      // Altrimenti se il giorno è minore o uguale a 28
      return data.giorno <= 28;
  }

  // Controlla i giorni dei mesi rimanenti
  switch (data.mese) {
    // gen, mar, mag, lug, ago, ott, dic
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return data.giorno <= 31;
    // apr, giu, set, nov
    case 4:
    case 6:
    case 9:
    case 11:
      return data.giorno <= 30;
  }

  return 0;
}

int compara_date(Data *prima, Data *seconda) {
  if (prima->giorno != seconda->giorno) {
    // Ritorna -1 se il primo giorno è inferiore al secondo, altrimenti 1
    return prima->giorno < seconda->giorno ? -1 : 1;
  }

  if (prima->mese != seconda->mese) {
    // Ritorna -1 se il primo mese è inferiore al secondo, altrimenti 1
    return prima->mese < seconda->mese ? -1 : 1;
  }

  if (prima->anno != seconda->anno) {
    // Ritorna -1 se il primo anno è inferiore al secondo, altrimenti 1
    return prima->anno < seconda->anno ? -1 : 1;
  }

  // Le due date sono uguali
  return 0;
}
