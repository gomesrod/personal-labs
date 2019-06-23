#include <iostream>
#include <vector>
#include <typeinfo>

#define SHOWTYPE(x) cout << #x << "     " << typeid(x).name() << endl;

using namespace std;

class A {};
class B : public A {};

int main()
{
	SHOWTYPE(1);
	SHOWTYPE(int);
	SHOWTYPE(1.0);
	SHOWTYPE(unsigned int);
	SHOWTYPE(unsigned long long);
	SHOWTYPE(unsigned long long int);

	A a;
	SHOWTYPE(a);
	SHOWTYPE(A);

	A* pa = 0;
	SHOWTYPE(pa);
	SHOWTYPE(*pa);

	vector<A> veca;
	SHOWTYPE(veca);
	SHOWTYPE(vector<A>);
	SHOWTYPE(vector<A*>);
	SHOWTYPE(vector<A>*);
	SHOWTYPE(vector<A>::iterator);
	return 0;
}
