/************************************************************
 ------------------------------------------------------------
Sarah Bass
IO Assignment
CS 41 Data Structures
Description: Double numbers in a string, print seperate lines
-------------------------------------------------------------
std::istream_iterator is a single-pass input iterator 
that reads successive objects of type T
-------------------------------------------------------------
************************************************************/

#include <stdio.h> 
#include <iostream> 
#include <string>
#include <sstream>
#include <iterator> 
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>


using namespace std;

string doubleNumber (string word){
  double number;
  int numbersimple; 
  std::string::size_type sz;
  if (word.find('0') != std::string::npos ||
        word.find('1') != std::string::npos ||
       word.find('2') != std::string::npos ||
        word.find('3') != std::string::npos ||
        word.find('4') != std::string::npos ||
        word.find('5') != std::string::npos ||
        word.find('6') != std::string::npos ||
        word.find('7') != std::string::npos ||
        word.find('8') != std::string::npos ||
        word.find('9') != std::string::npos){
number = stod (word.substr(sz));
number = number * 2;
numbersimple = (int)number;
word = to_string(numbersimple);

}
return word;
}

int main(){
    string sentence;
    string word;
    getline(cin, sentence);
    stringstream stream;
    stream.str(sentence);
    
    while (stream >> word)
    {
       word = doubleNumber(word);
        cout << word << endl;
    }
    return 0;}


 

