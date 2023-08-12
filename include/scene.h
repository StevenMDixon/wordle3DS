#ifndef SCENE_H
#define SCENE_H

#include <citro2d.h>
#include <3ds.h>
#include "sprite.h"

class Scene
{
private:
    /* data */
    static Sprite sprites[MAX_SPRITES];
public:
    virtual void Load(){};
    virtual void Update(){};
    virtual void HandleKeyInput(u32 kDown){};
    virtual void HandleTouchInput(touchPosition touch){};
};

#endif