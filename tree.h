#include <iostream>
#include <vector>
#include <string>

struct Node {
    int key;
    std::string value;
    Node *left = nullptr;
    Node *right = nullptr;
};

class Tree {
public:
    void insert(int key, std::string value) {
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

    Node *remove(int key) {
        return (deleteNode(rootNode, key));
    }

    Node *findMinNode(Node *root) {
        while(root->left != nullptr) root = root->left;
        return root;
    }


private:

    Node *rootNode = nullptr;


    void insert(int key, std::string value, Node *node) {
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

    /* Delete Node in Binary Search Tree */
    Node *deleteNode(Node *root, int key) {
        if (root == nullptr) {
            return root;
        } else if (key < root->key) {
            // key is less than root, go left
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            // key is more than root, go right
            root->right = deleteNode(root->right, key);
        } else {
            //we got our node
            if (root->left == nullptr && root->right == nullptr) {
                //if it has no children just delete it
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                // if it has no no left (smaller) node children, set bigger as the root
                Node *temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                // if it has no right (bigger) node children, set smaller as root
                Node *temp = root;
                root = root->left;
                delete temp;
            } else {
                // if it has both children
                Node *min = findMinNode(root->right); //get the minimum node on bigger side
                root->key = min->key; // set root key to minimum key from right side
                root->value = min->value; // set root value to minimum value from the right side
                root->right = deleteNode(root->right, min->key);
            }
        }
        return root;
    }


};



