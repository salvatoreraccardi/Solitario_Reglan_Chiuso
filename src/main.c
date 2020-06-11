//
// Solitario Reglan Chiuso
//
// Salvatore Raccardi salvatore.raccardi@community.unipa.it
// Antonino Graziano antonino.graziano01@community.unipa.it
//

#include <stdio.h>
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
#include "graphics/sectorA.c"
#include "graphics/sectorB.c"
#include "graphics/sectorC.c"
#include "deck.c"
#include "playground.c"

int main() {
    // Nome della console
    SetConsoleTitle("Solitario Reglan Chiuso");
    system("cls");
    /* 
        Menù
    */
    // Cursore disabilitato
    hidecursor(false);
    // Imposto la dimensione della console
    SMALL_RECT windowSize = {0, 0, 117, 52};
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
    system("COLOR 1F");

    gotoxy(43, 10);
    printf("Solitario Reglan Chiuso");
    gotoxy(30, 13);
    printf("Regole");
    gotoxy(30, 15);
    printf("1. Ordina le carte per seme in sequenza dall'asso al re");
    gotoxy(30, 16);
    printf("3. Gli spazi possono essere riempiti con qualsiasi carta disponibile");
    gotoxy(30, 17);
    printf("4. Ordina le carte alternando il colore");
    gotoxy(30, 18);
    printf("5. Puoi spostare solo una carta per ogni mossa");
     
    gotoxy(44, 30);
    printf("Per una nuova partita");
    gotoxy(47, 32);
    printf("> PREMI INVIO <");

    // WAIT
    while(getch() != 13){}
    system("cls");
    system("COLOR 20");

    // Caricamento partita 
    loading('f'); 
    // Generazione del mazzo
    deckGeneration();
    // Il primo caricamento - campo da gioco
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
        gotoxy(95, 20);
        printf("Comandi:");
        gotoxy(95, 22);
        printf("from(da) - to(a)");
        gotoxy(95, 24);
        printf("A>B from to");
        gotoxy(95, 25);
        printf("A>C from to");
        gotoxy(95, 26);
        printf("C>C from to");
        gotoxy(95, 27);
        printf("C>B from to");
        gotoxy(95, 29);
        printf("es. A>C 0 1");
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
        if((ptrB+0)->valore == 13 && (ptrB+1)->valore == 13 && (ptrB+2)->valore == 13 && (ptrB+3)->valore == 13){     
            system("cls");
            hidecursor(false);
            system("COLOR 0E"); 
            gotoxy(52, 10);
            printf("HAI VINTO!");
            textcolor(15);
            gotoxy(35, 15);
            printf("PREMI (INVIO) PER INIZIARE UNA NUOVA PARTITA");
            gotoxy(42, 17);
            printf("PREMI (ESC) PER USCIRE DAL GIOCO");
            int value, cycle = 1;
            // WAIT
            while(cycle == 1){
                value = getch();
                if(value == 27){
                    // EXIT
                    cycle = 0;
                    gameStatus = 0;
                }else if(value == 13){
                    // ENTER
                    system("cls");
                    system("COLOR 20");
                    // Caricamento partita 
                    loading('n'); 
                    // Generazione del deck
                    deckGeneration();
                    // Playground first rendering
                    firstRendering(); 
                    cycle = 0;
                }
            }
            
        } 
        hidecursor(true);      
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