#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

using namespace std;

class Concatenator : public binary_function<std::string, std::string, void>
{
    public:
    void operator()(std::string a, std::string b) const {
        cout << a << " " << b << endl;
    }
};

void concatAndPrint(string a, string b, ostream& out) {
    out << a << " " << b << endl;
}

bool compareNumerically(string a, string b) {
    int intA;
    stringstream(a) >> intA;

    int intB;
    stringstream(b) >> intB;

    return intA < intB;
}

int main()
{
    vector<string> vec;

    vec.push_back("10");
    vec.push_back("1");
    vec.push_back("2");
    vec.push_back("3");
    vec.push_back("299");

    // Using STL bind
    for_each(vec.begin(), vec.end(), std::bind1st(Concatenator(), "PrintingSTL"));

    // Using boost bind
    for_each(vec.begin(), vec.end(), boost::bind(concatAndPrint, "PrintingBoost", _1, boost::ref(cout)));

    // Standard sort
    vector<string> vec2(vec.begin(), vec.end());
    sort(vec2.begin(), vec2.end());
    for_each(vec2.begin(), vec2.end(), boost::bind(concatAndPrint, "PrintingBoostSorted", _1, boost::ref(cout)));

    // Standard sort using a custom function
    vector<string> vec3(vec.begin(), vec.end());
    sort(vec3.begin(), vec3.end(), boost::bind(compareNumerically, _1, _2));
    for_each(vec3.begin(), vec3.end(), boost::bind(concatAndPrint, "PrintingBoostSorted2", _1, boost::ref(cout)));

    return 0;
}
