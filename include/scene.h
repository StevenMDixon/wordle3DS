#ifndef SCENE_H
#define SCENE_H

#include <citro2d.h>
#include <3ds.h>
#include "sprite.h"
#include "screenContext.h"

class Scene
{
private:
    ScreenContext* screenContext = new ScreenContext();
public:
    virtual void Load(){};
    virtual void Update(){};
    virtual void HandleKeyInput(u32 kDown){};
    virtual void HandleTouchInput(touchPosition touch){};
    virtual ScreenContext* getContext(){
        return this->screenContext;
    }
    virtual ScreenContext* getSpritesForRenderer(){
        return this->screenContext;
    }
};

#endif