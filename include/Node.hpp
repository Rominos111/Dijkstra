// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include <vector>

#include "Node.fwd.hpp"
#include "Link.fwd.hpp"

#ifndef GRAPHS_DIJKSTRA_NODE_HPP
#define GRAPHS_DIJKSTRA_NODE_HPP

/**
 * Node
 * @tparam T Content type
 */
template <typename T>
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
     * Destructor
     */
    ~Node();

    /**
     * @return Content
     */
    [[nodiscard]] T getContent();

    /**
     * @param elt New content
     */
    void setContent(T elt);

    /**
     * Create a link from this to other
     * @param other Other node
     * @return Link
     */
    Link<T> createLinkTo(Node& other, float weight = 1.);

private:
    /**
     * All connected links
     */
    std::vector<Link<T>*> links;

    /**
     * Content
     */
    T content;
};

#include "Node.tpp"

#endif //GRAPHS_DIJKSTRA_NODE_HPP
