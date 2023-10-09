#include <iostream>

template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;

    Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(const T& value) {
        root = insert(root, value);
    }

    void remove(const T& value) {
        root = remove(root, value);
    }

    bool search(const T& value) const {
        return search(root, value);
    }

    void printInOrder() const {
        printInOrder(root);
        std::cout << std::endl;
    }

private:
    Node<T>* root;

    Node<T>* insert(Node<T>* node, const T& value) {
        if (node == nullptr) {
            return new Node<T>(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    Node<T>* remove(Node<T>* node, const T& value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }

            Node<T>* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }

    Node<T>* minValueNode(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool search(Node<T>* node, const T& value) const {
        if (node == nullptr) {
            return false;
        }

        if (value == node->value) {
            return true;
        } else if (value < node->value) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    void printInOrder(Node<T>* node) const {
        if (node == nullptr) {
            return;
        }

        printInOrder(node->left);
        std::cout << node->value << " ";
        printInOrder(node->right);
    }

    void destroyTree(Node<T>* node) {
        if (node == nullptr) {
            return;
        }

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
};

int main() {
    BinaryTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder traversal of the binary tree: ";
    tree.printInOrder(); // Should print: 20 30 40 50 60 70 80

    std::cout << "Searching for value 40: " << (tree.search(40) ? "Found" : "Not Found") << std::endl; // Should print "Found"

    tree.remove(30);
    std::cout << "Inorder traversal after removing 30: ";
    tree.printInOrder(); // Should print: 20 40 50 60 70 80

    return 0;
}
