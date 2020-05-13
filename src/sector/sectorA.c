// K 13
// Q 12
// J 11

// Vettori per la simulazione
int array_1_valore[6] = {13, 12, 4, 10, 11, 5};
char array_1_seme[6] = {'C', 'Q', 'C', 'Q', 'F', 'F'};
char array_1_colore[6] = {'B', 'R', 'R', 'B', 'B', 'R'};

void sector_A(int nCard, int *cardValore){
    int index = 0;
    // offset1/2 per gestire la visualizzazione delle carte
    int offset1 = 0;
    int offset2 = 0;

    // TopCard
    for(index = 0; index < nCard; index++){   
        // colore stampa
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        // imposto la posizione del cursore (x,y)
        gotoxy(offset1, 0);
        // print ┌
        printf("%c", 218);
        for(int i = 0; i < 5; i++)
            // print ─
            printf("%c", 196);
        // print ┐    
        printf("%c", 191);      
        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        // OUTPUT_1: ┌─────┐
    }
    
    //MidCard - valore
    offset1 = 0;
    offset2 = 6;
    for(int index = 0; index < nCard; index++){
        // colore stampa
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(offset1, 1);
        // print valore carta - (1...K)
        printf("%c %i", 179, *(cardValore + index));
        
        gotoxy(offset2, 1);
        printf("%c", 179);

        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        offset2 += 8;
        // OUTPUT_2: │ 8   │
    }

    //MidCard - empty
    offset1 = 0;
    offset2 = 6;
    for(index = 0; index < nCard; index++){
        // colore stampa
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(offset1, 2);
        printf("%c", 179);

        gotoxy(offset2, 2);
        printf("%c", 179);
        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        offset2 += 8;
        // OUTPUT_3: │     │
    }      

    //MidCard - seme  
    offset1 = 0;
    offset2 = 6;
    for(index = 0; index < nCard; index++){
        // colore stampa
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(offset1, 3);  
        printf("%c", 179);
        gotoxy(offset1 + 5, 3);
        // Print del seme
        printf("%c", array_1_seme[index]);
        gotoxy(offset2, 3);  
        printf("%c", 179);
        
        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        offset2 += 8;
        // OUTPUT_4: │    ♠│ 
    }

    //BottomCard - end
    offset1 = 0;
    offset2 = 6;
    for(index = 0; index < nCard; index++){
        // colore stampa
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(offset1, 4);
        printf("%c", 192);
        for(int j = 0; j < 5; j++)
            printf("%c", 196);
        gotoxy(offset2, 4);    
        printf("%c", 217);
        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        offset2 += 8;
        // OUTPUT_5: └─────┘
    }

    // FINAL RESULT
    // INDEX:      (0)     (1)     (2)     (3)
    // COLOR:      (R)     (R)    (B/W)   (B/W)
    // OUTPUT_1: ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐
    // OUTPUT_2: │ 8   │ │ A   │ │ Q   │ │ 2   │
    // OUTPUT_3: │     │ │     │ │     │ │     │
    // OUTPUT_4: │    ♠│ │    ♥│ │    ♦│ │    ♣│
    // OUTPUT_5: └─────┘ └─────┘ └─────┘ └─────┘
}