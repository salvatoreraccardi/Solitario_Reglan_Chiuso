void sector_C(int nCard, int *cDorso, int *cValore, char *cSeme, char *cColore, int offsetX){
    int index = 0;
    int offset1 = 10;
    int offset2 = 0; // Solo per il rendering delle carte che si vedono

    textcolor(15);
    if(nCard > 0){
        for(index = 0; index < nCard - 1; index++){
            // rendering dorso
            if(*(cDorso + index) == 1){
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
            }else if(*(cDorso + index) == 0){

                // rendering carta
                if(*(cColore + index) == 'R'){
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
                if(*(cValore + index) <= 10){
                    printf("%i",*(cValore + index));
                }else if(*(cValore + index) == 11){
                    printf("J");
                }else if(*(cValore + index) == 12){    
                    printf("Q");
                }else if(*(cValore + index) == 13){
                    printf("K");
                }
                gotoxy(offsetX + (offset2 += 4), offset1 - 1);
                // seme
                printf("%c", *(cSeme + index));
                gotoxy(offsetX + (offset2 += 1), offset1 - 1);
                printf("%c", 179);
            }  
        }  


        // rendering prima carta

        if(*(cColore + index) == 'R'){
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
        if(*(cValore + index) <= 10){
            printf("%c %i", 179, *(cValore + index));
        }else if(*(cValore + index) == 11){
            printf("%c J", 179);
        }else if(*(cValore + index) == 12){    
            printf("%c Q", 179);
        }else if(*(cValore + index) == 13){
            printf("%c K", 179);
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
        printf("%c", *(cSeme + index));
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
}