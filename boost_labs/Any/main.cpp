#include <boost/any.hpp>
#include <iostream>

using namespace std;
using boost::any;
using boost::any_cast;
using boost::bad_any_cast;

int main()
{
    any a;
    cout << a.empty() << endl;

    a = 5;
    cout << a.empty() << endl;
    cout << (a.type() == typeid(double)) << endl;
    cout << (a.type() == typeid(int)) << endl;
    cout << any_cast<int>(a) << endl << endl;

    any s(string("sssss"));
    cout << (s.type() == typeid(int)) << endl;
    cout << (s.type() == typeid(string)) << endl;
    cout << any_cast<string>(s) << endl;

    try
    {
        cout << any_cast<float>(s) << endl;
    } catch (bad_any_cast& bac)
    {
        cout << bac.what() << endl;
    }

    return 0;
}
