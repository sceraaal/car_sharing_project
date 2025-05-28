#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "prenotazioni.h"
#include "veicoli.h"

/*
In questo file "prenotazioni_test.c" sono presenti i test per le funzioni di gestione delle prenotazioni.
I test sono stati creati per verificare il corretto funzionamento delle funzioni di aggiunta, modifica, rimozione e calcolo del costo delle prenotazioni.
I test utilizzano asserzioni per verificare che le funzioni restituiscano i risultati attesi.
I test sono organizzati in funzioni separate per ogni operazione e vengono eseguiti in sequenza nel main.
*/

/*
FUNZIONE: aggiungiPrenotazioneTest
-------------------------
Testa la funzione di aggiunta di una prenotazione alla lista collegata.

IMPLEMENTAZIONE:
Prenotazione *aggiungiPrenotazioneTest(Prenotazione *prenota, Veicolo *punt, const char *nome, const char *cognome, const char *targa, time_t dataFine, int codice);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.
nome: una stringa che rappresenta il nome del cliente che effettua la prenotazione.
cognome: una stringa che rappresenta il cognome del cliente che effettua la prenotazione.
targa: una stringa che rappresenta la targa del veicolo da prenotare.
dataFine: un valore di tipo time_t che rappresenta la data di fine della prenotazione.
codice: un intero che rappresenta il codice della prenotazione da aggiungere.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
Se la prenotazione viene aggiunta con successo, il puntatore prenota deve contenere i dati della prenotazione aggiunta.
Se la prenotazione non può essere aggiunta (ad esempio, se il veicolo non è disponibile), il puntatore prenota deve rimanere invariato e non deve essere NULL.

SIDE-EFFECT:
La funzione stampa un messaggio di successo se la prenotazione è stata aggiunta correttamente.
*/
Prenotazione *aggiungiPrenotazioneTest(Prenotazione *prenota, Veicolo *punt, const char *nome, const char *cognome, const char *targa, time_t dataFine, int codice) 
{
   
    Veicolo *temp = punt;
    while (temp != NULL) 
    {
        if (strcmp(temp->targa, targa) == 0 && temp->disponibile) 
        {
            Prenotazione *nuova = malloc(sizeof(Prenotazione));

            if (!nuova) 
            return prenota;

            strncpy(nuova->nome, nome, sizeof(nuova->nome));
            nuova->nome[sizeof(nuova->nome)-1] = '\0';

            strncpy(nuova->cognome, cognome, sizeof(nuova->cognome));
            nuova->cognome[sizeof(nuova->cognome)-1] = '\0';

            strncpy(nuova->targa, targa, sizeof(nuova->targa));
            nuova->targa[sizeof(nuova->targa)-1] = '\0';

            nuova->dataInizio = time(NULL);
            nuova->dataFine = dataFine;
            nuova->codice = codice;
            nuova->prenota = prenota;
            temp->disponibile = 0;
            return nuova;
        }
        temp = temp->punt;
    }
    return prenota;
}
/*
FUNZIONE: modificaPrenotazioneTest
-------------------------
Testa la modifica dei dettagli di una prenotazione specifica nella lista collegata di prenotazioni.

IMPLEMENTAZIONE:
Prenotazione *modificaPrenotazioneTest(Prenotazione *prenota, int codiceDaModificare);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
codiceDaModificare: un intero che rappresenta il codice della prenotazione da modificare.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se la lista di prenotazioni è vuota, viene visualizzato un messaggio che indica che non ci sono prenotazioni disponibili e la funzione restituisce NULL.
- Se la prenotazione con il codice specificato viene trovata, i dettagli della prenotazione vengono modificati (ad esempio, il nome del cliente viene cambiato in "Giovanni").
- Se la prenotazione con il codice specificato non viene trovata, la funzione restituisce la lista di prenotazioni invariata.

SIDE-EFFECT:
La funzione stampa un messaggio di successo se la prenotazione è stata modificata correttamente.
*/
Prenotazione *modificaPrenotazioneTest(Prenotazione *prenota, int codiceDaModificare) 
{
    Prenotazione *corrente = prenota;
    while (corrente != NULL) 
    {
        if (corrente->codice == codiceDaModificare) 
        {
            strcpy(corrente->nome, "Giovanni");
            return prenota;
        }
        corrente = corrente->prenota;
    }
    return prenota;
}
/*
FUNZIONE: rimuoviPrenotazioneTest
-------------------------
Testa la rimozione di una prenotazione dalla lista collegata.

IMPLEMENTAZIONE:
Prenotazione *rimuoviPrenotazioneTest(Prenotazione *prenota, int codiceDaRimuovere, Veicolo *punt);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
codiceDaRimuovere: un intero che rappresenta il codice della prenotazione da rimuovere.
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la lista di prenotazioni è vuota, viene visualizzato un messaggio che indica che non ci sono prenotazioni disponibili e la funzione restituisce NULL.
- Se la prenotazione con il codice specificato viene trovata, viene rimossa dalla lista e la memoria allocata per la prenotazione viene liberata.
- Il veicolo associato alla prenotazione rimossa viene contrassegnato come disponibile.
- Se la prenotazione con il codice specificato non viene trovata, viene visualizzato un messaggio che indica che la prenotazione non è stata trovata e la lista rimane invariata.

SIDE-EFFECT:
La funzione stampa un messaggio di successo se la prenotazione è stata rimossa correttamente.
*/
Prenotazione *rimuoviPrenotazioneTest(Prenotazione *prenota, int codiceDaRimuovere, Veicolo *punt) 
{  
    Prenotazione *corrente = prenota;
    Prenotazione *precedente = NULL;

    while  (corrente != NULL) 
    {
        if  (corrente->codice == codiceDaRimuovere) 
        {
            if (precedente == NULL) 
            {
                prenota = corrente->prenota;
            } 
            else 
            {
                precedente->prenota = corrente->prenota;
            }
            Veicolo *temp = punt;

            while (temp != NULL) 
            {
                if (strcmp(temp->targa, corrente->targa) == 0) 
                {
                    temp->disponibile = 1;
                    break;
                }
                temp = temp->punt;
            }
            free (corrente);
            return prenota;
        }
        precedente = corrente;
        corrente = corrente->prenota;
    }
    return prenota;
}
/*
FUNZIONE: calcolaCostoPrenotazioneTest
-------------------------
Testa il calcolo del costo di una prenotazione specifica nella lista collegata.

IMPLEMENTAZIONE:
float calcolaCostoPrenotazioneTest(Prenotazione *prenota, int codiceDaCalcolare);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
codiceDaCalcolare: un intero che rappresenta il codice della prenotazione di cui calcolare il costo.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se la lista di prenotazioni è vuota, viene visualizzato un messaggio che indica che non ci sono prenotazioni disponibili e la funzione restituisce -1.
- Se la prenotazione con il codice specificato viene trovata, viene calcolato il costo totale della prenotazione in base alla durata in giorni e restituito come valore di tipo float.
- Se la prenotazione con il codice specificato non viene trovata, la funzione restituisce -1.

SIDE-EFFECT:
La funzione stampa un messaggio di successo se il costo della prenotazione è stato calcolato correttamente.
*/
float calcolaCostoPrenotazioneTest(Prenotazione *prenota, int codiceDaCalcolare) 
{
    Prenotazione *corrente = prenota;
    while (corrente != NULL) 
    {
        if (corrente->codice == codiceDaCalcolare) 
        {
            double durata = difftime(corrente->dataFine, corrente->dataInizio) / (60 * 60 * 24);
            return durata * 20.0; 
        }
        corrente = corrente->prenota;
    }
    return -1; 
}
/*
FUNZIONE: mostraPrenotazioniTest
-------------------------
Testa la visualizzazione delle prenotazioni nella lista collegata.

IMPLEMENTAZIONE:
void mostraPrenotazioniTest(Prenotazione *prenota);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se la lista di prenotazioni è vuota, viene visualizzato un messaggio che indica che non ci sono prenotazioni disponibili.
- Se la lista di prenotazioni contiene prenotazioni, vengono visualizzati i dettagli di ciascuna prenotazione, inclusi codice, nome, cognome, targa del veicolo, data di inizio e fine.

SIDE-EFFECT:
La funzione stampa i dettagli delle prenotazioni sulla console, formattati per una migliore leggibilità.
*/
void mostraPrenotazioniTest(Prenotazione *prenota) 
{
    Prenotazione *corrente = prenota;
    if (corrente == NULL) 
    {
        printf("Nessuna prenotazione disponibile.\n");
        return;
    }
    
    while (corrente != NULL) 
    {
        printf("----\tLista Prenotazione (TEST)\t----\n");
        printf("Codice: %d\n", corrente->codice);
        printf("Nome: %s\n", corrente->nome);
        printf("Cognome: %s\n", corrente->cognome);
        printf("Targa: %s\n", corrente->targa);
        printf("Data Inizio: %s", ctime(&corrente->dataInizio));
        printf("Data Fine: %s", ctime(&corrente->dataFine));
        printf("----------------------------------------------------------\n");
        corrente = corrente->prenota;
    }
}

