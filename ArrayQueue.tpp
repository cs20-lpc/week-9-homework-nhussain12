template <typename T>
ArrayQueue<T>::ArrayQueue(int i) : buffer(new T[i]), maxSize(i) {
    // TODO
    frontIndex = 0;
    backIndex = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw string("back: error, queue is empty, cannot access the back");
    } else {
        return buffer[backIndex];
    }
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    this->length = 0;
    frontIndex = 0;
    backIndex = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];

    for (int i = 0; i < copyObj.length; i++) {
        buffer[i] = copyObj.buffer[(copyObj.frontIndex + i) % copyObj.maxSize];
    }

    frontIndex = 0;
    backIndex = this->length-1;
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw string("dequeue: error, queue is empty");
    }

    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;

    if (this->length == 0) {
        frontIndex = 0;
        backIndex = 0;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {
        throw string("enqueue: error, stack is full, avoiding overflow");
    }

    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;

    if (this->length == 1) {
        frontIndex = backIndex;
    }
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw string("front: error, stack is empty, cannot access the top");
    }

    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
