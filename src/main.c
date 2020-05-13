#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 

#include "services.c"
#include "startup.c"
#include "sector/sectorA.c"

void textcolor(int colore);
void gotoxy(short x, short y);
void delay(int number_of_seconds);
void splashscreen();
void sector_A(int nCard, int *cardValore, char *cardColore, char *cardSeme);

int main() {
    // console name
    SetConsoleTitle("Solitario Reglan Chiuso");
    // clear screen
    system("cls");
    splashscreen();

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

    // carico il vettore
    for(i = 0; i < cardN; i++){
        *(cardValore + i) = i;
        *(cardColore + i) = array_1_colore[i];
        *(cardSeme + i) = array_1_seme[i];
    }

    sector_A(cardN, cardValore, cardColore, cardSeme);

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

    // free memory
    free(cardValore);
    free(cardColore);
    free(cardSeme);

    //
    // END TEST
    //

    textcolor(15);
    getch(); 
    return 0;
}