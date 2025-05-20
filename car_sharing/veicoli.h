#ifndef VEICOLI_H
#define VEICOLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veicolo
{
    char targa[11];
    char modello[50];
    int disponibile; 
    struct Veicolo *punt; 

} Veicolo;

void pulisciBuffer();
void premiInvio();

//Funzione per gestire menuVeicoli (Doppio puntatore per modificare la lista veicoli)
void menuVeicoli(Veicolo **punt);

//Funzione per gestire aggiungiVeicolo (Doppio puntatore per modificare la lista veicoli)
void aggiungiVeicolo(Veicolo **punt); 

//Funzione per gestire mostraVeicoli (Doppio puntatore per modificare la lista veicoli)
void mostraVeicoli(Veicolo *punt, int pausaFinale);

//Funzione per gestire rimuoviVeicolo (Doppio puntatore per modificare la lista veicoli, targa da rimuovere)
Veicolo * rimuoviVeicolo(Veicolo **punt, const char *targaDaRimuovere); 

//Funzione per gestire modificaVeicolo (Doppio puntatore per modificare la lista veicoli, targa da modificare)
Veicolo * modificaVeicolo(Veicolo **punt, const char *targaDaModificare); 

#endif