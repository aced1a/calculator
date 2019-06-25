#include "Token.h"

Token_stream ts;

void error(string str)
{
	throw runtime_error(str);
}

double factorial(double n)
{
	int res = 1;
	if (n != int(n))
		error("Некорректный факториал");
	for (int i = 2; i <= n; i++)
		res *= i;
	return res;
}

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case'(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')')
			{
				invalidSymbol("Требуется ')'");
				return 0;
			}
			return d;
		}
	case digit:
		cout << "Получено число: " << t.value << endl;
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		invalidSymbol("Отстутствует первичное выражение");
		return 0;
		//error("Отстутствует первичное выражение");
	}
}

double half_term()
{
	double left = primary();
	if (invalidSym)
		return 0;
	Token t = ts.get();
	while(true)
	{
		switch (t.kind)
		{
		case '√':
			left = sqrt(primary());
			t = ts.get();
			break;
		case '^':
			left = pow(left, primary());
			t = ts.get();
			break;
		case '!':
			left = factorial(left);
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double term()
{
	double left = half_term();
	if (invalidSym)
		return 0;
	Token t = ts.get();
	while (true) 
	{
		switch (t.kind)
		{

		case '*':
			left *= half_term();
			t = ts.get();
			break;
		case '/':
		{
			double d = half_term();
			if (d == 0)
				error("Деление на нуль");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = half_term();
			if (d == 0)
				error("Деление на нуль");
			left = int(left) % int(d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	if (invalidSym)
		return 0;
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		case '=':
			return left;
		default:
			return left;
		}
	}
}