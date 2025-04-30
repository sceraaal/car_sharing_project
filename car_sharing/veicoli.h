#include <stdlib.h>
#include <stdio.h>

typedef struct Veicolo
{
    char targa[20];
    char tipo[50]; // Tipo di veicolo (es. auto, furgone)
    int disponibile;      // 1 se disponibile, 0 altrimenti
    struct Veicolo *next; // Puntatore al prossimo veicolo nella lista
} Veicolo; 

void aggiungiVeicoli(Veicolo **veicoli); //Passiamo l'indirizzo del puntatore per modificare la lista di veicoli
void visualizzaVeicoliDisponibili(Veicolo *veicoli); //Passiamo il puntatore alla lista di veicoli 
Veicolo *cercaVeicolo(Veicolo *veicoli, const char *targa); //Passiamo il puntatore alla lista di veicoli e la targa da cercare
