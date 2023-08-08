#ifndef GAME_H
#define GAME_H

#include <citro2d.h>
#include <3ds.h>
#include <map>
#include <string>
#include "scene.h"

class Game
{
    private:
        C3D_RenderTarget* top;
        C3D_RenderTarget* bottom;
        std::map<std::string, Scene*> scenes;
        std::string currentScene;
    public:
        Game();
        bool HandleInput(u32 kDown);
        void Render();
        void RenderTop();
        void RenderBottom();
        void Run();
};

#endif