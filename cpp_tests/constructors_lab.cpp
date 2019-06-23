#include <iostream>

using namespace std;

class Foo
{
	public:
	Foo(string fooArg)
	{
		cout << "Foo constructor " << fooArg << endl;
	}
};

class Fuzz
{
	public:
	Fuzz()
	{
		cout << "Fuzz no-arg constructor" << endl;
	}
	Fuzz(int arg)
	{
		cout << "Fuzz constructor " << arg << endl;
	}
};

class Bar : Foo
{
	public:
	Bar(int mult) : Foo("lala"), fuu(10 * mult), fu(5 * mult)
	{
		cout << "Bar constructor" << endl;
	}

	private:
	Fuzz fu;
	Fuzz fuu;
	Fuzz * fupt;
};

int main()
{
	Bar b(10);
}
