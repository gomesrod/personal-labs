#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>
#include <boost/bind.hpp>

using namespace std;

void formatCreditCardNumber(string creditCardNumber)
{
    boost::regex exp("(\\d{4})[ -]?(\\d{4})[ -]?(\\d{4})[ -]?(\\d{4})");

    cout << "--------------------\n   Number: " << creditCardNumber << endl;

    if (!boost::regex_match(creditCardNumber, exp)) {
        cout << "Invalid number!" << endl;
        return;
    }

    string humanFormat = regex_replace(creditCardNumber, exp, "\\1-\\2-\\3-\\4",
                                       boost::match_default | boost::format_sed);
    cout << "Human format: " << humanFormat << endl;

    string machineFormat = regex_replace(creditCardNumber, exp, "\\1\\2\\3\\4",
                                       boost::match_default | boost::format_sed);
    cout << "Machine format: " << machineFormat << endl;
}

void doSomeSearch(string val) {
    boost::regex exp("(\\d\\d\\d)\\D\\D(\\d\\d\\d)");
    boost::smatch m;

    cout << "     Searching: expression in: " << val << endl;
    if (!boost::regex_search(val, m, exp)) {
        cout << "no match" << endl;
        return;
    }

    cout << "Size: " << m.size() << endl;

    for (size_t i = 0; i < m.size(); i++) {
        cout << "Len:" << m.length(i) << " : " << m[i] << endl;
    }
}

int main()
{
    string cards[] = {
        string("1234"),
        string("11112222333344445"),
        string("6666777788889999"),
        string("5555-6666-7777-8888")
    };

    for_each(cards, cards+4, formatCreditCardNumber);

    // Using the test results
    cout << "\n\n\n";

    string values[] = {
        "11bb22cc44dd55kk66jj",
        "112bb223cc445dd556kk667jj889"
    };

    for_each(values, values+2, doSomeSearch);
}
