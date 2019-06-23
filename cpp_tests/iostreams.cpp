#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("iostreams.cpp");

	input.seekg(-1, ios::end);
	cout << "Penultimo char: " << (input.get()) << endl;


	cout << input.bad() << " " << input.fail() << endl;

	input.seekg(0, ios::end);
	long fsize = input.tellg();
	cout << "Tamanho do arquivo: " << fsize << endl;
	cout << "Ultimo caractere: " << (input.get()) << endl;

	cout << input.bad() << " " << input.fail() << endl;

	cout << input.bad() << " " << input.fail() << endl;

	input.seekg(0, ios::beg);
	cout << input.bad() << " " << input.fail() << endl;
	cout << "Primeiro: " << (input.get()) << endl;

	input.seekg(fsize/2, ios::beg);
	cout << "Metade  : " << (input.get()) << endl;


	input.close();
}
