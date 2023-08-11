#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <citro2d.h>
#include <3ds.h>
#include <string>

class Renderer
{
    private:
        C3D_RenderTarget* top;
        C3D_RenderTarget* bottom;
        std::map<std::string, C2D_SpriteSheet> SpriteSheets;

        void RenderTop();
        void RenderBottom();
    public:
        Renderer();
        void Render();
        void LoadSpriteSheet(std::string name, std::string location);
};

#endif