#ifndef PRENOTAZIONI_H 
#define PRENOTAZIONI_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Dichiarazione della struttura Veicolo in modo da poterla utilizzare in Prenotazione 
typedef struct Veicolo Veicolo; 

typedef struct Prenotazione
{
    int codice; 
    char nome[50];
    char cognome[50];
    char targa[10];
    time_t dataInizio;
    time_t dataFine;
    struct Prenotazione *prenota; 

} Prenotazione;

void pulisciBuffer();
void premiInvio();
int generaCodice();
void pulisciESospendi();

//Funzione per gestire menuPrenotazioni (Doppio puntatore per modificare la lista prenotazioni, doppio puntatore per modificare la lista veicoli)
void menuPrenotazioni(Prenotazione **prenota, Veicolo **punt); 

//Funzione per gestire aggiungiPrenotazione (Doppio puntatore per modificare la lista prenotazioni, doppio puntatore per modificare la lista veicoli)
void aggiungiPrenotazione(Prenotazione **prenota, Veicolo **punt); 

//Funzione per gestire mostraPrenotazioni (Doppio puntatore per modificare la lista prenotazioni)
void mostraPrenotazioni(Prenotazione *prenota); 

//Funzione per gestire calcolaCostoPrenotazione (Doppio puntatore per modificare la lista prenotazioni, codice da calcolare)
float calcolaCostoPrenotazione(Prenotazione *prenota, int codiceDaCalcolare); 

//Funzione per gestire rimuoviPrenotazione (Doppio puntatore per modificare la lista prenotazioni, codice da rimuovere)
Prenotazione * rimuoviPrenotazione(Prenotazione **prenota, int codiceDaRimuovere, Veicolo **punt); 

//Funzione per gestire modificaPrenotazione (Doppio puntatore per modificare la lista prenotazioni, codice da modificare)
Prenotazione * modificaPrenotazione(Prenotazione **prenota, int codiceDaModificare); 

//Funzioni di test per le prenotazioni
Prenotazione *aggiungiPrenotazioneTest(Prenotazione *prenota, Veicolo *punt, const char *nome, const char *cognome, const char *targa, time_t dataFine, int codice);
Prenotazione *modificaPrenotazioneTest(Prenotazione *prenota, int codiceDaModificare);
Prenotazione *rimuoviPrenotazioneTest(Prenotazione *prenota, int codiceDaRimuovere, Veicolo *punt);
float calcolaCostoPrenotazioneTest(Prenotazione *prenota, int codiceDaCalcolare);
void mostraPrenotazioniTest(Prenotazione *prenota);

#endif