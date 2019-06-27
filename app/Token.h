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
#define sqrtSym 's'
#define clear 'c'
#define backspace '<'

//Лексемы
class Token		
{
public:
	char kind;     //Тип лексемы
	double value;	//Значение лексемы, если тип == число

	Token():kind{' '},value{0}{}
	Token(char ch) :kind{ ch }, value{ 0 }{}
	Token(char ch, double val) :kind{ ch }, value{ val }{}
};

//Поток лексем
class Token_stream
{
	bool full{ false };							//Буффер полный?
	Token buffer;								//Хранит возвращенную лексему
public:
	Token_stream():full{false},buffer{}{}
	void clearBuffer();
	Token get();								//Получение следующей лексемы
	void putback(Token t);						//Возврат лексемы и ее сохранение в буффер
};


extern short index;		//индекс обрабатываемого символа из строки 
extern bool invalidSym;	//Была ошибка в записи выражения
extern string invalidSym_mess;	//сообщение с ошибкой

extern string strExpression; //строка хранящая выражение

string tol(double val);	//перевод числа в строку
char getNextSymbol();	//получения нового символа из строки
void invalidSymbol(string str);	//вызывается при ошибке в выражении
void backspaceFunct();	
void clearFunct();
void clearIndex();

string calculate();	//старт подсчета выражения

void error(string str);	//вызывается при критической ошибке ( генерирует исключение )