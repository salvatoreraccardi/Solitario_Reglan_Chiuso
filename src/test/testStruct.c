#include <stdio.h>
#include <stdlib.h>

struct stack_sector_c{
    int valore;
    char seme;
    char colore;
};

int main(){
    struct stack_sector_c *ptr[2];
    int nCard[2];
    int i, j;
    // test stack 
    int valoreStack[3] = {12, 4, 6};
    char semeStack[3] = {'P', 'F', 'C'};
    char coloreStack[3] = {'R', 'R', 'B'};
    // test nCard
    nCard[0] = 2;
    nCard[1] = 3;
    // allocating memory for n numbers of struct person
    for(j = 0; j < 2; j++){
        ptr[j] = (struct stack_sector_c*) malloc(nCard[j]* sizeof(struct stack_sector_c));
    }
    // load data stack
    for(j = 0; j < 2; j++){
        for(i = 0; i < nCard[j]; i++){      
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
            printf("Valore: %d\tSeme: %c\tColore: %c\n", (ptr[j]+i)->valore, (ptr[j]+i)->seme, (ptr[j]+i)->colore);
        }      
    }
   return 0;
}