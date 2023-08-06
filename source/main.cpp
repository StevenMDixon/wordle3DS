#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citro2d.h>
#include <3ds.h>

#include "game.h"

int main(int argc, char* argv[])
{
	Game myGame;
	// Main loop
	while (aptMainLoop())
	{
		u32 kDown = hidKeysDown();
		if(!myGame.HandleInput(kDown)) break;
		
		myGame.Run();
		myGame.Render();
	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
