// Testes com argument-dependent-lookup (ADL)

#include <iostream>

namespace MyNS
{
	class A {};

	void doSomething(A a) {
		std::cout << "doing" << std::endl;
	}
}

int main()
{
	MyNS::A a;
	
	MyNS::doSomething(a);

	//Vai deduzir a funcao pelo parametro
	doSomething(a);

	//Sem ADL - Nao encontra
	//! (doSomething)(a);
	(MyNS::doSomething)(a);

	return 0;
}
