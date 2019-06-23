#include <vector>
#include <iostream>

using namespace std;

class A {
	int val;

	public:

	A(int v) : val(v) {
		cout << "In Constructor A::A(). Val=" << val << endl;
	}
	A(const A& a) {
		val = a.val + 1000;
		cout << "Copy-Constructor A::A(A~). Val=" << val << endl;
	}
	~A() {
		cout << "In Destructor A::~A(). Val=" << val << endl;
	}
};

typedef A* const a_const_ptr;

int main() {
	//cout << "Criando um objeto inicial" << endl;
	//A a1(1);

	//cout << "Copiando..." << endl;
	//A a1copy(a1);

	//cout << "Vetor de objetos by value" << endl;
	//vector<A> vec;
	//vec.push_back(a1copy);
	//vec.push_back(A(2));

	/*
	A* const pa1 = new A(1);
	A* const pa2 = new A(2);
	A* const pa3 = new A(3);
	vector<A* const> ptvec;
	ptvec.push_back(pa1);
	ptvec.push_back(pa2);
	ptvec.push_back(pa3);

	delete pa1;
	*/

	a_const_ptr obj1 = new A(5);
	a_const_ptr obj2 = new A(7);
	a_const_ptr array[] = {obj1};
	array[0] = obj2;

	delete obj1;
	delete obj2;

	return 0;
}
