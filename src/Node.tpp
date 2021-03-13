// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include "Node.hpp"
#include "Link.hpp"

template <typename T>
Node<T>::Node() = default;

template <typename T>
Node<T>::Node(T item) :
    content(item)
{}

template <typename T>
Node<T>::~Node() {
    for (Link<T>* link : links) {
        // FIXME: Some links are obviously already deleted
        if (link->getStart() == this)
            delete link;
    }
}

template <typename T>
T& Node<T>::getContent() const {
    return content;
}

template <typename T>
void Node<T>::setContent(T item) {
    content = item;
}

template <typename T>
Link<T>& Node<T>::createLinkTo(Node<T>* other, float weight) {
    auto* link = new Link<T>(this, other, weight);
    this->links.push_back(link);
    other->links.push_back(link);
    return *link;
}

template <typename T>
const std::vector<Link<T>*>& Node<T>::getLinks() const {
    return links;
}

template <typename U>
std::ostream& operator <<(std::ostream& os, const Node<U>& node) {
    os << "[" << node.content << "]";
    return os;
}
