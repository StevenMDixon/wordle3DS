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
static u32 clrClear = C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f);
// u32 clrWhite = C2D_Color32(0xff, 0xff, 0xff, 0xff);

Renderer::Renderer(){
        gfxInitDefault();
        C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
        C2D_Prepare();

        this->top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
        this->bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
};

void Renderer::Render(ScreenContext* screenData)
{
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    this->RenderTop(screenData);
    this->RenderBottom(screenData);
    C3D_FrameEnd(0);
};

void Renderer::RenderTop(ScreenContext* screenData){
    C2D_TargetClear(this->top, clrClear);
    C2D_SceneBegin(this->top);
    C2D_DrawRectSolid(0,0,0, TOP_SCREEN_WIDTH, TOP_SCREEN_HEIGHT, clrGreen);

    for(int i = 0; i < MAX_SPRITES; i++){
        if(screenData->topScreenSprites[i] != nullptr){
            C2D_DrawSprite(&screenData->topScreenSprites[i]->spr);
        }
    }
};

void Renderer::RenderBottom(ScreenContext* screenData){
    C2D_TargetClear(this->bottom, clrClear);
    C2D_SceneBegin(this->bottom);
    C2D_DrawRectSolid(0,0,0, BOTTOM_SCREEN_WIDTH, BOTTOM_SCREEN_HEIGHT, clrYellow);
    
    for(int i = 0; i < MAX_SPRITES; i++){
        if(screenData->bottomScreenSprites[i] != nullptr){
            if(screenData->bottomScreenSprites[i]->tint != nullptr)
            {
                C2D_DrawSpriteTinted(&screenData->bottomScreenSprites[i]->spr, screenData->bottomScreenSprites[i]->tint);
            } else {
                C2D_DrawSprite(&screenData->bottomScreenSprites[i]->spr);
            }
        }
    }
};

void Renderer::LoadSpriteSheet(std::string name, std::string location){
    // "romfs:/gfx/keyboard.t3x"
    this->SpriteSheets[name] = C2D_SpriteSheetLoad(location.c_str());
	if (!this->SpriteSheets[name]) svcBreak(USERBREAK_PANIC);
// load sprites from sheet into container
};

void Renderer::CreateSpriteFromContext(ScreenContext* screenContext, SpriteDTO spriteData, Screen screen){
    Sprite* sprite = new Sprite();
    C2D_SpriteFromSheet(&sprite->spr, this->SpriteSheets[spriteData.sheet], spriteData.index);
    C2D_SpriteSetCenter(&sprite->spr, spriteData.center_x, spriteData.center_y);
    C2D_SpriteSetPos(&sprite->spr, spriteData.x, spriteData.y);
    C2D_SpriteSetDepth(&sprite->spr, spriteData.depth);
    C2D_SpriteSetRotation(&sprite->spr, spriteData.angle);

    if(screen == SCREEN_TOP){
        screenContext->topScreenSprites[screenContext->topCurrentSpriteIndex] = sprite;
        screenContext->topCurrentSpriteIndex += 1;
    } else if (screen == SCREEN_BOTTOM) {
        screenContext->bottomScreenSprites[screenContext->bottomCurrentSpriteIndex] = sprite;
        screenContext->bottomCurrentSpriteIndex += 1;
    }
   
};

// void Renderer::CreateSpritesContext(std::string name){
//     this->Sprites[name][0] = new Sprite();
//     C2D_SpriteFromSheet(&this->Sprites[name][0]->spr, this->SpriteSheets["keyboard"], 0);
//     C2D_SpriteSetCenter(&this->Sprites[name][0]->spr, 0.5f, 0.5f);
//     C2D_SpriteSetPos(&this->Sprites[name][0]->spr, BOTTOM_SCREEN_WIDTH/ 2,BOTTOM_SCREEN_HEIGHT /2);
    // C2D_ImageTint* tint = new C2D_ImageTint();
    // tint->corners[0] = {
    //     clrGreen,  
    //     1
    // };
    // tint->corners[1] = {
    //     clrGreen,  
    //     1
    // };
    // tint->corners[2] = {
    //     clrGreen,  
    //     1
    // };
    // tint->corners[3] = {
    //     clrGreen,  
    //     1
    // };
    // this->Sprites[name][0]->tint = tint;
//}