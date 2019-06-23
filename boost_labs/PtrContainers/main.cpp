#include <iostream>
#include <vector>
#include <boost/ptr_container/ptr_vector.hpp>

#define MSG(x) cout << x << endl;

using namespace std;
using namespace boost;

class A
{
    public:
    int id;

    A(int _id) : id(_id)
    {
        cout << "Constructing " << id << endl;
    }
    A(A& other) : id(other.id)
    {
        cout << "Copying " << id << endl;
    }
    ~A()
    {
        cout << "~ Destructing " << id << endl;
    }
};

int main()
{
    ptr_vector<A> vec;

    vec.push_back(new A(1));
    vec.push_back(new A(2));
    vec.push_back(new A(3));

    MSG("Removing...");
    vec.pop_back();
    MSG("Removed");
}
