// Carte rosse: 13x♥ - 13x♦
// Carte nere: 13x♣ - 13x♠ 
int deckValore[52];
char deckSeme[52];
char deckColore[52];

char semi[4] = {3,5,4,6};

int printRandoms(int lower, int upper){ 
    int num = (rand() % 
            (upper - lower + 1)) + lower; 
    return num; 
} 
  

void deckGeneration(){

    // Generazione del deck

    // Assi
    for(int y = 0; y < 4; y++){
        deckValore[y] = 1;
        deckSeme[y] = semi[y];
        if(y == 0 || y == 2){
            deckColore[y] = 'R';
        }else{
            deckColore[y] = 'B';
        }
    }

    // tutte le carte
    int index = 2;
    int offset = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 12; j++){
            deckValore[4 + j + offset] = index;
            deckSeme[4 + j + offset] = semi[i];
            if(i == 0 || i == 2){
                deckColore[4 + j + offset] = 'R';
            }else{
                deckColore[4 + j + offset] = 'B';
            }
            index++;
        }
        index = 2;
        offset += 12;
    }   

    // DEBUG: PRINT DATASET    
    for(int k = 0; k < 52; k++){
        printf("Index: %i \t Valore: %i \t Seme: %c \t Colore: %c \n", k, deckValore[k], deckSeme[k], deckColore[k]);
    }


    printf("\n\n\nShuffling cards \n\n\n");
    // Shuffling cards
    
    srand(time(0)); // seed for random index

    for(int swap = 0; swap < 10; swap++){
        int rnd1 = 0;
        int rnd2 = 0;
        // Random index
        while(rnd1 == rnd2 && deckValore[rnd1] == deckValore[rnd2]){
            rnd1 = printRandoms(4, 51);
            rnd2 = printRandoms(4, 51);
        }
        
        printf("RND1: %i \t RND2: %i\n", rnd1, rnd2);    

        // Swap Valore
        int tempValore = deckValore[rnd1];
        deckValore[rnd1] = deckValore[rnd2];
        deckValore[rnd2] = tempValore;

        // Swap Seme
        char tempSeme = deckSeme[rnd1];
        deckSeme[rnd1] = deckSeme[rnd2];
        deckSeme[rnd2] = tempSeme;

        // Swap Seme
        char tempColore = deckColore[rnd1];
        deckColore[rnd1] = deckColore[rnd2];
        deckColore[rnd2] = tempColore;
    }

    // DEBUG: PRINT DATASET    
    for(int k = 0; k < 52; k++){
        printf("Index: %i \t Valore: %i \t Seme: %c \t Colore: %c \n", k, deckValore[k], deckSeme[k], deckColore[k]);
    }
}