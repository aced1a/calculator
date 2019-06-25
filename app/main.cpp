#include "Button.h"

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "RUS");
	try
	{
		init_SDL();
		init_elements();
		firsLoadMedia();
		draw();
		eventControll();
		close_SDL();
		return 0;
	}
	catch(exception c)
	{
		cerr << c.what() << endl;
		return 1;
	}
}