#ifndef VEICOLI_H
#define VEICOLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Prenotazione Prenotazione;

typedef struct Veicolo
{
    char targa[11];
    char modello[50];
    int disponibile; 
    struct Veicolo *punt; 

} Veicolo;

void pulisciBuffer();
void premiInvio();
void pulisciESospendi();

//Funzione per gestire menuVeicoli (Doppio puntatore per modificare la lista veicoli)
void menuVeicoli(Veicolo **punt);

//Funzione per gestire aggiungiVeicolo (Doppio puntatore per modificare la lista veicoli)
void aggiungiVeicolo(Veicolo **punt); 

//Funzione per gestire mostraVeicoli (Doppio puntatore per modificare la lista veicoli, pausa finale)
void mostraVeicoli(Veicolo *punt, int pausaFinale);

//Funzione per gestire rimuoviVeicolo (Doppio puntatore per modificare la lista veicoli, targa da rimuovere)
Veicolo * rimuoviVeicolo(Veicolo **punt, const char *targaDaRimuovere); 

//Funzione per gestire modificaVeicolo (Doppio puntatore per modificare la lista veicoli, targa da modificare)
Veicolo * modificaVeicolo(Veicolo **punt, const char *targaDaModificare); 

//Funzioni di test per i veicoli
Veicolo *aggiungiVeicoloTest(Veicolo *punt, const char *targa, const char *modello, int disponibile);
Veicolo *rimuoviVeicoloTest(Veicolo **punt, const char *targaDaRimuovere);
Veicolo *modificaVeicoloTest(Veicolo **punt, const char *targaDaModificare);
void mostraVeicoliTest(Veicolo *punt, int pausaFinale);

#endif