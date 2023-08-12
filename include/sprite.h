#ifndef SPRITE_H
#define SPRITE_H

#include <citro2d.h>

#define MAX_SPRITES  768

typedef struct
{
	C2D_Sprite spr;
	float dx, dy; // velocity
} Sprite;

#endif
