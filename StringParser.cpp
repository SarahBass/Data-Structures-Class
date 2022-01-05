#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

int main(void)
{
	cout << "Expression: ";
	string s;
	getline(cin, s);
	cout << "Line: " << s << endl;

	stringstream str(s);
	string buffer;
	while (str >> buffer)
	{
		cout << "Buffer: "<< buffer << endl;
		if (buffer == "-")
			cout << "Negative" << endl;
		else
		{
			float f = atof(buffer.c_str());
			if (f < 0)
				cout << "Negative operand ";
			else
				cout << "Operand ";
			cout << f << endl;
		}
	};

	return 0;
}