void menu(){
    hidecursor(false);
    SMALL_RECT windowSize = {0, 0, 117, 52};
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
    system("COLOR 1F");

    gotoxy(43, 10);
    printf("Solitario Reglan Chiuso");

    gotoxy(40, 13);
    printf("Lista comandi");
    gotoxy(40, 15);
    printf("(1) A>B from to");
    gotoxy(40, 16);
    printf("(2) A>C from to");
    gotoxy(40, 17);
    printf("(3) C>C from to");
    gotoxy(40, 18);
    printf("(4) C>B from to");
    
    gotoxy(44, 20);
    printf("Per una nuova partita");
    gotoxy(47, 22);
    printf("> PREMI INVIO <");


    // sleep
    while(getch() != 13){}
    system("COLOR 0F");
    
    //printf("Salvatore Raccardi: salvatore.raccardi@community.unipa.it\n");
    //printf("Antonino Graziano: antonino.graziano01@community.unipa.it\n");
    //delay(4);
    system("cls");
}