// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 12/03/2021.

#include <limits>

#include "PriorityQueue.hpp"

template <typename T>
PriorityQueueItem<T>::PriorityQueueItem(T item) :
    dist(std::numeric_limits<float>::infinity()),
    content(item),
    next(nullptr)
{}

template <typename T>
void PriorityQueueItem<T>::setNext(PriorityQueueItem<T>* nextItem) {
    next = nextItem;
}

template<typename T>
T PriorityQueueItem<T>::getContent() const {
    return content;
}

template<typename T>
PriorityQueueItem<T>* PriorityQueueItem<T>::getNext() const {
    return next;
}

template <typename T>
PriorityQueue<T>::PriorityQueue() :
    size(0),
    first(nullptr),
    last(nullptr)
{}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
PriorityQueue<T>* PriorityQueue<T>::enqueue(T item) {
    auto* queueItem = new PriorityQueueItem<T>(item);

    if (isEmpty()) {
        first = queueItem;
    }
    else {
        last->setNext(queueItem);
    }

    last = queueItem;
    ++size;
    return this;
}

template <typename T>
PriorityQueue<T>* PriorityQueue<T>::enqueue(T item, float dist) {
    auto* queueItem = new PriorityQueueItem<T>(item);

    if (isEmpty()) {
        first = queueItem;
    }
    else {
        PriorityQueueItem<T>* tmp = first;

        while (tmp != nullptr && tmp->getNext()) {
            last->setNext(queueItem);
        }

    }

    last = queueItem;
    ++size;
    return this;
}

template<typename T>
T PriorityQueue<T>::dequeue() {
    T item;

    if (isEmpty()) {
        std::cerr << "Empty queue" << std::endl;
        throw std::exception();
    }
    else {
        item = first->getContent();
        auto* oldFirst = first;
        first = first->getNext();
        delete oldFirst;

        if (first == nullptr) {
            last = nullptr;
        }
    }

    --size;
    return item;
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
size_t PriorityQueue<T>::getSize() const {
    return size;
}
