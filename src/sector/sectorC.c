void sector_C(){
    int offset1 = 10;
    textcolor(15);
    for(int j = 0; j < 4; j++){
        gotoxy(0, offset1);
        printf("%c", 218);
        for(int i = 0; i < 5; i++)
            // print ─
            printf("%c", 196);
        // print ┐    
        printf("%c", 191);

        gotoxy(0, offset1 + 1);
        printf("%c", 179);
        for(int i = 0; i < 5; i++)
            // print ▒
            printf("%c", 177);
        printf("%c", 179);  
        offset1 += 2;
    }
    
    
}