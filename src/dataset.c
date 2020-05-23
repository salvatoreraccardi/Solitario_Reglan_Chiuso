// Deck - dataset
struct deck_data{
    int valore[52];
    char seme[52];
    char colore[52];
}deck;

struct stack_sector_a{
    int nCard; // MAX 6
    int valore;
    char seme;
    char colore;
};

struct stack_sector_b{
    int valore;
    char seme;
    char colore;
};

struct stack_sector_c{
    int renderingCard; // nCard for each pointer(Dynamic array)
    int dorsi;
    int valore;
    char seme;
    char colore;
};

struct stack_sector_a *ptrA;
struct stack_sector_b *ptrB;
struct stack_sector_c *ptrC[9];