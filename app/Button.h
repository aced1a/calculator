#include "Texture.h"


class Button
{
	int x, y;		
	char index;	
	//Uint16 index;
	bool active;	
	Element element;	
public:
	Button();
	Button(int xx, int yy, char i, Element e, void(*f)(short));
	char getIndex();
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
	Texture resultOutput;
	vector<Button> mButtons;
	void screenRender();
};

extern Screen screen;


void init_SDL();
void close_SDL();