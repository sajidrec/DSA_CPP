#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
};

template <class T>
class SinglyLinkedList
{
private:
    Node<T> *head, *curPos, *node;
    int totalNodes;

public:
    SinglyLinkedList()
    {
        head = NULL;
        curPos = NULL;
        totalNodes = 0;
    }

    // append

    void append(T data)
    {
        if (head == NULL)
        {
            head = new Node<T>();
            head->data = data;
            head->next = NULL;
            curPos = head;
        }
        else
        {
            node = new Node<T>();
            curPos->next = node;
            curPos = node;
            node->data = data;
            node->next = NULL;
        }
        totalNodes++;
    }

    // prepend

    void prepend(T data)
    {
        if (head == NULL)
        {
            this->append(data);
        }
        else
        {
            node = new Node<T>();
            node->data = data;
            node->next = head;
            head = node;
        }
        totalNodes++;
    }

    // insert

    void insert(T data, int index)
    {
        if (index < 0 || index >= this->size())
        {
            throw invalid_argument("invalid index number provided.");
        }
        if (index == 0)
        {
            this->prepend(data);
        }
        else if (index == this->size() - 1)
        {
            this->append(data);
        }
        else
        {
            Node<T> *prev, *cur, *nextE, *newAdded;
            prev = this->getNode(index - 1);
            nextE = this->getNode(index + 1);
            cur = this->getNode(index);
            newAdded = new Node<T>();
            newAdded->data = data;
            prev->next = newAdded;
            newAdded->next = cur;
            cur->next = nextE;
        }
        totalNodes++;
    }

    // delete or remove node by index number

    void remove(int index)
    {
        if (index < 0 || index >= this->size())
        {
            throw invalid_argument("invalid index number");
        }
        if (index == 0)
        {
            if (this->size() == 1)
            {
                head = NULL;
            }
            else
            {
                Node<T> *temp = new Node<T>();
                temp->next = head->next;
                head = NULL;
                head = temp->next;
                delete temp;
            }
        }
        else
        {
            Node<T> *prev, *cur, *nextE;
            prev = this->getNode(index - 1);
            cur = this->getNode(index);
            if (cur->next == NULL)
            {
                delete cur;
                totalNodes--;
                return;
            }
            nextE = this->getNode(index + 1);
            prev->next = nextE;
            delete cur;
        }
        totalNodes--;
    }

    // size

    int size()
    {
        return totalNodes;
    }

    // at 0 based indexing
    T at(int index)
    {
        if (index >= this->size() || index < 0)
        {
            throw invalid_argument("index number trying to access is invalid.");
        }
        Node<T> *data = head;
        for (int i = 0; i < index; i++)
        {
            data = data->next;
        }
        return data->data;
    }

    // get a full node

    Node<T> *getNode(int index)
    {
        if (index >= this->size() || index < 0)
        {
            throw invalid_argument("index number trying to access is invalid.");
        }
        Node<T> *data = head;
        for (int i = 0; i < index; i++)
        {
            data = data->next;
        }
        return data;
    }
};

int main()
{
    SinglyLinkedList<string> str;
    str.append("Hello");
    str.append("world");
    str.append("war");
    str.append("will");
    str.append("begain");
    str.append("don't worry");
    str.insert("3", 3);
    str.insert("2", 3);

    str.remove(3);

    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << endl;
    }
    return 0;
}