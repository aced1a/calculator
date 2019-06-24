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
				error("Требуется ')'");
				//invalidSymbol();
			return d;
		}
	case digit:
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("Отстутствует первичное выражение");
	}
}

double half_term()
{
	double left = primary();
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
			factorial(left);
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

		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
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