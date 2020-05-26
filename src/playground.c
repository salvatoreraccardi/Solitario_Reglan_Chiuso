void firstRendering(){
    /* 
        SECTOR_A - first rendering deck
    */ 
    int default_nCard = 6;
    ptrA = (struct stack_sector_a*) malloc(default_nCard* sizeof(struct stack_sector_a));
    ptrA->nCard = default_nCard;
    for(int i = 0; i < 6; i++){
        (ptrA+i)->valore = deck.valore[46 + i];
        (ptrA+i)->seme = deck.seme[46 + i];
        (ptrA+i)->colore = deck.colore[46 + i];
    }
    sector_A();

    /* 
        SECTOR_B - first rendering deck
    */ 
    ptrB = (struct stack_sector_b*) malloc(4* sizeof(struct stack_sector_b));
    for(int i = 0; i < 4; i++){
        (ptrB+i)->valore = deck.valore[i];
        (ptrB+i)->seme = deck.seme[i];
        (ptrB+i)->colore = deck.colore[i];
    }
    sector_B();

    /* 
        SECTOR_C - first rendering deck
    */ 
    
    int offsetData = 4; // TODO: EDIT
    int i, j;

    int default_RenderingCard[9] = {7, 7, 7, 6, 5, 4, 3, 2, 1};

    // allocating memory for n numbers of struct stack_sector_c
    for(j = 0; j < 9; j++){
        ptrC[j] = (struct stack_sector_c*) malloc(default_RenderingCard[j]* sizeof(struct stack_sector_c));
    }

    // load data stack
    for(j = 0; j < 9; j++){
        for(i = 0; i < default_RenderingCard[j]; i++){  
            (ptrC[j]+i)->dorsi = 1; // 1 for first rendering
            (ptrC[j]+i)->renderingCard = default_RenderingCard[j];
            (ptrC[j]+i)->valore = deck.valore[offsetData + i];
            (ptrC[j]+i)->seme = deck.seme[offsetData + i];
            (ptrC[j]+i)->colore = deck.colore[offsetData + i];
        }      
        offsetData += default_RenderingCard[j];
    }
    // rendering sector_C
    sector_C();
}

// ERROR POPUP
void errorAlert(char type){
    textcolor(12);
    gotoxy(0, 55);                     
    if(type == 'A'){
        // ARRAY INDEX - NON VALIDO
        printf("Mossa non consentita, carte non sufficienti!");
    }else if(type == 'V'){
        // VALORE DELLA CARTA 
        printf("Il valore della carta non consente la mossa!");
    }else if(type == 'C'){
        // COLORE DELLA CARTA
        printf("Il colore della carta non consente la mossa!");
    }else if(type == 'S'){
        // SEME DELLA CARTA
        printf("Il seme della carta non consente la mossa!");
    }else if(type == 'G'){  
        // ERRORE GENERICO
        printf("Stai sbagliando qualcosa, controlla che il comando sia corretto!");
    }
    textcolor(15);
}