#include <iostream>
#include <vector>
#include <string>

struct Node {
    int key;
    std::string value;
    Node *left = nullptr;
    Node *right = nullptr;
};

template<class T>
class Tree {
public:
    void insert(int key, T value) {
        if (this->rootNode != nullptr) {
            this->insert(key, value, this->rootNode);
        } else {
            this->rootNode = new Node;
            this->rootNode->key = key;
            this->rootNode->value = value;
        }
    }

    void destroy(Node *node) {
        //destroy starting from specified node
        if (node != nullptr) {
            this->destroy(node->left);
            this->destroy(node->right);
            delete node;
        }
    }


    std::string *lookup(int key) {
        Node *node = this->search(key, rootNode);
        if (node == nullptr) {
            return nullptr;
        }
        return &node->value;
    }

    void remove(int key) {
        remove(key, rootNode);
    }

    Node *remove(int key, Node *node) {
        if (node == nullptr) {
            return this->rootNode;
        }
        if (key < node->key) {
            // go left
            node->left = remove(key, node->left);
        } else if (key > node->key) {
            // go right
            node->right = remove(key, rootNode->right);
        } else {
            // found the node
            if (rootNode->left == nullptr && rootNode->right == nullptr) {
                rootNode = nullptr;
            } else if (rootNode->left == nullptr) {
                Node *tmp = rootNode->right;
                free(rootNode);
                return tmp;
            } else if (rootNode->right == nullptr) {
                Node *tmp = rootNode->left;
                free(rootNode);
                return tmp;
            } else {
                Node *tmp = this->minValueNode(rootNode->right);
                rootNode->key = tmp->key;
                rootNode->value = tmp->value;
                rootNode->right = remove(tmp->key, rootNode->right);
            }
        }
        return rootNode;
    }

    Node *minValueNode(Node *node) {
        Node *current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }

    void destroy_all() {
        // destroy the whole node
        this->destroy(this->rootNode);
    }

    void removeIf() {

    }

private:

    Node *rootNode = nullptr;


    void insert(int key, T value, Node *node) {
        //insert node into tree, with key and its value

        if (key < node->key) {
            if (node->left != nullptr) {
                this->insert(key, value, node->left);
            } else {
                node->left = new Node;
                node->left->key = key;
                node->left->value = value;
                node->left->left = nullptr;
                node->left->right = nullptr;
            }
        } else if (key > node->key) {
            if (node->right != nullptr) {
                insert(key, value, node->right);
            } else {
                node->right = new Node;
                node->right->key = key;
                node->right->value = value;
                node->right->left = nullptr;
                node->right->right = nullptr;

            }
        } else {
            node->value = value;
        }

    }

    Node *search(int key, Node *leaf) {
        if (leaf != nullptr) {
            if (key == leaf->key) {
                return leaf;
            }
            if (key < leaf->key) {
                return search(key, leaf->left);
            } else {
                return search(key, leaf->right);
            }
        } else {
            return nullptr;
        }
    }


};