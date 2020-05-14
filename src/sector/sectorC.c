//int matrix_valori[2][2] = {{4, 7},{8, 4}};

void sector_C(int nDorsi, int nCard, int offsetX){

    // rendering dorsi
    int offset1 = 10;
    int offset2 = 0; // Solo per il rendering delle carte che si vedono

    textcolor(15);
    for(int j = 0; j < nDorsi; j++){
        // TODO: SELEZIONE COLORE
        gotoxy(offsetX, offset1);
        printf("%c", 218);
        for(int i = 0; i < 5; i++)
            // print ─
            printf("%c", 196);
        // print ┐    
        printf("%c", 191);

        gotoxy(offsetX, offset1 + 1);
        printf("%c", 179);
        for(int i = 0; i < 5; i++)
            // print ▒
            printf("%c", 177);
        printf("%c", 179);  
        offset1 += 2;
    }
    
    // rendering carte
    for(int i = 0; i < nCard - 1; i++){
        // TODO: SELEZIONE COLORE
        gotoxy(offsetX, offset1);
        printf("%c", 218);
            for(int i = 0; i < 5; i++)
            // print ─
            printf("%c", 196);
        // print ┐    
        printf("%c", 191);
        offset1 += 2;

        offset2 = 0; 
        gotoxy(offsetX + offset2, offset1 - 1);
        printf("%c", 179);     
        gotoxy(offsetX + (offset2 += 1), offset1 - 1);
        // valore 
        printf("%i", 3);
        gotoxy(offsetX + (offset2 += 4), offset1 - 1);
        // seme
        printf("%c", 'C');
        gotoxy(offsetX + (offset2 += 1), offset1 - 1);
        printf("%c", 179);
    }   

    // rendering first card
    gotoxy(offsetX, offset1);
    printf("%c", 218);
        for(int i = 0; i < 5; i++)
        // print ─
        printf("%c", 196);
    // print ┐    
    printf("%c", 191);
    // OUTPUT_1: ┌─────┐

    offset1 += 1;
    offset2 = 6;
    gotoxy(offsetX, offset1);
    printf("%c %i", 179, 10);
    gotoxy(offsetX + offset2, offset1);
    printf("%c", 179);
    // OUTPUT_2: │ 10   │

    offset1 += 1;
    gotoxy(offsetX, offset1);
    printf("%c", 179);
    gotoxy(offsetX + offset2, offset1);
    printf("%c", 179);
    // OUTPUT_3: │     │

    offset1 += 1;
    gotoxy(offsetX, offset1);  
    printf("%c", 179);
    gotoxy(offsetX + (offset2 - 1), offset1);
    // Print del seme
    printf("%c", 'P');
    gotoxy(offsetX + offset2, offset1);  
    printf("%c", 179);
    // OUTPUT_4: │    ♠│

    offset1 += 1;
    gotoxy(offsetX, offset1);
    printf("%c", 192);
    for(int j = 0; j < 5; j++)
        printf("%c", 196);
    gotoxy(offsetX + offset2, offset1);    
    printf("%c", 217);
    // OUTPUT_5: └─────┘

}