// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include "Node.fwd.hpp"
#include "Link.fwd.hpp"

#ifndef GRAPHS_DIJKSTRA_LINK_HPP
#define GRAPHS_DIJKSTRA_LINK_HPP

/**
 * Link between two nodes
 * @tparam T Content type
 */
template <typename T>
class Link {
public:
    /**
     * Constructor
     * @param start Start node
     * @param end End node
     * @param weight Weight
     */
    Link(Node<T>& start, Node<T>& end, float weight = 1.);

    /**
     * Destructor
     */
    ~Link() = default;

    /**
     * @return Start node
     */
    Node<T>& getStart();

    /**
     * @return End node
     */
    Node<T>& getEnd();

private:
    /**
     * Start node
     */
    Node<T>& start;

    /**
     * End node
     */
    Node<T>& end;

    /**
     * Link weight
     */
    float weight = 1.;
};

#include "Link.tpp"

#endif //GRAPHS_DIJKSTRA_LINK_HPP
