#include <stdio.h>
#include <stdbool.h>
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
void sector_C(int nCard, int indexL, int *matrixDorso, int *matrixValore, char *matrixSeme, char *matrixColore, int offsetX);

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
    char array_1_seme[6] = {3, 4, 3, 4, 5, 5};
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

   
    //int nCard = 3;
    //int offsetX = 0;
    // array_dataset
    // int arr_dorso[3] = {0, 0, 0};
    // int arr_valore[3] = {3, 10, 4};
    // char arr_seme[3] = {3, 4, 5};
    // char arr_colore[3] = {'R', 'B', 'B'};
    int arr_dorso[2][2] = {{0, 0},
                           {1, 0}};

    int arr_valore[2][2] = {{10, 7},
                            {3, 5}};

    char arr_seme[2][2] = {{3, 5},
                           {4, 6}};

    char arr_colore[2][2] = {{'R', 'R'},
                             {'R', 'B'}};

    // crea matrice
    int *matrixDorso = NULL;
    int *matrixValore = NULL;
    char *matrixSeme = NULL;
    char *matrixColore = NULL;

    int nCard = 2;
    int indexC = 0;
    int offsetX = 0;
    int lines = nCard;
    int columns = nCard;

    matrixDorso = (int *)malloc(lines * columns * sizeof(int)); 
    matrixValore = (int *)malloc(lines * columns * sizeof(int));
    matrixSeme = (char *)malloc(lines * columns * sizeof(char));  
    matrixColore = (char *)malloc(lines * columns * sizeof(char));  


    for (int i = 0; i < lines; ++i){
      for (int j = 0; j < columns; ++j){
        matrixDorso[i*lines + j] = arr_dorso[i][j];
        matrixValore[i*lines + j] = arr_valore[i][j];
        matrixSeme[i*lines + j] = arr_seme[i][j];
        matrixColore[i*lines + j] = arr_colore[i][j];
      }
    }

    for(int load = 0; load < nCard; load++){
        sector_C(nCard, indexC, matrixDorso, matrixValore, matrixSeme, matrixColore, offsetX);
        indexC += 1;
        offsetX += 8;
    }       

    /*
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
        *(cValore + i) = arr_valore[i];
        *(cSeme + i) = arr_seme[i];
        *(cColore + i) = arr_colore[i];
    }

    // int nCard, bool array_dorso[3], int array_valore[3], char array_seme[3], char array_colore[3], int offsetX
    sector_C(nCard, cDorso, cValore, cSeme, cColore, offsetX);
    */
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