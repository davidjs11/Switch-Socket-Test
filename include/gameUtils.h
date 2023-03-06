///////////////////////////////////////////
/// gameUtils.h: game-related utilities ///
///////////////////////////////////////////

#ifndef GAME_UTILS
#define GAME_UTILS

struct player{
    float posX, posY;
    char color[3];
    float speed;
};

int movePlayer(struct player *p, float speedX, float speedY);

#endif
