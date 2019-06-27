#include "Texture.h"


class Button
{
	int x, y;		
	char index;	
	Element element;	
public:
	Button();
	Button(int xx, int yy, char i, Element e, void(*f)(char));
	char getIndex();
	//void setIndex(short i);
	int getX();
	int getY();
	void(*buttonFunction)(char);	
	Element getElement();	
	/*void chgElement(Element e);*/

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
void loadMedia_resultOutput();
void buttonFunct(char index);
void firsLoadMedia();
void draw();
void eventControll();
void init_SDL();
void close_SDL();
void init_elements();