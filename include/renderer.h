#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <citro2d.h>
#include <3ds.h>
#include <string>
#include "sprite.h"
#include "screenContext.h"
#include <array>
#include "spriteDTO.h"
#include "screen_enum.h"

class Renderer
{
    private:
        C3D_RenderTarget* top;
        C3D_RenderTarget* bottom;
        std::map<std::string, C2D_SpriteSheet> SpriteSheets;
        //std::map<std::string, std::array<Sprite*, MAX_SPRITES>> Sprites;

        void RenderTop(ScreenContext* screenData);
        void RenderBottom(ScreenContext* screenData);
    public:
        Renderer();
        void Render(ScreenContext* screenData);
        void LoadSpriteSheet(std::string name, std::string location);
        //void CreateSpritesContext(std::string name);
        void CreateSpriteFromContext(ScreenContext* screenContext, SpriteDTO spriteData, Screen screen);
};

#endif