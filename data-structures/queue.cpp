template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
class Queue {
public:
    Queue() {
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    ~Queue() {
        while (this->head != nullptr) {
            Node<T>* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }

    void enqueue(T item) {
        Node<T>* node = new Node<T>;
        node->value = item;
        node->next = nullptr;

        this->length++;

        if(this->tail == nullptr) {
            this->head = this->tail = node;
            return;
        }

        this->tail->next = node;
        this->tail = node;
    }

    T deque() {
        if (this->head == nullptr) {
            return T();         
        }

        this->length--;

        Node<T>* temp = this->head;
        this->head = this->head->next;
        T value = temp->value;

        delete temp;

        if (this->head == nullptr) {
            this->tail = nullptr;
        }

        return value;
    }

    T peek() {
        if (this->head == nullptr) {
            return T();
        }

        return this->head->value;
    }

    int length;

private:
    Node<T>* head;
    Node<T>* tail;
};
