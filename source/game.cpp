#include "game.h"
#include "title.h"

#define TOP_SCREEN_WIDTH  400
#define TOP_SCREEN_HEIGHT 240
#define BOTTOM_SCREEN_WIDTH  320
#define BOTTOM_SCREEN_HEIGHT 240
#define MAX_SPRITES   768

// Simple sprite struct
typedef struct
{
	C2D_Sprite spr;
	float dx, dy; // velocity
} Sprite;

static C2D_SpriteSheet spriteSheet;
static Sprite sprites[MAX_SPRITES];
// static size_t numSprites = MAX_SPRITES/2;

// Create colors, pulled from wordle
// u32 clrBlack = C2D_Color32(33, 33, 33, 0xff);
// u32 clrGray = C2D_Color32(134, 136, 138, 0xff);
static u32 clrGreen = C2D_Color32(106, 170, 100, 0xff);
static u32 clrYellow = C2D_Color32(201, 180,88, 0xff);
// u32 clrWhite = C2D_Color32(0xff, 0xff, 0xff, 0xff);

    Game::Game() {
        // Init libs
        romfsInit();
	    gfxInitDefault();
        C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
        C2D_Prepare();

        this->top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
        this->bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

        // Initialize sprites
        spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/keyboard.t3x");
	    if (!spriteSheet) svcBreak(USERBREAK_PANIC);

        // load sprites from sheet into container
        C2D_SpriteFromSheet(&sprites[0].spr, spriteSheet, 0);
        C2D_SpriteSetCenter(&sprites[0].spr, 0.5f, 0.5f);
        C2D_SpriteSetPos(&sprites[0].spr, BOTTOM_SCREEN_WIDTH/ 2,BOTTOM_SCREEN_HEIGHT /2);

        this->currentScene = "Title";
        this->scenes["Title"] = new Title();
    };

    bool Game::HandleInput(u32 kDown){
        if (kDown & KEY_START)
			return false; // break in order to return to hbmenu
        return true;
    };

    void Game::Render(){
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        this->RenderTop();
        this->RenderBottom();
        C3D_FrameEnd(0);
    };

    void Game::RenderTop(){
        C2D_TargetClear(this->top, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
		C2D_SceneBegin(this->top);
        C2D_DrawRectSolid(0,0,0, TOP_SCREEN_WIDTH, TOP_SCREEN_HEIGHT, clrGreen);
    };

    void Game::RenderBottom(){
        C2D_TargetClear(this->bottom, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
		C2D_SceneBegin(this->bottom);
        C2D_DrawRectSolid(0,0,0,BOTTOM_SCREEN_WIDTH, BOTTOM_SCREEN_HEIGHT, clrYellow);
        C2D_DrawSprite(&sprites[0].spr);
    };

    void Game::Run(){
        this->scenes[currentScene]->Update();
    };