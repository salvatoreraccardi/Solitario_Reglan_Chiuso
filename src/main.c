//
// Solitario Reglan Chiuso(v0.0.1)
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

#include "dataset.c"
#include "tools.c"
#include "startup.c"
#include "graphics/sectorA.c"
#include "graphics/sectorB.c"
#include "graphics/sectorC.c"
#include "deck.c"
#include "playground.c"

void textcolor(int colore);
void gotoxy(short x, short y);
void delay(int seconds);
void splashscreen();
void deckGeneration();
void sector_A();
void sector_B();
void sector_C();
void firstRendering();

int main() {
    // console name
    SetConsoleTitle("Solitario Reglan Chiuso");
    // Clear screen
    system("cls");

    // Schemata iniziale
    //splashscreen();

    // Generazione del deck
    deckGeneration();
    // Playground first rendering
    firstRendering();
    

    //
    // REALTIME UPDATE
    // INSIDE GAME
    //
    

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
        } 
    }

    //TODO: FREE ALL POINTERS
    //free(sectorA_Valore);

    // Fix text color
    textcolor(15);  
    // Clear screen
    system("cls");
    printf("Bye");
    //getch();
    return 0;
}