#ifndef TITLE_H
#define TITLE_H

#include <citro2d.h>
#include <3ds.h>
#include "scene.h"

class Title: public Scene
{
private:
    /* data */
public:
    Title();
    void Load();
    void Update();
    void HandleKeyInput(u32 kDown);
};

#endif