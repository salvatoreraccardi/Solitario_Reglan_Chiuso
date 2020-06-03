void menu(){
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
    system("COLOR 0F");

    system("cls");
}