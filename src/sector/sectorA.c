// K 13
// Q 12
// J 11
int array_1_valore[6] = {13, 12, 4, 10, 11, 5};
char array_1_seme[6] = {'C', 'Q', 'C', 'Q', 'F', 'F'};
char array_1_colore[6] = {'B', 'R', 'R', 'B', 'B', 'R'};

void sector_A(int nCard, int *cardValore){
    //int nCard = 6;
    int index = 0;
    int step1 = 0;
    int step2 = 0;

    // TopCard
    for(index = 0; index < nCard; index++){   
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 0);  
        printf("%c", 218);
        for(int i = 0; i < 5; i++)
            printf("%c", 196);
        printf("%c", 191);       
        step1 += 8;
    }
    
    //MidCard - valore
    step1 = 0;
    step2 = 6;
    for(int index = 0; index < nCard; index++){
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 1);
        printf("%c %i", 179, *(cardValore + index));
        
        gotoxy(step2, 1);
        printf("%c", 179);

        step1 += 8;
        step2 += 8;
    }

    //MidCard - empty
    step1 = 0;
    step2 = 6;
    for(index = 0; index < nCard; index++){
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 2);
        printf("%c", 179);

        gotoxy(step2, 2);
        printf("%c", 179);
        step1 += 8;
        step2 += 8;
    }      

    //MidCard - seme  
    step1 = 0;
    step2 = 6;
    for(index = 0; index < nCard; index++){
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 3);  
        printf("%c", 179);
        gotoxy(step1 + 5, 3);
        printf("%c", array_1_seme[index]);
        gotoxy(step2, 3);  
        printf("%c", 179);
        step1 += 8;
        step2 += 8;
    }

    //BottomCard - end
    step1 = 0;
    step2 = 6;
    for(index = 0; index < nCard; index++){
        if(array_1_colore[index] == 'R'){
            textcolor(12);
        }else{
            textcolor(15);
        }
        gotoxy(step1, 4);
        printf("%c", 192);
        for(int j = 0; j < 5; j++)
            printf("%c", 196);
        gotoxy(step2, 4);    
        printf("%c", 217);
        step1 += 8;
        step2 += 8;
    }

}