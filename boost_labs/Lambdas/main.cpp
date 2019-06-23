#include <iostream>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <numeric>
#include <iterator>
#include <set>

#include <boost/function.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/if.hpp>

using namespace std;

int generateRand()
{
    static bool initialized = false;
    if (!initialized) {
        srand(time(0));
        initialized = true;
    }

    return rand();
}

int main()
{
    set<int> s;

    generate_n(insert_iterator<set<int> >(s, s.begin()),
               5, boost::function<int (void)>(generateRand));

    for_each(s.begin(), s.end(), cout << boost::lambda::_1 << "\n");

    cout << "---------" << endl;
    for_each(s.begin(), s.end(), boost::lambda::if_then(boost::lambda::_1 > 20000, cout << boost::lambda::_1 << "\n"));

    cout << "---------" << endl;
    for_each(s.begin(), s.end(), boost::lambda::if_then_else(boost::lambda::_1 > 20000, cout << boost::lambda::_1 << "\n", cout << boost::lambda::_1 * -1 << "\n"));

    cout << "--------- Somando" << endl;
    int accum = accumulate(s.begin(), s.end(), 0, boost::lambda::_1 + boost::lambda::_2);
    cout << accum << endl;
}
