#include <boost/variant.hpp>
#include <iostream>
#include <string>

using namespace std;

class print_visitor : public boost::static_visitor<>
{
public:
    void operator()(int& val) const
    {
        cout << "Visiting INT:    " << val << endl;
    }
    void operator()(double& val) const
    {
        cout << "Visiting DOUBLE: " << val << endl;
    }
    void operator()(const char* val) const
    {
        cout << "Visiting CHAR*:  " << val << endl;
    }
    void operator()(string& val) const
    {
        cout << "Visiting STRING: " << val << endl;
    }
};

int main()
{
    boost::variant<int, double, const char*, string> vari;

    cout << vari << endl;

    vari = 9;
    cout << vari << endl;
    cout << boost::get<int>(vari) << endl;
    boost::apply_visitor(print_visitor(), vari);

    vari = 3.15;
    cout << vari << endl;
    boost::apply_visitor(print_visitor(), vari);

    vari = "vari";
    cout << vari << endl;
    boost::apply_visitor(print_visitor(), vari);

    vari = string("varistring");
    cout << vari << endl;
    boost::apply_visitor(print_visitor(), vari);

    string& ref = boost::get<string>(vari);
    ref += " _concat_";
    cout << vari << endl;
    boost::apply_visitor(print_visitor(), vari);


    return 0;
}
