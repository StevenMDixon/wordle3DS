#include "game.h"
#include "title.h"

    Game::Game() {
        // Init libs
        romfsInit();
	    this->renderer = new Renderer();
        this->currentScene = "Title";
        
        //load sprite sheets into renderer
        this->renderer->LoadSpriteSheet("keyboard", "romfs:/gfx/keyboard.t3x");
        // create a scene
        this->scenes["Title"] = new Title();
        this->renderer->CreateSpritesContext("Title");
        // this->createScene("Title", new Title());
    };

    bool Game::HandleInput(u32 kDown, touchPosition touch){
        if (kDown & KEY_START)
			return false; // break in order to return to hbmenu
        
        this->scenes[currentScene]->HandleKeyInput(kDown);
        this->scenes[currentScene]->HandleTouchInput(touch);
        return true;
    };

    void Game::Render(){
       this->renderer->Render(this->currentScene);
    };

    void Game::Run(){
        this->scenes[currentScene]->Update();
    };

    void Game::createScene(std::string sceneName, Scene* scene){
        
    }