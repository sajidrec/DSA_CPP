#include <iostream>

using namespace std;

template <class T>
class CircularQueue
{
private:
    int totalElements, front, back;
    T storage[10];

public:
    CircularQueue()
    {
        totalElements = 0;
        front = back = -1;
    }

    bool isEmpty()
    {
        if (!totalElements)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (totalElements == 10)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        return this->totalElements;
    }

    void enqueue(T data)
    {
        if (this->isFull())
        {
            cout << "Can't add more items queue is full" << endl;
            return;
        }
        else if (front == -1 && back == -1)
        {
            front = back = 0;
            storage[front] = data;
        }
        else
        {
            back = (back + 1) % 10;
            storage[back] = data;
        }
        this->totalElements++;
    }

    void dequeue()
    {
        if (this->isEmpty())
        {
            cout << "There is no item left so can't dequeue." << endl;
            front = back = -1;
            return;
        }
        totalElements--;
        front = (front + 1) % 10;
    }

    T getFrontElement()
    {
        return storage[front];
    }
};

int main()
{
    // Circular queue methods
    // isEmpty
    // isFull
    // size
    // enqueue
    // dequeue
    // getFrontElement

    CircularQueue<string> circularQueue;

    for (int i = 0; i < 10; i++)
    {
        circularQueue.enqueue("sajid");
    }
    for (int i = 0; i < 10; i++)
    {
        circularQueue.dequeue();
    }

    circularQueue.enqueue("sajid");
    circularQueue.enqueue("hossain");
    circularQueue.dequeue();

    cout << circularQueue.getFrontElement() << endl;
    cout << circularQueue.size() << endl;

    return 0;
}