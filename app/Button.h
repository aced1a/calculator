#include "Texture.h"


class Button
{
	int x, y;		
	char index;	
	bool active;	
	Element element;	
public:
	Button();
	Button(int xx, int yy, char i, Element e, void(*f)(short));
	short getIndex();
	void setIndex(short i);
	int getX();
	int getY();
	void(*buttonFunction)(short);	
	Element getElement();	
	void chgElement(Element e);

	Texture mTexture;
};


struct Screen
{
public:
	Texture mBackground;
	vector<Button> mButtons;
	void screenRender();
};

Screen screen;