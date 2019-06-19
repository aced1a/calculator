#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
using namespace std;

#define MAINWINDOW_WIDTH 1000
#define MAINWINDOW_HEIGHT 600


extern SDL_Renderer* gRenderer;
extern SDL_Window* gWindow;

extern SDL_Color gFontColor;

extern TTF_Font* gFont_small;
extern TTF_Font* gFont_big;
extern const string fontPath;

enum class Element { background=0,resultOutput,button,COUNT };

extern pair<short,short> imgSizes[short(Element::COUNT)];
extern string imgPaths[short(Element::COUNT)];


class Texture
{
public:
	Texture();
	~Texture();
	void free();																						
	void surfaceFree();																					
	void createSurface(Element element);
	void loadImage(string path);					
	void addImage(string path, int x, int y);	
	void loadFromText(string text, TTF_Font* font, SDL_Color color, int x, int y);						
	void loadTexture();																					
	void render(int x, int y);																			
	int getWidth();																						
	int getHeight();																					

private:
	SDL_Texture* mTexture;
	SDL_Surface* mSurface;

	int mWidth;
	int mHeight;
};


void text_transform(wstring text, Uint16* unicode);
wstring transform_str(string text);
void error(string str);