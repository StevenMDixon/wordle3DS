#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <citro2d.h>
#include <3ds.h>
#include <string>
#include "sprite.h"

class Renderer
{
    private:
        C3D_RenderTarget* top;
        C3D_RenderTarget* bottom;
        std::map<std::string, C2D_SpriteSheet> SpriteSheets;

        std::map<std::string, Foo>> Sprites;

        void RenderTop(std::string currentScene);
        void RenderBottom(std::string currentScene);
    public:
        Renderer();
        void Render(std::string currentScene);
        void LoadSpriteSheet(std::string name, std::string location);
        void CreateSpritesContext(std::string name);
};

#endif