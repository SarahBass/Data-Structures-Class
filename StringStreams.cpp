#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>   

using namespace std;

int main()
{
	string sentence;
	string word;
	getline(cin, sentence);

	stringstream stream;
	stream.str(sentence);

	while (stream >> word)
	{
		cout << word << endl;
	}
	return 0;
}