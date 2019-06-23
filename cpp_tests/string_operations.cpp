#include <string>
#include <iostream>

using namespace std;

void print(const char*);
void print(const string&);

int main()
{
	print(">>>> Simple initialization");
	string a("ABCDEFGH");
	print(a);
	string b(a, 4, 2);
	print(b);

	print(">>>> Initializing with iterators");
	string::iterator iter1 = a.begin() + 3;
	string::iterator iter2 = a.end() - 2;
	print(string("iter1=") + *iter1 + " , iter2=" + *iter2);
	string c(iter1,iter2);
	print(c);

	print(">>>> Size and capacity test");
	string d;
	d.reserve(7);
	for (int i = 0; i < 17; i++) {
		d += "X";
		cout << d << " Size=" << d.size() << " , Cap=" << d.capacity() << endl;
	}

	print(">>>> Inserting and replacing");
	string e("A piece of text");
	e.insert(8, "$tag* ");
	print(e);
	int tagpos = e.find("$tag*");
	e.replace(tagpos, 5, "embromation");
	print(e);
}

void print(const char* msg)
{
	cout << msg << endl;
}

void print(const string& msg)
{
	cout << msg << endl;
}
