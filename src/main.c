#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h> 
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 

#include "services.c"
#include "startup.c"
#include "deck.c"
#include "graphics/sectorA.c"
#include "graphics/sectorB.c"
#include "graphics/sectorC.c"

void textcolor(int colore);
void gotoxy(short x, short y);
void delay(int number_of_seconds);
void splashscreen();
void deckGeneration();
void sector_A(int nCard, int *cardValore, char *cardColore, char *cardSeme);
void sector_B(int *cardValore, char *cardColore, char *cardSeme);
void sector_C(int nCard, int *cDorso, int *cValore, char *cSeme, char *cColore, int offsetX);


int main() {
    // console name
    SetConsoleTitle("Solitario Reglan Chiuso");
    system("cls");
    // splashscreen();

    deckGeneration();

    //
    // START TEST 
    //  
    
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
        *(cardValore + i) = deckValore[45 + i];
        *(cardColore + i) = deckColore[45 + i];
        *(cardSeme + i) = deckSeme[45 + i];
    }

    // generazione delle carte
    sector_A(cardN, cardValore, cardColore, cardSeme);
    //free(cardValore);
    //free(cardColore);
    //free(cardSeme);

    //
    // END TEST
    //

    // puntatori <--data-- vettori
    for(i = 0; i < cardN; i++){
        *(cardValore + i) = deckValore[i];
        *(cardColore + i) = deckColore[i];
        *(cardSeme + i) = deckSeme[i];
    }

    sector_B(cardValore, cardColore, cardSeme);

   
    int nCard = 6;
    int offsetX = 0;
    // array_dataset
    int arr_dorso[6] = {1, 1, 0, 0, 0, 0};
    
    int *cDorso = NULL;
    int *cValore = NULL;
    char *cSeme = NULL;
    char *cColore = NULL;

    // puntatori - allocazione memoria
    cDorso = (int*) calloc(nCard, sizeof(int));
    cValore = (int*) calloc(nCard, sizeof(int));
    cSeme = (char*) calloc(nCard, sizeof(char));
    cColore = (char*) calloc(nCard, sizeof(char));

    // puntatori <--data-- vettori
    for(i = 0; i < nCard; i++){
        *(cDorso + i) = arr_dorso[i];
        *(cValore + i) = deckValore[4 + i];
        *(cSeme + i) = deckSeme[4 + i];
        *(cColore + i) = deckColore[4 + i];
    }

    // int nCard, bool array_dorso[3], int array_valore[3], char array_seme[3], char array_colore[3], int offsetX
    sector_C(nCard, cDorso, cValore, cSeme, cColore, offsetX);
    
    //sector_C(5, 2, 8);
    //sector_C(6, 3, 16);
    //sector_C(numeroDorsi, numeroCard, 24);
    //sector_C(numeroDorsi, numeroCard, 32);
    //sector_C(numeroDorsi, numeroCard, 40);
    //sector_C(numeroDorsi, numeroCard, 48);
    //sector_C(numeroDorsi, numeroCard, 56);
    //sector_C(numeroDorsi, numeroCard, 64);

    textcolor(15);
    getch(); 
    return 0;
}