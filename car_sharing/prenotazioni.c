#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "prenotazioni.h"
#include "veicoli.h"

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
                    scanf("%d", &codiceDaRimuovere); // Legge il codice della prenotazione da rimuovere

                    if (codiceDaRimuovere < 0) // Controlla se il codice è negativo
                    {
                        printf("Codice non valido.\n"); // Messaggio di errore
                        return;
                    }
                    else if (codiceDaRimuovere == 0) // Controlla se il codice è zero
                    {
                        printf("Nessuna prenotazione da rimuovere.\n"); // Messaggio di errore
                        return;
                    }

                   *prenota = rimuoviPrenotazione(prenota, codiceDaRimuovere, punt); 
                }
            break;

            case 3:
                {
                    int codiceDaModificare;
                    printf("Inserisci il codice della prenotazione da modificare: ");
                    scanf("%d", &codiceDaModificare); // Legge il codice della prenotazione da modificare

                    if (codiceDaModificare < 0) // Controlla se il codice è negativo
                    {
                        printf("Codice non valido.\n"); // Messaggio di errore
                        return;
                    }
                    else if (codiceDaModificare == 0) // Controlla se il codice è zero
                    {
                        printf("Nessuna prenotazione da modificare.\n"); // Messaggio di errore
                        return;
                    }

                    *prenota = modificaPrenotazione(prenota, codiceDaModificare); 
                }
            break;

            case 4: 
                {
                    int codiceDaCalcolare;
                    printf("Inserisci il codice della prenotazione di cui calcolare il costo: ");
                    scanf("%d", &codiceDaCalcolare); // Legge il codice della prenotazione di cui calcolare il costo

                    if (codiceDaCalcolare < 0) // Controlla se il codice è negativo
                    {
                        printf("Codice non valido.\n"); // Messaggio di errore
                        return;
                    }
                    else if (codiceDaCalcolare == 0) // Controlla se il codice è zero
                    {
                        printf("Nessuna prenotazione da calcolare.\n"); 
                        return;
                    }

                    calcolaCostoPrenotazione(*prenota, codiceDaCalcolare); // Chiama la funzione per calcolare il costo della prenotazione
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

float calcolaCostoPrenotazione(Prenotazione *prenota, int codiceDaCalcolare)
{
    printf("-----------------------\tCALCOLO COSTO PRENOTAZIONE\t-----------------------\n");
    if (prenota == NULL)
    {
        printf("NESSUNA PRENOTAZIONE DISPONIBILE. \n");
        return 0; // Restituisce la prenotazione vuota se non trovata
    }

    Prenotazione *corrente = prenota; 
    float costoTotale = 0.0; 

    printf("COSTO BASE: 20 euro al giorno\n");
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
        corrente = corrente->prenota; // Passa alla prossima prenotazione nella lista
    }    
    
    return costoTotale;
    premiInvio();   

}

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
        if (nododaeliminare->codice == codiceDaRimuovere) // Controlla se la targa corrisponde a quella da rimuovere
        {
            if (precedente == NULL) // Se è il primo nodo della lista
            {
                *prenota = nododaeliminare->prenota; // Aggiorna il puntatore alla lista
            }
            else
            {
                precedente->prenota = nododaeliminare->prenota; // Collega il nodo precedente al successivo
            }

            Veicolo *temp = *punt; // Ripristina la disponibilità del veicolo

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

Prenotazione *modificaPrenotazione(Prenotazione **prenota, int codiceDaModificare)
{
    Prenotazione *corrente = *prenota; // Puntatore alla prenotazione corrente

    printf("-----------------------\tMODIFICA PRENOTAZIONE\t-----------------------\n");
    if (prenota == NULL)
    {
        printf("NESSUNA PRENOTAZIONE DISPONIBILE. \n");
        return NULL; // Restituisce la prenotazione vuota se non trovata
    }
    
    int scelta=0;

    while(corrente != NULL)
    {
        if (corrente->codice == codiceDaModificare) // Controlla se il codice corrisponde a quello da modificare
        {
            break; // Esci dal ciclo se trovato
        }
        corrente = corrente->prenota; // Passa alla prossima prenotazione nella lista
    }

    printf("Che attributo vuoi modificare?\n");
    printf("1. Nome\n");
    printf("2. Cognome\n");
    printf("3. Data fine\n");
    printf("Scelta: ");
    scanf("%d", &scelta); // Legge la scelta dell'utente

    switch(scelta)
    {
        case 1:
        {
            char nuovoNome[50];
            printf("Inserisci il nuovo nome: ");
            scanf(" %49s", nuovoNome); // Limita l'input a 49 caratteri per evitare overflow

            strcpy((*prenota)->nome, nuovoNome);
            printf("Nome modificato con successo.\n"); // Messaggio di conferma
        }
        break;

        case 2:
        {
            char nuovoCognome[50];
            printf("Inserisci il nuovo cognome: ");
            scanf(" %49s", nuovoCognome); // Limita l'input a 49 caratteri per evitare overflow

            strcpy((*prenota)->cognome, nuovoCognome); // Copia il nuovo cognome nella struttura della prenotazione
            printf("Cognome modificato con successo.\n"); // Messaggio di conferma
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

int generaCodice()
{
    static int ultimoCodice = 0;
    ultimoCodice++; 
    return ultimoCodice;
}

