#include "Button.h"

Screen screen;

Button::Button()
	:x{ 0 }, y{ 0 }, index{ 0 }, active{ 0 }, element{  }
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
	resultOutput.render(0, 0);
}

void buttonFunct(char index)
{
	if (index == backspace)
		backspaceFunct();
	else if (index == clear)
		clearFunct();
	else if (index == pi)
		strExpression += "3.14";
	else if (index == prefSign)
		strExpression += '-';
	else
		strExpression += index;
	loadMedia_resultOutput();
	draw();
}