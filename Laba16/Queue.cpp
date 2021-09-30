
template<typename T>
struct Queue {
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

    void pushEnd(T* item) {
        Node* n = new Node(item);
        n->prev = end;
        n->next = nullptr;
        if (end != nullptr) {
            end->next = n;
        }
        end = n;
        if (start == nullptr) {
            start = end;
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

        Queue<T>* temp = new Queue<T>;
        int size = this->size();
        for (int i = 0; i < size; ++i) {
            T* b = this->pop();
            if (predicate(b)) {
                delete b;
                found = true;
            } else {
                temp->pushEnd(b);
            }
        }
        size = temp->size();
        for (int i = 0; i < size; ++i) {
            T*b = temp->pop();
            this->pushEnd(b);
        }
        delete temp;
        return found;
    }

    void forEach(function<void(T*, int)> consumer) {
        Queue<T>* temp = new Queue<T>;
        int size = this->size();
        for (int i = 0; i < size; ++i) {
            T* b = this->pop();
            temp->pushEnd(b);
            consumer(b, i);
        }
        for (int i = 0; i < size; ++i) {
            T*b = temp->pop();
            this->pushEnd(b);
        }
        delete temp;
    }
};