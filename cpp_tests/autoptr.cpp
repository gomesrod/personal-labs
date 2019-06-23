#include <iostream>
#include <memory>

using namespace std;

class A {
	private:
		static int objectsCount;

		string name;

		A(A& a);
		A& operator=(A& a);

	public:
		A(const string& n) : name(n) {
			cout << "Ctor A() " << name << endl;
			objectsCount++;
		}
		~A() {
			cout << "Dtor ~A() " << name << endl;
			objectsCount--;
		}

		inline const string& getName() {
			return name;
		}

		static void check() {
			if (objectsCount != 0) {
				cerr << "LEAKING! Count=" << objectsCount << endl;
			}
		}
};

int A::objectsCount = 0;

int main() {
	{
		auto_ptr<A> pa(new A(string("Teste")));
		auto_ptr<A> pa2(new A(string("Teste2")));

		cout << "::: " << pa->getName() << endl;
		cout << "::: " << pa2->getName() << endl;
	}

	A::check();
	return 0;
}
