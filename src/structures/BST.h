#pragma once
#include <vector>
#include <algorithm>

class BST
{
public:
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(int v) { root = insertRec(root, v); }
    void remove(int v) { root = removeRec(root, v); }
    std::vector<int> inorder() const
    {
        std::vector<int> res;
        inorderRec(root, res);
        return res;
    }
    void clear()
    {
        clear(root);
        root = nullptr;
    }

private:
    Node *root;

    Node *insertRec(Node *node, int v)
    {
        if (!node)
            return new Node(v);
        if (v < node->val)
            node->left = insertRec(node->left, v);
        else if (v > node->val)
            node->right = insertRec(node->right, v);
        return node;
    }

    Node *removeRec(Node *node, int v)
    {
        if (!node)
            return nullptr;
        if (v < node->val)
            node->left = removeRec(node->left, v);
        else if (v > node->val)
            node->right = removeRec(node->right, v);
        else
        {
            if (!node->left)
            {
                Node *r = node->right;
                delete node;
                return r;
            }
            if (!node->right)
            {
                Node *l = node->left;
                delete node;
                return l;
            }
            Node *min = node->right;
            while (min->left)
                min = min->left;
            node->val = min->val;
            node->right = removeRec(node->right, min->val);
        }
        return node;
    }

    void inorderRec(Node *node, std::vector<int> &res) const
    {
        if (!node)
            return;
        inorderRec(node->left, res);
        res.push_back(node->val);
        inorderRec(node->right, res);
    }

    void clear(Node *node)
    {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
};
