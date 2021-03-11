// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#ifndef GRAPHS_DIJKSTRA_NODE_HPP
#define GRAPHS_DIJKSTRA_NODE_HPP

/**
 * Node
 * @tparam T Content type
 */
template<typename T>
class Node {
public:
    /**
     * Default constructor
     */
    Node();

    /**
     * Constructor
     * @param elt Content
     */
    explicit Node(T elt);

    /**
     * @return Content
     */
    [[nodiscard]] T getContent();

    /**
     * @param elt New content
     */
    void setContent(T elt);

private:
    T content;
};

#include "Node.tpp"

#endif //GRAPHS_DIJKSTRA_NODE_HPP
