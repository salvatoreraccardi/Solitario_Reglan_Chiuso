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
int keyboard_interrupt(){
    int value;
    value = getch();
    // printf("Keyboard request  -> %d\n", value);
    return value;
}

int main() {


    while(1){
        // KEYBOARD
        if(keyboard_interrupt() == 27){
            printf("ESC");
            break; 
        }else if(keyboard_interrupt() == 72){
            printf("ARROW UP\n");
        }else if(keyboard_interrupt() == 80){
            printf("ARROW DOWN\n");
        }else if(keyboard_interrupt() == 77){
            printf("ARROW RIGHT\n");
        }else if(keyboard_interrupt() == 75){
            printf("ARROW LEFT\n");
        }
    }

    return 0;
}