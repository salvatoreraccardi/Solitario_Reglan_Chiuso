#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "startup.c"

void textcolor(int colore);
void gotoxy(short x, short y);
void delay(int number_of_seconds);
void topCard(int nCard, int *cardValore);

// K 13
// Q 12
// J 11
int array_1_valore[6] = {13, 12, 4, 10, 11, 5};
char array_1_seme[6] = {'C', 'Q', 'C', 'Q', 'F', 'F'};
char array_1_colore[6] = {'B', 'R', 'R', 'B', 'B', 'R'};

void topCard(int nCard, int *cardValore){
    //int nCard = 6;
    int index = 0;
    int step1 = 0;
    int step2 = 0;

    // TopCard
    for(index = 0; index < nCard; index++){   
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 0);  
        printf("%c", 218);
        for(int i = 0; i < 5; i++)
            printf("%c", 196);
        printf("%c", 191);       
        step1 += 8;
    }
    
    //MidCard - valore
    step1 = 0;
    step2 = 6;
    for(int index = 0; index < nCard; index++){
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 1);
        printf("%c %i", 179, *(cardValore + index));
        
        gotoxy(step2, 1);
        printf("%c", 179);

        step1 += 8;
        step2 += 8;
    }

    //MidCard - empty
    step1 = 0;
    step2 = 6;
    for(index = 0; index < nCard; index++){
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 2);
        printf("%c", 179);

        gotoxy(step2, 2);
        printf("%c", 179);
        step1 += 8;
        step2 += 8;
    }      

    //MidCard - seme  
    step1 = 0;
    step2 = 6;
    for(index = 0; index < nCard; index++){
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 3);  
        printf("%c", 179);
        gotoxy(step1 + 5, 3);
        printf("%c", array_1_seme[index]);
        gotoxy(step2, 3);  
        printf("%c", 179);
        step1 += 8;
        step2 += 8;
    }

    //BottomCard - end
    step1 = 0;
    step2 = 6;
    for(index = 0; index < nCard; index++){
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 4);
        printf("%c", 192);
        for(int j = 0; j < 5; j++)
            printf("%c", 196);
        gotoxy(step2, 4);    
        printf("%c", 217);
        step1 += 8;
        step2 += 8;
    }

}

int main() {
    // console name
    SetConsoleTitle("Solitario Reglan Chiuso");
    // clear screen
    system("cls");
    splashscreen();

    // vettore dinamico
    int *cardValore, cardN = 6;
    cardValore = (int*) calloc(cardN, sizeof(int));
    // carico il vettore
    for(int i = 0; i < cardN; i++)
        *(cardValore + i) = i;

    topCard(cardN, cardValore);

    delay(4); 
    system("cls");

    cardN = 4;
    // carico il vettore
    for(int i = 0; i < cardN; i++)
        *(cardValore + i) = array_1_valore[i];

    topCard(cardN, cardValore);


    textcolor(15);
    getch(); 
    return 0;
}

void textcolor(int colore){
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), colore);
}

void gotoxy(short x, short y){
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}