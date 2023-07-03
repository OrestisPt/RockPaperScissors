typedef enum {
    Rock, Paper, Scissors
}blockType;

typedef struct block {
    blockType type;
    int x;
    int y;
}*Block;

void move(Block element);