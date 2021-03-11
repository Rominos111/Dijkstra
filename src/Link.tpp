// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include "Node.hpp"
#include "Link.hpp"

template <typename T>
Link<T>::Link(Node<T>& start, Node<T>& end, float weight):
    start(start),
    end(end),
    weight(weight)
{}

template <typename T>
Node<T>& Link<T>::getStart() {
    return start;
}

template <typename T>
Node<T>& Link<T>::getEnd() {
    return end;
}
