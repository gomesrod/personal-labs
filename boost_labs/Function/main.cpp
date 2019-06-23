#include <cstdlib>
#include <cstring>

#include <iostream>

#include <boost/function.hpp>

using namespace std;

int main()
{
    boost::function<int (const char*)> f = atoi;
    cout << f("2013") << endl;

    f = strlen;
    cout << f("2013") << endl;

    f.clear();
    try {
        cout << f("2013") << endl;
    } catch (boost::bad_function_call& ex) {
        cerr << ex.what() << endl;
    }
    return 0;
}
