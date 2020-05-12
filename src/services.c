void delay(int number_of_seconds){ 
    // Conversione del tempo in millisecondi 
    int milli_seconds = 1000 * number_of_seconds; 
    // Memorizzare l'ora di inizio
    clock_t start_time = clock(); 
    // Loop fino a quando non viene raggiunto il tempo richiesto
    while (clock() < start_time + milli_seconds); 
} 

void textcolor(int colore){
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), colore);
}

void gotoxy(short x, short y){
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}