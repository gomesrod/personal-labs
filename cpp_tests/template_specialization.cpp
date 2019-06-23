#include <iostream>

using namespace std;

class A
{
public:
	string toString() {
		return string("ClassA");
	}
};

class B
{
public:
	string toString() {
		return string("ClassB");
	}
};


class C
{
public:
	string toString() {
		return string("ClassC");
	}
};

// General Template
template<class T, class U>
class CoutPrinter
{
public:
	static void print(T first, U second) {
		cout << "I print any class: " << first.toString() << " " << second.toString() << endl;
	}
};

// Partial Specialization - B and something
template<class U>
class CoutPrinter<B,U>
{
public:
	static void print(B first, U second) {
		cout << "I print B in a special way : ***(" << first.toString() << ")*** " << second.toString() << endl;
	}
};

// Total specialization for A and C
template<>
class CoutPrinter<A,C>
{
public:
	static void print(A first, C second) {
		cout << "I like A and C: [[[" << first.toString() << "]]] {{{" << second.toString() << "}}}" << endl;
	}
};

int main()
{
	A a;
	B b;
	C c;

	CoutPrinter<A,B>::print(a, b);
	CoutPrinter<B,C>::print(b, c);
	CoutPrinter<A,C>::print(a, c);


	return 0;
}
