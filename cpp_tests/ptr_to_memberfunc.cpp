#include <iostream>
#include <vector>

class A {
	public:
	int mult2(int val) {
		return val*2;
	}

	int mult3(int val) {
		return val*3;
	}
};

class B {
	public:
	int val;

	B(int v) : val(v) {
	}

	int mult2() {
		return val*2;
	}

	int mult3() {
		return val*3;
	}
};

using namespace std;

template<typename ElementType, typename FuncRetType>
void operateOnAll(vector<ElementType> items, FuncRetType (ElementType::*function)(void))
{
	typename vector<ElementType>::iterator iter;
	for(iter = items.begin(); iter < items.end(); iter++) {
		ElementType elem = *iter;
		FuncRetType ret = (elem.*function)();
		cout << ret << endl;
	}
}

int main()
{
	// A simple example
	int (A::*f)(int);
	A a;
	
	f = &A::mult2;

	cout << (a.*f)(100) << endl;

	f = &A::mult3;

	cout << (a.*f)(100) << endl;

	// Now using the template
	vector<B> vec;
	vec.push_back(B(1000));
	vec.push_back(B(1001));
	vec.push_back(B(1002));
	vec.push_back(B(1003));

	operateOnAll<B, int>(vec, &B::mult2);
	operateOnAll(vec, &B::mult3); //deduzindo automaticamente

	return 0;
}
