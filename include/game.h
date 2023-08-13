#ifndef GAME_H
#define GAME_H

#include <citro2d.h>
#include <3ds.h>
#include <map>
#include <string>
#include "scene.h"
#include "renderer.h"
#include "title.h"
#include "spriteDTO.h"

class Game
{
    private:
        std::map<std::string, Scene*> scenes;
        std::string currentScene;
        Renderer* renderer;
        void createScene(std::string sceneName, Scene* sceneClass);
    public:
        Game();
        bool HandleInput(u32 kDown, touchPosition touch);
        void Render();
        void RenderTop();
        void RenderBottom();
        void Run();
        void LoadSprites();
};

#endif