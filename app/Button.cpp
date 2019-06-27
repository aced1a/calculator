<<<<<<< HEAD
﻿#include "Button.h"

Screen screen;

Button::Button()
	:x{ 0 }, y{ 0 }, index{ 0 }, element{ Element::COUNT }
{
	buttonFunction = nullptr;
}

Button::Button(int xx, int yy, char i, Element e, void(*f)(char))
	: x{ xx }, y{ yy }, index{ i }, element{ e }
{
	buttonFunction = f;
}

char Button::getIndex()
{
	return index;
}

int Button::getX()
{
	return x;
}

int Button::getY()
{
	return y;
}

Element Button::getElement()
{
	return element;
}


//void Button::setIndex(short i)
//{
//	index = i;
//}
//
//void Button::chgElement(Element e)
//{
//	element = e;
//}

void Screen::screenRender()
{
	mBackground.render(0, 0);
	for (short i = 0; i < mButtons.size(); i++)
	{
		mButtons[i].mTexture.render(mButtons[i].getX(), mButtons[i].getY());
	}
	resultOutput.render(0, 0);
}

void buttonFunct(char symbol)
{
	if (symbol == backspace)
		backspaceFunct();
	else if (symbol == clear)
		clearFunct();
	else if (symbol == sqrtSym)
		strExpression += "sqrt";
	else if (symbol == '=')
	{
		strExpression += symbol;
		strExpression = calculate();
	}
	else 
		strExpression += symbol;
	loadMedia_resultOutput();
	draw();
}

bool inSquare(Button* button, int& x, int& y)
{
	if (x > button->getX() && y > button->getY() && x < (button->getX() + button->mTexture.getWidth()) && y < (button->getY() + button->mTexture.getHeight()))
		return true;
	return false;
}

void whichButtonDown(int& x, int& y)
{
	for (short i = 0; i <screen.mButtons.size(); i++)
	{
		if (inSquare(&screen.mButtons[i], x, y))
		{
			screen.mButtons[i].buttonFunction(screen.mButtons[i].getIndex());
		}
	}
}

void eventControll()
{
	int x = 0, y = 0;
	SDL_Event e;
	bool running = true;
	while(running)
	{
		if (SDL_PollEvent(&e)) 
		{
			switch (e.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				SDL_GetMouseState(&x, &y);
				whichButtonDown(x, y);
				break;
			default:
				break;
			}
		}
	}
=======
#include "Button.h"


Button::Button()
	:x{ 0 }, y{ 0 }, index{ 0 }, active{ 0 }, element{  }
{
	buttonFunction = nullptr;
}

Button::Button(int xx, int yy, char i, Element e, void(*f)(short))
	: x{ xx }, y{ yy }, index{ i }, element{ e }
{
	buttonFunction = f;
}

short Button::getIndex()
{
	return index;
}

int Button::getX()
{
	return x;
}

int Button::getY()
{
	return y;
}

Element Button::getElement()
{
	return element;
}


void Button::setIndex(short i)
{
	index = i;
}

void Button::chgElement(Element e)
{
	element = e;
}

void Screen::screenRender()
{
	mBackground.render(0, 0);
	for (short i = 0; i < mButtons.size(); i++)
	{
		mButtons[i].mTexture.render(mButtons[i].getX(), mButtons[i].getY());
	}
>>>>>>> e553ba224247422ddf39e00477a91e3967ccec24
}