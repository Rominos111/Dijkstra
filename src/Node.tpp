// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include "Node.hpp"

template<typename T>
Node<T>::Node() = default;

template<typename T>
Node<T>::Node(T elt) {
    content = elt;
}

template<typename T>
T Node<T>::getContent() {
    return content;
}

template<typename T>
void Node<T>::setContent(T elt) {
    content = elt;
}
