#include <stdio.h>
#include <iostream>
using namespace std;

class deque
{
public:
    int head, rear;
    int count;
    int *arr;

    deque();
    deque(int n, int x);

    bool empty();
    int size();
    bool is_full();
    int *double_copy();
    void push_back(int x);
    void pop_back();
    void push_front(int x);
    void pop_front();
    int front();
    int back();
    void clear();
    void resize(int x, int d);
    int &operator[](int x);
};

deque::deque()
{
    this->head = 0;
    this->rear = 0;
    this->arr = new int[1000];
    this->count = 1000;
}

deque::deque(int n, int x)
{
    this->arr = new int[2 * n];
    for (int i = 0; i < n; i++)
    {
        this->arr[i] = x;
    }
    this->head = 0;
    this->rear = n;
    this->count = 2 * n;
}

bool deque::empty()
{
    if (this->head == this->rear)
        return true;
    else
        return false;
}

int deque::size()
{
    int diff = this->rear - this->head;
    if (this->head <= this->rear)
        return diff;
    else
        return this->count + diff;
}

bool deque::is_full()
{
    if (this->size() + 1 >= this->count)
    {
        return true;
    }
    return false;
}

int *deque::double_copy()
{
    int count = 2 * (this->count);
    if (this->count == 0)
        count = 2;
    int *arr = new int[count];

    if (arr == NULL)
    {
        cout << "{Memory allocation failed} " << endl;
        exit(0);
    }

    if (this->head <= this->rear)
    {
        for (int i = this->head; i < this->rear; i++)
            arr[i] = this->arr[i];
    }
    else
    {
        for (int i = 0; i < this->rear; i++)
            arr[i + this->count] = this->arr[i];

        for (int i = this->head; i < this->count; i++)
            arr[i] = this->arr[i];

        this->rear += this->count;
    }

    delete[] this->arr;
    this->count = count;

    return arr;
}

void deque::push_back(int x)
{
    if (this->is_full())
        arr = this->double_copy();

    arr[(this->rear)++] = x;
    if (this->rear == this->count)
        this->rear = 0;
    return;
}

void deque::pop_back()
{
    if (this->head == this->rear)
    {
        cout << "Underflow {pop_back}" << endl;
        return;
    }
    else if (this->rear == 0)
    {
        this->rear = this->count - 1;
        return;
    }
    else
        this->rear--;

    return;
}

void deque::push_front(int x)
{
    if (this->is_full())
        arr = this->double_copy();

    if (this->head == 0)
    {
        this->head = this->count - 1;
        arr[this->head] = x;
        return;
    }
    else
    {
        arr[--(this->head)] = x;
        return;
    }
}

void deque::pop_front()
{
    if (this->head == this->rear)
    {
        cout << "Underflow {pop_front}" << endl;
        return;
    }
    if (this->head + 1 == this->count)
        this->head = 0;
    this->head++;
    return;
}

int deque::front()
{
    if (this->head == this->rear)
    {
        cout << "Underflow {front} ";
        return -1;
    }
    else
    {
        return arr[this->head];
    }
}

int deque::back()
{
    if (this->head == this->rear)
    {
        cout << "Underflow {back} ";
        return -1;
    }
    if (this->rear == 0)
        return arr[this->count - 1];
    else
        return arr[this->rear - 1];
}

void deque::clear()
{
    this->head = 0;
    this->rear = 0;
}

void deque::resize(int x, int d)
{
    if (x == 0)
        this->clear();
    else if (x < this->size())
    {
        if (this->head <= this->rear)
        {
            this->rear = this->head + x;
        }
        else
        {
            this->rear = (this->head + x) % this->count;
        }
    }
    else if (x > this->size())
    {
        int diff = x - this->size();
        for (int i = 0; i < diff; i++)
        {
            this->push_back(d);
        }
    }
}

int &deque::operator[](int x)
{
    int num_elm = this->size();
    if (x >= num_elm || x < 0)
    {
        cout << "Out of range" << endl;
        exit(0);
    }
    else
    {
        if (this->head <= this->rear)
        {
            int index = this->head + x;
            return arr[index];
        }
        else
        {
            int index = (this->head + x) % this->count;
            return arr[index];
        }
    }
}

int main()
{
    //cout << "Driver Code" << endl;
    // deque a;
    // deque a(4, 6);

    // a.push_back(4);
    // a.push_front(7);
    // a.push_back(1);
    // a.push_front(2);

    // cout << "SIZE : " << a.size() << endl;
    // cout << "Front Element : " << a.front() << endl;
    // cout << "Back Element : " << a.back() << endl
    //      << "\n";

    // a.pop_back();
    // a.pop_front();

    // cout << "SIZE : " << a.size() << endl;
    // cout << "Front Element : " << a.front() << endl;
    // cout << "Back Element : " << a.back() << endl
    //      << "\n";

    // a.resize(10, 9);
    // cout << "Deque[5] => " << a[5] << endl;

    deque a;
    a.push_back(2);
    a.push_back(20);
    a.push_back(31);
    a.push_front(44);
    a.push_front(76);

    cout << "Front Element : " << a.front() << endl;
    cout << "Back Element : " << a.back() << endl
         << "\n";

    a.pop_back();
    a.pop_front();

    cout << "Front Element : " << a.front() << endl;
    cout << "Back Element : " << a.back() << endl
         << "\n";

    cout << "Deque[1] => " << a[1] << endl;

    a.clear();

    bool is_empty = a.empty();
    cout << bool(is_empty) << endl;

    a.resize(4, 11);
    cout << "Deque[3] => " << a[3] << endl;
    return 0;
}