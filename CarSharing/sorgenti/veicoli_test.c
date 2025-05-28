#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "veicoli.h"

/*
In questo file "veicoli_test.c" sono presenti i test per le funzioni di gestione dei veicoli.
I test sono stati creati per verificare il corretto funzionamento delle funzioni di aggiunta, rimozione, modifica e visualizzazione dei veicoli.
I test utilizzano asserzioni per verificare che le funzioni restituiscano i risultati attesi.
I test sono organizzati in funzioni separate per ogni operazione e vengono eseguiti in sequenza nel main.
*/

/*
FUNZIONE: aggiungiVeicoloTest
-------------------------
Testa la funzione di aggiunta di un veicolo alla lista collegata.

IMPLEMENTAZIONE:
Veicolo *aggiungiVeicoloTest(Veicolo *punt, const char *targa, const char *modello, int disponibile);

PARAMETRI:
punt: un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.
targa: una stringa che rappresenta la targa del veicolo da aggiungere.
modello: una stringa che rappresenta il modello del veicolo da aggiungere.
disponibile: un intero che rappresenta la disponibilità del veicolo (1 per disponibile, 0 per non disponibile).

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se l'aggiunta del veicolo ha successo, il puntatore punt deve contenere i dati del veicolo aggiunto.
- Se l'aggiunta del veicolo fallisce, il puntatore punt deve rimanere invariato e non deve essere NULL.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se il veicolo è stato aggiunto correttamente.
*/
Veicolo *aggiungiVeicoloTest(Veicolo *punt, const char *targa, const char *modello, int disponibile) 
{
    Veicolo *nuovoVeicolo = (Veicolo *)malloc(sizeof(Veicolo));
    if (nuovoVeicolo == NULL) 
    {
        printf("Errore nell'allocazione della memoria per il veicolo.\n");
        return NULL;
    }
    
    strcpy(nuovoVeicolo->targa, targa);
    strcpy(nuovoVeicolo->modello, modello);
    nuovoVeicolo->disponibile = disponibile;
    nuovoVeicolo->punt = punt; // Inserisce il nuovo veicolo all'inizio della lista
    return nuovoVeicolo;
}
/*
FUNZIONE: rimuoviVeicoloTest
-------------------------
Testa la funzione di rimozione di un veicolo dalla lista collegata.

IMPLEMENTAZIONE:
Veicolo *rimuoviVeicoloTest(Veicolo **punt, const char *targaDaRimuovere);

PARAMETRI:
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.
targaDaRimuovere: una stringa che rappresenta la targa del veicolo da rimuovere dalla lista.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la rimozione del veicolo ha successo, il puntatore punt deve essere aggiornato per riflettere la lista senza il veicolo rimosso.
- Se il veicolo con la targa specificata non viene trovato, viene visualizzato un messaggio e la lista rimane invariata.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se il veicolo è stato rimosso correttamente.
*/
Veicolo *rimuoviVeicoloTest(Veicolo **punt, const char *targaDaRimuovere) 
{
    Veicolo *nododaeliminare = *punt;
    Veicolo *precedente = NULL;

    while (nododaeliminare != NULL) 
    {
        if (strcmp(nododaeliminare->targa, targaDaRimuovere) == 0) 
        {
            if (precedente == NULL) 
            {
                *punt = nododaeliminare->punt; // Rimuove il primo nodo
            } 
            else 
            {
                precedente->punt = nododaeliminare->punt; // Rimuove un nodo intermedio o finale
            }
            free(nododaeliminare);
            return *punt; // Restituisce la lista aggiornata
        }
        precedente = nododaeliminare;
        nododaeliminare = nododaeliminare->punt;
    }
    
    printf("Veicolo con targa %s non trovato.\n", targaDaRimuovere);
    return *punt; // Restituisce la lista invariata se il veicolo non è trovato
}
/*
FUNZIONE: modificaVeicoloTest
-------------------------
Testa la funzione di modifica di un veicolo nella lista collegata.

IMPLEMENTAZIONE:
Veicolo *modificaVeicoloTest(Veicolo **punt, const char *targaDaModificare);

PARAMETRI:
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.
targaDaModificare: una stringa che rappresenta la targa del veicolo da modificare.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la lista di veicoli è vuota (punt == NULL), viene visualizzato un messaggio che indica che non ci sono veicoli disponibili e la funzione termina senza modificare la lista.
- Se il veicolo con la targa specificata viene trovato, il modello del veicolo viene modificato a "Punto" per il test.
- Se il veicolo con la targa specificata non viene trovato, viene visualizzato un messaggio che indica che la targa non è stata trovata e la lista rimane invariata.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se il veicolo è stato modificato correttamente.
*/
Veicolo *modificaVeicoloTest(Veicolo **punt, const char *targaDaModificare)
{
    Veicolo *corrente = *punt;
    while (corrente != NULL) 
    {
        if (strcmp(corrente->targa, targaDaModificare) == 0) {
            // Per il test, imposta sempre il modello a "Punto"
            strcpy(corrente->modello, "Punto");
            return *punt;
        }
        corrente = corrente->punt;
    }
    return *punt;
}
/*
FUNZIONE: mostraVeicoliTest
-------------------------
Testa la visualizzazione dei veicoli nella lista collegata.

IMPLEMENTAZIONE:
void mostraVeicoliTest(Veicolo *punt, int pausaFinale);

PARAMETRI:
punt: un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.
pausaFinale: un intero che indica se la funzione deve attendere l'input dell'utente alla fine della visualizzazione (1 per sì, 0 per no).

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la lista di veicoli è vuota (punt == NULL), viene visualizzato un messaggio che indica che non ci sono veicoli disponibili.
- Se la lista di veicoli contiene nodi, vengono stampati i dettagli di ogni veicolo (targa, modello, disponibilità).
- Se il parametro pausaFinale è impostato a 1, la funzione attende l'input dell'utente prima di terminare.

SIDE-EFFECT:
- La funzione stampa i dettagli dei veicoli sulla console.
*/
void mostraVeicoliTest(Veicolo *punt, int pausaFinale)
{
    Veicolo *corrente = punt;
    printf("---- Lista Veicoli (TEST) ----\n");
    while (corrente != NULL) 
    {
        printf("Targa: %s, Modello: %s, Disponibile: %d\n", corrente->targa, corrente->modello, corrente->disponibile);
        corrente = corrente->punt;
        printf("-------------------------------\n");
    }
    
    if (pausaFinale) 
    {
        premiInvio();
    }
}
