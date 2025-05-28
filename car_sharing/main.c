#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "veicoli.h"
#include "prenotazioni.h"
/*
Questo è un programma di gestione di un sistema di car sharing.
Permette di aggiungere, modificare e rimuovere veicoli e prenotazioni.
Il programma è strutturato in modo da avere un menu principale che permette di accedere a due sotto-menu:
1. Gestione veicoli: permette di aggiungere, modificare e rimuovere veicoli.
2. Gestione prenotazioni: permette di aggiungere, modificare, rimuovere prenotazioni e calcolarne il costo.
Il programma utilizza strutture dati per gestire le informazioni sui veicoli e le prenotazioni.
Il programma è interattivo e richiede l'input dell'utente per eseguire le operazioni desiderate.
*/

/*
FUNZIONE: main
-------------------------
Funzione principale del programma che gestisce il menu principale e le operazioni sui veicoli e le prenotazioni.

IMPLEMENTAZIONE:
int main ();

PARAMETRI:
Nessuno.

PRE-CONDIZIONI:
- Nessuna condizione predefinita.

POST-CONDIZIONI:
- Il programma mostra un menu principale con le opzioni per gestire i veicoli e le prenotazioni.
- L'utente può scegliere di gestire i veicoli o le prenotazioni, oppure uscire dal programma.
- Se l'utente sceglie di gestire i veicoli, viene chiamata la funzione `menuVeicoli` per gestire le operazioni sui veicoli.
- Se l'utente sceglie di gestire le prenotazioni, viene chiamata la funzione `menuPrenotazioni` per gestire le operazioni sulle prenotazioni.
- Se l'utente sceglie di uscire, il programma termina.

SIDE-EFFECT:
- La funzione stampa un menu interattivo per l'utente, richiedendo l'input per le operazioni da eseguire.
*/
int main ()
{
    Veicolo *punt = NULL;
    Prenotazione *prenota = NULL;

    int scelta = 0;

    do
    {
       printf("-------------------------CAR SHARING-----------------------\n");
       printf("Benvenuto nel menu principale! (Inserisci il numero per la scelta)\n");
       printf("1. Gestisci i veicoli\n");
       printf("2. Gestisci le prenotazioni\n");
       printf("3. Uscire \n");
       printf("Inserisci la tua scelta: \n");
       printf("-------------------------------------------------------------\n");
       scanf("%d", &scelta); 
       pulisciBuffer();
       system("cls");

       switch(scelta)
       {
           case 1:     
               menuVeicoli(&punt);
               break;

           case 2:
                menuPrenotazioni(&prenota, &punt);
               break;

           case 3:
               printf("Uscita dal programma...\n");
               break;

           default:
               printf("Scelta non valida. Riprova.\n");
       }

    }
    while(scelta != 3);
    return 0;
}

