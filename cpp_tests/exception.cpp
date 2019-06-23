#include <iostream>

#define PRINT(x) std::cout << #x << "  =  " << x << std::endl;

class Exception {
public:
	const char * const message;
	Exception(const char * const msg) : message(msg) {}
};

class Exception2 {
};

double divisao(double a, double b) throw (Exception) {
	if (b == 0.0) {
		//throw Exception("Division by zero");
		throw Exception2(); //unexpected
	}

	return a / b;
}

int main() {
	try {
		PRINT(divisao(10.0, 5.0));
		PRINT(divisao(15.0, 4));
		PRINT(divisao(20.0, 0));
	} catch (Exception& e) {
		std::cout << e.message << std::endl;
	}
	return 0;
}
