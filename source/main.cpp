#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citro2d.h>
#include <3ds.h>
#include "view/view.h"

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

static SwkbdCallbackResult MyCallback(void* user, const char** ppMessage, const char* text, size_t textlen)
{
	return SWKBD_CALLBACK_OK;
}

int main(int argc, char* argv[])
{
	// View myView;
	// myView.test();
	// Init libs
	gfxInitDefault();
	// C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	// C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	// C2D_Prepare();
	// consoleInit(GFX_BOTTOM, NULL);
	consoleInit(GFX_TOP, NULL);

	// Create screens
	//C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	// Create colors, pulled from wordle
	u32 clrBlack = C2D_Color32(33, 33, 33, 0xff);
	u32 clrGray = C2D_Color32(134, 136, 138, 0xff);
	u32 clrGreen = C2D_Color32(106, 170, 100, 0xff);
	u32 clrYellow = C2D_Color32(201, 180,88, 0xff);
	u32 clrWhite = C2D_Color32(0xff, 0xff, 0xff, 0xff);

	printf("Software keyboard demo - by fincs\n");
	printf("A: text input\n");
	printf("B: numpad input\n");
	printf("X: western input\n");
	printf("Y: filtered input + HOME/POWER/reset handling\n");
	printf("START: exit\n");
	// Main loop
	while (aptMainLoop())
	{
		// gspWaitForVBlank();
		// gfxSwapBuffers();
		hidScanInput();

		bool didit = false;
		static SwkbdState swkbd;
		static char mybuf[60];
		static SwkbdStatusData swkbdStatus;
		static SwkbdLearningData swkbdLearning;
		SwkbdButton button = SWKBD_BUTTON_NONE;

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		if (kDown & KEY_X)
		{
			didit = true;
			swkbdInit(&swkbd, SWKBD_TYPE_WESTERN, 1, -1);
			swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, SWKBD_FILTER_DIGITS | SWKBD_FILTER_AT | SWKBD_FILTER_PERCENT | SWKBD_FILTER_BACKSLASH | SWKBD_FILTER_PROFANITY, 2);
			swkbdSetFeatures(&swkbd, SWKBD_MULTILINE);
			swkbdSetHintText(&swkbd, "No Japanese text allowed ¯\\_(ツ)_/¯");
			button = swkbdInputText(&swkbd, mybuf, sizeof(mybuf));
		}

		if (didit)
		{
			if (button != SWKBD_BUTTON_NONE)
			{
				printf("You pressed button %d\n", button);
				printf("Text: %s\n", mybuf);
			} else
				printf("swkbd event: %d\n", swkbdGetResult(&swkbd));
		}

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
		// Render the scene
		// C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		// C2D_TargetClear(top, clrBlack);
		// C2D_SceneBegin(top)/;

		//C2D_DrawRectSolid(0,0, 0, 400, 240, black);

		// C2D_DrawRectSolid(0,0,0, 50, 50, clrYellow);
		// C2D_DrawRectSolid(0,0,0, 100, 50, clrYellow);
		// C2D_DrawRectSolid(0,0,0, 150, 50, clrYellow);

		// C3D_FrameEnd(0);
	}

	// Deinit libs
	// C2D_Fini();
	// C3D_Fini();
	gfxExit();
	return 0;
}
