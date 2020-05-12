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
void sector_A(int nCard, int *cardValore);

int main() {
    // console name
    SetConsoleTitle("Solitario Reglan Chiuso");
    // clear screen
    system("cls");
    splashscreen();

    // TEST - vettore dinamico
    int *cardValore, cardN = 6;
    cardValore = (int*) calloc(cardN, sizeof(int));
    // carico il vettore
    for(int i = 0; i < cardN; i++)
        *(cardValore + i) = i;

    sector_A(cardN, cardValore);

    delay(4); 
    system("cls");

    cardN = 4;
    // carico il vettore
    for(int i = 0; i < cardN; i++)
        *(cardValore + i) = array_1_valore[i];

    sector_A(cardN, cardValore);

    // END TEST

    textcolor(15);
    getch(); 
    return 0;
}