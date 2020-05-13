void sector_B(){
    int index = 0;
    // offset1/2 per gestire la visualizzazione delle carte
    int offset1 = 0;
    int offset2 = 0;

    textcolor(15); //test
    offset1 = 85;
    gotoxy(offset1, 0);

    for(int j = 0; j < 4; j++){
        printf("%c", 218);
        for(int i = 0; i < 5; i++)
            // print ─
            printf("%c", 196);
        // print ┐    
        printf("%c", 191);
        offset1 += 8;
        gotoxy(offset1, 0);
    }

}