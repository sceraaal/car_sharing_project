#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "prenotazioni.h"
#include "veicoli.h"

/*
In questo file "prenotazioni.c" sono implementate le funzioni per la gestione delle prenotazioni.
Le funzioni permettono di aggiungere, rimuovere, modificare e calcolare il costo delle prenotazioni.
Le funzioni utilizzano strutture dati per gestire le informazioni sulle prenotazioni e sui veicoli.
Le funzioni sono organizzate in modo da essere facilmente richiamabili dal menu principale del programma.
Le funzioni sono strutturate per gestire errori comuni, come la gestione di codici di prenotazione non validi o veicoli non disponibili.
*/

/*
FUNZIONE: menuPrenotazioni
-------------------------
Mostra un menu per la gestione delle prenotazioni, permettendo all'utente di aggiungere, rimuovere, modificare o calcolare il costo delle prenotazioni.

IMPLEMENTAZIONE:
void menuPrenotazioni(Prenotazione **prenota, Veicolo **punt);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se l'utente sceglie di aggiungere una prenotazione, la funzione chiama `aggiungiPrenotazione` per aggiungere una o più prenotazioni alla lista.
- Se l'utente sceglie di rimuovere una prenotazione, la funzione chiama `rimuoviPrenotazione` per rimuovere una prenotazione specifica dalla lista.
- Se l'utente sceglie di modificare una prenotazione, la funzione chiama `modificaPrenotazione` per modificare i dettagli di una prenotazione specifica nella lista.
- Se l'utente sceglie di calcolare il costo di una prenotazione, la funzione chiama `calcolaCostoPrenotazione` per calcolare il costo di una prenotazione specifica.
- Se l'utente sceglie di mostrare le prenotazioni disponibili, la funzione chiama `mostraPrenotazioni` per visualizzare le prenotazioni presenti nella lista.
- Se l'utente sceglie di tornare al menu principale, la funzione termina e ritorna al menu principale.

SIDE-EFFECT:
- La funzione stampa un menu interattivo per l'utente, richiedendo l'input per le operazioni da eseguire.
*/
void menuPrenotazioni(Prenotazione **prenota, Veicolo **punt)
{
    int scelta = 0;

    do
    {
        printf("-------------------------MENU PRENOTAZIONI-----------------------\n");
        printf("Benvenuto nel menu prenotazioni! (Inserisci il numero per la scelta)\n");
        printf("1. Aggiungi una prenotazione\n");
        printf("2. Rimuovere una prenotazione\n");
        printf("3. Modificare una prenotazione\n");
        printf("4. Calcolare il costo di una prenotazione\n");
        printf("5. Mostrare le prenotazioni disponibili\n");
        printf("6. Tornare al menu principale\n");
        printf("Scelta: ");
        scanf("%d", &scelta); 

        switch(scelta)
        {
            case 1:
                aggiungiPrenotazione(prenota, punt);
            break;

            case 2:
                {
                    int codiceDaRimuovere; 
                    printf("Inserisci il codice della prenotazione da rimuovere: ");
                    scanf("%d", &codiceDaRimuovere); 

                    if (codiceDaRimuovere < 0) 
                    {
                        printf("Codice non valido.\n"); 
                        return;
                    }
                    else if (codiceDaRimuovere == 0) 
                    {
                        printf("Nessuna prenotazione da rimuovere.\n"); 
                        return;
                    }

                   *prenota = rimuoviPrenotazione(prenota, codiceDaRimuovere, punt); 
                }
            break;

            case 3:
                {
                    int codiceDaModificare;
                    printf("Inserisci il codice della prenotazione da modificare: ");
                    scanf("%d", &codiceDaModificare); 

                    if (codiceDaModificare < 0) 
                    {
                        printf("Codice non valido.\n"); 
                        return;
                    }
                    else if (codiceDaModificare == 0) 
                    {
                        printf("Nessuna prenotazione da modificare.\n"); 
                        return;
                    }

                    *prenota = modificaPrenotazione(prenota, codiceDaModificare); 
                }
            break;

            case 4: 
                {
                    int codiceDaCalcolare;
                    printf("Inserisci il codice della prenotazione di cui calcolare il costo: ");
                    scanf("%d", &codiceDaCalcolare); 

                    if (codiceDaCalcolare < 0) 
                    {
                        printf("Codice non valido.\n"); 
                        return;
                    }
                    else if (codiceDaCalcolare == 0) 
                    {
                        printf("Nessuna prenotazione da calcolare.\n"); 
                        return;
                    }

                    calcolaCostoPrenotazione(*prenota, codiceDaCalcolare); 
                }
            break;

            case 5:
                mostraPrenotazioni(*prenota);           
            break;

            case 6:
                printf("Tornando al menu principale...\n");
            break;

            default:
                printf("Scelta non valida. Riprova.\n");
        }   
    }
    while(scelta != 6);

}
/*
FUNZIONE: aggiungiPrenotazione
-------------------------
Aggiunge una o più prenotazioni alla lista collegata di prenotazioni, 
richiedendo all'utente i dettagli della prenotazione e gestendo la disponibilità dei veicoli.

IMPLEMENTAZIONE:
void aggiungiPrenotazione(Prenotazione **prenota, Veicolo **punt);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se l'utente sceglie di mostrare la lista dei veicoli, la funzione chiama `mostraVeicoli` per visualizzare i veicoli disponibili.
- Se l'utente sceglie di aggiungere prenotazioni, la funzione richiede all'utente di inserire i dettagli della prenotazione (nome, cognome, targa del veicolo).
- La funzione verifica la disponibilità del veicolo con la targa specificata e, se disponibile, lo segna come non disponibile.
- La funzione imposta automaticamente la data di inizio della prenotazione all'ora corrente e richiede all'utente di inserire la data di fine della prenotazione.
- La funzione calcola la durata della prenotazione in giorni e genera un codice univoco per la prenotazione.
- La prenotazione viene aggiunta alla lista collegata di prenotazioni e viene visualizzato un messaggio di conferma.
- Se il veicolo con la targa specificata non viene trovato o non è disponibile, viene visualizzato un messaggio di errore e la prenotazione non viene aggiunta.
- Se la data di fine inserita non è valida, viene visualizzato un messaggio di errore e la prenotazione non viene aggiunta.

SIDE-EFFECT:
- La funzione richiede l'input dell'utente per i dettagli della prenotazione e per la data di fine.
- La funzione stampa messaggi di stato per informare l'utente sull'aggiunta della prenotazione, sulla disponibilità del veicolo e sulla durata della prenotazione.
*/
void aggiungiPrenotazione(Prenotazione **prenota, Veicolo **punt)
{
    printf("-----------------------\tAGGIUNTA PRENOTAZIONE\t-----------------------\n");
    printf("Vuoi che ti venga mostrata la lista dei veicoli? (1 per si, 0 per no): ");
    int scelta;
    scanf("%d", &scelta);

    if(scelta == 1)
    {
        mostraVeicoli(*punt, 0);
        premiInvio();
    }
    else
    {
        printf("Non verra' mostrata la lista dei veicoli.\n");
    }

    int numPrenotazioni;

    printf("-----------------------\tAGGIUNTA PRENOTAZIONE\t-----------------------\n");
    printf("Quante prenotazioni vuoi aggiungere? ");
    scanf("%d", &numPrenotazioni);

    for(int i=0; i<numPrenotazioni; i++)
    {      
        Prenotazione *nuovaPrenotazione = (Prenotazione *)malloc(sizeof(Prenotazione));

        if (nuovaPrenotazione == NULL)
        {
            printf("-----------------------\tAGGIUNTA PRENOTAZIONE\t-----------------------\n");
            printf("Errore nell'allocazione della memoria per la prenotazione.\n");
            return;
        }
        else
        {
            printf("---------------------\tAGGIUNTA PRENOTAZIONE\t-----------------------\n");
            printf("Allocazione della memoria per la prenotazione riuscita.\n");
            printf("---------------------\tAGGIUNTA PRENOTAZIONE\t-----------------------\n");
        }

        printf("Aggiunta della prenotazione numero %d:\n", i+1);
        printf("Inserisci il nome: ");
        scanf(" %49s", nuovaPrenotazione->nome);
        printf("Inserisci il cognome: ");
        scanf(" %49s", nuovaPrenotazione->cognome);
        printf("Inserisci il numero di targa del veicolo: ");
        scanf(" %10s", nuovaPrenotazione->targa);

        Veicolo *temp = *punt;
        int veicoloTrovato = 0;

        while (temp != NULL) 
        {
            if (strcmp(temp->targa, nuovaPrenotazione->targa) == 0) 
            {
                if (temp->disponibile == 1) 
                {
                    temp->disponibile = 0;
                    veicoloTrovato = 1;
                    break;
                } 
                else 
                {
                    printf("Veicolo non disponibile.\n");
                    free(nuovaPrenotazione); 
                    return;
                }
            }
            temp = temp->punt; 
        }

        if (!veicoloTrovato) 
        {
            printf("Veicolo con targa %s non trovato.\n", nuovaPrenotazione->targa);
            free(nuovaPrenotazione);
            return;
        }

        time_t ora_corrente;
        time(&ora_corrente);

        nuovaPrenotazione->dataInizio = ora_corrente;
        printf("Data di inizio impostata automaticamente: %s", ctime(&nuovaPrenotazione->dataInizio)); 

        struct tm dataFine = {0}; 
        printf("Inserisci la data di fine (formato: gg-mm-aaaa)\n Nota: il giorno e il mese devono essere compresi tra 1 e 31): ");
        scanf("%d-%d-%d", &dataFine.tm_mday, &dataFine.tm_mon, &dataFine.tm_year);

        while (temp != NULL)
        {
            if(dataFine.tm_mday < 1 || dataFine.tm_mday > 31 || dataFine.tm_mon < 1 || dataFine.tm_mon > 12)
            {
                printf("Formato data non valido.\n");
                free(nuovaPrenotazione);
                temp->disponibile = 1; 
                return;
            }
            else if(dataFine.tm_year < ora_corrente || dataFine.tm_mday < ora_corrente || dataFine.tm_mon < ora_corrente)
            {
                printf("Data non valida.\n");
                free(nuovaPrenotazione);
                temp->disponibile = 1;
                return;
            }
        }
        dataFine.tm_year -= 1900;
        dataFine.tm_mon -= 1;

        nuovaPrenotazione->dataFine = mktime(&dataFine);

        if(nuovaPrenotazione->dataFine == (time_t)-1) 
        {
            printf("Errore nella conversione della data di fine.\n");
            free(nuovaPrenotazione);
            return;
        }

        double durata = difftime(nuovaPrenotazione->dataFine, nuovaPrenotazione->dataInizio) / (60 * 60 * 24);
        printf("Durata della prenotazione: %.0f giorni\n", durata);

        nuovaPrenotazione->codice = generaCodice();

        printf("---------------------\tAGGIUNTA PRENOTAZIONE\t-----------------------\n");
        

        printf("Collegando la nuova prenotazione alla lista...\n");

        nuovaPrenotazione->prenota = *prenota;
        *prenota = nuovaPrenotazione;
        printf("Prenotazione aggiunta con successo!\n");

        printf("---------------------\tAGGIUNTA PRENOTAZIONE\t-----------------------\n");

        if (numPrenotazioni != 0) 
        {
            printf("Dettagli della prenotazione numero %d: \n", i + 1);
            printf("Nome: %s\n", nuovaPrenotazione->nome); 
            printf("Cognome: %s\n", nuovaPrenotazione->cognome); 
            printf("Durata: %.0f giorni\n", durata); 
            printf("Codice: %d\n", nuovaPrenotazione->codice); 
            printf("----------------------------------------------------------\n"); 
        }
        else
        {
            printf("Aggiunta della prenotazione riuscita.\n"); 
            printf("Nome: %s\n", nuovaPrenotazione->nome); 
            printf("Cognome: %s\n", nuovaPrenotazione->cognome);
            printf("Durata: %.0f giorni\n", difftime(nuovaPrenotazione->dataFine, nuovaPrenotazione->dataInizio) / (60 * 60 * 24));
            printf("Codice: %d\n", nuovaPrenotazione->codice); 
            printf("----------------------------------------------------------\n"); 
        }
    }
    printf("Prenotazione aggiunta con successo!\n"); 

    return; 
}
/*
FUNZIONE: mostraPrenotazioni
-------------------------
Visualizza le prenotazioni presenti nella lista collegata, mostrando i dettagli di ciascuna prenotazione.

IMPLEMENTAZIONE:
void mostraPrenotazioni(Prenotazione *prenota);

PARAMETRI:
prenota: un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.

POST-CONDIZIONI:
- Se la lista di prenotazioni è vuota, viene visualizzato un messaggio che indica che non ci sono prenotazioni effettuate.
- Se la lista di prenotazioni contiene prenotazioni, vengono visualizzati i dettagli di ciascuna prenotazione, inclusi nome, cognome, targa del veicolo, data di inizio e fine, e codice della prenotazione.
- La funzione stampa un messaggio di separazione tra le prenotazioni per una migliore leggibilità.

SIDE-EFFECT:
- La funzione stampa i dettagli delle prenotazioni sulla console.
*/
void mostraPrenotazioni(Prenotazione *prenota)
{
    printf("-----------------------\tMOSTRA PRENOTAZIONI\t-----------------------\n");
    if (prenota == NULL)
    {
        printf("NESSUNA PRENOTAZIONE EFFETTUATA. \n");
        return;
    }

    Prenotazione *corrente = prenota;

    while(corrente != NULL)
    {
        printf("Nome: %s\n", corrente->nome);
        printf("Cognome: %s\n", corrente->cognome);
        printf("Targa: %s\n", corrente->targa);
        printf("Data inizio: %s", ctime(&corrente->dataInizio));
        printf("Data fine: %s", ctime(&corrente->dataFine));
        printf("Codice: %d\n", corrente->codice);
        printf("----------------------------------------------------------\n");

        corrente = corrente->prenota;
    }
    premiInvio();
    return;
}
/*
FUNZIONE: calcolaCostoPrenotazione
-------------------------
Calcola il costo di una prenotazione specifica, applicando sconti in base alla durata della prenotazione.

IMPLEMENTAZIONE:
float calcolaCostoPrenotazione(Prenotazione *prenota, int codiceDaCalcolare);

PARAMETRI:
prenota: un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
codiceDaCalcolare: un intero che rappresenta il codice della prenotazione di cui calcolare il costo.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.
- Il codiceDaCalcolare deve essere un intero positivo che rappresenta il codice di una prenotazione esistente.

POST-CONDIZIONI:
- Se la lista di prenotazioni è vuota, viene visualizzato un messaggio che indica che non ci sono prenotazioni disponibili e la funzione restituisce 0.
- Se la prenotazione con il codice specificato viene trovata, viene calcolato il costo totale della prenotazione in base alla durata in giorni.
- Il costo base è di 20 euro al giorno e vengono applicati sconti in base alla durata della prenotazione:
  - Sconto del 50% per durate superiori a 100 giorni.
  - Sconto del 40% per durate superiori a 60 giorni.
  - Sconto del 30% per durate superiori a 30 giorni.
  - Sconto del 20% per durate superiori a 20 giorni.
  - Sconto del 10% per durate superiori a 10 giorni.
- Se la durata della prenotazione è inferiore a 10 giorni, non viene applicato alcuno sconto.
- Viene visualizzato un riepilogo dei dettagli della prenotazione, inclusi il costo totale, la durata, il codice, la targa, il nome, il cognome e le date di inizio e fine.
- La funzione restituisce il costo totale della prenotazione.

SIDE-EFFECT:
- La funzione richiede l'input dell'utente per il codice della prenotazione da calcolare.
- La funzione stampa i dettagli della prenotazione e il costo totale sulla console.
*/
float calcolaCostoPrenotazione(Prenotazione *prenota, int codiceDaCalcolare)
{
    printf("-----------------------\tCALCOLO COSTO PRENOTAZIONE\t-----------------------\n");
    if (prenota == NULL)
    {
        printf("NESSUNA PRENOTAZIONE DISPONIBILE. \n");
        return 0; 
    }

    Prenotazione *corrente = prenota; 
    float costoTotale = 0.0; 

    printf("COSTO BASE: 20 euro al giorno\n");
    printf("SCONTI DISPONIBILI:\n");

    while (corrente != NULL) 
    {
        if (corrente->codice == codiceDaCalcolare) 
        {
            double durata = difftime(corrente->dataFine, corrente->dataInizio) / (60 * 60 * 24);
            float costoBase = 20.0; 
            costoTotale = costoBase * durata;

            if (durata > 100)
            {
                costoTotale *= 0.5; // 50% di sconto
                printf("Hai diritto ad uno sconto del 50 percento!!\n");
            }
            else if (durata > 60)
            {
                costoTotale *= 0.6; // 40% di sconto
                printf("Hai diritto ad uno sconto del 40 percento!!\n");
            }
            else if (durata > 30)
            {
                costoTotale *= 0.7; // 30% di sconto
                printf("Hai diritto ad uno sconto del 30 percento!!\n");
            }
            else if (durata > 20)
            {
                costoTotale *= 0.8; // 20% di sconto
                printf("Hai diritto ad uno sconto del 20 percento!!\n");
            }
            else if (durata > 10)
            {
                costoTotale *= 0.9; // 10% di sconto
                printf("Hai diritto ad uno sconto del 10 percento!!\n");
            }
            else
            {
                printf("Non ci sono sconti disponibili");
            }
            printf("\n");
            printf("Dettagli della prenotazione:\n");
            printf("Costo totale: %.2f euro\n", costoTotale);
            printf("Durata della prenotazione: %.0f giorni\n", durata); 
            printf("Codice: %d\n", corrente->codice); 
            printf("Targa: %s\n", corrente->targa); 
            printf("Nome: %s\n", corrente->nome); 
            printf("Cognome: %s\n", corrente->cognome);
            printf("Data inizio: %s", ctime(&corrente->dataInizio));
            printf("Data fine: %s", ctime(&corrente->dataFine));
            printf("----------------------------------------------------------\n"); 
             
        }
        corrente = corrente->prenota; 
    }    
    
    return costoTotale;
    premiInvio();   

}
/*
FUNZIONE: rimuoviPrenotazione
-------------------------
Rimuove una prenotazione specifica dalla lista collegata di prenotazioni.

IMPLEMENTAZIONE:
Prenotazione *rimuoviPrenotazione(Prenotazione **prenota, int codiceDaRimuovere, Veicolo **punt);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
codiceDaRimuovere: un intero che rappresenta il codice della prenotazione da rimuovere.
punt: un puntatore a un puntatore di tipo Veicolo, che rappresenta la testa della lista collegata di veicoli.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.
- Il codiceDaRimuovere deve essere un intero positivo che rappresenta il codice di una prenotazione esistente.
- Il puntatore punt deve essere inizializzato a NULL o a un nodo esistente della lista di veicoli.

POST-CONDIZIONI:
- Se la lista di prenotazioni è vuota, viene visualizzato un messaggio che indica che non ci sono prenotazioni disponibili e la funzione restituisce NULL.
- Se la prenotazione con il codice specificato viene trovata, viene rimossa dalla lista e la memoria allocata per la prenotazione viene liberata.
- Il veicolo associato alla prenotazione rimossa viene contrassegnato come disponibile.
- Se la prenotazione con il codice specificato non viene trovata, viene visualizzato un messaggio che indica che la prenotazione non è stata trovata e la lista rimane invariata.
- La funzione restituisce la testa aggiornata della lista di prenotazioni.

SIDE-EFFECT:
- La funzione stampa messaggi di stato per informare l'utente sulla rimozione della prenotazione e sulla disponibilità del veicolo.
*/
Prenotazione *rimuoviPrenotazione(Prenotazione **prenota, int codiceDaRimuovere, Veicolo **punt)
{
    Prenotazione *nododaeliminare = *prenota;
    Prenotazione *precedente = NULL; 

    printf("-----------------------\tRIMOZIONE PRENOTAZIONE\t-----------------------\n");
    if (prenota == NULL)
    {
        printf("NESSUNA PRENOTAZIONE DISPONIBILE. \n");
        return NULL;
    }

    while (nododaeliminare != NULL)
    {
        if (nododaeliminare->codice == codiceDaRimuovere)
        {
            if (precedente == NULL) 
            {
                *prenota = nododaeliminare->prenota; 
            }
            else
            {
                precedente->prenota = nododaeliminare->prenota; 
            }

            Veicolo *temp = *punt; 

            while (temp != NULL)
            {
                if (strcmp(temp->targa, nododaeliminare->targa) == 0)
                {
                    temp->disponibile = 1;
                    break;
                }
                temp = temp->punt;
            }

            free(nododaeliminare); 
            printf("Prenotazione rimossa con successo.\n"); 

        }
        else
        {
            printf("Prenotazione non trovata.\n");
        }

        precedente = nododaeliminare;
        nododaeliminare = nododaeliminare->prenota; 
    }
    premiInvio();
    return *prenota;
}
/*
FUNZIONE: modificaPrenotazione
-------------------------
Modifica i dettagli di una prenotazione specifica nella lista collegata di prenotazioni.

IMPLEMENTAZIONE:
Prenotazione *modificaPrenotazione(Prenotazione **prenota, int codiceDaModificare);

PARAMETRI:
prenota: un puntatore a un puntatore di tipo Prenotazione, che rappresenta la testa della lista collegata di prenotazioni.
codiceDaModificare: un intero che rappresenta il codice della prenotazione da modificare.

PRE-CONDIZIONI:
- Il puntatore prenota deve essere inizializzato a NULL o a un nodo esistente della lista di prenotazioni.
- Il codiceDaModificare deve essere un intero positivo che rappresenta il codice di una prenotazione esistente.

POST-CONDIZIONI:
- Se la lista di prenotazioni è vuota, viene visualizzato un messaggio che indica che non ci sono prenotazioni disponibili e la funzione restituisce NULL.
- Se la prenotazione con il codice specificato viene trovata, l'utente può modificare uno dei seguenti attributi: nome, cognome o data di fine.
- La funzione richiede all'utente di scegliere quale attributo modificare e di inserire il nuovo valore.
- Se l'utente sceglie di modificare il nome o il cognome, viene richiesto di inserire il nuovo valore e il campo corrispondente viene aggiornato.
- Se l'utente sceglie di modificare la data di fine, viene richiesto di inserire la nuova data in un formato specifico e il campo corrispondente viene aggiornato.
- Se la data di fine inserita non è valida, viene visualizzato un messaggio di errore e la prenotazione non viene modificata.
- Se la prenotazione con il codice specificato non viene trovata, viene visualizzato un messaggio che indica che la prenotazione non è stata trovata e la lista rimane invariata.
- La funzione restituisce la prenotazione modificata.

SIDE-EFFECT:
- La funzione richiede l'input dell'utente per il codice della prenotazione da modificare e per i nuovi valori degli attributi.
- La funzione stampa messaggi di stato per informare l'utente sulla modifica della prenotazione e sui dettagli aggiornati.

*/
Prenotazione *modificaPrenotazione(Prenotazione **prenota, int codiceDaModificare)
{
    Prenotazione *corrente = *prenota; 

    printf("-----------------------\tMODIFICA PRENOTAZIONE\t-----------------------\n");
    if (prenota == NULL)
    {
        printf("NESSUNA PRENOTAZIONE DISPONIBILE. \n");
        return NULL; 
    }
    
    int scelta=0;

    while(corrente != NULL)
    {
        if (corrente->codice == codiceDaModificare) 
        {
            break; 
        }
        corrente = corrente->prenota; 
    }

    printf("Che attributo vuoi modificare?\n");
    printf("1. Nome\n");
    printf("2. Cognome\n");
    printf("3. Data fine\n");
    printf("Scelta: ");
    scanf("%d", &scelta); 

    switch(scelta)
    {
        case 1:
        {
            char nuovoNome[50];
            printf("Inserisci il nuovo nome: ");
            scanf(" %49s", nuovoNome); 

            strcpy((*prenota)->nome, nuovoNome);
            printf("Nome modificato con successo.\n"); 
        }
        break;

        case 2:
        {
            char nuovoCognome[50];
            printf("Inserisci il nuovo cognome: ");
            scanf(" %49s", nuovoCognome); 

            strcpy((*prenota)->cognome, nuovoCognome); 
            printf("Cognome modificato con successo.\n"); 
        }
        break;

        case 3:
        {
            struct tm dataFine = {0};
            printf("Inserisci la nuova data di fine (formato gg-mm-aaaa): ");
            scanf("%d-%d-%d", &dataFine.tm_mday, &dataFine.tm_mon, &dataFine.tm_year); 

            dataFine.tm_year -= 1900; // Anno a partire dal 1900
            dataFine.tm_mon -= 1; // Mese a partire da 0
            (*prenota)->dataFine = mktime(&dataFine); 

            if ((*prenota)->dataFine == (time_t)-1) 
            {
                printf("Errore nella conversione della data di fine.\n");
                return *prenota;
            }
            printf("Data di fine modificata con successo.\n"); 
        }
        break;

        default:
            printf("Scelta non valida. Riprova.\n"); 
            break;     
    }
    printf("-----------------------------------------------------------\n"); 
    premiInvio();
    return *prenota;
}
/*
FUNZIONE: generaCodice
-------------------------
Genera un codice univoco per una prenotazione, incrementando un contatore statico.

IMPLEMENTAZIONE:
int generaCodice();

PARAMETRI:
Nessuno.

PRE-CONDIZIONI:
- Nessuna condizione predefinita.

POST-CONDIZIONI:
- La funzione restituisce un intero che rappresenta il codice univoco generato per la prenotazione.
- Il codice è univoco e incrementale, partendo da 1 e aumentando di 1 per ogni chiamata alla funzione.

SIDE-EFFECT:
- La funzione utilizza una variabile statica per mantenere lo stato del codice generato tra le chiamate.
*/
int generaCodice()
{
    static int ultimoCodice = 0;
    ultimoCodice++; 
    return ultimoCodice;
}

