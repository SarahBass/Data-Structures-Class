#include <iostream>
using namespace std;

int main(void)
{	
    char letter = '\0';
    do
    {
        cout << "Give me a letter, (x) to quit." << endl;
        cin >> letter;
        cout << "\nThe value of " << letter << " is " << (int)letter;
    } while (letter != 'x');

	char ascii = (char)0;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
			cout << (int)ascii++ << " " << ascii;
		cout << endl;
	}
	return 0;
}