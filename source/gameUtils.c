#include "gameUtils.h"

int movePlayer(struct player *p, float speedX, float speedY)
{
    p->posX+=speedX;
    p->posY+=speedY;
    return 0;
}
