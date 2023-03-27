#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	char key;
	bool loop = true;

	int a=0;
	while(loop)
	{
		a++;
		cout << a << endl;
		
		if(kbhit())
		{
			key = getch();
			if(key == 27)
			{
				loop = false;
			}
			else
			{

			}

		}


	}
	return 0;
}
