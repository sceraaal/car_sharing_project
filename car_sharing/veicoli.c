#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "veicoli.h"

void menuVeicoli(Veicolo **punt)
{
    int scelta = 0;

    do
    {
        printf("-------------------------MENU VEICOLI-----------------------\n");
        printf("Benvenuto nel menu veicoli! (Inserisci il numero per la scelta)\n");
        printf("1. Aggiungi un veicolo\n");
        printf("2. Mostra i veicoli\n");
        printf("3. Rimuovere un veicolo\n");
        printf("4. Modificare un veicolo\n");
        printf("5. Tornare al menu principale\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        pulisciBuffer();

        switch(scelta)
        {
            case 1:
                aggiungiVeicolo(punt); //Chiamata alla funzione aggiungiVeicolo
            break;

            case 2:
                mostraVeicoli(*punt, 1);   //Chiamata alla funzione mostraVeicoli
            break;
            
            case 3:  
            {
                char targaDaRimuovere[20];
                printf("Inserisci la targa del veicolo da rimuovere: ");
                scanf("%s", targaDaRimuovere);

                *punt = rimuoviVeicolo(punt, targaDaRimuovere); //Assegnazione del puntatore alla funzione rimuoviVeicolo, restituendo il puntatore aggiornato
            }    
            break;
            
            case 4:
            {
                char targaDaModificare[20];
                printf("Inserisci la targa del veicolo da modificare: ");
                scanf("%s", targaDaModificare);

                *punt = modificaVeicolo(punt, targaDaModificare); //Assegnazione del puntatore alla funzione modificaVeicolo, restituendo il puntatore aggiornato
            }
            break;
            
            case 5:
                printf("Tornando al menu principale...\n");
            break;

            default:
                printf("Scelta non valida. Riprova.\n");
        }
    }
    while(scelta != 5); //Continua a mostrare il menu finché l'utente non sceglie di uscire
}

void aggiungiVeicolo(Veicolo **punt)
{
    int numVeicoli; 

    printf("-------------------------\tAGGIUNTA VEICOLI\t-----------------------\n");
    printf("Quanti veicoli vuoi aggiungere? ");
    scanf("%d", &numVeicoli);
    pulisciBuffer();

    if(numVeicoli < 0)
    {
        printf("Numero di veicoli non valido.\n");
        return;
    }
    else if(numVeicoli == 0)
    {
        printf("Nessun veicolo da aggiungere.\n");
        return;
    }

    printf("Numero di veicoli da aggiungere: %d\n", numVeicoli);
    printf("-------------------------\tAGGIUNTA VEICOLI\t-----------------------\n");

    for(int i=0; i<numVeicoli; i++)
    {
        Veicolo *nuovoVeicolo = (Veicolo *)malloc(sizeof(Veicolo)); //Allocazione della memoria per il nuovoVeicolo

        if (nuovoVeicolo == NULL)
        {
            printf("Errore nell'allocazione della memoria per il veicolo.\n");
            return;
        }
        else
        {
            printf("Allocazione della memoria per il veicolo riuscita.\n");
            printf("-------------------------\tAGGIUNTA VEICOLI\t-----------------------\n");
        }

        if(numVeicoli != 0) 
        {
            printf("Aggiunta del veicolo numero %d:\n", i+1);
            printf("Inserisci la targa del veicolo: ");
            scanf(" %10s", nuovoVeicolo->targa);

            printf("Inserisci il modello del veicolo: ");
            scanf(" %49s", nuovoVeicolo->modello);

            printf("E' disponibile? (1 per si, 0 per no): ");
            scanf("%d", &nuovoVeicolo->disponibile);

            if(nuovoVeicolo->disponibile != 0 && nuovoVeicolo->disponibile != 1) //Controllando se la disponibilità è valida 
            {
                printf("Disponibilità non valida. Deve essere 1 (si) o 0 (no).\n");
                free(nuovoVeicolo); 
                return;
            }

            printf("-------------------------\tAGGIUNTA VEICOLI\t-----------------------\n");
        }
        else
        {
            printf("Inserisci la targa del veicolo: ");
            scanf(" %10s", nuovoVeicolo->targa);

            printf("Inserisci il modello del veicolo: ");
            scanf(" %49s", nuovoVeicolo->modello);

            printf("E' disponibile? (1 per si, 0 per no): ");
            scanf("%d", &nuovoVeicolo->disponibile);

            printf("-------------------------\tAGGIUNTA VEICOLI\t-----------------------\n");
        }

        printf("Collegando il nuovo veicolo alla lista...\n");
        nuovoVeicolo->punt = *punt; //Collegamento del nuovo veicolo alla lista
        *punt = nuovoVeicolo; //Assegnazione del puntatore alla lista aggiornata

        printf("-------------------------\tAGGIUNTA VEICOLI\t-----------------------\n");

        if(numVeicoli != 0) 
        {
            printf("Dettagli del veicolo numero %d:\n", i+1);
            printf("Targa: %s\n", nuovoVeicolo->targa);
            printf("Modello: %s\n", nuovoVeicolo->modello);
            printf("Disponibile: %s\n", nuovoVeicolo->disponibile ? "Si" : "No");
            printf("---------------------------------------------------------\n");
        }
        else
        {
            printf("Dettagli del veicolo: \n");
            printf("Targa: %s\n", nuovoVeicolo->targa);
            printf("Modello: %s\n", nuovoVeicolo->modello);
            printf("Disponibile: %s\n", nuovoVeicolo->disponibile ? "Si" : "No");
        }

        printf("Veicolo aggiunto con successo!\n");
        printf("---------------------------------------------------------\n");
    }
    premiInvio();
}

void mostraVeicoli(Veicolo *punt, int pausaFinale)
{
    printf("-----------------------\tMOSTRA VEICOLI\t-----------------------\n");

    if (punt == NULL)
    {
        printf("NESSUN VEICOLO DISPONIBILE. \n");
        return;
    }

    printf("-----------------------\tVEICOLI\t-----------------------\n");
    while (punt != NULL)
    {
        printf("Targa: %s\n", punt->targa);
        printf("Modello: %s\n", punt->modello);
        printf("Disponibile: %s\n", punt->disponibile ? "Si" : "No");
        printf("---------------------------------------------------------\n");

        punt = punt->punt; //Passaggio al prossimo veicolo nella lista
    }

    if(pausaFinale)
    {
        premiInvio();
    }
}

Veicolo * rimuoviVeicolo(Veicolo **punt, const char *targaDaRimuovere)
{ 
    printf("-----------------------\tRIMOZIONE VEICOLI\t-----------------------\n");
    if (punt == NULL)
    {
        printf("NESSUN VEICOLO DISPONIBILE. \n");
        return NULL;
    }

    Veicolo *nododaeliminare = *punt;
    Veicolo *precedente = NULL;

    while(nododaeliminare != NULL)
    {
        if(strcmp(nododaeliminare->targa, targaDaRimuovere) == 0) //Controllo della targa
        {
            if(precedente == NULL) 
            {
                *punt = nododaeliminare->punt; //Aggiorna il puntatore alla lista
            }
            else
            {
                precedente->punt = nododaeliminare->punt; //Collega il nodo precedente al successivo
            }

            free(nododaeliminare);
            printf("Veicolo con targa %s rimosso.\n", targaDaRimuovere);
            printf("---------------------------------------------------------\n");
        }

        precedente = nododaeliminare; //Aggiorna il puntatore al nodo precedente
        nododaeliminare = nododaeliminare->punt; //Passa al prossimo veicolo nella lista
    }
    premiInvio();
    return *punt;
}

Veicolo * modificaVeicolo(Veicolo **punt, const char *targaDaModificare)
{
    Veicolo *corrente = *punt;

    printf("-----------------------\tMODIFICA VEICOLI\t-----------------------\n");
    if (*punt==NULL)
    {
        printf("NESSUN VEICOLO DISPONIBILE. \n");
        return NULL;
    }
    
    int scelta=0;

    while (corrente != NULL) 
    {
        if (strcmp(corrente->targa, targaDaModificare) == 0) 
        {
            break;
        }
        corrente = corrente->punt;
    }

    if (corrente == NULL) 
    {
        printf("TARGA NON TROVATA.\n");
        return *punt;
    }

    printf("Che attributo vuoi modificare? (Inserisci il numero per la scelta)\n");
    printf("1. Targa\n");
    printf("2. Modello\n");
    printf("3. Disponibilita'\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    pulisciBuffer();

    switch(scelta)
    {
        case 1:
        {
            char nuovaTarga[10];
            printf("Inserisci la nuova targa: ");
            scanf(" %10s", nuovaTarga);

            strcpy(corrente->targa, nuovaTarga);
            printf("Targa modificata con successo.\n");
        }
        break;

        case 2:
        {
            char nuovoModello[50];
            printf("Inserisci il nuovo modello: ");
            scanf(" %49s", nuovoModello);

            strcpy(corrente->modello, nuovoModello);
            printf("Modello modificato con successo.\n");
        }
        break;

        case 3:
        {
            int nuovaDisponibilita;
            printf("Inserisci la nuova disponibilita' (1 per si, 0 per no): ");
            scanf("%d", &nuovaDisponibilita);

            corrente->disponibile = nuovaDisponibilita;
            printf("Disponibilita' modificata con successo.\n");
        }
        break;

        default:
            printf("Scelta non valida. Riprova.\n");
            break;
    }

    printf("---------------------------------------------------------\n");
    premiInvio();

    return *punt;
}
