// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 12/03/2021.

#ifndef GRAPHS_DIJKSTRA_PRIORITYQUEUE_HPP
#define GRAPHS_DIJKSTRA_PRIORITYQUEUE_HPP

namespace {
    template <typename T>
    class PriorityQueueItem {
    public:
        explicit PriorityQueueItem(T item);

        void setNext(PriorityQueueItem<T>* nextItem);

        PriorityQueueItem<T>* getNext() const;

        T getContent() const;

    private:
        float dist;
        T content;
        PriorityQueueItem<T>* next;
    };
}

template <typename T>
class PriorityQueue {
public:
    PriorityQueue();

    ~PriorityQueue();

    PriorityQueue<T>* enqueue(T item);

    PriorityQueue<T>* enqueue(T item, float dist);

    T dequeue();

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] size_t getSize() const;

private:
    size_t size;
    PriorityQueueItem<T>* first;
    PriorityQueueItem<T>* last;
};

#include "PriorityQueue.tpp"

#endif //GRAPHS_DIJKSTRA_PRIORITYQUEUE_HPP
