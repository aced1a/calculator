#include "Button.h"

void invalidSymbol(string str)
{
	cout << str << endl;
	invalidSym = true;
	invalidSym_mess = str;
}

void loadMedia_screenButtons()
{
	for (short i = 0; i < screen.mButtons.size(); i++)
	{
		screen.mButtons[i].mTexture.createSurface(screen.mButtons[i].getElement(), true, SDL_Color{ 195,195,195 });

		if(i!=1)
			screen.mButtons[i].mTexture.loadFromText(string{ screen.mButtons[i].getIndex() }, gFont_big, gFontColor, 5, 5);
		else
			screen.mButtons[i].mTexture.loadFromText("sqrt", gFont_big, gFontColor, 2, 5);
		
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
	string first;
	first = strExpression;
	if (invalidSym)
	{
		invalidSym = false;
		first = invalidSym_mess;
	}
	short offset = MAINWINDOW_WIDTH - (first.size() * 25);
	if (offset < 25)
	{
		while (offset < 25)
		{
			offset += 25;
			first.erase(first.begin());
		}
	}
	screen.resultOutput.createSurface(Element::resultOutput);
	screen.resultOutput.loadFromText(first, gFont_big, gFontColor, offset, 30);
	screen.resultOutput.loadTexture();
}

void firsLoadMedia()
{
	loadMedia_background();
	loadMedia_screenButtons();
	loadMedia_resultOutput();
}

void setViewport()
{
	SDL_Rect topLeft{ 0,0,MAINWINDOW_WIDTH,200 };
	
}

void draw()
{
	screen.screenRender();
	SDL_RenderPresent(gRenderer);
	SDL_RenderClear(gRenderer);
}