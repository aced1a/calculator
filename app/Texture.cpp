#include "Texture.h"

SDL_Renderer* gRenderer=nullptr;
SDL_Window* gWindow=nullptr;

TTF_Font* gFont_small = nullptr;
TTF_Font* gFont_big   = nullptr;
SDL_Color gFontColor = {0xFF,0xFF,0xFF};

const string fontPath = "C:/SDL/projects/engDataBase/engDataBase/Fonts/fixedsys.ttf";;

pair<short, short> elementsSizes[short(Element::COUNT)];
string imgPaths[short(Images::COUNT)];


void error(string str)
{
	throw runtime_error(str);
}

wstring transform_str(string str)
{
	wchar_t* new_str = new wchar_t[str.size() + 1];
	mbstowcs(new_str, str.c_str(), str.size() + 1);
	wstring str2 = new_str;

	delete[]new_str;
	return str2;
}

//Перевод строки юникода в массив типа Uint16
void text_transform(wstring str, Uint16* new_str)
{
	int size = str.size();
	for (short i = 0; i < size + 1; i++)
	{
		new_str[i] = str[i];
	}
}

Texture::Texture()
{
	mTexture = nullptr;
	mSurface = nullptr;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture()
{
	free();
	surfaceFree();
	mWidth = 0;
	mHeight = 0;
}

void Texture::free()
{
	if (mTexture != nullptr)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
	}
}

void Texture::surfaceFree()
{
	if (mSurface != nullptr)
	{
		SDL_FreeSurface(mSurface);
		mSurface = nullptr;
	}
}

int Texture::getHeight()
{
	return mHeight;
}

int Texture::getWidth()
{
	return mWidth;
}

void Texture::createSurface(Element element,bool fill,SDL_Color color)
{
	mWidth  = elementsSizes[short(element)].first;
	mHeight = elementsSizes[short(element)].second;
	
	surfaceFree();
	mSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, mWidth, mHeight, 32, 0xff000000, 0x00ff0000, 0x00000ff00, 0x00000000ff);
	if (mSurface == nullptr)
	{
		error("SDL_CreateRGBSurface error: " + string(SDL_GetError()));
	}
	if (fill) {
		SDL_Rect rect = { 0,0,mWidth,mHeight };
		SDL_FillRect(mSurface, &rect, SDL_MapRGB(mSurface->format, color.r, color.g, color.b));
	}
}

//Загрузка изображения на поверхность mSurface
void Texture::loadImage(string path)
{
	surfaceFree();

	mSurface = IMG_Load(path.c_str());
	if (mSurface == nullptr)
	{
		error("loadImage: IMG_Load error: " + string(IMG_GetError()));
	}

	mWidth = mSurface->w;
	mHeight = mSurface->h;
}


void Texture::addImage(string path, int x, int y)
{
	SDL_Surface* loadedImage = IMG_Load(path.c_str());
	if (loadedImage == nullptr)
	{
		error("loadImage: LoadBMP error: " + string(SDL_GetError()));
	}
	SDL_Rect rect = { NULL,NULL,loadedImage->w,loadedImage->h };
	SDL_Rect desc = { x,y,NULL,NULL };
	SDL_BlitSurface(loadedImage, &rect, mSurface, &desc);
	SDL_FreeSurface(loadedImage);
}


void Texture::loadFromText(string text, TTF_Font* font, SDL_Color color, int x, int y)
{
	if (text.size() == 0)
	{
		return;
	}

	SDL_Surface* textSurface = nullptr;
	Uint16* unicode_text = new Uint16[text.size() + 1];

	text_transform(transform_str(text), unicode_text);
	textSurface = TTF_RenderUNICODE_Solid(font, unicode_text, color);

	if (textSurface == nullptr)
	{
		error("loadFromText failed: " + string(TTF_GetError()));
	}

	SDL_Rect rect = { NULL,NULL,mSurface->w - x,mSurface->h - y };
	SDL_Rect desc = { x,y,NULL,NULL };
	SDL_BlitSurface(textSurface, &rect, mSurface, &desc);

	SDL_FreeSurface(textSurface);
}

//Получение текстуры mTexture из поверхности mSurface
void Texture::loadTexture()
{
	free();
	mTexture = SDL_CreateTextureFromSurface(gRender, mSurface);
	if (mTexture == nullptr)
	{
		error("loadTexute failed: " + string(SDL_GetError()));
	}
	surfaceFree();
}

//Рендер текстуры mTexture
void Texture::render(int x, int y)
{
	SDL_Rect renderQuad = { x,y,mWidth,mHeight };
	SDL_RenderCopy(gRender, mTexture, NULL, &renderQuad);
}
