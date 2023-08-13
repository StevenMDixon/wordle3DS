#ifndef SPRITE_H
#define SPRITE_H

#include <citro2d.h>

#define MAX_SPRITES  768

typedef struct
{
	C2D_Sprite spr;
    C2D_ImageTint* tint = nullptr;

} Sprite;

#endif
