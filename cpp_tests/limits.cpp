#include <iostream>
#include <limits>

#define DISPLAY(x) cout << #x << endl << \
            "     SIZE: " << sizeof(x) << endl << \
            "     MIN:  " << numeric_limits<x>::min() << endl << \
            "     MAX:  " << numeric_limits<x>::max() << endl

using namespace std;

int main()
{
	DISPLAY(char);
	DISPLAY(unsigned char);
	
	DISPLAY(int);
	DISPLAY(unsigned int);

	DISPLAY(short int);
	DISPLAY(short);

	DISPLAY(long int);
	DISPLAY(long long int);
	DISPLAY(unsigned long long int);

	DISPLAY(float);
	DISPLAY(double);
	
	DISPLAY(streamsize);

	return 0;
}
