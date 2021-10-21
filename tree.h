#include <iostream>
#include <vector>

template <class T>
struct Node {
    int key;
    T value;
    Node* left = nullptr;
    Node* right = nullptr;
};

template <class T>
class BinaryTree {
public:
    BinaryTree();
    void insert(int key, value T)
    {
        //insert node into tree, with key and its value
    }
    T lookup(int key)
    {
        //return the value from the node with associated key
    }
    void remove(int key)
    {
        //remove the node with associated key
    }
    std::vector<T> vectrorise()
    {
        // return the vector representation of binary tree
    }

private:
    Node<T> rootNode = new Node<T>;
};
