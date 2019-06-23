#include <iostream>
#include <boost/lambda/lambda.hpp>

#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
using namespace boost;

string genLetter() {
    static char nextval[] = {'@', '\0'}; // @ e o valor imediatamente anterior ao "A"
    nextval[0]++;
    return string(nextval);
}

int main()
{
    vector<string> vec;

    generate_n(back_insert_iterator<vector<string> >(vec), 10, genLetter);

    for_each(vec.begin(), vec.end(), cout << "Hello " + lambda::_1 << "\n");

    return 0;
}
