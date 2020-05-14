#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 

#include "services.c"
#include "startup.c"
#include "sector/sectorA.c"
#include "sector/sectorB.c"
#include "sector/sectorC.c"

void textcolor(int colore);
void gotoxy(short x, short y);
void delay(int number_of_seconds);
void splashscreen();
void sector_A(int nCard, int *cardValore, char *cardColore, char *cardSeme);
void sector_B();
void sector_C(int nDorsi, int nCard, int offsetX);

int main() {
    // console name
    SetConsoleTitle("Solitario Reglan Chiuso");
    // clear screen
    system("cls");
    // splashscreen();

    //
    // START TEST 
    //

    // Vettori per la simulazione
    int array_1_valore[6] = {13, 12, 4, 10, 11, 5};
    char array_1_seme[6] = {'C', 'Q', 'C', 'Q', 'F', 'F'};
    char array_1_colore[6] = {'B', 'R', 'R', 'B', 'B', 'R'};
    
    int cardN = 6, i;
    // Vettore dinamico
    int *cardValore = NULL;
    char *cardColore = NULL;
    char *cardSeme = NULL;
    // puntatori - allocazione memoria
    cardValore = (int*) calloc(cardN, sizeof(int));
    cardColore = (char*) calloc(cardN, sizeof(char));
    cardSeme = (char*) calloc(cardN, sizeof(char));

    // puntatori <--data-- vettori
    for(i = 0; i < cardN; i++){
        *(cardValore + i) = i;
        *(cardColore + i) = array_1_colore[i];
        *(cardSeme + i) = array_1_seme[i];
    }

    // generazione delle carte
    sector_A(cardN, cardValore, cardColore, cardSeme);
/*
    delay(4); 
    system("cls");

    cardN = 4;
    // carico il vettore
    for(i = 0; i < cardN; i++){
        *(cardValore + i) = array_1_valore[i];
        *(cardColore + i) = array_1_colore[i];
        *(cardSeme + i) = array_1_seme[i];
    }     

    sector_A(cardN, cardValore, cardColore, cardSeme);
*/
    // free memory
    free(cardValore);
    free(cardColore);
    free(cardSeme);

    //
    // END TEST
    //

    sector_B();

    // simulazione sectorC
    int numeroDorsi = 3;
    int numeroCard = 4;
    sector_C(numeroDorsi, numeroCard, 0);
    sector_C(5, 2, 8);
    sector_C(6, 3, 16);
    sector_C(numeroDorsi, numeroCard, 24);
    sector_C(numeroDorsi, numeroCard, 32);
    sector_C(numeroDorsi, numeroCard, 40);
    sector_C(numeroDorsi, numeroCard, 48);
    sector_C(numeroDorsi, numeroCard, 56);
    sector_C(numeroDorsi, numeroCard, 64);

    textcolor(15);
    getch(); 
    return 0;
}