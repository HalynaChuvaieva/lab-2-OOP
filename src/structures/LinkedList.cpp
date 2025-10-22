#include "LinkedList.h"
#include <stdexcept>

LinkedList::LinkedList() : head(nullptr), sz(0) {}
LinkedList::~LinkedList() { clear(); }
void LinkedList::push_back(int v)
{
    if (!head)
    {
        head = new Node(v);
    }
    else
    {
        Node *p = head;
        while (p->next)
            p = p->next;
        p->next = new Node(v);
    }
    sz++;
}
void LinkedList::push_front(int v)
{
    Node *n = new Node(v);
    n->next = head;
    head = n;
    sz++;
}
void LinkedList::insert_at(int idx, int v)
{
    if (idx <= 0)
    {
        push_front(v);
        return;
    }
    Node *p = head;
    for (int i = 0; i < idx - 1 && p; i++)
        p = p->next;
    if (!p)
        push_back(v);
    else
    {
        Node *n = new Node(v);
        n->next = p->next;
        p->next = n;
    }
    sz++;
}
void LinkedList::remove_at(int idx)
{
    if (!head)
        return;
    if (idx <= 0)
    {
        Node *t = head;
        head = head->next;
        delete t;
        sz--;
        return;
    }
    Node *p = head;
    for (int i = 0; i < idx - 1 && p->next; i++)
        p = p->next;
    if (p->next)
    {
        Node *t = p->next;
        p->next = t->next;
        delete t;
        sz--;
    }
}
std::vector<int> LinkedList::toVector() const
{
    std::vector<int> out;
    Node *p = head;
    while (p)
    {
        out.push_back(p->val);
        p = p->next;
    }
    return out;
}
void LinkedList::clear()
{
    Node *p = head;
    while (p)
    {
        Node *t = p;
        p = p->next;
        delete t;
    }
    head = nullptr;
    sz = 0;
}
bool LinkedList::empty() const { return head == nullptr; }