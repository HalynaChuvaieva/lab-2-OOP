#pragma once
#include <vector>

class LinkedList
{
public:
    struct Node
    {
        int val;
        Node *next;
        Node(int v) : val(v), next(nullptr) {}
    };
    LinkedList();
    ~LinkedList();
    void push_back(int v);
    void push_front(int v);
    void insert_at(int idx, int v);
    void remove_at(int idx);
    std::vector<int> toVector() const;
    void clear();
    bool empty() const;

private:
    Node *head = nullptr;
    int sz = 0;
};