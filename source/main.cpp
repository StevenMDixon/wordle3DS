#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;
#include <citro2d.h>;
#include <3ds.h>;
#include "view/view.h";

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

int main(int argc, char* argv[])
{
	View myView;
	myView.test();
	// Init libs
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	// Create colors, pulled from wordle
	u32 clrBlack = C2D_Color32(33, 33, 33, 0xff);
	u32 clrGray = C2D_Color32(134, 136, 138, 0xff);
	u32 clrGreen = C2D_Color32(106, 170, 100, 0xff);
	u32 clrYellow = C2D_Color32(201, 180,88, 0xff);
	u32 clrWhite = C2D_Color32(0xff, 0xff, 0xff, 0xff);
	// Main loop
	while (aptMainLoop())
	{
		// gspWaitForVBlank();
		// gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu


		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrBlack);
		C2D_SceneBegin(top);

		//C2D_DrawRectSolid(0,0, 0, 400, 240, black);

		C2D_DrawRectSolid(0,0,0, 50, 50, clrYellow);
		C2D_DrawRectSolid(0,0,0, 50, 50, clrYellow);
		C2D_DrawRectSolid(0,0,0, 50, 50, clrYellow);

		C3D_FrameEnd(0);
	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
