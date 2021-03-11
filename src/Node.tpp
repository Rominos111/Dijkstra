// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include "Node.hpp"
#include "Link.hpp"

template <typename T>
Node<T>::Node() = default;

template <typename T>
Node<T>::Node(T elt) {
    content = elt;
}

template <typename T>
Node<T>::~Node() {
    for (Link<T>* link : links)
        if (&(link->getStart()) == this)
            delete link;
}

template <typename T>
T Node<T>::getContent() {
    return content;
}

template <typename T>
void Node<T>::setContent(T elt) {
    content = elt;
}

template <typename T>
Link<T> Node<T>::createLinkTo(Node& other, float weight) {
    auto* link = new Link<T>(*this, other, weight);
    this->links.push_back(link);
    other.links.push_back(link);
}
