#pragma once
#include <vector>

class Queue
{
public:
    void enqueue(int v) { data.push_back(v); }
    void dequeue()
    {
        if (!data.empty())
            data.erase(data.begin());
    }
    std::vector<int> toVector() const { return data; }
    void clear() { data.clear(); }
    bool empty() const { return data.empty(); }

private:
    std::vector<int> data;
};
