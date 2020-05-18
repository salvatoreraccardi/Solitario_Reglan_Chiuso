void sector_B(int *cardValore, char *cardColore, char *cardSeme){
    int index = 0;
    int i = 0;
    // offset1/2 per gestire la visualizzazione delle carte
    int offset1 = 0;
    int offset2 = 0;

    // topCard
    offset1 = 85;
    for(index = 0; index < 4; index++){
         // colore stampa
        if(*(cardColore + index) == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        // imposto la posizione del cursore (x,y)
        gotoxy(offset1, 0);
        // print ┌
        printf("%c", 218);
        for(i = 0; i < 5; i++)
            // print ─
            printf("%c", 196);
        // print ┐    
        printf("%c", 191);      
        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        // OUTPUT_1: ┌─────┐
    }

    //MidCard - valore
    offset1 = 85;
    offset2 = 91;
    for(index = 0; index < 4; index++){
        // colore stampa
        if(*(cardColore + index) == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(offset1, 1);
        // print valore carta - (A...K)
        if(*(cardValore + index) > 1 && *(cardValore + index) <= 10){
            printf("%c %i", 179, *(cardValore + index));
        }else if(*(cardValore + index) == 1){
            printf("%c A", 179);
        }else if(*(cardValore + index) == 11){
            printf("%c J", 179);
        }else if(*(cardValore + index) == 12){    
            printf("%c Q", 179);
        }else if(*(cardValore + index) == 13){
            printf("%c K", 179);
        }    
        
        gotoxy(offset2, 1);
        printf("%c", 179);

        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        offset2 += 8;
        // OUTPUT_2: │ 8   │
    }

    //MidCard - empty
    offset1 = 85;
    offset2 = 91;
    for(i = 0; i < 2; i++){
        for(index = 0; index < 4; index++){
            // colore stampa
            if(*(cardColore + index) == 'R'){
                textcolor(12);
            }else{
                textcolor(15);
            }
            gotoxy(offset1, 2 + i);
            printf("%c", 179);

            gotoxy(offset2, 2 + i);
            printf("%c", 179);
            // traslazione di 8pixel per il print successivo 
            offset1 += 8;
            offset2 += 8;
            // OUTPUT_3: │     │
        }  
        offset1 = 85;
        offset2 = 91;    
    }

    //MidCard - seme  
    offset1 = 85;
    offset2 = 91;
    for(index = 0; index < 4; index++){
        // colore stampa
        if(*(cardColore + index) == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(offset1, 4);  
        printf("%c", 179);
        gotoxy(offset1 + 5, 4);
        // Print del seme
        printf("%c", *(cardSeme + index));
        gotoxy(offset2, 4);  
        printf("%c", 179);
        
        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        offset2 += 8;
        // OUTPUT_4: │    ♠│ 
    }

    //BottomCard - end
    offset1 = 85;
    offset2 = 91;
    for(index = 0; index < 4; index++){
        // colore stampa
        if(*(cardColore + index) == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(offset1, 5);
        printf("%c", 192);
        for(i = 0; i < 5; i++)
            printf("%c", 196);
        gotoxy(offset2, 5);    
        printf("%c", 217);
        // traslazione di 8pixel per il print successivo 
        offset1 += 8;
        offset2 += 8;
        // OUTPUT_5: └─────┘
    }

}