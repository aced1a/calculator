#include "Token.h"
string strExpression = "";
short index = 0;


double parseToDouble()
{
	string val = "";
	bool dot = false;
	while (isdigit(strExpression[index]) || (!dot && strExpression[index] == '.'))
	{
		if (strExpression[index] == '.')
			dot = true;

		val += strExpression[index];
		index++;
	}
	return atof(val.c_str());
}

char getNextSymbol()
{
	index++;
	return strExpression[index - 1];
}

void backspaceFunct()
{
	strExpression.pop_back();
	index--;
}

void clearFunct()
{
	strExpression = "";
	index = 0;
}

void Token_stream::putback(Token t)
{
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch = getNextSymbol();
	switch (ch)
	{
		/*case backspace:
			backspaceFunct();
			break;
		case clear:
			clearFunct();
			break;*/
		case'=':
		case'(': case')': case'+':
		case'-': case'*': case'/':
		case'√': case'^': case'!':
		//case pi: case prefSign:
			return Token{ ch };
			//case'.':
		case'0': case'1': case'2': case'3': case'4':
		case'5': case'6': case'7': case'8': case'9':
			double val = parseToDouble();
			return Token{ digit,val };
		default:
			invalidSymbol();
			break;
	}
}