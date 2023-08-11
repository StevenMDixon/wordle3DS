#include "game.h"
#include "title.h"

    Game::Game() {
        // Init libs
        romfsInit();
	    this->renderer = new Renderer();
        this->currentScene = "Title";
        this->scenes["Title"] = new Title();

        this->renderer->LoadSpriteSheet("keyboard", "romfs:/gfx/keyboard.t3x");
    };

    bool Game::HandleInput(u32 kDown){
        if (kDown & KEY_START)
			return false; // break in order to return to hbmenu
        return true;
    };

    void Game::Render(){
       this->renderer->Render();
    };

    void Game::Run(){
        this->scenes[currentScene]->Update();
    };