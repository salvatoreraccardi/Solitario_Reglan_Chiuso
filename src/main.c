#include <stdio.h>
#include <conio.h>
#include <windows.h>

void textcolor(int colore);
void pokerCard(int valore, char seme, char colore);

// K 13
// Q 12
// J 11
int array_1_valore[6] = {13, 12, 4, 10, 11, 5};
char array_1_seme[6] = {'C', 'Q', 'C', 'Q', 'F', 'F'};
char array_1_colore[6] = {'R', 'R', 'B', 'R', 'B', 'R'};

void pokerCard(int valore, char seme, char colore){
    if(colore == 'R'){
        textcolor(12);
    }else{
        textcolor(15);
    }
    // Top card
    printf("%c", 218);
    for(int index = 0; index <= 4; index++)
        printf("%c", 196);
    printf("%c\n", 191);

    // Da modificare - fatto con i piedi
    if(valore == 13){
        printf("%cK    %c\n", 179, 179);
        printf("%c  %c  %c\n", 179, seme, 179);
        printf("%c     %c\n", 179, 179);
    }else if(valore == 12){
        printf("%cQ    %c\n", 179, 179);
        printf("%c  %c  %c\n", 179, seme, 179);
        printf("%c     %c\n", 179, 179);
    }else if(valore == 11){
        printf("%cJ    %c\n", 179, 179);
        printf("%c  %c  %c\n", 179, seme, 179);
        printf("%c     %c\n", 179, 179);
    }else if(valore == 10){
        printf("%c%d   %c\n", 179, valore, 179);
        printf("%c  %c  %c\n", 179, seme, 179);
        printf("%c     %c\n", 179, 179);
    }else{
        printf("%c%d    %c\n", 179, valore, 179);
        printf("%c  %c  %c\n", 179, seme, 179);
        printf("%c     %c\n", 179, 179);
    }  
     
    // bottom card
    printf("%c", 192);
    for(int index = 0; index <= 4; index++)
        printf("%c", 196);
    printf("%c\n", 217);

    
}

int main() {
    // clear screen
    system("cls");

    for (int i = 0; i < 6; i++)
        //printf("ID: %i - VALORE: %i - SEME: %c - COLORE: %c\n", i, array_1_valore[i], array_1_seme[i], array_1_colore[i]);
        pokerCard(array_1_valore[i], array_1_seme[i], array_1_colore[i]); 

    
    textcolor(15);
    getch(); 
    return 0;
}

void textcolor(int colore){
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), colore);
}