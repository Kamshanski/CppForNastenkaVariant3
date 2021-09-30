
template<typename T>
struct DoublyLinkedList {
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

    Node* getNode(int i) {
        Node* node = start;
        for (int j = 0; j < i; ++j) {
            node = node->next;
        }
        return node;
    }

    void addInEmpty(T* item) {
        start = new Node(item);
        end = start;
        _size++;
    }

public:
    int size() {return _size;}

    T* get(int i) {
        if (i < 0 || i >= _size) {
            return nullptr;
            //throw out_of_range("Index out of bounds. Size: " + to_string(_size) + ". Index: " + to_string(i));
        }

        Node* node = getNode(i);
        return node->item;
    }

    void addLast(T* item) {
        if (_size == 0) {
            addInEmpty(item);
        } else {
            Node* nn = new Node(item);
            nn->prev = end;
            end->next = nn;
            end = nn;
            _size++;
        }
    }

    bool remove(function<bool(T*)> predicate) {
        Node* node = start;
        for (int i = 0; i < _size; ++i) {
            if (predicate(node->item)) {
                if (node == start) {
                    start = start->next;
                    if (start != nullptr) {
                        start->prev = nullptr;
                    } else {
                        end = nullptr;
                    }
                } else {
                    node->prev->next = node->next;
                    if (node->next != nullptr) {
                        node->next->prev = node->prev;
                    } else {
                        end = nullptr;
                    }
                }
                delete node;
                _size--;
                return true;
            }
            node = node->next;
        }
        return false;
    }

    void forEach(function<void(T*, int)> consumer) {
        Node* n = start;
        for (int i = 0; i < _size; ++i) {
            consumer(n->item, i);
            n = n->next;
        }
    }
};
