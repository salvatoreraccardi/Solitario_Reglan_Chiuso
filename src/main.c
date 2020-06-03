//
// Solitario Reglan Chiuso
//
// Salvatore Raccardi salvatore.raccardi@community.unipa.it
// Antonino Graziano antonino.graziano01@community.unipa.it
//

#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <stdbool.h>
#include <conio.h> // getch()
#include <windows.h>

// Stato del gioco 
int gameStatus = 1;
// Struct per il mazzo di carte(Valore, seme, colore)
struct deck_data{
    int valore[52];
    char seme[52];
    char colore[52];
}deck;
// Struct per settore A
struct stack_sector_a{
    int nCard; // MAX 6
    int valore;
    char seme;
    char colore;
};
// Struct per settore B
struct stack_sector_b{
    int valore;
    char seme;
    char colore;
};
// Struct per settore C
struct stack_sector_c{
    int renderingCard; // numero di carte che contiene il puntatore (array dinamico)
    int dorsi;
    int valore;
    char seme;
    char colore;
};
// Struct & puntatori - (ptrA+index)->seme
struct stack_sector_a *ptrA;
struct stack_sector_b *ptrB;
struct stack_sector_c *ptrC[9];

#include "tools.c"
#include "startup.c"
#include "graphics/sectorA.c"
#include "graphics/sectorB.c"
#include "graphics/sectorC.c"
#include "deck.c"
#include "playground.c"

int main() {
    // Nome della console
    SetConsoleTitle("Solitario Reglan Chiuso");
    system("cls");
    // Menù
    menu();
    system("COLOR 20");
    // Caricamento partita 
    loading(); 
    // Generazione del mazzo
    deckGeneration();
    // Il primo caricamento del campo di gioco
    firstRendering();  
    // Ciclo per il controllo della partita
    while(gameStatus == 1){
        // Variabili locali del ciclo while
        // Variabili per i contatori
        int j, i;
        // (SWAP) - Variabili temporanee per scambiare le carte tra puntatori
        int tempValore[52], tempDorsi[52];
        char tempSeme[52], tempColore[52];
        char c_1, c_2, c_3;
        int from, to;
        // Abilito il cursore
        hidecursor(true);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47);
        // Lista comandi
        commands();
        // SCANF - comando
        gotoxy(0, 50);
        printf("comando: "); 
        // Format del comando: es. A>B 1 3 - Sposto la carta 1 del settore A --> alla posizione 3 del settore B       
        scanf("%c %c %c %i %i", &c_1, &c_2, &c_3, &from, &to);     
        // Controllo del comando
        if(c_1 == 'A' && c_2 == '>' && c_3 == 'B'){
            // Controllo ARRAY INDEX 
            if(ptrA->nCard > 0){  
                // Controllo SEME
                if((ptrA+from)->seme == (ptrB+to)->seme){  
                    // Controllo VALORE
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
        // Controllo del comando
        if(c_1 == 'C' && c_2 == '>' && c_3 == 'C'){  
            // Controllo ARRAY INDEX 
            if(ptrC[from]->renderingCard != 0){
                // Controllo VALORE
                if((ptrC[from]+(ptrC[from])->renderingCard - 1)->valore == ((ptrC[to]+(ptrC[to])->renderingCard - 1)->valore - 1) || (ptrC[to]+(ptrC[to])->renderingCard - 1)->valore < 0 || (ptrC[to]+(ptrC[to])->renderingCard - 1)->valore > 13){
                    // Controllo COLORE
                    if((ptrC[from]+(ptrC[from])->renderingCard - 1)->colore != ((ptrC[to]+(ptrC[to])->renderingCard - 1)->colore) || ((ptrC[to]+(ptrC[to])->renderingCard - 1)->colore) < 0){
                        // Salvo i dati del putatore(to)
                        for(i = 0; i < (ptrC[to])->renderingCard; i++){  
                            tempDorsi[i] = (ptrC[to]+i)->dorsi;
                            tempValore[i] = (ptrC[to]+i)->valore;
                            tempSeme[i] = (ptrC[to]+i)->seme;
                            tempColore[i] = (ptrC[to]+i)->colore;                
                        }
                        // Modifico il numero di carte presenti nel puntatore(to)-(Array dinamico)
                        int temp_nCard = (ptrC[to])->renderingCard + 1;
                        // Memory allocation
                        //ptrC[to] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c));   
                        ptrC[to] = realloc(ptrC[to], temp_nCard* sizeof(struct stack_sector_c));
                        // Carico i dati nel nuovo puntatore(to) 
                        for(i = 0; i < temp_nCard; i++){  
                            (ptrC[to]+i)->dorsi = tempDorsi[i]; 
                            (ptrC[to]+i)->renderingCard = temp_nCard;
                            (ptrC[to]+i)->valore = tempValore[i];
                            (ptrC[to]+i)->seme = tempSeme[i];
                            (ptrC[to]+i)->colore = tempColore[i];
                        }
                        // Modifico il numero di carte visibili
                        (ptrC[to]+(temp_nCard - 2))->dorsi = 0;
                        // Modifico il numero di carte presenti nel puntatore(to)
                        (ptrC[to])->renderingCard = temp_nCard;
                        // Aggiungo la carta nel nuovo puntatore(to)
                        (ptrC[to]+(temp_nCard - 1))->dorsi = 0; 
                        (ptrC[to]+(temp_nCard - 1))->valore = (ptrC[from]+((ptrC[from])->renderingCard - 1))->valore; 
                        (ptrC[to]+(temp_nCard - 1))->seme = (ptrC[from]+((ptrC[from])->renderingCard - 1))->seme; 
                        (ptrC[to]+(temp_nCard - 1))->colore = (ptrC[from]+((ptrC[from])->renderingCard - 1))->colore; 
                        // Salvo i dati del puntatore(from) e rimuovo la prima carta
                        for(i = 0; i < ((ptrC[from])->renderingCard - 1); i++){  
                            tempDorsi[i] = (ptrC[from]+i)->dorsi;
                            tempValore[i] = (ptrC[from]+i)->valore;
                            tempSeme[i] = (ptrC[from]+i)->seme;
                            tempColore[i] = (ptrC[from]+i)->colore;
                        }
                        // Modifico il numero di carte presenti nel puntatore
                        if((ptrC[from])->renderingCard != 0){
                            temp_nCard = (ptrC[from])->renderingCard - 1;
                        }                   
                        // Memory allocation
                        //ptrC[from] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c));  
                        if(temp_nCard > 0){
                            ptrC[from] = realloc(ptrC[from], temp_nCard* sizeof(struct stack_sector_c)); 
                        }                   
                        // Carico i dati nel nuovo puntatore(from)
                        for(i = 0; i < temp_nCard; i++){  
                            (ptrC[from]+i)->dorsi = tempDorsi[i]; 
                            (ptrC[from]+i)->renderingCard = temp_nCard;
                            (ptrC[from]+i)->valore = tempValore[i];
                            (ptrC[from]+i)->seme = tempSeme[i];
                            (ptrC[from]+i)->colore = tempColore[i];
                        }            
                        // Modifico il numero di carte presenti nel puntatore(from)
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
        // Controllo del comando
        if(c_1 == 'A' && c_2 == '>' && c_3 == 'C'){  
            // Controllo ARRAY INDEX
            if(ptrA->nCard > 0){  
                // Controllo VALORE
                if((ptrA+from)->valore == ((ptrC[to]+(ptrC[to])->renderingCard - 1)->valore - 1) || ((ptrC[to]+(ptrC[to])->renderingCard - 1)->valore < 0 || ((ptrC[to]+(ptrC[to])->renderingCard - 1)->valore > 13))){                    
                    // Controllo COLORE
                    if((ptrA+from)->colore != ((ptrC[to]+(ptrC[to])->renderingCard - 1)->colore) || ((ptrC[to]+(ptrC[to])->renderingCard - 1)->colore) < 0){
                        // Salvo i dati del putatore(to)
                        for(i = 0; i < (ptrC[to])->renderingCard; i++){  
                            tempDorsi[i] = (ptrC[to]+i)->dorsi;
                            tempValore[i] = (ptrC[to]+i)->valore;
                            tempSeme[i] = (ptrC[to]+i)->seme;
                            tempColore[i] = (ptrC[to]+i)->colore;                
                        }
                        // Modifico il numero di carte presenti nel puntatore(to)-(Array dinamico)
                        int temp_nCard = (ptrC[to])->renderingCard + 1;
                        // Memory allocation
                        //ptrC[to] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c)); 
                        ptrC[to] = realloc(ptrC[to], temp_nCard* sizeof(struct stack_sector_c));    
                        // Carico i dati nel nuovo puntatore(to)
                        for(i = 0; i < temp_nCard; i++){  
                            (ptrC[to]+i)->dorsi = tempDorsi[i]; 
                            (ptrC[to]+i)->renderingCard = temp_nCard;
                            (ptrC[to]+i)->valore = tempValore[i];
                            (ptrC[to]+i)->seme = tempSeme[i];
                            (ptrC[to]+i)->colore = tempColore[i];
                        }
                        // Modifico il numero di carte visibili
                        (ptrC[to]+(temp_nCard - 2))->dorsi = 0;
                        // Modifico il numero di carte presenti nel puntatore(to)
                        (ptrC[to])->renderingCard = temp_nCard;
                        // Aggiungo la carta nel nuovo puntatore(to <-- from)
                        (ptrC[to]+(temp_nCard - 1))->dorsi = 0; 
                        (ptrC[to]+(temp_nCard - 1))->valore = (ptrA+from)->valore; 
                        (ptrC[to]+(temp_nCard - 1))->seme = (ptrA+from)->seme; 
                        (ptrC[to]+(temp_nCard - 1))->colore = (ptrA+from)->colore;
                        // Ordino il settore_A
                        for(j = from; j < ptrA->nCard; j++){
                            (ptrA+j)->valore = (ptrA+(j+1))->valore;
                            (ptrA+j)->seme = (ptrA+(j+1))->seme;
                            (ptrA+j)->colore = (ptrA+(j+1))->colore;
                        }
                        // Modifico il numero di carte presenti nel settore_A
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
        // Controllo del comando
        if(c_1 == 'C' && c_2 == '>' && c_3 == 'B'){
            // Controllo ARRAY INDEX
            if(ptrC[from]->renderingCard != 0){
                // Controllo SEME
                if((ptrC[from]+((ptrC[from])->renderingCard - 1))->seme == (ptrB+to)->seme){
                    // Controllo VALORE
                    if(((ptrC[from]+((ptrC[from])->renderingCard - 1))->valore - 1) == (ptrB+to)->valore){
                        // Copio il valore del puntatore(from) al puntatore(to)
                        (ptrB+to)->valore = (ptrC[from]+((ptrC[from])->renderingCard - 1))->valore; 
                        // Salvo i dati del putatore(from)
                        for(i = 0; i < (ptrC[from])->renderingCard; i++){  
                            tempDorsi[i] = (ptrC[from]+i)->dorsi;
                            tempValore[i] = (ptrC[from]+i)->valore;
                            tempSeme[i] = (ptrC[from]+i)->seme;
                            tempColore[i] = (ptrC[from]+i)->colore;                
                        }
                        // Modifico il numero di carte presenti nel puntatore(from)
                        int temp_nCard = (ptrC[from])->renderingCard - 1;
                        // Memory allocation
                        //ptrC[from] = (struct stack_sector_c*) malloc(temp_nCard* sizeof(struct stack_sector_c)); 
                        if(temp_nCard > 0){
                            ptrC[from] = realloc(ptrC[from], temp_nCard* sizeof(struct stack_sector_c));
                        }               
                        // Carico i dati nel nuovo puntatore(from)
                        for(i = 0; i < temp_nCard; i++){  
                            (ptrC[from]+i)->dorsi = tempDorsi[i]; 
                            (ptrC[from]+i)->renderingCard = temp_nCard;
                            (ptrC[from]+i)->valore = tempValore[i];
                            (ptrC[from]+i)->seme = tempSeme[i];
                            (ptrC[from]+i)->colore = tempColore[i];
                        }
                        // Modifico il numero di carte visibili
                        (ptrC[from]+(temp_nCard - 1))->dorsi = 0;
                        // Modifico il numero di carte presenti nel puntatore(from)
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
        // Controllo vittoria
        winCheck();       
        // SCANF - CLEAR INPUT BUFFER
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    // Prima della chiusura del programma eseguo i seguenti comandi
    // FREE ALL POINTERS
    free(ptrA);
    free(ptrB);
    for(int j = 0; j < 9; j++){
        free(ptrC[j]);
    }
    // BG color
    system("COLOR 0");
    // Clear screen
    system("cls");  
    // Fix text color
    textcolor(15);    
    printf("Bye");
    delay(3);
    system("cls");  

    return 0;
}