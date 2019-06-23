#include <iostream>

#include <boost/regex.hpp>

using namespace std;

int main()
{
    boost::regex exp("(((0[1-9]|[12]\\d|3[01])(0[13578]|1[02])((19|[2-9]\\d)\\d{2}))|((0[1-9]|[12]\\d|30)(0[13456789]|1[012])((19|[2-9]\\d)\\d{2}))|((0[1-9]|1\\d|2[0-8])02((19|[2-9]\\d)\\d{2}))|(2902((1[6-9]|[2-9]\\d)(0[48]|[2468][048]|[13579][26])|((16|[2468][048]|[3579][26])00))))(2[0-3]|[01][0-9])[0-5][0-9][0-5][0-9]");

    string value("30012012235959");

    if (boost::regex_match(value, exp)) {
        cout << "value " << value << " is valid" << endl;
    } else {
        cout << "value " << value << " is *NOT* valid" << endl;
    }

    return 0;
}
