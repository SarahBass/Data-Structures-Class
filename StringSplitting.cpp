#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main (void)
{
	stringstream stream;
	string token;
	stream << "1 2 3 + *";

	while(!stream.eof())
	{
		stream >> token;
		cout << token << endl;
	}
	return 0;
}