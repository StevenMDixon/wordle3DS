#ifndef SCENE_H
#define SCENE_H

#include <citro2d.h>
#include <3ds.h>

class Scene
{
private:
    /* data */
public:
    virtual void Load(){};
    virtual void Update(){};
};

#endif