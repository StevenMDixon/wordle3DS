#ifndef SCREENCONTEXT_H
#define SCREENCONTEXT_H

#include "sprite.h"

struct ScreenContext
{
    /* data */
    int currentSpriteIndex = 0;
    Sprite* sprites[MAX_SPRITES];
    int topCurrentSpriteIndex = 0;
    int bottomCurrentSpriteIndex = 0;
    Sprite* topScreenSprites[MAX_SPRITES];
    Sprite* bottomScreenSprites[MAX_SPRITES];
} ;

#endif