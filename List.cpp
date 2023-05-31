//
// Created by Esawy on 5/31/2023.
//

#include "List.h"


template<class T>
bool List<T>::out_of_range(int index) {
    if (index < 0 || index > count) {
        std::cout << "Index out of bounds.\n";
        return true;
    }
    return false;
}

template<class T>
void List<T>::init() {
    dummyNode = new Node;
    head = new Node;
    tail = new Node;
    count = 0;
}

template<typename T>
List<T>::List() {
    init();
}

template<class T>
List<T>::List(T value, int initial_size) {
    init();
    for (int i = 0; i < initial_size; i++)
        push_back(value);
}

template<class T>
List<T>::List(const List &other) {
    init();
    for (auto &value: other)
        push_back(value);
}

template<class T>
List<T> &List<T>::operator=(const List &other) {
    List copy = other;
    std::swap(*this, copy);
    return *this;
}

template<class T>
List<T>::List(List &&other) : count{other.count}, head{other.head}, tail{other.tail} {
    other.count = 0;
    other.head = other.tail = nullptr;
}

template<class T>
List<T> &List<T>::operator=(List &&other) {
    std::swap(count, other.count);
    std::swap(head, other.head);
    std::swap(tail, other.tail);

    return *this;
}

template<class T>
int List<T>::size() const {
    return count;
}

template<class T>
void List<T>::push_front(T value) {
    Node *newNode = new Node(value);
    if (count == 0) {
        head = tail = newNode;
        tail->next = dummyNode;
        dummyNode->prev = tail;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    ++count;
}

template<class T>
void List<T>::push_back(T value) {
    Node *newNode = new Node(value);
    if (count == 0) {
        head = tail = newNode;
        tail->next = dummyNode;
        dummyNode->prev = tail;
    } else {
        newNode->next = dummyNode;
        dummyNode->prev = newNode;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++count;
}

template<class T>
void List<T>::pop_back() {
    if (isEmpty()) {
        std::cout << "List is empty.\n";
        return;
    }
    Node *d = tail;
//        tail->prev->next = tail->next;
    tail = tail->prev;
    delete d;
    --count;
}

template<class T>
void List<T>::pop_front() {
    if (isEmpty()) {
        std::cout << "List is empty.\n";
        return;
    }
    Node *d = head;
    head = head->next;
    delete d;
    --count;
}

template<class T>
void List<T>::insert(T value, List::iterator postion) {
    if (postion != end() && postion.current == nullptr)
        throw exit;
    if (postion.current == head)push_front(value);
    else if (postion.current == dummyNode)push_back(value);
    else {
        Node *newNode = new Node(value);
        Node *ptr = postion.current;
        ptr->prev->next = newNode;
        newNode->next = ptr;
        newNode->prev = ptr->prev;
        ptr->prev = newNode;
        ++count;
    }
}

template<class T>
void List<T>::Indexinsert(int index, T value) {

    if (out_of_range(index))
        throw exit;

    Node *newNode = new Node(value);
    if (index == 0)
        push_front(value);

    else if (index == count - 1)
        push_back(value);

    else {
        Node *ptr = head;

        for (int i = 0; i < index - 1; ++i)
            ptr = ptr->next;

        ptr->next->prev = newNode;
        newNode->next = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
        ++count;
    }
}

template<class T>
void List<T>::erase(List::iterator position) {
    if (isEmpty()) {
        std::cout << "List if empty.\n";
        return;
    }
    if (position != end() && position.current == nullptr) {
        throw exit;
    }

    if (position == head)
        pop_front();
    else if (position == tail)
        pop_back();
    else {
        Node *ptr = position.current;
        iterator retVal = ptr->next;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
        --count;
    }
}

template<class T>
typename List<T>::iterator List<T>::begin() const {
    return head;
}

template<class T>
typename List<T>::iterator List<T>::end() const {
    return tail->next;
}

template<class T>
bool List<T>::find(T value) {
    Node *ptr = head;
    while (ptr != tail) {
        if (ptr->data == value)
            return true;
        ptr = ptr->next;
    }
    return (tail->data == value);
}

template<class T>
bool List<T>::isEmpty() const {
    return (count == 0);
}

template<class T>
void List<T>::clear() {
    if (isEmpty()) {
        return;
    }
    while (!isEmpty())
        pop_back();
}

template<class T>
List<T>::~List() {
    clear();
    delete head;
    delete tail;
    delete dummyNode;
}
