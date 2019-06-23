#include <iostream>
#include <string>
#include <list>

template <typename T>  
class Capsule {
	T element;
public:
	Capsule(T &element) :
		element(element)  
	{} 
	T operator*() { 
		return element;
	}
};

using namespace std;

int main() {
	string * const ptr1 = new string("UM");
	string * const ptr2 = new string("DOIS");

	//list<string*> lst; // Compila normal com ponteiro nao const
	//vector<string* const> lst;   //Nao compila - ponteiro const
	list<Capsule<string* const> > lst;

	lst.push_back(ptr1);
	lst.push_back(ptr2);

	cout << *lst.front() << endl;
	lst.pop_front();
	cout << *lst.front() << endl;


	delete ptr1;
	delete ptr2;
}
