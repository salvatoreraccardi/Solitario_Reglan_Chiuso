void firstRendering(){
    // Variabili per i contatori
    int i, j;
    /* 
        SECTOR_A - Prima generazione del mazzo(inizio partita)
    */ 
    int default_nCard = 6;
    // Memory allocation - per la struct "stack_sector_a" 
    ptrA = (struct stack_sector_a*) malloc(default_nCard* sizeof(struct stack_sector_a));
    ptrA->nCard = default_nCard;
    // Caricamento dei dati dalla struct deck al puntatore del settore_A
    for(i = 0; i < 6; i++){
        (ptrA+i)->valore = deck.valore[46 + i];
        (ptrA+i)->seme = deck.seme[46 + i];
        (ptrA+i)->colore = deck.colore[46 + i];
    }
    // Grafica settore A
    sector_A();

    /* 
        SECTOR_B - Prima generazione del mazzo(inizio partita)
    */ 
    // Memory allocation - per la struct "stack_sector_b" 
    ptrB = (struct stack_sector_b*) malloc(4* sizeof(struct stack_sector_b));
    // Caricamento dei dati dalla struct deck al puntatore del settore_B
    for(i = 0; i < 4; i++){
        (ptrB+i)->valore = deck.valore[i];
        (ptrB+i)->seme = deck.seme[i];
        (ptrB+i)->colore = deck.colore[i];
    }
    // Grafica settore B
    sector_B();

    /* 
        SECTOR_C - Prima generazione del mazzo(inizio partita)
    */ 
    
    int offsetData = 4;
    // Pattern per la prima generazione delle carte
    int default_RenderingCard[9] = {7, 7, 7, 6, 5, 4, 3, 2, 1};
    // Memory allocation - per "n" numeri di struct "stack_sector_a" 
    for(j = 0; j < 9; j++){
        ptrC[j] = (struct stack_sector_c*) malloc(default_RenderingCard[j]* sizeof(struct stack_sector_c));
    }
    // Caricamento dei dati dalla struct deck al puntatore[j] del settore_C
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
    // Grafica settore C
    sector_C();
}

// Caricamento partita
void loading(char type){
    char semi[4] = {3,5,4,6};   
    system("cls");
    // Cursore disabilitato
    hidecursor(false);
    gotoxy(45, 18);
    if(type == 'f'){
        // Prima partita
        printf("Caricamento della partita");
    }else if(type == 'n'){
        // Nuova partita
        printf("Caricamento nuova partita");
    }
    for(int i = 0; i < 4; i++){
        if(i == 0 || i == 2){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 44);
        }else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
        }
        gotoxy(54 + (i * 2), 20);
        printf("%c", semi[i]);
        delay(1);
    }
    hidecursor(true);
    system("cls");
}

// Messaggio di errore
void errorAlert(char type){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
    gotoxy(0, 52);                     
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