//
// Created by Esawy on 5/31/2023.
//

#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

#include <iostream>

template<class T>
class List {

private:
    struct Node {
        T data;
        Node *next;
        Node *prev;

        Node() {
            data = 0;
            next = prev = nullptr;
        }

        explicit Node(T value) : data(value) {
            next = prev = nullptr;
        }
    };

    Node *head;
    Node *tail;
    Node *dummyNode;
    int count;

    bool out_of_range(int index);

    void init();

public:
    class iterator {
    public:
        iterator() : current{nullptr} {}

        const T &operator*() const {
            return retrieve();
        }

        iterator &operator++() {
            if (current == nullptr)
                throw "Out of range";
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            if (current == nullptr)
                throw "Out of range";
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator &operator--() {
            if (current == nullptr)
                throw "Out of range";

            current = current->prev;
            return *this;
        }

        iterator operator--(int) {
            if (current == nullptr)
                throw "Out of range";
            iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const iterator &other) const {
            return current == other.current;
        }

        bool operator!=(const iterator &other) const {
            return !(*this == other);
        }

    private:
        Node *current;

        iterator(Node *node) : current{node} {}

        T &retrieve() const {
            return current->data;
        }

        friend class List<T>;
    };

    List();

    List(T value, int initial_size);

    List(const List &other);

    List &operator=(const List &other);


    List(List &&other);

    List &operator=(List &&other);

    int size() const;

    void push_front(T value);

    void push_back(T value);

    void pop_back();

    void pop_front();


    void insert(T value, iterator postion);

    void Indexinsert(int index, T value);


    void erase(iterator position);

    iterator begin() const;

    iterator end() const;

    bool find(T value);

    bool isEmpty() const;

    void clear();

    ~List();
};



#endif //LINKEDLIST_LIST_H
