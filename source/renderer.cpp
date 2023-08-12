#include "renderer.h"

#define TOP_SCREEN_WIDTH  400
#define TOP_SCREEN_HEIGHT 240
#define BOTTOM_SCREEN_WIDTH  320
#define BOTTOM_SCREEN_HEIGHT 240

// static size_t numSprites = MAX_SPRITES/2;

// Create colors, pulled from wordle
// u32 clrBlack = C2D_Color32(33, 33, 33, 0xff);
// u32 clrGray = C2D_Color32(134, 136, 138, 0xff);
static u32 clrGreen = C2D_Color32(106, 170, 100, 0xff);
static u32 clrYellow = C2D_Color32(201, 180,88, 0xff);
// u32 clrWhite = C2D_Color32(0xff, 0xff, 0xff, 0xff);

// static C2D_SpriteSheet spriteSheet;
//static Sprite sprites[MAX_SPRITES];

Renderer::Renderer(){
        gfxInitDefault();
        C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
        C2D_Prepare();

        this->top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
        this->bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
};

void Renderer::Render(std::string currentScene)
{
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    this->RenderTop(currentScene);
    this->RenderBottom(currentScene);
    C3D_FrameEnd(0);
};

void Renderer::RenderTop(std::string currentScene){
    C2D_TargetClear(this->top, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
    C2D_SceneBegin(this->top);
    C2D_DrawRectSolid(0,0,0, TOP_SCREEN_WIDTH, TOP_SCREEN_HEIGHT, clrGreen);
};

void Renderer::RenderBottom(std::string currentScene){
    C2D_TargetClear(this->bottom, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
    C2D_SceneBegin(this->bottom);
    C2D_DrawRectSolid(0,0,0,BOTTOM_SCREEN_WIDTH, BOTTOM_SCREEN_HEIGHT, clrYellow);
    Sprite* mySprite = this->Sprites[currentScene];
    C2D_DrawSprite(&mySprite[0].spr);
};

void Renderer::LoadSpriteSheet(std::string name, std::string location){
    // "romfs:/gfx/keyboard.t3x"
    this->SpriteSheets[name] = C2D_SpriteSheetLoad(location.c_str());
	if (!this->SpriteSheets[name]) svcBreak(USERBREAK_PANIC);
// load sprites from sheet into container
};

void Renderer::CreateSpritesContext(std::string name){
    Sprite sprites[MAX_SPRITES];
    C2D_SpriteFromSheet(&sprites[0].spr, this->SpriteSheets["keyboard"], 0);
    C2D_SpriteSetCenter(&sprites[0].spr, 0.5f, 0.5f);
    C2D_SpriteSetPos(&sprites[0].spr, BOTTOM_SCREEN_WIDTH/ 2,BOTTOM_SCREEN_HEIGHT /2);
    this->Sprites.emplace(name, sprites);
}