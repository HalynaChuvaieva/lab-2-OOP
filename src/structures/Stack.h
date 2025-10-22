#pragma once
#include <vector>

class Stack
{
public:
    void push(int v) { data.push_back(v); }
    void pop()
    {
        if (!data.empty())
            data.pop_back();
    }
    std::vector<int> toVector() const { return data; }
    void clear() { data.clear(); }
    bool empty() const { return data.empty(); }

private:
    std::vector<int> data;
};
