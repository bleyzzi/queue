#include "queue.h"
void Queue::cln()
{
    front = nullptr;
    high_rear = nullptr;
    medium_rear = nullptr;
    low_rear = nullptr;
    r_high_size = 0;
    r_medium_size = 0;
    r_low_size = 0;
}

Queue::Queue()
{
    cln();
}

void Queue::push(const int& _val, const Prt& p)
{
    Node* num = new Node;
    num->val = _val;
    if (p == Prt::High) {
        if (high_rear == nullptr)
        {
            num->next = front;
            front = num;
        }
        else if (high_rear != nullptr)
        {
            num->next = high_rear->next;
            high_rear->next = num;
        }
        high_rear = num;
        r_high_size++;
    }
    if (p == Prt::Medium)
    {
        if (medium_rear == nullptr && high_rear == nullptr) {
            num->next = front;
            front = num;
        }
        else if (medium_rear == nullptr && high_rear != nullptr)
        {
            num->next = high_rear->next;
            high_rear->next = num;
        }
        else if (medium_rear != nullptr && high_rear != nullptr)
        {
            num->next = medium_rear->next;
            medium_rear->next = num;
        }
        medium_rear = num;
        r_medium_size++;
    }
    if (p == Prt::Low)
    {
        if (low_rear == nullptr && medium_rear == nullptr && high_rear == nullptr)
        {
            num->next = nullptr;
            front = num;
        }
        if (low_rear == nullptr && medium_rear == nullptr && high_rear != nullptr)
        {
            high_rear->next = num;
        }
        if (low_rear == nullptr && medium_rear != nullptr && high_rear != nullptr)
        {
            medium_rear->next = num;
        }
        if (low_rear != nullptr && medium_rear != nullptr && high_rear != nullptr)
        {
            num->next = low_rear->next;
            low_rear->next = num;
        }
        low_rear = num;
        r_low_size++;
    }
}

Queue::Queue(const Queue& q)
{
    cout << "Copy...." << "\n";
    copy_copy(q);
}

Queue::Queue(Queue&& q)
{
    cout << "Move...." << "\n";
    copy_move(move(q));
    q.cln();
}

void Queue::copy_copy(const Queue& q)
{
    int i = 0;
    cln();
    int cnt = 0;
    Node* ptr = q.front;
    while (ptr != nullptr)
    {
        if (i < q.high_size())
        {
            push(ptr->val, Prt::High);
        }
        else if (i < q.high_size() + q.medium_size())
        {
            push(ptr->val, Prt::Medium);
        }
        else if (i < q.size())
        {
            push(ptr->val, Prt::Low);
        }
        ptr = ptr->next;
        cnt++;
    }
}

void Queue::copy_move(Queue&& q)
{
    front = q.front;
    high_rear = q.high_rear;
    medium_rear = q.medium_rear;
    low_rear = q.low_rear;
    r_high_size = q.r_high_size;
    r_medium_size = q.r_medium_size;
    r_low_size = q.r_low_size;
}

Queue& Queue::operator=(const Queue& q)
{
    cout << "Copying with the assignment operator...." << "\n";
    if (&q == this)
    {
        return *this;
    }
    erase();
    copy_copy(move(q));
    return *this;
}

Queue& Queue::operator=(Queue&& q)
{
    cout << "Movying with the assignment operator...." << "\n";
    if (&q == this)
    {
        return *this;
    }
    copy_move(move(q));
    q.cln();
    return *this;
}


bool Queue::is_empty() const
{
    return (front == nullptr);
}

void Queue::erase()
{
    Node* ptr = front;
    Node* ptr2;
    while (ptr != nullptr)
    {
        ptr2 = ptr;
        ptr = ptr2->next;
        cout << ptr2->val << " Deleted" << "\n";
        delete ptr2;
    }
    cln();
}

Queue::~Queue()
{
    erase();
}
int Queue::size() const
{
    return r_high_size + r_medium_size + r_low_size;
}

int Queue::high_size() const
{
    return r_high_size;
}

int Queue::medium_size() const
{
    return r_medium_size;
}

int Queue::low_size() const
{
    return r_low_size;
}

bool Queue::pop()
{
    if (is_empty())
    {
        return 0;
    }
    Node* p = front;
    front = p->next;
    if (r_high_size > 0)
    {
        high_rear = nullptr;
        r_high_size--;
    }
    else if (r_medium_size > 0)
    {
        medium_rear = nullptr;
        r_medium_size--;
    }
    else if (r_low_size > 0)
    {
        low_rear = nullptr;
        r_low_size--;
    }
    cout << "Deleting...." << "\n";
    delete p;
    return 1;
}

string Queue::get_top(const Queue& q)
{
    Node* ptr = front;
    string p;
    string s = "";
    if (is_empty())
    {
        throw logic_error("Error, queue is empty");
    }
    if (r_high_size != 0)
    {
        p = "High";
    }
    else if (r_medium_size != 0)
    {
        p = "Medium";
    }
    else if (r_low_size != 0)
    {
        p = "Low";
    }
    s += to_string(ptr->val) + " " + p;
    return s;
}

ostream& operator<<(ostream& out, const Queue& q)
{
    Node* ptr = q.front;
    out << "{ ";
    while (ptr != nullptr) {
        out << ptr->val << " ";
        ptr = ptr->next;
    }
    out << "}";
    return out << "\n";
}
