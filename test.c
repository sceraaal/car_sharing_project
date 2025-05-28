#include <stdio.h>
#include <assert.h>

#include "veicoli.h"
#include "prenotazioni.h"

/*
In questo file "test.c" sono presenti i test per le funzioni di gestione dei veicoli e delle prenotazioni.
I test sono stati creati per verificare il corretto funzionamento delle funzioni di aggiunta, rimozione, modifica e visualizzazione dei veicoli e delle prenotazioni.
I test utilizzano asserzioni per verificare che le funzioni restituiscano i risultati attesi.
I test sono organizzati in funzioni separate per ogni operazione e vengono eseguiti in sequenza nel main.
*/

/*
FUNZIONE: testAggiungiVeicolo
-------------------------
Testa la funzione di aggiunta di un veicolo alla lista collegata.

IMPLEMENTAZIONE:
void testAggiungiVeicolo();

PARAMETRI:
punt: un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se l'aggiunta del veicolo ha successo, il puntatore punt non deve essere NULL e deve contenere i dati del veicolo aggiunto.
- Se l'aggiunta del veicolo fallisce, il puntatore punt deve rimanere NULL.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se il veicolo è stato aggiunto correttamente.
*/
void testAggiungiVeicolo() 
{
    Veicolo *punt = NULL;
    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);
        
    assert(punt != NULL);

    assert(strcmp(punt->targa, "AA123BB") == 0);
    printf("\n");
}
/*
FUNZIONE: testRimuoviVeicolo
-------------------------
Testa la funzione di rimozione di un veicolo dalla lista collegata.

IMPLEMENTAZIONE:
void testRimuoviVeicolo();

PARAMETRI:
punt: un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.
POST-CONDIZIONI:
- Se la rimozione del veicolo ha successo, il puntatore punt deve essere NULL.
- Se la rimozione del veicolo fallisce, il puntatore punt deve rimanere invariato e non deve essere NULL.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se il veicolo è stato rimosso correttamente.
*/
void testRimuoviVeicolo() 
{
    Veicolo *punt = NULL;
    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);    
    assert(punt != NULL);

    char targaDaRimuovere[20];
    strcpy(targaDaRimuovere, punt->targa); 
    punt = rimuoviVeicoloTest(&punt, targaDaRimuovere);
    assert(punt == NULL); 
    printf("\n");
}
/*
FUNZIONE: testModificaVeicolo
-------------------------
Testa la funzione di modifica di un veicolo nella lista collegata.

IMPLEMENTAZIONE:
void testModificaVeicolo();

PARAMETRI:
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la modifica del veicolo ha successo, il puntatore punt deve contenere i dati del veicolo modificato.
- Se la modifica del veicolo fallisce, il puntatore punt deve rimanere invariato e non deve essere NULL.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se il veicolo è stato modificato correttamente.
*/
void testModificaVeicolo() 
{
    Veicolo *punt = NULL;
    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);
    assert(punt != NULL);

    punt = modificaVeicoloTest(&punt, "AA123BB");
    assert(punt != NULL);
    assert(strcmp(punt->modello, "Punto") == 0);
    printf("\n");
}
/*
FUNZIONE: testAggiungiPrenotazione
-------------------------
Testa la funzione di aggiunta di una prenotazione alla lista collegata.

IMPLEMENTAZIONE:
void testAggiungiPrenotazione();

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se l'aggiunta della prenotazione ha successo, il puntatore prenota non deve essere NULL e deve contenere i dati della prenotazione aggiunta.
- Se l'aggiunta della prenotazione fallisce, il puntatore prenota deve rimanere NULL.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se la prenotazione è stata aggiunta correttamente.
*/
void testAggiungiPrenotazione() 
{
    Prenotazione *prenota = NULL;
    Veicolo *punt = NULL;

    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);

    time_t dataFine = time(NULL) + 86400 * 5; // 5 giorni dopo oggi

    prenota = aggiungiPrenotazioneTest(prenota, punt, "Mario", "Rossi", "AA123BB", dataFine, 1);
    assert(prenota != NULL);
    printf("\n");
}
/*
FUNZIONE: testModificaPrenotazione
-------------------------
Testa la funzione di modifica di una prenotazione nella lista collegata.

IMPLEMENTAZIONE:
void testModificaPrenotazione();

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se la modifica della prenotazione ha successo, il puntatore prenota deve contenere i dati della prenotazione modificata.
- Se la modifica della prenotazione fallisce, il puntatore prenota deve rimanere invariato e non deve essere NULL.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se la prenotazione è stata modificata correttamente.
*/
void testModificaPrenotazione() 
{
    Prenotazione *prenota = NULL;
    Veicolo *punt = NULL;
    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);

    time_t dataFine = time(NULL) + 86400 * 5;
    prenota = aggiungiPrenotazioneTest(prenota, punt, "Mario", "Rossi", "AA123BB", dataFine, 1);

    prenota = modificaPrenotazioneTest(prenota, prenota->codice);
    assert(prenota != NULL);
    printf("\n");
}
/*
FUNZIONE: testRimuoviPrenotazione
-------------------------
Testa la funzione di rimozione di una prenotazione dalla lista collegata.

IMPLEMENTAZIONE:
void testRimuoviPrenotazione();

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se la rimozione della prenotazione ha successo, il puntatore prenota deve essere NULL.
- Se la rimozione della prenotazione fallisce, il puntatore prenota deve rimanere invariato e non deve essere NULL.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se la prenotazione è stata rimossa correttamente.
*/
void testRimuoviPrenotazione() 
{
    Prenotazione *prenota = NULL;
    Veicolo *punt = NULL;
    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);

    time_t dataFine = time(NULL) + 86400 * 5;
    prenota = aggiungiPrenotazioneTest(prenota, punt, "Mario", "Rossi", "AA123BB", dataFine, 1);

    int codiceDaRimuovere = prenota->codice;
    prenota = rimuoviPrenotazioneTest(prenota, codiceDaRimuovere, punt);
    assert(prenota == NULL);
    printf("\n");
}
/*
FUNZIONE: testCalcolaCostoPrenotazione
-------------------------
Testa la funzione di calcolo del costo di una prenotazione.

IMPLEMENTAZIONE:
void testCalcolaCostoPrenotazione();

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se il calcolo del costo della prenotazione ha successo, la funzione restituisce un valore di tipo float maggiore o uguale a 0.
- Se il calcolo del costo della prenotazione fallisce, la funzione restituisce 0.

SIDE-EFFECT:
- La funzione stampa un messaggio di successo se il costo della prenotazione è stato calcolato correttamente.
*/
void testCalcolaCostoPrenotazione() 
{
    Prenotazione *prenota = NULL;
    Veicolo *punt = NULL;
    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);

    time_t dataFine = time(NULL) + 86400 * 5;
    prenota = aggiungiPrenotazioneTest(prenota, punt, "Mario", "Rossi", "AA123BB", dataFine, 1);

    float costo = calcolaCostoPrenotazioneTest(prenota, prenota->codice);
    assert(costo >= 0);
    printf("\n");
}
/*
FUNZIONE: testMostraPrenotazioni
-------------------------
Testa la funzione di visualizzazione delle prenotazioni nella lista collegata.

IMPLEMENTAZIONE:
void testMostraPrenotazioni();

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se la visualizzazione delle prenotazioni ha successo, la funzione stampa i dettagli di ciascuna prenotazione sulla console.
- Se la visualizzazione delle prenotazioni fallisce, la funzione stampa un messaggio che indica che non ci sono prenotazioni effettuate.

SIDE-EFFECT:
La funzione stampa un messaggio di successo se le prenotazioni sono state visualizzate correttamente.
*/
void testMostraPrenotazioni() 
{
    Prenotazione *prenota = NULL;
    Veicolo *punt = NULL;
    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);

    time_t dataFine = time(NULL) + 86400 * 5;
    prenota = aggiungiPrenotazioneTest(prenota, punt, "Mario", "Rossi", "AA123BB", dataFine, 1);

    mostraPrenotazioniTest(prenota);
    printf("\n");
}
/*
FUNZIONE: testMostraVeicoli
-------------------------
Testa la funzione di visualizzazione dei veicoli nella lista collegata.

IMPLEMENTAZIONE:
void testMostraVeicoli();

PARAMETRI:
punt: un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la visualizzazione dei veicoli ha successo, la funzione stampa i dettagli di ciascun veicolo sulla console.
- Se la visualizzazione dei veicoli fallisce, la funzione stampa un messaggio che indica che non ci sono veicoli disponibili.

SIDE-EFFECT:
La funzione stampa un messaggio di successo se i veicoli sono stati visualizzati correttamente.
*/
void testMostraVeicoli() 
{
    Veicolo *punt = NULL;
    punt = aggiungiVeicoloTest(punt, "AA123BB", "Punto", 1);
    mostraVeicoliTest(punt, 0);
    printf("\n");
}
/*
FUNZIONE: main
-------------------------
Funzione principale che esegue tutti i test delle funzioni di gestione dei veicoli e delle prenotazioni.

IMPLEMENTAZIONE:
int main();

PARAMETRI:
Nessuno.

PRE-CONDIZIONI:
- Nessuna condizione predefinita.

POST-CONDIZIONI:
- Se tutti i test hanno successo, la funzione stampa un messaggio che indica che tutti i test sono stati superati con successo.
- Se uno o più test falliscono, la funzione termina con un errore.

SIDE-EFFECT:
- La funzione stampa i risultati dei test sulla console, indicando se ciascun test è stato superato o meno.
*/
int main()
{
    printf("Inizio dei test...\n");
    
    testAggiungiVeicolo();
    printf("Test di aggiunta veicolo SUPERATO.\n");

    testRimuoviVeicolo();
    printf("Test di rimozione veicolo SUPERATO.\n");

    testModificaVeicolo();
    printf("Test di modifica veicolo SUPERATO.\n");

    testAggiungiPrenotazione();
    printf("Test di aggiunta prenotazione SUPERATO.\n");

    testModificaPrenotazione();
    printf("Test di modifica prenotazione SUPERATO.\n");

    testRimuoviPrenotazione();
    printf("Test di rimozione prenotazione SUPERATO.\n");

    testCalcolaCostoPrenotazione();
    printf("Test di calcolo costo prenotazione SUPERATO.\n");

    testMostraPrenotazioni();
    printf("Test di visualizzazione prenotazioni SUPERATO.\n");

    testMostraVeicoli();
    printf("Test di visualizzazione veicoli SUPERATO.\n");

    printf("Tutti i test sono stati SUPERATI con successo!\n");
    
    return 0;
}