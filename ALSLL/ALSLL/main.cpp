#include<iostream>
using namespace std;

template<typename T>
struct Node
{
    T info;
    int next;
    Node()
    {
        next = -1;
    }
    Node(T val)
    {
        info = val;
        next = -1;
    }
};

template<typename T>
class ALSLL
{
    Node<T>* data;
    int size;
    int SLH; //System list head
    int ULH;//User list head
    int getNewNode()
    {
        if (SLH == -1 || SLH >= size)
        {
            return -1;
        }
        int x = SLH;
        SLH = data[SLH].next;
        return x;
    }

    void initializer()
    {
        if (size == 0) return; // Handle empty list
        for (int i = 0; i < size - 1; i++)
        {
            data[i].next = i + 1;
        }
        data[size - 1].next = -1;
        SLH = 0; // Update SLH to point to the first available node
    }

public:
    ALSLL()
    {
        data = nullptr;
        size = 0;
        ULH = -1;
        SLH = -1; // Initialize SLH to -1
    }
    ALSLL(int capacity)
    {
        data = new Node<T>[capacity];
        size = capacity;
        ULH = -1;
        SLH = size > 0 ? 0 : -1; // Update SLH based on size
        initializer();
    }
    ~ALSLL()
    {
        delete[] data;
    }
    void insertAtHead(T val)
    {
        int x = getNewNode();
        if (x == -1)
            return;
        data[x].info = val;
        data[x].next = ULH;
        ULH = x;
    }
    void displayALSLL()
    {
        if (ULH == -1)
            return;

        int x = ULH;
        while (x != -1)
        {
            cout << data[x].info << " ";
            x = data[x].next;
        }
        cout << endl; // Add this to flush the output
    }

    void insertAtTail(T val)
    {
        int x = getNewNode();
        if (x == -1)
            return;

        data[x].info = val;
        data[x].next = -1;

        if (ULH == -1)
        {
            ULH = x;
            return;
        }

        int y = ULH;
        while (data[y].next != -1)
        {
            y = data[y].next;
        }
        data[y].next = x;
    }

    void remove(T key)
    {
        if (ULH == -1)
            return;

        int x = ULH;
        int previous = -1;

        while (x != -1 && data[x].info != key)
        {
            previous = x;
            x = data[x].next;
        }

        if (x == -1) // Key not found
            return;

        if (previous == -1) // Key found at the head
            ULH = data[x].next;
        else
            data[previous].next = data[x].next;

        data[x].next = SLH;
        SLH = x;
    }

    void removeAfter(T key)
    {
        if (ULH == -1)
            return;

        int x = ULH;
        while (x != -1 && data[x].info != key)
        {
            x = data[x].next;
        }
        if (x == -1 || data[x].next == -1)
        {
            return;
        }
        int y = data[x].next;
        data[x].next = data[y].next;
        data[y].next = SLH;
        SLH = y;
    }
    void removeBefore(T key)
    {
        if (ULH == -1 || data[ULH].next == -1)
            return;

        if (data[ULH].info == key)
            return;

        int x = data[ULH].next;
        int previous = ULH;
        int slow = -1;
        while (x != -1 && data[x].info != key)
        {
            slow = previous;
            previous = x;
            x = data[x].next;
        }

        if (x == -1) // Key not found
            return;

        if (slow == -1) // Key found at the head
            ULH = data[ULH].next;
        else
            data[slow].next = data[previous].next;
    }
};

int main()
{
    ALSLL<int> list;
    list.insertAtHead(5);
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtTail(6);
    list.displayALSLL();
    return 0;
}
