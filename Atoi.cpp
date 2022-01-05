#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main ()
{
  int i;
  char szInput [256];
  string str = "5";
  do
  {
	  printf ("Enter a number: ");
	  fgets ( szInput, 256, stdin );
	  i = atoi (szInput);
	  printf ("The value entered is %d\n",i);

	  // need a char * 
	  cout <<  atoi(str.c_str()) << endl;
  } while (i >= 0);

  return 0;
}
 



