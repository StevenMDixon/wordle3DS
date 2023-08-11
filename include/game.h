#ifndef GAME_H
#define GAME_H

#include <citro2d.h>
#include <3ds.h>
#include <map>
#include <string>
#include "scene.h"
#include "renderer.h"

class Game
{
    private:
        std::map<std::string, Scene*> scenes;
        std::string currentScene;
        Renderer* renderer;
    public:
        Game();
        bool HandleInput(u32 kDown);
        void Render();
        void RenderTop();
        void RenderBottom();
        void Run();
        void LoadSprites();
};

#endif