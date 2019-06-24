#include "Button.h"

void loadMedia_screenButtons()
{
	for (short i = 0; i < screen.mButtons.size(); i++)
	{
		screen.mButtons[i].mTexture.createSurface(screen.mButtons[i].getElement(), true, SDL_Color{ 195,195,195 });
		if (screen.mButtons[i].getIndex() != 0 || screen.mButtons[i].getIndex() != 1 || screen.mButtons[i].getIndex() != 2)
			screen.mButtons[i].mTexture.loadFromText(string{ screen.mButtons[i].getIndex() }, gFont_small, gFontColor, 5, 5);
		else{
			screen.mButtons[i].mTexture.addImage(imgPaths[screen.mButtons[i].getIndex()],0,0);
		}
		screen.mButtons[i].mTexture.loadTexture();
	}
}

void loadMedia_background()
{
	screen.mBackground.createSurface(Element::background, true, SDL_Color{ 255,255,255 });
	screen.mBackground.loadTexture();
}

void loadMedia_resultOutput()
{
	string first = strExpression, second = tol(expression());
	short offset = MAINWINDOW_WIDTH - (strExpression.size() * 10)-20,offset2=MAINWINDOW_WIDTH - 20;
	if (offset < 20)
	{
		//offset = 20;
		while (offset < 20)
		{
			offset += 10;
			first.erase(first.begin());
		}
		offset -= second.size() * 10;
	}
	screen.resultOutput.createSurface(Element::resultOutput);
	screen.mBackground.loadFromText(first, gFont_small, gFontColor, offset, 30);
	screen.mBackground.loadFromText(second, gFont_small, gFontColor, 20, 20);
}

void draw()
{
	screen.screenRender();
	SDL_RenderPresent(gRenderer);
	SDL_RenderClear(gRenderer);
}