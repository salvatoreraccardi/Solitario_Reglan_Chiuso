#include <stdio.h>
// For keyboard input
#include <conio.h>

// Playground 
int playground() {
    printf("playground");
    // ASCII CHAR - OK!
    int i = 179;
    printf("%c\n", i);
    // ISSUES - UNICODE 
    //wchar_t data = "\x2660\x2663\x2665\x2666";
    printf("\2660");
} 

// Keyboard input
int keyboard_input(){
    int value;
    value = getch();
    // printf("Keyboard request  -> %d\n", value);
    /*
    if(keyboard_interrupt() == 27){
        printf("ESC");
    }else if(keyboard_interrupt() == 72){
        printf("ARROW UP\n");
    }else if(keyboard_interrupt() == 80){
        printf("ARROW DOWN\n");
    }else if(keyboard_interrupt() == 77){
        printf("ARROW RIGHT\n");
    }else if(keyboard_interrupt() == 75){
        printf("ARROW LEFT\n");
    }*/
    return value;
    
}

int pokerCard(char seme, int valore){
    printf("%c", 218);
    for(int index = 0; index <= 6; index++)
        printf("%c", 196);
    printf("%c\n", 191);
    
    printf("%c%d      %c\n", 179, valore, 179);
    printf("%c   %c   %c\n", 179, seme, 179);
    printf("%c       %c\n", 179, 179);


    printf("%c", 192);
    for(int index = 0; index <= 6; index++)
        printf("%c", 196);
    printf("%c\n", 217);
}

int main() {
    int set1N[4] = {3, 8, 4, 7};
    char set1S[4] = {'C', 'P', 'F', 'Q'};
    int count = 0;

    for(int j = 0; j <= 4; j++){
        printf("%c", 218);
        for(int index = 0; index <= 6; index++)
            printf("%c", 196);
        printf("%c\n", 191);
    }  
    pokerCard(set1S[count], set1N[count]);       

    while(1){
        if(keyboard_input() == 27){
            break;
        }else if(keyboard_input() == 72 && count <= 3){
            count++;
        }else if(keyboard_input() == 80 && count >= 1){
            count--;
        }
        
        pokerCard(set1S[count], set1N[count]);       
    }

    

    return 0;
}