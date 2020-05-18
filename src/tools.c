// Delay
void delay(int seconds){ 
    // Conversione del tempo in millisecondi 
    int milli_seconds = 1000 * seconds; 
    // Memorizzare l'ora di inizio
    clock_t start_time = clock(); 
    // Loop fino a quando non viene raggiunto il tempo richiesto
    while (clock() < start_time + milli_seconds); 
} 
// Change textcolor
void textcolor(int colore){
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), colore);
}
// Cursor position
void gotoxy(short x, short y){
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// Random number
int random(int lower, int upper){ 
    int num = (rand() % 
            (upper - lower + 1)) + lower; 
    return num; 
} 