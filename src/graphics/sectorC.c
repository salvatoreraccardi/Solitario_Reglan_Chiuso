void sector_C(){
    int index = 0;
    int offsetX = 0;
    int offset1 = 10;
    int offset2 = 0; // Solo per il rendering delle carte che si vedono
    int j;

    textcolor(15);
    for(j = 0; j < 9; j++){
        if((ptrC[j])->renderingCard != 0){
            for(index = 0; index < ((ptrC[j]+index)->renderingCard - 1); index++){
                // rendering dorso
                if((ptrC[j]+index)->dorsi == 1){
                    // rendering dorso
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
                }else if((ptrC[j]+index)->dorsi == 0){

                    // rendering carta
                    if((ptrC[j]+index)->colore == 'R'){
                        textcolor(12);
                    }else{
                        textcolor(15);
                    }
                    
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
                    // print valore carta - (2...K)
                    if((ptrC[j]+index)->valore <= 10){
                        printf("%i",(ptrC[j]+index)->valore);
                    }else if((ptrC[j]+index)->valore == 11){
                        printf("J");
                    }else if((ptrC[j]+index)->valore == 12){    
                        printf("Q");
                    }else if((ptrC[j]+index)->valore == 13){
                        printf("K");
                    }
                    gotoxy(offsetX + (offset2 += 4), offset1 - 1);
                    // seme
                    printf("%c", (ptrC[j]+index)->seme);
                    gotoxy(offsetX + (offset2 += 1), offset1 - 1);
                    printf("%c", 179);
                }  
            }  

                        
            // rendering prima carta
            if((ptrC[j]+index)->colore == 'R'){
                textcolor(12);
            }else{
                textcolor(15);
            }

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
            // print valore carta - (2...K)
            if((ptrC[j]+index)->valore <= 10){
                printf("%c%i", 179, (ptrC[j]+index)->valore);
            }else if((ptrC[j]+index)->valore == 11){
                printf("%cJ", 179);
            }else if((ptrC[j]+index)->valore == 12){    
                printf("%cQ", 179);
            }else if((ptrC[j]+index)->valore == 13){
                printf("%cK", 179);
            }
            gotoxy(offsetX + offset2, offset1);
            printf("%c", 179);
            // OUTPUT_2: │ 10   │

            for(int i = 0; i < 2; i++){
                offset1 += 1;
                gotoxy(offsetX, offset1);
                printf("%c", 179);
                gotoxy(offsetX + offset2, offset1);
                printf("%c", 179);
            }      
            // OUTPUT_3: │     │

            offset1 += 1;
            gotoxy(offsetX, offset1);  
            printf("%c", 179);
            gotoxy(offsetX + (offset2 - 1), offset1);
            // Print del seme
            printf("%c", (ptrC[j]+index)->seme);
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
        }else{
            // rendering slot vuoto

            // OUTPUT_1: ┌─────┐
            // OUTPUT_2: │     │
            // OUTPUT_3: │     │
            // OUTPUT_4: │     │
            // OUTPUT_5: └─────┘

            // OUTPUT_1:
            gotoxy(offsetX, offset1);
            printf("%c", 218);
            for(int i = 0; i < 5; i++)
                printf("%c", 196);
            printf("%c", 191);

            // OUTPUT_2:
            offset1 += 1;
            offset2 = 6;
            gotoxy(offsetX, offset1);
            printf("%c", 179);
            gotoxy(offsetX + offset2, offset1);
            printf("%c", 179);

            // OUTPUT_3:
            for(int i = 0; i < 2; i++){
                offset1 += 1;
                gotoxy(offsetX, offset1);
                printf("%c", 179);
                gotoxy(offsetX + offset2, offset1);
                printf("%c", 179);
            }      

            // OUTPUT_4:
            offset1 += 1;
            gotoxy(offsetX, offset1);  
            printf("%c", 179);
            gotoxy(offsetX + offset2, offset1);  
            printf("%c", 179);

            // OUTPUT_5:
            offset1 += 1;
            gotoxy(offsetX, offset1);
            printf("%c", 192);
            for(int j = 0; j < 5; j++)
                printf("%c", 196);
            gotoxy(offsetX + offset2, offset1);    
            printf("%c", 217);
        }
        offset1 = 10;
        offsetX += 8;
        textcolor(15);
    }
}