#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
using namespace std;

#define digit '0'
#define clear 'c'
#define pi 0
#define backspace 1
#define prefSign 2

class Token
{
public:
	char kind;
	double value;

	Token(char ch) :kind{ ch }, value{ 0 }{}
	Token(char ch, double val) :kind{ ch }, value{ val }{}
};

class Token_stream
{
	bool full{ false };
	Token buffer;
public:
	Token get();
	void putback(Token t);
};

extern string strExpression;
char getNextSymbol();
void invalidSymbol();
void backspaceFunct();
void clearFunct();

double expression();

void error(string str);