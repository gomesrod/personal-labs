#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>

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
    ~A()
    {
        cout << "~ Destructing " << id << endl;
    }
};

void del(A* ptr) {
    MSG("Custom delete");
    delete ptr;
}

int main()
{
    // BASIC
    {
        shared_ptr<A> ptr1(new A(1));
        MSG("Resetting");

        ptr1.reset(new A(2));

        MSG("Copying pointer");

        shared_ptr<A> ptr2(ptr1);

        MSG("Assigning");
        shared_ptr<A> ptr3;
        ptr3 = ptr2;

        MSG("Leaving scope");
    }

    MSG("");

    // USING A CUSTOM DELETER
    typedef shared_ptr<A> a_ptr;
    {
        a_ptr ptr4(new A(4), del);
    }

    MSG("");

    // ARRAY
    {
        shared_array<A> arr(new A[3] {A(10),A(11),A(12)});
    }

    MSG("");

    // WEAK PTR
    {
        a_ptr ptr5(new A(20));
        {
            weak_ptr<A> weak(ptr5);

            a_ptr sh = weak.lock();

            if (sh) {
                MSG("Weak ref. is Valid");
                MSG(sh.get()->id);
            } else {
                MSG("Weak ref. NOT valid!")
            }
        }

        ptr5.reset();

        {
            weak_ptr<A> weak(ptr5);

            a_ptr sh = weak.lock();

            if (sh) {
                MSG("Weak ref. is Valid");
                MSG(sh.get()->id);
            } else {
                MSG("Weak ref. NOT valid!")
            }
        }

    }
    return 0;
}
