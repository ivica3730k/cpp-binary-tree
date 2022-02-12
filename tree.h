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
    /**
     * @brief Adds the data point into binary tree with specified key and value
     *
     * @param key Key for the data point
     * @param value Value to store
     */
    void insert(int key, std::string value) {
        if (this->rootNode != nullptr) {
            this->insert(key, value, this->rootNode);
        } else {
            this->rootNode = new Node;
            this->rootNode->key = key;
            this->rootNode->value = value;
        }
    }

    /**
     * @brief Retrieves the data associated with an input key
     *
     * @param key Key to lookup to retrieve the data contents
     * @return std::string* Pointer to the data
     */
    std::string *lookup(int key) {
        Node *node = this->search(key, rootNode);
        if (node == nullptr) {
            return nullptr;
        }
        return &node->value;
    }

    /**
     * @brief Removes the datapoint from the tree with specified key
     *
     * @param key Key of the datapoint to delete from binary tree
     * @return Node* Deleted node
     */
    Node *remove(int key) {
        return (deleteNode(key, rootNode));
    }

    /**
     * @brief Destroys the whole binary tree
     *
     */
    void destroy() {
        this->destroy(this->rootNode);
    }

private:
    Node *rootNode = nullptr;

    /**
     * @brief Destroys the tree starting from specified point.
     *
     * Can be called on rootNode to delete thw whole tree
     *
     * @param node Node to start deleting from
     */
    void destroy(Node *node) {
        if (node != nullptr) {
            this->destroy(node->left);
            this->destroy(node->right);
            delete node;
        }
    }

    /**
     * @brief Adds the data point into the binary tree, starting from the provided node
     *
     * Can be called on rootNode to start inserting data from the top of the binary tree
     *
     * @param key Key of the datapoint
     * @param value Data to store
     * @param node Node to start inserting at
     */
    void insert(int key, std::string value, Node *node) {
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

    /**
     * @brief Search the binary tree for a node with associated key
     *
     * Can be called on rootNode to search the whole binary tree
     *
     * @param key Key of the datapoint to retrieve
     * @param node node to start the lookup at
     * @return Node* Node matching the key provided in the search parameter
     */
    Node *search(int key, Node *node) {
        if (node != nullptr) {
            if (key == node->key) {
                return node;
            }
            if (key < node->key) {
                return search(key, node->left);
            } else {
                return search(key, node->right);
            }
        } else {
            return nullptr;
        }
    }

    /**
     * @brief Find the minimum node on from the startpoint node provided
     *
     * Used for deleting the node from the tree
     *
     * @param node starting node
     * @return Node* minimum node found
     */
    Node *findMinNode(Node *node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    /**
     * @brief Deletes the node from the binary tree
     *
     * Can be called with rootNode in the parameter to start the lookup
     * for deletion on the whole tre
     *
     * @param key Key of the datapoint to delete
     * @param node Node to start lookup for deletion on
     * @return Node*
     */
    Node *deleteNode(int key, Node *&node) {
        if (node == nullptr) {
            return node;
        } else if (key < node->key) {
            // key is less than node, go left
            node->left = deleteNode(key, node->left);
        } else if (key > node->key) {
            // key is more than node, go right
            node->right = deleteNode(key, node->right);
        } else {
            // we got our node
            if (node->left == nullptr && node->right == nullptr) {
                // if it has no children just delete it
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                // if it has no no left (smaller) node children, set bigger as the node
                Node *temp = node->right;
                delete node;
                node = temp;
            } else if (node->right == nullptr) {
                // if it has no right (bigger) node children, set smaller as node
                Node *temp = node->left;
                delete node;
                node = temp;
            } else {
                // if it has both children
                Node *min = findMinNode(node->right); // get the minimum node on bigger side
                node->key = min->key;                 // set node key to minimum key from right side
                node->value = min->value;             // set node value to minimum value from the right side
                node->right = deleteNode(min->key, node->right);
            }
        }
        return node;
    }
};
