#include <iostream>
#include <fstream>

#include <cstdlib>

using namespace std;

int main()
{
	ifstream in("inputs.in.txt");

	if(in.fail()) {
		cerr << "Error opening file" << endl;
		exit(1);
	}

	for(int i = 1; i <= 3; i++) {
		int n;
		in >> n;
		cout << n << endl;
	}

	for(int i = 1; i <= 3; i++) {
		string s;
		in >> s;
		cout << s << endl;
	}
	
	for(int i = 1; i <= 5; i++) {
		int n;
		in >> n;
		cout << n << endl;
	}
	
	double d;
	in >> d;
	cout << d << endl;
}
