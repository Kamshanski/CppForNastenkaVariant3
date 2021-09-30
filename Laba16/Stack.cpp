
template<typename T>
struct Stack {
private:
    struct Node {
        T* item;
        Node* next = nullptr;
        Node* prev = nullptr;

        Node(T* item) : item(item) {}
    };

    int _size = 0;
    Node* start = nullptr;
    Node* end = nullptr;

public:
    int size() { return _size; }

    void push(T* item) {
        Node* n = new Node(item);
        n->next = start;
        n->prev = nullptr;
        if (start != nullptr) {
            start->prev = n;
        }
        start = n;
        if (end == nullptr) {
            end = start;
        }
        _size++;
    }

    T* pop() {
        Node* top = start;
        if (top == nullptr) {
            return nullptr;
        }
        T* item = top->item;
        start = start->next;
        if (start != nullptr) {
            start->prev = nullptr;
        } else {
            end = nullptr;
        }
        _size--;
        return item;
    }


    bool remove(function<bool(T*)> predicate) {
        if (_size == 0 && start != nullptr) {
            return false;
        }
        bool found = false;

        Stack<T>* temp = new Stack<T>;
        int size = this->size();
        for (int i = 0; i < size; ++i) {
            T* b = this->pop();
            if (predicate(b)) {
                delete b;
                found = true;
            } else {
                temp->push(b);
            }
        }
        size = temp->size();
        for (int i = 0; i < size; ++i) {
            T*b = temp->pop();
            this->push(b);
        }
        delete temp;
        return found;
    }

    void forEach(function<void(T*, int)> consumer) {
        Stack<T>* temp = new Stack<T>;
        int size = this->size();
        for (int i = 0; i < size; ++i) {
            T* b = this->pop();
            temp->push(b);
            consumer(b, i);
        }
        for (int i = 0; i < size; ++i) {
            T*b = temp->pop();
            this->push(b);
        }
        delete temp;
    }
};
