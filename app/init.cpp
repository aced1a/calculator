#include "Button.h"

void init_fonts()
{
	gFont_small = TTF_OpenFont(fontPath.c_str(), 14);
	gFont_big = TTF_OpenFont(fontPath.c_str(), 24);
	if (gFont_small == nullptr || gFont_big==nullptr)
	{
		error("TTF_OpenFont failed: " + string(TTF_GetError()));
	}
}

void init_SDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		error("SDL initialization failed. SDL Error: " + string(SDL_GetError()));
	}
	if (TTF_Init() < 0)
	{
		error("SDL_TTF initialization failed: " + string(TTF_GetError()));
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		error("IMG_Init failed: " + string(IMG_GetError()));
	}

	gWindow = SDL_CreateWindow("Calendar", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == nullptr)
	{
		error("SDL_CreateWindow failed: " + string(SDL_GetError()));
	}
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);	// | SDL_RENDERER_PRESENTVSYNC
	if (gRenderer == nullptr)
	{
		error("SDL_CreateRenderer failed: " + string(SDL_GetError()));
	}
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
	init_fonts();
}

void close_SDL()
{
	TTF_CloseFont(gFont_small);
	TTF_CloseFont(gFont_big);
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void init_elementsSizes()
{
	elementsSizes[short(Element::background)] = { MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT };
	elementsSizes[short(Element::resultOutput)] = {0,0};
	elementsSizes[short(Element::button)] = { 20,20 };
}

void init_imgPaths()
{
	imgPaths[short(Images::pi)] = " ";
	imgPaths[short(Images::prefixCharacter)] = "";
	imgPaths[short(Images::backspace)] = "";
}

void init_screen()
{
	short w = elementsSizes[short(Element::button)].first;
	short h = elementsSizes[short(Element::button)].second;
	short size = 24;
	char symbols[] = { '%','√','^',char(0),'C',char(1),'!','/','7','8','9','*','4','5','6','-','1','2','3','+',char(2),'0','.','=' };//'π'
	for (short i = 0; i < size; i++) {
		screen.mButtons.push_back(Button{ w*(i / 4) + 2,h*(i % 4) + 2,symbols[i],Element::button,nullptr });
	}
}