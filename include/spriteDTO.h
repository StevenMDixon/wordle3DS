#ifndef SPRITEDTO_H
#define SPRITEDTO_H

#include <string>

typedef struct
{
    float x;
    float y;
    std::string sheet;
    int index;
    float center_x;
	float center_y;
	float angle;
	float depth;

} SpriteDTO;

#endif