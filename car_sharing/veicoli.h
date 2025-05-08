#ifndef VEICOLI_H
#define VEICOLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struttura per rappresentare un veicolo
typedef struct Veicolo
{
    char targa[20];
    char modello[50];
    int disponibile; // 1 se disponibile, 0 se noleggiato
    struct Veicolo *punt; // Puntatore al prossimo veicolo nella lista

} Veicolo;

void pulisciBuffer();
void premiInvio(); // Funzione per attendere che l'utente prema Invio
void menuVeicoli(Veicolo **punt);
void aggiungiVeicolo(Veicolo **punt); 
void mostraVeicoli(Veicolo *punt); // Funzione per mostrare i veicoli
Veicolo * rimuoviVeicolo(Veicolo **punt, const char *targaDaRimuovere); // Funzione per rimuovere un veicolo dalla lista
Veicolo * modificaVeicolo(Veicolo **punt, const char *targaDaModificare); // Funzione per modificare un veicolo nella lista
#endif // VEICOLI_H
