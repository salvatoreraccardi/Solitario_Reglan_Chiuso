void sector_C(int nCard, int indexC, int *matrixDorso, int *matrixValore, char *matrixSeme, char *matrixColore, int offsetX){
    //matrix
    int lines = nCard;
    int columns = nCard;
    //counter
    //int indexC = 0;
    int indexL = 0;
    //int offsetX = 0;
    int offset1 = 10;
    int offset2 = 0; // Solo per il rendering delle carte che si vedono

    textcolor(15);
    if(nCard > 0){
        for(indexL = 0; indexL < nCard - 1; indexL++){
            // rendering dorso
            if(matrixDorso[indexC*lines + indexL] == 1){
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
            }else if(matrixDorso[indexC*lines + indexL] == 0){
                // rendering carta
                if(matrixColore[indexC*lines + indexL] == 'R'){
                    textcolor(12);
                }else{
                    textcolor(15);
                }
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
                printf("%i", matrixValore[indexC*lines + indexL]);
                gotoxy(offsetX + (offset2 += 4), offset1 - 1);
                // seme
                printf("%c", matrixSeme[indexC*lines + indexL]);
                gotoxy(offsetX + (offset2 += 1), offset1 - 1);
                printf("%c", 179);
            }  
        }  


        // rendering prima carta

        if(matrixColore[indexC*lines + (nCard - 1)] == 'R'){
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
        printf("%c %i", 179, matrixValore[indexC*lines + (nCard - 1)]);
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
        printf("%c", matrixSeme[indexC*lines + (nCard - 1)]);
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