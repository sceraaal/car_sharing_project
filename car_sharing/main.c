#include <stdio.h>
#include <stdlib.h>


int main() 
{
    int scelta;

    do 
    {
        printf("\n--- Car Sharing Menu ---\n");
        printf("1. Aggiungi un veicolo \n");
        printf("2. Visualizza veicoli disponibili \n");
        printf("3. Prenota un veicolo \n");
        printf("4. Visualizza tutte le prenotazioni\n");
        printf("5. Calcola il costo di una prenotazione\n");
        printf("6. Visualizza storico noleggi di un utente\n");
        printf("0. Esci\n");
        printf("Inserire un opzione: ");

        if (scanf("%d", &scelta) != 1) 
        {
            printf("Input non valido.\n");
            while (getchar() != '\n');  // Pulisce il buffer di input
            scelta = -1;                // Imposta una scelta non valida per continuare il ciclo
            continue;
        }

        switch (scelta) 
        {
            case 1:
                printf("Aggiunta di un veicolo\n");
                //aggiungiVeicolo();
                break;

            case 2:
                printf("Visualizzazione veicoli disponibili\n");
               // mostraDisponibili();
                break;

            case 3:
                printf("Prenotazione di un veicolo\n");
               // prenotaVeicolo();
                break;

            case 4:
                printf("Visualizzazione di tutte le prenotazioni\n");
               // visualizzaPrenotazioni();
                break;

            case 5:
                printf("Calcolo del costo di una prenotazione\n");
               // calcolaCostoPrenotazione();
                break;

            case 6:
                printf("Visualizzazione dello storico noleggi di un utente\n");
               // visualizzaStoricoNoleggiUtente();
                break;

            case 0:
                printf("Uscita dal programma\n");
                break;

            default:
                printf("Scelta non valida, riprova.\n");
        }
    } 
    while (scelta != 0);

    return 0;
}

