#ifndef PRENOTAZIONI_H
#define PRENOTAZIONI_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "veicoli.h"

typedef struct Prenotazione
{
    int codice; 
    char nome[50];
    char cognome[50];
    char targa[10]; // Targa del veicolo prenotato
    time_t dataInizio;
    time_t dataFine;
    struct Prenotazione *prenota; // Puntatore al prossimo nodo nella lista

} Prenotazione;

void pulisciBuffer();
void premiInvio(); // Funzione per attendere che l'utente prema Invio
int generaCodice();
void menuPrenotazioni(Prenotazione **prenota, Veicolo **punt);
void aggiungiPrenotazione(Prenotazione **prenota, Veicolo **punt);
void mostraPrenotazioni(Prenotazione *prenota); // Funzione per mostrare le prenotazioni
float calcolaCostoPrenotazione(Prenotazione *prenota, int codiceDaCalcolare); // Funzione per calcolare il costo della prenotazione
Prenotazione * rimuoviPrenotazione(Prenotazione **prenota, int codiceDaRimuovere); // Funzione per rimuovere una prenotazione dalla lista
Prenotazione * modificaPrenotazione(Prenotazione **prenota, int codiceDaModificare); // Funzione per modificare una prenotazione nella lista

#endif // PRENOTAZIONI_H