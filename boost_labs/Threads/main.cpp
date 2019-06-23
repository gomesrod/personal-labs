#include <boost/thread.hpp>
#include <iostream>

using namespace std;

void fazAlgo()
{
    static boost::mutex mutex;

    for(int i = 0; i < 5; i++) {
        {
            boost::lock_guard<boost::mutex> guard(mutex);
            //mutex.lock();
            cout << boost::this_thread::get_id() << "  :: " << i << "  :: " << endl;
            //mutex.unlock();
        }

        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    }
}

int main()
{
    std::cout << boost::thread::hardware_concurrency() << std::endl;

    boost::thread t(fazAlgo);
    boost::thread t2(fazAlgo);
    boost::thread t3(fazAlgo);

    t.join();
    t2.join();
    t3.join();
    return 0;
}
