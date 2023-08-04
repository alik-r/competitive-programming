template <typename T>
struct Node {
    T value;
    Node<T>* prev;
};

template <typename T>
class Stack {
public:
    int length;

    Stack() {
        this->head = nullptr;
        this->length = 0;
    }

    ~Stack() {
        while (this->head != nullptr) {
            Node<T>* temp = this->head;
            this->head = this->head->prev;
            delete temp;
        }
    }

    void push(T item) {
        Node<T>* node = new Node<T>;
        node->value = item;
        node->prev = nullptr;

        this->length++;

        if (this->head == nullptr) {
            this->head = node;
            return;
        }

        node->prev = this->head;
        this->head = node;
    }

    T pop() {
        if (this->length == 0) {
            throw std::out_of_range("Stack is empty");
        }

        this->length--;

        Node<T>* head = this->head;
        this->head = head->prev;
        T value = head->value;
        delete head;
        return value;
    }

    T peek() {
        if (this->length == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return this->head->value;
    }

private:
    Node<T>* head;
};