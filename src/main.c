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
#include "graphics/sectorA.c"
#include "graphics/sectorB.c"
#include "graphics/sectorC.c"
#include "deck.c"

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
    // Clear screen
    system("cls");
    // Schemata iniziale
    //splashscreen();
    // Generazione del deck
    deckGeneration();

    /* 
        SECTOR_A - first rendering deck
    */    
    
    // Vettore dinamico
    int *sectorA_Valore = NULL;
    char *sectorA_Colore = NULL;
    char *sectorA_Seme = NULL;
    // puntatori - allocazione memoria
    sectorA_Valore = (int*) calloc(6, sizeof(int));
    sectorA_Colore = (char*) calloc(6, sizeof(char));
    sectorA_Seme = (char*) calloc(6, sizeof(char));

    // puntatori
    for(int i = 0; i < 6; i++){
        *(sectorA_Valore + i) = deck.valore[46 + i];
        *(sectorA_Colore + i) = deck.colore[46 + i];
        *(sectorA_Seme + i) = deck.seme[46 + i];
    }
  
    // visualizzazione carte
    sector_A(6, sectorA_Valore, sectorA_Colore, sectorA_Seme);

    /* 
        SECTOR_B - first rendering deck
    */ 

    // Vettore dinamico
    int *sectorB_Valore = NULL;
    char *sectorB_Colore = NULL;
    char *sectorB_Seme = NULL;
    sectorB_Valore = (int*) calloc(4, sizeof(int));
    sectorB_Colore = (char*) calloc(4, sizeof(char));
    sectorB_Seme = (char*) calloc(4, sizeof(char));
    
    for(int i = 0; i < 4; i++){
        *(sectorB_Valore + i) = deck.valore[i];
        *(sectorB_Colore + i) = deck.colore[i];
        *(sectorB_Seme + i) = deck.seme[i];
    }

    sector_B(sectorB_Valore, sectorB_Colore, sectorB_Seme);

    /* 
        SECTOR_C - first rendering deck
    */ 
   
    int nCard = 9;
    int offsetX = 0;
    // array_dataset
    int arr_dorso[9] = {1, 1, 1, 1, 1, 1, 1, 1, 0};
    
    int *sectorC_Dorso = NULL;
    int *sectorC_Valore = NULL;
    char *sectorC_Seme = NULL;
    char *sectorC_Colore = NULL;

    // puntatori - allocazione memoria
    sectorC_Dorso = (int*) calloc(nCard, sizeof(int));
    sectorC_Valore = (int*) calloc(nCard, sizeof(int));
    sectorC_Seme = (char*) calloc(nCard, sizeof(char));
    sectorC_Colore = (char*) calloc(nCard, sizeof(char));

    int getCard[9] = {7, 7, 7, 6, 5, 4, 3, 2, 1};
    int offsetData = 4;

    for(int j = 0; j < 9; j++){
        // puntatori <--data-- vettori
        for(int i = 0; i < getCard[j]; i++){
            *(sectorC_Dorso + i) = arr_dorso[i];
            *(sectorC_Valore + i) = deck.valore[offsetData + i];
            *(sectorC_Seme + i) = deck.seme[offsetData + i];
            *(sectorC_Colore + i) = deck.colore[offsetData + i];
        }

        // int nCard, bool array_dorso[3], int array_valore[3], char array_seme[3], char array_colore[3], int offsetX
        sector_C(getCard[j], sectorC_Dorso, sectorC_Valore, sectorC_Seme, sectorC_Colore, offsetX);
        offsetData += getCard[j];
        offsetX += 8;
    }

    //
    // REALTIME UPDATE
    // INSIDE GAME
    //
    int sector_A_nCard = 6;
    while(1){
        textcolor(15); 
        gotoxy(0, 40);
        printf("comando: ");
        char c_1, c_2, c_3;
        int from, to;
        scanf("%c %c %c %i %i", &c_1, &c_2, &c_3, &from, &to);

        // CHECK - comando
        if(c_1 == 'A' && c_2 == '>' && c_3 == 'B'){
            // TODO: CHECK FROM_VALUE && TO_VALUE
            // CHECK - sequenza valori / seme delle carte
            if(*(sectorA_Valore + from) == (*(sectorB_Valore + to) + 1) && *(sectorA_Seme + from) == *(sectorB_Seme + to)){
                // SWAP VALORI
                *(sectorB_Valore + to) = *(sectorA_Valore + from);
                // Decremento il numero delle carte totali nel settore A
                sector_A_nCard -= 1;
                // SWAP POINTERS
                for(int y = from; y < sector_A_nCard; y++){
                    *(sectorA_Valore + y) = *(sectorA_Valore + (y + 1));
                    *(sectorA_Colore + y) = *(sectorA_Colore + (y + 1));
                    *(sectorA_Seme + y) = *(sectorA_Seme + (y + 1));
                }                 
                // refresh screen
                system("cls");
                sector_A(sector_A_nCard, sectorA_Valore, sectorA_Colore, sectorA_Seme);
                sector_B(sectorB_Valore, sectorB_Colore, sectorB_Seme);
                //sector_C(getCard[j], sectorC_Dorso, sectorC_Valore, sectorC_Seme, sectorC_Colore, offsetX);
            }else{
                printf("\n error\n");
            }
        }   
    }

    //TODO: FREE ALL POINTER
    //free(sectorA_Valore);
    //free(sectorA_Colore);
    //free(sectorA_Seme);

    // Fix text color
    textcolor(15);  
    // Clear screen
    system("cls");
    printf("Bye");
    return 0;
}