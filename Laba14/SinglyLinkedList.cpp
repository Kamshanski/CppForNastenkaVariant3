
template<typename T>
struct SinglyLinkedList {
private:
    int _size = 0;
    struct Node {
        T* item;
        Node* next = nullptr;

        Node(T* item) : item(item) {}
    };
    Node* start = nullptr;

    Node* getNode(int i) {
        Node* node = start;
        for (int j = 0; j < i; ++j) {
            node = node->next;
        }
        return node;
    }

public:
    T* get(int i) {
        if (i < 0 || i >= _size) {
            return nullptr;
        }

        Node* node = getNode(i);
        return node->item;
    }

    void addFirst(T* item) {
        Node* nn = new Node(item);
        nn->next = start;
        start = nn;
        _size++;
    }

    void addLast(T* item) {
        Node* n = start;
        if (n == nullptr) {
            addFirst(item);
            return;
        }
        while (n->next != nullptr)
            n = n->next;
        n->next = new Node(item);
        _size++;
    }

    bool remove(function<bool(T*)> predicate) {
        if (_size == 0 && start != nullptr) {
            return false;
        }

        Node* n = start;
        if (predicate(start->item)) {
            start = n->next;
        } else {
            while (n != nullptr && !predicate(n->next->item))
                n = n->next;
            if (n == nullptr) {
                return false;
            }
            n->next = n->next->next;
        }
        _size--;
        return true;
    }

    void forEach(function<void(T*, int)> consumer) {
        Node* n = start;
        for (int i = 0; i < _size; ++i) {
            consumer(n->item, i);
            n = n->next;
        }
    }
};