#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

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
               menuVeicoli(&punt); // Chiamata alla funzione menuVeicoli
               break;

           case 2:
                menuPrenotazioni(&prenota, &punt); // Chiamata alla funzione menuPrenotazioni
               break;

           case 3:
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
    printf("Premi INVIO per continuare...\n");
    getchar();
    getchar();
}

void pulisciBuffer()
{
    int c;
    while ((c = getchar()) != '\n'); //Consuma i caratteri rimasti nel buffer fino a newline
}
