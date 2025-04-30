#include <stdlib.h>
#include <stdio.h>

#include "veicolo.h" // Include il file di intestazione per la struttura Veicolo

void aggiungiVeicolo(Veicolo **veicoli)  // Passa l'indirizzo del puntatore per modificare la lista di veicoli
{
    Veicolo *nuovoVeicolo = (Veicolo *)malloc(sizeof(Veicolo)); // Alloca memoria per un nuovo veicolo

    if (nuovoVeicolo == NULL) // Controlla se l'allocazione è andata a buon fine
    {
        printf("Errore di allocazione della memoria.\n");
        return;
    }

    printf("Inserisci la targa del veicolo: ");
    scanf("%s", nuovoVeicolo->targa); // Legge la targa del veicolo

    printf("Inserisci il tipo di veicolo: ");
    scanf("%s", nuovoVeicolo->tipo); // Legge il tipo di veicolo

    nuovoVeicolo->disponibile = 1; // Imposta il veicolo come disponibile
    nuovoVeicolo->next = *veicoli // Inizializza il puntatore al prossimo veicolo a NULL
    *veicoli = nuovoVeicolo; // Aggiunge il nuovo veicolo all'inizio della lista

    printf("Veicolo aggiunto con successo.\n");
}

void visualizzaVeicoliDisponibili(Veicolo *veicoli) // Passa il puntatore alla lista di veicoli
{
    if (veicoli == NULL) 
    {
        printf("Nessun veicolo disponibile.\n");
        return;
    }

    printf("Veicoli disponibili:\n");
    printf("Targa\tTipo\n"); // Intestazione della tabella
    printf("-----\t----\n"); // Separatore tra intestazione e dati

    while (veicoli != NULL) 
    {
        if (veicoli->disponibile) // Controlla se il veicolo è disponibile
        {
            printf("%s\t%s\n", veicoli->targa, veicoli->tipo); // Stampa la targa e il tipo del veicolo
        }
        veicoli = veicoli->next; // Passa al prossimo veicolo nella lista
    }

    printf("Funzione per mostrare i veicoli disponibili.\n");
}

Veicolo *cercaVeicolo(Veicolo *veicoli, const char *targa) // Passa il puntatore alla lista di veicoli e la targa da cercare 
{ 
    if(strcmp(veicoli->targa, targa) == 0) //Controlla se la targa del veicolo corrente corrisponde a quella cercata (0 se uguali)
    { 
        printf("Veicolo trovato: %s, %s\n", veicoli->targa, veicoli->tipo); // Stampa i dettagli del veicolo trovato
        return veicoli; // Restituisce il puntatore al veicolo trovato
    }

    printf("Funzione per cercare un veicolo.\n");
    return NULL; // Restituisce NULL se non trovato
}
