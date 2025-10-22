template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), last(nullptr) {
    // TODO
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw string("back: error, queue is empty, cannot access the back");
    } else {
        return last->value;
    }
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    Node* curr = head;
    Node* temp = nullptr;
    while (curr != nullptr) {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    if (copyObj.isEmpty()) {
        return;
    }

    head = nullptr;
    last = nullptr;
    this->length = 0; 
    
    head = new Node(copyObj.head->value);
    this->length++;
    
    Node* curr = head;
    Node* copy = copyObj.head->next;

    while (copy != nullptr) {
        curr->next = new Node(copy->value);
        copy = copy->next;
        curr = curr->next;
        this->length++;
    }
    last = curr;

}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw string("dequeue: error, queue is empty");
    }
    
    Node* curr = head->next;
    Node* temp = head;
    delete temp;
    head = curr;
    this->length--;

    if (head == nullptr) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* new_node = new Node(elem);
    if (isEmpty()) {
        head = new_node;
        last = new_node;
    } else {
        last->next = new_node;
        last = new_node;
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw string("front: error, queue is empty, cannot access the front");
    } else {
        return head->value;
    }
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
