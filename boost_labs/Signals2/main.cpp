#include <boost/signals2.hpp>
#include <iostream>

using namespace std;

int func()
{
    static int invocationId = 0;

    cout << "Hello signals! " << ++invocationId << endl;
    return 1000;
}

int func2()
{
    static int invocationId = 0;

    cout << "Hello signals2! " << ++invocationId << endl;
    return 2000;
}

int func3(int param)
{
    cout << "Received param: " << param << endl;
    return 1700;
}

int main()
{
    boost::signals2::signal<int ()> s;
    s(); // Nothing happens
    cout << "----\n";

    s.connect(func);
    cout << *s() << endl; // Executes one
    cout << "----\n";

    s.connect(func2);
    //s.connect(0, func2);
    cout << *s() << endl; // Executes both
    cout << "----\n";

    s.disconnect(func);
    cout << *s() << endl;
    cout << "----\n";

    s.disconnect_all_slots();
    s.connect(func3);
    s(27);
}
