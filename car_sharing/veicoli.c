#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "veicoli.h"

/*
In questo file "veicoli.c" sono implementate le funzioni per la gestione dei veicoli.
Le funzioni permettono di aggiungere, rimuovere, modificare e visualizzare i veicoli.
Le funzioni utilizzano strutture dati per gestire le informazioni sui veicoli.
Le funzioni sono organizzate in modo da essere facilmente richiamabili dal menu principale del programma.
*/

/*
FUNZIONE: menuVeicoli
-------------------------
Mostra un menu per la gestione dei veicoli, permettendo all'utente di aggiungere, mostrare, rimuovere o modificare veicoli.

IMPLEMENTAZIONE:
void menuVeicoli(Veicolo **punt);
{
    ...
}

PARAMETRI:
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se l'utente sceglie di aggiungere un veicolo, la funzione chiama la funzione `aggiungiVeicolo` per aggiungere uno o più veicoli alla lista.
- Se l'utente sceglie di mostrare i veicoli, la funzione chiama `mostraVeicoli` per visualizzare i veicoli presenti nella lista.
- Se l'utente sceglie di rimuovere un veicolo, la funzione chiama `rimuoviVeicolo` per rimuovere un veicolo specifico dalla lista.
- Se l'utente sceglie di modificare un veicolo, la funzione chiama `modificaVeicolo` per modificare i dettagli di un veicolo specifico nella lista.
- Se l'utente sceglie di tornare al menu principale, la funzione termina e ritorna al menu principale.

SIDE-EFFECT:
- La funzione stampa un menu interattivo per l'utente, richiedendo l'input per le operazioni da eseguire.
- La funzione gestisce le operazioni sui veicoli in base alla scelta dell'utente, modificando la lista collegata di veicoli.
*/
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
                aggiungiVeicolo(punt); 
            break;

            case 2:
                mostraVeicoli(*punt, 1);
            break;
            
            case 3:  
            {
                char targaDaRimuovere[20];
                printf("Inserisci la targa del veicolo da rimuovere: ");
                scanf("%s", targaDaRimuovere);

                *punt = rimuoviVeicolo(punt, targaDaRimuovere);
            }    
            break;
            
            case 4:
            {
                char targaDaModificare[20];
                printf("Inserisci la targa del veicolo da modificare: ");
                scanf("%s", targaDaModificare);

                *punt = modificaVeicolo(punt, targaDaModificare); 
            }
            break;
            
            case 5:
                printf("Tornando al menu principale...\n");
            break;

            default:
                printf("Scelta non valida. Riprova.\n");
        }
    }
    while(scelta != 5); 
}
/*
FUNZIONE: aggiungiVeicolo
-------------------------
Aggiunge uno o più veicoli a una lista collegata di veicoli, richiedendo all'utente di inserire i dati da tastiera.

IMPLEMENTAZIONE: 
void aggiungiVeicolo(Veicolo **punt)
{
...
}

PARAMETRI:
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.
POST-CONDIZIONI:
- Se l'utente inserisce un numero di veicoli valido, i nuovi veicoli vengono aggiunti alla lista collegata.
- Se l'utente inserisce un numero di veicoli non valido (minore di 0), viene visualizzato un messaggio di errore e la funzione termina senza modificare la lista.
- Se l'utente inserisce 0 come numero di veicoli, viene visualizzato un messaggio che indica che non ci sono veicoli da aggiungere e la funzione termina senza modificare la lista.

SIDE-EFFECT:
- La funzione alloca memoria dinamica per ogni nuovo veicolo aggiunto alla lista.
- La funzione richiede l'input dell'utente per i dati del veicolo (targa, modello, disponibilità).
- La funzione stampa messaggi di stato per informare l'utente sull'allocazione della memoria, l'aggiunta dei veicoli e i dettagli dei veicoli aggiunti.
*/
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
        // Allocazione della memoria per il nuovo veicolo
        Veicolo *nuovoVeicolo = (Veicolo *)malloc(sizeof(Veicolo)); 

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
/*
FUNZIONE: mostraVeicoli
-------------------------
Visualizza i veicoli presenti nella lista collegata, mostrando i dettagli di ciascun veicolo.

IMPLEMENTAZIONE:
void mostraVeicoli(Veicolo *punt, int pausaFinale)
{
    ...
}

PARAMETRI:
punt: un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.
pausaFinale: un intero che indica se la funzione deve attendere l'input dell'utente prima di terminare (1 per attendere, 0 per non attendere).

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la lista di veicoli è vuota (punt == NULL), viene visualizzato un messaggio che indica che non ci sono veicoli disponibili.
- Se la lista di veicoli contiene uno o più veicoli, vengono visualizzati i dettagli di ciascun veicolo (targa, modello, disponibilità).
- Se il parametro pausaFinale è impostato a 1, la funzione attende l'input dell'utente prima di terminare.

SIDE-EFFECT:
- La funzione stampa i dettagli dei veicoli sulla console.
*/
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

        punt = punt->punt; 
    }

    if(pausaFinale)
    {
        premiInvio();
    }
}
/*
FUNZIONE: rimuoviVeicolo
-------------------------
Rimuove un veicolo dalla lista collegata di veicoli, cercando il veicolo con la targa specificata.

IMPLEMENTAZIONE:
Veicolo * rimuoviVeicolo(Veicolo **punt, const char *targaDaRimuovere)
{
    ...
}

PARAMETRI:
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.
targaDaRimuovere: una stringa che rappresenta la targa del veicolo da rimuovere dalla lista.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la lista di veicoli è vuota (punt == NULL), viene visualizzato un messaggio che indica che non ci sono veicoli disponibili e la funzione termina senza modificare la lista.
- Se il veicolo con la targa specificata viene trovato, viene rimosso dalla lista e la memoria allocata per il veicolo viene liberata.
- Se il veicolo con la targa specificata non viene trovato, la lista rimane invariata e viene visualizzato un messaggio che indica che il veicolo non è stato trovato.

SIDE-EFFECT:
- La funzione modifica la lista collegata di veicoli rimuovendo il nodo corrispondente alla targa specificata.
*/
Veicolo * rimuoviVeicolo(Veicolo **punt, const char *targaDaRimuovere)
{ 
    printf("-----------------------\tRIMOZIONE VEICOLI\t-----------------------\n");
    if (punt == NULL)
    {
        printf("NESSUN VEICOLO DISPONIBILE. \n");
        return NULL;
    }

    /*
        *nododaeliminare è il puntatore al nodo corrente che stiamo esaminando
        *precedente è il puntatore al nodo precedente, inizialmente NULL
    */
    Veicolo *nododaeliminare = *punt;
    Veicolo *precedente = NULL;

    while(nododaeliminare != NULL)
    {
        /*
        Ricerca della targa da rimuovere confrontando le stringhe
        */
        if(strcmp(nododaeliminare->targa, targaDaRimuovere) == 0) 
        {
            if(precedente == NULL) 
            {
                /*
                Se il nodo da eliminare è il primo della lista, aggiorniamo il puntatore principale
                */
                *punt = nododaeliminare->punt; 
            }
            else
            {
                /*
                Altrimenti aggiorniamo il puntatore del nodo precedente per saltare il nodo da eliminare
                */
                precedente->punt = nododaeliminare->punt; 
            }

            free(nododaeliminare);
            printf("Veicolo con targa %s rimosso.\n", targaDaRimuovere);
            printf("---------------------------------------------------------\n");
        }

        /*
        Precedente diventa il nodo corrente e nododaeliminare punta al successivo
        */
        precedente = nododaeliminare; 
        nododaeliminare = nododaeliminare->punt; 
    }
    premiInvio();
    return *punt;
}
/*
FUNZIONE: modificaVeicolo
-------------------------
Modifica i dettagli di un veicolo nella lista collegata, cercando il veicolo con la targa specificata e permettendo all'utente di modificare uno dei suoi attributi.

IMPLEMENTAZIONE:
Veicolo * modificaVeicolo(Veicolo **punt, const char *targaDaModificare)
{
    ...
}

PARAMETRI:
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.
targaDaModificare: una stringa che rappresenta la targa del veicolo da modificare.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la lista di veicoli è vuota (punt == NULL), viene visualizzato un messaggio che indica che non ci sono veicoli disponibili e la funzione termina senza modificare la lista.
- Se il veicolo con la targa specificata viene trovato, l'utente può scegliere di modificare uno dei seguenti attributi: targa, modello o disponibilità.
- Se l'utente sceglie di modificare un attributo, il valore dell'attributo viene aggiornato e viene visualizzato un messaggio di conferma.
- Se il veicolo con la targa specificata non viene trovato, viene visualizzato un messaggio che indica che la targa non è stata trovata e la lista rimane invariata.

SIDE-EFFECT:
- La funzione richiede l'input dell'utente per la targa del veicolo da modificare e per i nuovi valori degli attributi da modificare.
- La funzione stampa un menu per permettere all'utente di scegliere quale attributo modificare.
- La funzione modifica i dettagli del veicolo nella lista collegata in base alla scelta dell'utente.
*/
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
/*
FUNZIONE: premiInvio
-------------------------
Attende che l'utente prema il tasto INVIO per continuare l'esecuzione del programma.

IMPLEMENTAZIONE:
void premiInvio()
{
    printf("Premi INVIO per continuare...\n");
    getchar(); // Attende il primo carattere (per catturare l'input precedente)
    getchar(); // Attende il secondo carattere (l'input dell'utente)
}

PARAMETRI:
Nessuno.

PRE-CONDIZIONI:
- Nessuna condizione predefinita.

POST-CONDIZIONI:
- La funzione attende che l'utente prema il tasto INVIO prima di continuare l'esecuzione del programma.

SIDE-EFFECT:
- La funzione stampa un messaggio sulla console per informare l'utente di premere il tasto INVIO.
*/
void premiInvio()
{
    printf("Premi INVIO per continuare...\n");
    getchar();
    getchar();
}
/*
FUNZIONE: pulisciBuffer
-------------------------
Pulisce il buffer di input, rimuovendo tutti i caratteri fino al carattere di nuova linea.

IMPLEMENTAZIONE:
void pulisciBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}

PARAMETRI:
Nessuno.

PRE-CONDIZIONI:
- Nessuna condizione predefinita.

POST-CONDIZIONI:
- La funzione rimuove tutti i caratteri dal buffer di input fino al carattere di nuova linea, 
garantendo che il buffer sia vuoto per le successive letture.

SIDE-EFFECT:
- La funzione consuma tutti i caratteri nel buffer di input fino al carattere di nuova linea, 
evitando che eventuali input precedenti influenzino le letture successive.
*/
void pulisciBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}
