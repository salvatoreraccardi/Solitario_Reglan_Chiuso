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
void menu();
void deckGeneration();
void sector_A();
void sector_B();
void sector_C();
void firstRendering();
void errorAlert(char type);
void winCheck();
void hidecursor(boolean status);

int main() {
    // console name
    SetConsoleTitle("Solitario Reglan Chiuso - (v0.5.0)");
    // Clear screen
    system("cls");

    // Menù
    menu();

    // Generazione del deck
    deckGeneration();
    // Playground first rendering
    firstRendering();
    

    //
    // REALTIME UPDATE
    // INSIDE GAME
    //

    while(1){
        int j, i;
        int tempValore[52], tempDorsi[52];
        char tempSeme[52], tempColore[52];
        char c_1, c_2, c_3;
        int from, to;

        hidecursor(true);
        textcolor(15); 
        gotoxy(0, 50);
        printf("comando: ");       
        scanf("%c %c %c %i %i", &c_1, &c_2, &c_3, &from, &to);
        
        // CHECK - comando
        if(c_1 == 'A' && c_2 == '>' && c_3 == 'B'){
            // CHECK ARRAY INDEX 
            if(ptrA->nCard > 0){  
                // CHECK SEME
                if((ptrA+from)->seme == (ptrB+to)->seme){  
                    // CHECK VALORE
                    if(((ptrA+from)->valore - 1) == (ptrB+to)->valore){                  
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
                        // Errore valore
                        errorAlert('V');
                    } 
                }else{
                    // Errore seme
                    errorAlert('S');
                }  
            }else{
                // Errore array index
                errorAlert('A');
            }
        }
        
        if(c_1 == 'C' && c_2 == '>' && c_3 == 'C'){  
            // CHECK ARRAY INDEX AND GAME RULES 
            if(ptrC[from]->renderingCard != 0){
                // CHECK VALUE
                if((ptrC[from]+(ptrC[from])->renderingCard - 1)->valore == ((ptrC[to]+(ptrC[to])->renderingCard - 1)->valore - 1) || (ptrC[to]+(ptrC[to])->renderingCard - 1)->valore < 0 || (ptrC[to]+(ptrC[to])->renderingCard - 1)->valore > 13){
                    // CHECK COLOR
                    if((ptrC[from]+(ptrC[from])->renderingCard - 1)->colore != ((ptrC[to]+(ptrC[to])->renderingCard - 1)->colore) || ((ptrC[to]+(ptrC[to])->renderingCard - 1)->colore) < 0){
                        // SAVE DATA FROM POINTER
                        for(i = 0; i < (ptrC[to])->renderingCard; i++){  
                            tempDorsi[i] = (ptrC[to]+i)->dorsi;
                            tempValore[i] = (ptrC[to]+i)->valore;
                            tempSeme[i] = (ptrC[to]+i)->seme;
                            tempColore[i] = (ptrC[to]+i)->colore;                
                        }

                        // EDIT RENDERING CARD VALUE
                        int temp_nCard = (ptrC[to])->renderingCard + 1;

                        // NEW DECLARATION FOR POINTERS
                        ptrC[to] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c));   

                        // UPDATE ALL POINTER
                        for(i = 0; i < temp_nCard; i++){  
                            (ptrC[to]+i)->dorsi = tempDorsi[i]; 
                            (ptrC[to]+i)->renderingCard = temp_nCard;
                            (ptrC[to]+i)->valore = tempValore[i];
                            (ptrC[to]+i)->seme = tempSeme[i];
                            (ptrC[to]+i)->colore = tempColore[i];
                        }

                        (ptrC[to]+(temp_nCard - 2))->dorsi = 0;

                        (ptrC[to])->renderingCard = temp_nCard;

                        // ADD NEW CARD --> POINTERS
                        (ptrC[to]+(temp_nCard - 1))->dorsi = 0; 
                        (ptrC[to]+(temp_nCard - 1))->valore = (ptrC[from]+((ptrC[from])->renderingCard - 1))->valore; 
                        (ptrC[to]+(temp_nCard - 1))->seme = (ptrC[from]+((ptrC[from])->renderingCard - 1))->seme; 
                        (ptrC[to]+(temp_nCard - 1))->colore = (ptrC[from]+((ptrC[from])->renderingCard - 1))->colore; 

                        // SAVE DATA FROM POINTER AND REMOVE FIRST CARD
                        for(i = 0; i < ((ptrC[from])->renderingCard - 1); i++){  
                            tempDorsi[i] = (ptrC[from]+i)->dorsi;
                            tempValore[i] = (ptrC[from]+i)->valore;
                            tempSeme[i] = (ptrC[from]+i)->seme;
                            tempColore[i] = (ptrC[from]+i)->colore;
                        }

                        // EDIT RENDERING CARD VALUE
                        if((ptrC[from])->renderingCard != 0){
                            temp_nCard = (ptrC[from])->renderingCard - 1;
                        }
                        
                        // NEW DECLARATION FOR POINTERS
                        ptrC[from] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c));  
                        
                        // UPDATE ALL POINTER
                        for(i = 0; i < temp_nCard; i++){  
                            (ptrC[from]+i)->dorsi = tempDorsi[i]; 
                            (ptrC[from]+i)->renderingCard = temp_nCard;
                            (ptrC[from]+i)->valore = tempValore[i];
                            (ptrC[from]+i)->seme = tempSeme[i];
                            (ptrC[from]+i)->colore = tempColore[i];
                        }            
                        
                        (ptrC[from])->renderingCard = temp_nCard;

                        // Refresh screen
                        system("cls");
                        sector_A();
                        sector_B();
                        sector_C();
                    }else{
                        // Errore colore
                        errorAlert('C');
                    }
                }else{
                    // Errore valore
                    errorAlert('V');
                }
            }else{
                // Errore array index
                errorAlert('A');
            }
            
        }

        if(c_1 == 'A' && c_2 == '>' && c_3 == 'C'){  
            // CHECK ARRAY INDEX
            if(ptrA->nCard > 0){  
                // CHECK VALUE
                if((ptrA+from)->valore == ((ptrC[to]+(ptrC[to])->renderingCard - 1)->valore - 1) || ((ptrC[to]+(ptrC[to])->renderingCard - 1)->valore < 0 || ((ptrC[to]+(ptrC[to])->renderingCard - 1)->valore > 13))){                    
                    // CHECK COLOR
                    if((ptrA+from)->colore != ((ptrC[to]+(ptrC[to])->renderingCard - 1)->colore) || ((ptrC[to]+(ptrC[to])->renderingCard - 1)->colore) < 0){
                        // SAVE DATA FROM POINTER
                        for(i = 0; i < (ptrC[to])->renderingCard; i++){  
                            tempDorsi[i] = (ptrC[to]+i)->dorsi;
                            tempValore[i] = (ptrC[to]+i)->valore;
                            tempSeme[i] = (ptrC[to]+i)->seme;
                            tempColore[i] = (ptrC[to]+i)->colore;                
                        }

                        // EDIT RENDERING CARD VALUE
                        int temp_nCard = (ptrC[to])->renderingCard + 1;

                        // NEW DECLARATION FOR POINTERS
                        ptrC[to] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c));   

                        // UPDATE ALL POINTER
                        for(i = 0; i < temp_nCard; i++){  
                            (ptrC[to]+i)->dorsi = tempDorsi[i]; 
                            (ptrC[to]+i)->renderingCard = temp_nCard;
                            (ptrC[to]+i)->valore = tempValore[i];
                            (ptrC[to]+i)->seme = tempSeme[i];
                            (ptrC[to]+i)->colore = tempColore[i];
                        }

                        (ptrC[to]+(temp_nCard - 2))->dorsi = 0;

                        (ptrC[to])->renderingCard = temp_nCard;

                        // ADD NEW CARD --> POINTERS
                        (ptrC[to]+(temp_nCard - 1))->dorsi = 0; 
                        (ptrC[to]+(temp_nCard - 1))->valore = (ptrA+from)->valore; 
                        (ptrC[to]+(temp_nCard - 1))->seme = (ptrA+from)->seme; 
                        (ptrC[to]+(temp_nCard - 1))->colore = (ptrA+from)->colore;

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
                        // Errore colore
                        errorAlert('C');
                    }
                }else{
                    // Errore valore
                    errorAlert('V');
                }   
            }else{
                // Errore array index
                errorAlert('A');
            }
        }

        if(c_1 == 'C' && c_2 == '>' && c_3 == 'B'){
            // CHECK ARRAY INDEX AND GAME RULES 
            if(ptrC[from]->renderingCard != 0){
                // CHECK SEME
                if((ptrC[from]+((ptrC[from])->renderingCard - 1))->seme == (ptrB+to)->seme){
                    // CHECK VALORE
                    if(((ptrC[from]+((ptrC[from])->renderingCard - 1))->valore - 1) == (ptrB+to)->valore){
                        // MOVE THE CARD ON SECTOR B
                        // only value 
                        (ptrB+to)->valore = (ptrC[from]+((ptrC[from])->renderingCard - 1))->valore; 

                        // SAVE DATA FROM POINTER
                        for(i = 0; i < (ptrC[from])->renderingCard; i++){  
                            tempDorsi[i] = (ptrC[from]+i)->dorsi;
                            tempValore[i] = (ptrC[from]+i)->valore;
                            tempSeme[i] = (ptrC[from]+i)->seme;
                            tempColore[i] = (ptrC[from]+i)->colore;                
                        }

                        // EDIT RENDERING CARD VALUE
                        int temp_nCard = (ptrC[from])->renderingCard - 1;

                        // NEW DECLARATION FOR POINTERS
                        ptrC[from] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c));   

                        // UPDATE ALL POINTER
                        for(i = 0; i < temp_nCard; i++){  
                            (ptrC[from]+i)->dorsi = tempDorsi[i]; 
                            (ptrC[from]+i)->renderingCard = temp_nCard;
                            (ptrC[from]+i)->valore = tempValore[i];
                            (ptrC[from]+i)->seme = tempSeme[i];
                            (ptrC[from]+i)->colore = tempColore[i];
                        }

                        (ptrC[from]+(temp_nCard - 1))->dorsi = 0;

                        (ptrC[from])->renderingCard = temp_nCard;      

                        // Refresh screen
                        system("cls");
                        sector_A();
                        sector_B();
                        sector_C();
                    }else{
                        // Errore valore
                        errorAlert('V');
                    }
                }else{
                    // Errore seme
                    errorAlert('S');
                }
            }else{
                // Errore array index
                errorAlert('A');
            }    
        }

        //WIN
        winCheck();

        // SCANF - CLEAR INPUT BUFFER
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    //TODO: FREE ALL POINTERS
    free(ptrA);
    free(ptrB);
    for(int j = 0; j < 9; j++){
        free(ptrC[j]);
    }

    // BG color
    system("COLOR 0");
    // Fix text color
    textcolor(15);  
    // Clear screen
    system("cls");  

    return 0;
}