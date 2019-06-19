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
}