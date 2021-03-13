// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include <memory>

#include "Node.hpp"
#include "Link.hpp"

template <typename T>
Link<T>::Link(Node<T>* start, Node<T>* end, float weight):
    start(start),
    end(end),
    weight(weight)
{}

template <typename T>
Node<T>* Link<T>::getStart() const {
    return start;
}

template <typename T>
Node<T>* Link<T>::getEnd() const {
    return end;
}

template <typename T>
Node<T>* Link<T>::getOther(Node<T>* node) const {
    if (node == start) {
        return end;
    }
    else if (node == end) {
        return start;
    }
    else {
         std::cerr << "No such node" << std::endl;
        throw std::exception();
    }
}

template <typename T>
float Link<T>::getWeight() const {
    return weight;
}

template <typename T>
std::ostream& operator <<(std::ostream& os, const Link<T>& link) {
    os << "(" << link.start << "-" << link.end << ")";
    return os;
}
