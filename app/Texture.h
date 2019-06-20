#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
using namespace std;

#define MAINWINDOW_WIDTH  300
#define MAINWINDOW_HEIGHT 600


extern SDL_Renderer* gRenderer;
extern SDL_Window* gWindow;

extern SDL_Color gFontColor;

extern TTF_Font* gFont_small;
extern TTF_Font* gFont_big;
extern const string fontPath;

enum class Element { background=0,resultOutput,button,COUNT };
enum class Images{pi=0,prefixCharacter,backspace,COUNT};

extern pair<short,short> elementsSizes[short(Element::COUNT)];
extern string imgPaths[short(Images::COUNT)];


class Texture
{
public:
	Texture();
	~Texture();
	void free();																						
	void surfaceFree();																					
	void createSurface(Element element, bool fill = false, SDL_Color color = { 0,0,0 });
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