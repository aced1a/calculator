#include "Button.h"

void init_SDL(){}

void close_SDL(){}

void init_elementsSizes()
{
	elementsSizes[short(Element::background)] = { MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT };
	elementsSizes[short(Element::resultOutput)] = {0,0};
	elementsSizes[short(Element::button)] = { 20,20 };
}

void init_screen()
{
	short w = elementsSizes[short(Element::button)].first;
	short h = elementsSizes[short(Element::button)].second;
	short size = 24;
	char symbols[] = { '%','s','^','p','C','b','!','/','7','8','9','*','4','5','6','-','1','2','3','+','f','0','.','=' };
	for (short i = 0; i < size; i++) {
		screen.mButtons.push_back(Button{ w*(i / 4) + 2,h*(i % 4) + 2,symbols[i],Element::button,nullptr });
	}

}