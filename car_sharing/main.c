#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "veicoli.h"
#include "prenotazioni.h"

int main ()
{
    Veicolo *punt = NULL; // Inizializza la lista dei veicoli a NULL
    Prenotazione *prenota = NULL; // Inizializza la lista delle prenotazioni a NULL

    int scelta = 0;

    do
    {
       printf("-------------------------CAR SHARING-----------------------\n");
       printf("Benvenuto nel menu principale!\n");
       printf("1. Gestisci i veicoli\n");
       printf("2. Gestisci le prenotazioni\n");
       printf("3. Uscire \n");
       printf("Inserisci la tua scelta: ");
       printf("-------------------------------------------------------------\n");
       scanf("%d", &scelta); // Legge la scelta dell'utente
       
       switch(scelta)
       {
           case 1:
               system("cls");
               menuVeicoli(&punt); // Chiama la funzione per gestire i veicoli
               break;

           case 2:
               system("cls");
                menuPrenotazioni(&prenota, &punt); // Chiama la funzione per gestire le prenotazioni
               break;

           case 3:
               system("cls");
               printf("Uscita dal programma...\n");
               break;

           default:
               printf("Scelta non valida. Riprova.\n");
       }

    }
    while(scelta != 3); // Continua a mostrare il menu finché l'utente non sceglie di uscire
    return 0;
}

void premiInvio()
{
    while (getchar() != '\n'); // Consuma i caratteri rimasti nel buffer fino a newline
    printf("Premi INVIO per continuare...\n");
    getchar();     // Consuma il carattere newline rimasto nel buffer
    system("cls"); // Pulisce lo schermo
}

void pulisciBuffer()
{
    int c;
    while ((c = getchar()) != '\n'); // Consumes all characters until newline or EOF
}
