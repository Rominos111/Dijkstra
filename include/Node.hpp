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
    [[nodiscard]] T& getContent() const;

    /**
     * @param elt New content
     */
    void setContent(const T& elt);

    /**
     * Create a link from this to other
     * @param other Other node
     * @return Link
     */
    Link<T>& createLinkTo(Node<T>* other, float weight = 1.);

    /**
     * @return Links
     */
    const std::vector<Link<T>*>& getLinks() const;

    /**
     * Override the << operator
     * @tparam U Any type
     * @param os Output stream
     * @param node Node
     * @return Output stream
     */
    template <typename U>
    friend std::ostream& operator <<(std::ostream& os, const Node<U>& node);

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
