#include <iostream>

using namespace std;

void indexOutOfBounds()
{
    throw invalid_argument("Wrong index number provided.");
}

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
            return;
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
            indexOutOfBounds();
        }
        if (index == 0)
        {
            this->prepend(data);
            return;
        }
        else if (index == this->size() - 1)
        {
            this->append(data);
            return;
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
            indexOutOfBounds();
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
            indexOutOfBounds();
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
            indexOutOfBounds();
        }
        Node<T> *data = head;
        for (int i = 0; i < index; i++)
        {
            data = data->next;
        }
        return data;
    }

    // update value
    void update(int index, T data)
    {
        Node<T> *temp = this->getNode(index);
        temp->data = data;
    }
};

int main()
{
    SinglyLinkedList<string> str;
    str.append("Hello");
    str.append("world");
    str.update(0, "Hi");
    str.append("war");
    str.append("will");
    str.append("begain");
    str.append("don't worry");
    str.insert("3", 3);
    str.insert("2", 3);

    str.remove(3);

    // cout << str.size() << endl;

    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << endl;
    }
    return 0;
}
