#include <iostream>
#include <vector>
#include <string>

template<class T>
struct Node {
    int key;
    T value;
    Node *left = nullptr;
    Node *right = nullptr;
};

template<class T>
class Tree {
public:
    void insert(int key, T value) {
        if (this->rootNode == nullptr) {
            std::cout << "Adding first node, " << key << " " << value << std::endl;
            //this is the root node, first node
            this->rootNode = new Node<T>;
            this->rootNode->key = key;
            this->rootNode->value = value;
            this->rootNode->left = nullptr;
            this->rootNode->right = nullptr;
        } else {
            this->insert_at(key, value, this->rootNode);
        }
    }

    void insert_at(int key, T value, Node<T> *node) {
        //insert node into tree, with key and its value

        if (key < node->key) {
            std::cout << "Adding smaller" << std::endl;
            if (node->left == nullptr) {
                std::cout << "Reached empty node" << std::endl;
                node->left = new Node<T>;
                node->left->key = key;
                node->left->value = value;
                node->left->left = nullptr;
                node->left->right = nullptr;
            } else {
                std::cout << "Reaching empty node" << std::endl;
                insert_at(key, value, node->left);
            }
        } else if (key > node->key) {
            std::cout << "Adding bigger" << std::endl;
            if (node->right == nullptr) {
                node = new Node<T>;
                node->right->key = key;
                node->right->value = value;
                node->right->left = nullptr;
                node->right->right = nullptr;
            } else {
                insert_at(key, value, node->right);

            }
        } else {
            node->value = value;
        }

    }

    T lookup(int key) {
        //return the value from the node with associated key
    }

    void remove(int key) {
        //remove the node with associated key
    }

    std::vector<T> vectrorise() {
        //return the vector representation of binary tree
    }

    void destroy_all() {
        // destroy the whole node
        this->destroy(this->rootNode);
    }

private:

    Node<T> *rootNode = nullptr;

    void destroy(Node<T> *leaf) {
        //destroy starting from specified node
        if (leaf != nullptr) {
            this->destroy(leaf->left);
            this->destroy(leaf->right);
            delete leaf;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Tree<std::string> a;
    a.insert(1, "Ivica");
    a.insert(0, "Popo");
    a.insert(-1, "Leon");
    a.insert(2, "Oliver");
    //std::cout << a.rootNode->value << std::endl;
    a.destroy_all();
    return 0;
}
