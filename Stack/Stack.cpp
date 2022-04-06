#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    int index;
    T storage[10];

public:
    Stack()
    {
        index = -1;
    }

    int count()
    {
        return index + 1;
    }

    bool isEmpty()
    {
        if (index < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(T data)
    {
        if (index == 9)
        {
            cout << "Overflowed" << endl;
        }
        else
        {
            index++;
            storage[index] = data;
        }
    }

    void pop()
    {
        if (this->isEmpty())
        {
            cout << "Underflowed" << endl;
        }
        else
        {
            index--;
        }
    }

    T top()
    {
        if (this->isEmpty())
        {
            throw invalid_argument("Stack is empty.");
        }
        return storage[index];
    }
};

int main()
{
    return 0;
}