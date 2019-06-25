#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
using namespace std;

#define digit '0'
#define clear 'c'
#define backspace 2

class Token
{
public:
	char kind;
	double value;

	Token():kind{' '},value{0}{}
	Token(char ch) :kind{ ch }, value{ 0 }{}
	Token(char ch, double val) :kind{ ch }, value{ val }{}
};

class Token_stream
{
	bool full{ false };
	Token buffer;
public:
	Token_stream():full{false},buffer{}{}
	Token get();
	void putback(Token t);
};

extern bool invalidSym;
extern string invalidSym_mess;
extern string strExpression;
char getNextSymbol();
void invalidSymbol(string str);
void backspaceFunct();
void clearFunct();
void clearIndex();

double expression();

void error(string str);