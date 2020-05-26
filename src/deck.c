// Carte rosse: 13x♥ - 13x♦
// Carte nere: 13x♣ - 13x♠ 
void deckGeneration(){
    // Generazione del deck   
    int y, i, j, swap;
    int index = 2, offset = 0;
    int rnd1, rnd2;
    int tempValore; 
    char tempSeme, tempColore;
    char semi[4] = {3,5,4,6};
    // Assi
    for(y = 0; y < 4; y++){
        deck.valore[y] = 1;
        deck.seme[y] = semi[y];
        if(y == 0 || y == 2){
            deck.colore[y] = 'R';
        }else{
            deck.colore[y] = 'B';
        }
    }
    // tutte le carte = 48
    for(i = 0; i < 4; i++){
        for(j = 0; j < 12; j++){
            deck.valore[4 + j + offset] = index;
            deck.seme[4 + j + offset] = semi[i];
            if(i == 0 || i == 2){
                deck.colore[4 + j + offset] = 'R';
            }else{
                deck.colore[4 + j + offset] = 'B';
            }
            index++;
        }
        index = 2;
        offset += 12;
    }  

    
    /*
    //EASY WIN
    deck.valore[0] = 13; 
    deck.valore[1] = 13; 
    deck.valore[2] = 13; 
    deck.valore[3] = 13; 
    */
    
    // seed for random index
    srand(time(0)); 
    // Shuffling cards   
    for(swap = 0; swap < 300; swap++){
        rnd1 = 0;
        rnd2 = 0;
        // Random index
        while(rnd1 == rnd2 && deck.valore[rnd1] == deck.valore[rnd2]){
            rnd1 = random(4, 51);
            rnd2 = random(4, 51);
        }
        // Swap Valore
        tempValore = deck.valore[rnd1];
        deck.valore[rnd1] = deck.valore[rnd2];
        deck.valore[rnd2] = tempValore;
        // Swap Seme
        tempSeme = deck.seme[rnd1];
        deck.seme[rnd1] = deck.seme[rnd2];
        deck.seme[rnd2] = tempSeme;
        // Swap Seme
        tempColore = deck.colore[rnd1];
        deck.colore[rnd1] = deck.colore[rnd2];
        deck.colore[rnd2] = tempColore;
    }
    
    // DEBUG: PRINT DATASET   
    /*
    for(int k = 0; k < 52; k++){
        printf("Index: %i \t Valore: %i \t Seme: %c \t Colore: %c \n", k, deck.valore[k], deck.seme[k], deck.colore[k]);
    }
    //delay(5);    
    system("cls");
    */
}