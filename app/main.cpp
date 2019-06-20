#include "Button.h"

int main(int argc, char * argv[])
{
	try
	{
		init_SDL();
		return 0;
	}
	catch(exception* c)
	{
		cerr << c->what() << endl;
		return 1;
	}
}