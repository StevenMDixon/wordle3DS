# Wordle 3DS

A 3DS homebrew implementation of Wordle

# Setup

If using the provided create bat file please add Citra to your enviromental variables.

Otherwise use Make

# Development

- Make sure to set Citra in your environment
- Use Citra-qt otherwise applets like keyboard input will not load properly!

## Splitting project into multiple files

Update the Make files source and includes to include the folder that contains the file you want to include

```
TARGET		:=	$(notdir $(CURDIR))
BUILD		:=	build
SOURCES		:=	source source/view
DATA		:=	data
INCLUDES	:=	include source/view
GRAPHICS	:=	gfx
GFXBUILD	:=	$(BUILD)
#ROMFS		:=	romfs
GFXBUILD	:=	$(ROMFS)/gfx
```