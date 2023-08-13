#include "game.h"

Game::Game() {
    // Init libs
    romfsInit();
    this->renderer = new Renderer();
    this->currentScene = "Title";
    
    //load sprite sheets into renderer
    this->renderer->LoadSpriteSheet("keyboard", "romfs:/gfx/keyboard.t3x");
    this->renderer->LoadSpriteSheet("grid", "romfs:/gfx/grid.t3x");
    this->renderer->LoadSpriteSheet("letters", "romfs:/gfx/letters.t3x");
    // create a scene
    this->scenes["Title"] = new Title();
    //this->renderer->CreateSpritesContext("Title");
    // this->createScene("Title", new Title());

    SpriteDTO d = {
        .x = 0.0f,
        .y =0.0f,
        .sheet = "keyboard",
        .index = 0,
        .center_x = 0.0f,
        .center_y = 0.0f,
        .angle = 0.0f,
        .depth = 0.0f
    };

    this->renderer->CreateSpriteFromContext(this->scenes["Title"]->getSpritesForRenderer(), d, SCREEN_TOP);

    SpriteDTO t = {
        .x = 20.0f,
        .y = 20.0f,
        .sheet = "letters",
        .index = 0,
        .center_x = 0.0f,
        .center_y = 0.0f,
        .angle = 0.0f,
        .depth = 0.0f
    };

    this->renderer->CreateSpriteFromContext(this->scenes["Title"]->getSpritesForRenderer(), t, SCREEN_BOTTOM);

};

bool Game::HandleInput(u32 kDown, touchPosition touch){
    if (kDown & KEY_START)
        return false; // break in order to return to hbmenu
    
    this->scenes[currentScene]->HandleKeyInput(kDown);
    this->scenes[currentScene]->HandleTouchInput(touch);
    return true;
};

void Game::Render(){
    this->renderer->Render(this->scenes[this->currentScene]->getSpritesForRenderer());
};

void Game::Run(){
    this->scenes[currentScene]->Update();
};

void Game::createScene(std::string sceneName, Scene* scene){
    
}