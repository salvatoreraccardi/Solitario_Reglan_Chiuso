//
// Solitario Reglan Chiuso(v0.0.1)
// MIT LICENSE Copyright (c) 2020 Salvatore Raccardi
//
// Salvatore Raccardi salvatore.raccardi@community.unipa.it
// Antonino Graziano antonino.graziano01@community.unipa.it
//
// Repo: github.com/salvatoreraccardi/Solitario_Reglan_Chiuso
//

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h> 
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 

// Deck - dataset
struct deck_data{
    int valore[52];
    char seme[52];
    char colore[52];
}deck;

#include "tools.c"
#include "startup.c"
#include "deck.c"
#include "graphics/sectorA.c"
#include "graphics/sectorB.c"
#include "graphics/sectorC.c"

void textcolor(int colore);
void gotoxy(short x, short y);
void delay(int seconds);
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
        *(cardValore + i) = deck.valore[46 + i];
        *(cardColore + i) = deck.colore[46 + i];
        *(cardSeme + i) = deck.seme[46 + i];
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
    for(i = 0; i < 4; i++){
        *(cardValore + i) = deck.valore[i];
        *(cardColore + i) = deck.colore[i];
        *(cardSeme + i) = deck.seme[i];
    }

    sector_B(cardValore, cardColore, cardSeme);

   
    int nCard = 9;
    int offsetX = 0;
    // array_dataset
    int arr_dorso[9] = {1, 1, 1, 1, 1, 1, 1, 1, 0};
    
    int *cDorso = NULL;
    int *cValore = NULL;
    char *cSeme = NULL;
    char *cColore = NULL;

    // puntatori - allocazione memoria
    cDorso = (int*) calloc(nCard, sizeof(int));
    cValore = (int*) calloc(nCard, sizeof(int));
    cSeme = (char*) calloc(nCard, sizeof(char));
    cColore = (char*) calloc(nCard, sizeof(char));

    int getCard[9] = {7, 7, 7, 6, 5, 4, 3, 2, 1};
    int offsetData = 4;

    for(int j = 0; j < 9; j++){
        // puntatori <--data-- vettori
        for(int i = 0; i < getCard[j]; i++){
            *(cDorso + i) = arr_dorso[i];
            *(cValore + i) = deck.valore[offsetData + i];
            *(cSeme + i) = deck.seme[offsetData + i];
            *(cColore + i) = deck.colore[offsetData + i];
        }

        // int nCard, bool array_dorso[3], int array_valore[3], char array_seme[3], char array_colore[3], int offsetX
        sector_C(getCard[j], cDorso, cValore, cSeme, cColore, offsetX);
        offsetData += getCard[j];
        offsetX += 8;
    }

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