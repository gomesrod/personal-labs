#include <iostream>
#include <string>

template <class T>
class MyVector {
	private:
		int capacity;
		int size;
		T* data;

		void increaseCapacity() {
			// Aumenta dinamicamente a capacidade
			// realocando o array data.
			// Nao vamos precisar disso...
		}
	public:
		MyVector() {
			capacity = 10;
			data = new T[capacity];
			size = 0;
		}
		~MyVector() {
			delete[] data;
		}

		/** Inclui um objeto no final */
		void push(T obj) {
			if (size >= capacity) {
				increaseCapacity();
			}
			data[size] = obj;
			size++;
		}

		T operator[](int index) {
			return data[index];
		}
};

using namespace std;

int main() {
	string* strptr1 = new string("Ptr 1");
	string* strptr2 = new string("Ptr 2");

	MyVector<string*> vec;
	vec.push(strptr1);
	vec.push(strptr2);

	cout << *vec[0] << endl;
	cout << *vec[1] << endl;
	
	delete strptr1;
	delete strptr2;

	//string* const strconstptr = new string("Const Ptr");
	//MyVector<string * const> constvec;
	//constvec.push(strconstptr);
	//cout << *constvec[0] << endl;

	//delete strconstptr;
}
