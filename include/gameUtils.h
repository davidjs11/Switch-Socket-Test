///////////////////////////////////////////
/// gameUtils.h: game-related utilities ///
///////////////////////////////////////////



struct player{
    float posX, posY;
    char color[3];
    float speed;
};

int movePlayer(struct player *p, float speedX, float speedY);
