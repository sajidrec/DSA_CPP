#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    T storage[10];
    int front, back;

public:
    Queue()
    {
        front = back = -1;
    }

    bool isEmpty()
    {
        if ((front == -1 && back == -1) || (back - front < 0))
        {
            return true;
        }
        return false;
    }

    int size()
    {
        if (this->isEmpty())
        {
            return 0;
        }
        return (back - front) + 1;
    }

    void enqueue(T data)
    {
        if (back == 9)
        {
            cout << "Can't add any more value" << endl;
            return;
        }
        if (front == -1 && back == -1)
        {
            front = back = 0;
            storage[front] = data;
        }
        else
        {
            back++;
            storage[back] = data;
        }
    }

    void dequeue()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty can't remove any item";
            return;
        }
        front++;
    }

    T front_value()
    {

        return storage[front];
    }
};

int main()
{
    Queue<string> queue;
    cout << queue.front_value() << endl;
    return 0;
}