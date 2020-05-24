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
    int j, i;

    while(1){
        textcolor(15); 
        gotoxy(0, 50);
        printf("comando: ");
        char c_1, c_2, c_3;
        int from, to;
        scanf("%c %c %c %i %i", &c_1, &c_2, &c_3, &from, &to);
        
        // CHECK - comando
        if(c_1 == 'A' && c_2 == '>' && c_3 == 'B'){
            if(ptrA->nCard > 0){                         
                // Swap data
                (ptrB+to)->valore = (ptrA+from)->valore;
                // Sort sector_A
                for(j = from; j < ptrA->nCard; j++){
                    (ptrA+j)->valore = (ptrA+(j+1))->valore;
                    (ptrA+j)->seme = (ptrA+(j+1))->seme;
                    (ptrA+j)->colore = (ptrA+(j+1))->colore;
                }
                ptrA->nCard -= 1;
                // Refresh screen
                system("cls");
                sector_A();
                sector_B();
                sector_C();
            }else{
                printf("ERR");
            }
        }
        
        if(c_1 == 'C' && c_2 == '>' && c_3 == 'C' && ptrC[1]->renderingCard >= 0){  
            // TODO: TAKE NEW CARD FROM POINTER

            // SAVE DATA FROM POINTER
            int tempValore[30], tempDorsi[30];
            char tempSeme[30], tempColore[30];
            for(i = 0; i < (ptrC[0])->renderingCard; i++){  
                tempDorsi[i] = (ptrC[0]+i)->dorsi;
                tempValore[i] = (ptrC[0]+i)->valore;
                tempSeme[i] = (ptrC[0]+i)->seme;
                tempColore[i] = (ptrC[0]+i)->colore;
            }

            // EDIT RENDERING CARD VALUE
            int temp_nCard = (ptrC[0])->renderingCard + 1;

            // NEW DECLARATION FOR POINTERS
            ptrC[0] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c));   

            // UPDATE ALL POINTER
            for(i = 0; i < temp_nCard; i++){  
                (ptrC[0]+i)->dorsi = tempDorsi[i]; 
                (ptrC[0]+i)->renderingCard = temp_nCard;
                (ptrC[0]+i)->valore = tempValore[i];
                (ptrC[0]+i)->seme = tempSeme[i];
                (ptrC[0]+i)->colore = tempColore[i];
            }

            (ptrC[0]+(temp_nCard - 2))->dorsi = 0;
            // ADD NEW CARD --> POINTERS
            (ptrC[0]+(temp_nCard - 1))->dorsi = 0; 
            (ptrC[0]+(temp_nCard - 1))->valore = (ptrC[1]+((ptrC[1])->renderingCard - 1))->valore; // TODO: CHECK!! (ptrC[1])->renderingCard - 1)
            (ptrC[0]+(temp_nCard - 1))->seme = (ptrC[1]+((ptrC[1])->renderingCard - 1))->seme; // TODO: UP
            (ptrC[0]+(temp_nCard - 1))->colore = (ptrC[1]+((ptrC[1])->renderingCard - 1))->colore; // TODO: UP

            // TODO: REMOVE CARD FROM OLD POINTER

            // SAVE DATA FROM POINTER AND REMOVE FIRST CARD
            for(i = 0; i < ((ptrC[1])->renderingCard - 1); i++){  
                tempDorsi[i] = (ptrC[1]+i)->dorsi;
                tempValore[i] = (ptrC[1]+i)->valore;
                tempSeme[i] = (ptrC[1]+i)->seme;
                tempColore[i] = (ptrC[1]+i)->colore;
            }

            // EDIT RENDERING CARD VALUE
            temp_nCard = (ptrC[1])->renderingCard - 1;

            // NEW DECLARATION FOR POINTERS
            ptrC[1] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c));  

            // UPDATE ALL POINTER
            for(i = 0; i < temp_nCard; i++){  
                (ptrC[1]+i)->dorsi = tempDorsi[i]; 
                (ptrC[1]+i)->renderingCard = temp_nCard;
                (ptrC[1]+i)->valore = tempValore[i];
                (ptrC[1]+i)->seme = tempSeme[i];
                (ptrC[1]+i)->colore = tempColore[i];
            }            

            // SHOW NEW FIRST CARD 
            (ptrC[1]+(temp_nCard - 1))->dorsi = 0; 

            // Refresh screen
            system("cls");
            sector_A();
            sector_B();
            sector_C();
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