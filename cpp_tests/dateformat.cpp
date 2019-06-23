#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	time_t tt;
	time(&tt);

	tm* t = localtime(&tt);

	cout.fill('0');

	cout << setw(2) << t->tm_mday
	     << "/"
	     << setw(2) << t->tm_mon+1
	     << "/"
	     << setw(4) << t->tm_year+1900
	     << " "
	     << setw(2) << t->tm_hour
	     << ":"
	     << setw(2) << t->tm_min
	     << ":"
	     << setw(2) << t->tm_sec
	     << endl;
		;

	return 0;
}
