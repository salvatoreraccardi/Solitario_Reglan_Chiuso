#include <stdio.h>
#include <stdlib.h>

struct stack_sector_c{
    int dorsi;
    int valore;
    char seme;
    char colore;
};

int main(){
    struct stack_sector_c *ptr[2];
    int nCard[2];
    int i, j;
    // test stack 
    int dorsiStack[7] = {0, 1, 1, 1, 1, 1, 1};
    int valoreStack[7] = {12, 4, 6, 8, 10, 5, 3};
    char semeStack[7] = {'P', 'F', 'C', 'F', 'C', 'C', 'P'};
    char coloreStack[7] = {'R', 'R', 'B', 'R', 'B', 'R', 'B'};
    // test nCard
    nCard[0] = 7;
    nCard[1] = 6;
    // allocating memory for n numbers of struct stack_sector_c
    for(j = 0; j < 2; j++){
        ptr[j] = (struct stack_sector_c*) malloc(nCard[j]* sizeof(struct stack_sector_c));
    }
    // load data stack
    for(j = 0; j < 2; j++){
        for(i = 0; i < nCard[j]; i++){  
            (ptr[j]+i)->dorsi = dorsiStack[i];
            (ptr[j]+i)->valore = valoreStack[i];
            (ptr[j]+i)->seme = semeStack[i];
            (ptr[j]+i)->colore = coloreStack[i];
        }
    }
    // clear screen
    system("cls");
    // print data
    for(j = 0; j < 2; j++){
        printf("Displaying Information STACK_%d:\n", j);
        for(i = 0; i < nCard[j]; i++){
            printf("Dorso: %d\tValore: %d\tSeme: %c\tColore: %c\n", (ptr[j]+i)->dorsi, (ptr[j]+i)->valore, (ptr[j]+i)->seme, (ptr[j]+i)->colore);
        }      
    }
   return 0;
}