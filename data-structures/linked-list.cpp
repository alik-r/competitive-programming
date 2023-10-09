#include <iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void append(const T& data) {
        Node<T>* newNode = new Node<T>{data, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void prepend(const T& data) {
        Node<T>* newNode = new Node<T>{data, head};
        head = newNode;
    }

    void remove(const T& data) {
        if (!head) {
            return;
        }

        if (head->value == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next) {
            if (current->next->value == data) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node<T>* head;
};

int main() {
    LinkedList<int> myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.prepend(0);
    myList.display();

    myList.remove(2);
    myList.display();

    myList.clear();
    myList.display();

    return 0;
}
