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
			if (invalidSym) return 0;
			t = ts.get();
			if (t.kind != ')')
			{
				invalidSymbol("Требуется ')'");
				{
					ts.putback(t);
					return 0; 
				}
			}
			return d;
		}
	case digit:
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
	case sqrtSym:
		ts.putback(t);
		return 0;
	default:
		ts.putback(t);
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
		case sqrtSym:
			index += 3;
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
			ts.putback(t);
			return left;
		}
	}
}