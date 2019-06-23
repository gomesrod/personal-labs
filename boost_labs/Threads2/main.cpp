#include <iostream>
#include <stdexcept>
#include <vector>
#include <boost/thread.hpp>

using namespace std;

/**
* Regular queue (throws exception when polling an empty queue)
*
*/
template <typename T>
class Queue
{
    public:

    void add(T val)
    {
        data.push_back(val);
    }

    T poll()
    {
        if (data.empty()) {
            throw logic_error("Queue empty");
        } else {
            T val = data.front();
            data.erase(data.begin());
            return val;
        }
    }

    private:
    vector<T> data;
};


/**
* Synchronized queue (add and poll communicate with each other using a condition
                      variable)
*
*/
template <typename T>
class SyncQueue
{
    public:

    SyncQueue(boost::mutex& mut) : queueMutex(mut)
    {

    }

    void add(T val)
    {
        boost::lock_guard<boost::mutex> guard(queueMutex);
        data.push_back(val);
        cond.notify_all();
    }

    T poll()
    {
        {
            boost::lock_guard<boost::mutex> guard(queueMutex);
            while (data.empty()) {
                cond.wait(queueMutex);
            }
        }

        T val = data.front();
        data.erase(data.begin());
        return val;
    }

    private:
    vector<T> data;
    boost::condition_variable_any cond;
    boost::mutex& queueMutex;
};


/*
* Functions that write and consume the regular queue
*/
Queue<int> queue;
void fillQueue()
{
    for(int i = 1000; i <= 1030; i++) {
        queue.add(i);
        boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    }
}
void consumeQueue()
{
    while(true) {
        int val;
        try {
            val = queue.poll();
        } catch (logic_error& le) {
            cerr << le.what() << endl;
            return;
        }

        cout << val << " - ";
        if (val == 1030) {
            break;
        }
    }
    cout << endl;
}

/*
* Functions that write and consume the synchronized queue
*/
boost::mutex mutex;
SyncQueue<int> syncQueue(mutex);
void syncFillQueue()
{
    for(int i = 1000; i <= 1030; i++) {
        syncQueue.add(i);
        boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    }
}
void syncConsumeQueue()
{
    while(true) {
        int val = syncQueue.poll();

        cout << val << " - ";
        if (val == 1030) {
            break;
        }
    }
    cout << endl;
}

int main()
{
    boost::thread fillthread(fillQueue);
    boost::thread consumethread(consumeQueue);

    fillthread.join();
    consumethread.join();

    ////////////////////////////

    boost::thread syncFillthread(syncFillQueue);
    boost::thread syncConsumethread(syncConsumeQueue);

    syncFillthread.join();
    syncConsumethread.join();
    return 0;
}
