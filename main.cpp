// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <math.h>

#include "Node.hpp"
#include "Link.hpp"
#include "PriorityQueue.hpp"

template <typename T>
void largeur(Node<T>* origin) {
    std::unordered_set<Node<T>*> visited;
    std::queue<Node<T>*> toVisit;
    visited.insert(origin);
    toVisit.push(origin);

    while (!toVisit.empty()) {
        Node<T>* currentNode = toVisit.front();
        toVisit.pop();

        std::vector<Link<T>*> currentLinks = currentNode->getLinks();

        std::cout << *currentNode << std::endl;

        for (Link<T>* link : currentLinks) {
            auto* nextNode = (Node<T>*) link->getOther(currentNode);

            if (visited.find(nextNode) == visited.end()) {
                toVisit.push(nextNode);
                visited.insert(nextNode);
            }
        }
    }
}

template <typename T>
void profondeurIter(Node<T>* origin) {
    std::unordered_set<Node<T>*> visited;
    std::stack<Node<T>*> toVisit;
    visited.insert(origin);
    toVisit.push(origin);

    while (!toVisit.empty()) {
        Node<T>* currentNode = toVisit.top();
        toVisit.pop();

        std::vector<Link<T>*> currentLinks = currentNode->getLinks();

        std::cout << *currentNode << std::endl;

        for (Link<T>* link : currentLinks) {
            auto* nextNode = (Node<T>*) link->getOther(currentNode);

            if (visited.find(nextNode) == visited.end()) {
                toVisit.push(nextNode);
                visited.insert(nextNode);
            }
        }
    }
}

template <typename T>
void profondeurRec(Node<T>* origin, std::unordered_set<Node<T>*>* visited = nullptr) {
    std::unordered_set<Node<T>*> _visited;
    if (visited == nullptr) {
        visited = &_visited;
    }

    visited->insert(origin);

    std::vector<Link<T>*> currentLinks = origin->getLinks();

    std::cout << *origin << std::endl;

    for (Link<T>* link : currentLinks) {
        auto* nextNode = (Node<T>*) link->getOther(origin);
        if (visited->find(nextNode) == visited->end()) {
            visited->insert(nextNode);
            profondeurRec(nextNode, visited);
        }
    }
}

template <typename T>
void dijkstra(Node<T>* src, Node<T>* dst) {
    std::unordered_map<Node<T>*, float> distNodes;
    distNodes[src] = 0;

    std::unordered_set<Node<T>*> finished;
    finished.insert(src);

    std::unordered_set<Node<T>*> visited;
    std::queue<Node<T>*> toVisit;
    visited.insert(src);
    toVisit.push(src);

    while (!toVisit.empty()) {
        Node<T>* currentNode = toVisit.front();
        toVisit.pop();

        float distMin = std::numeric_limits<float>::infinity();
        Node<T>* distMinNode = nullptr;
        for (auto& pair : distNodes) {
            if (finished.find(pair.first) != finished.end() && distNodes[pair.first] <= distMin) {
                distMinNode = pair.first;
                distMin = pair.second;
            }
        }

        finished.insert(distMinNode);

        std::vector<Link<T>*> currentLinks = currentNode->getLinks();

        for (Link<T>* link : currentLinks) {
            auto* nextNode = (Node<T>*) link->getOther(currentNode);

            if (finished.find(nextNode) == finished.end()
            && !isinf(distNodes[nextNode])
            && (distNodes[distMinNode] + link->getWeight() < distMinNode[nextNode])) {
                // TODO: Calculate
            }
        }

        for (Link<T>* link : currentLinks) {
            auto* nextNode = (Node<T>*) link->getOther(currentNode);

            if (visited.find(nextNode) == visited.end()) {
                toVisit.push(nextNode);
                visited.insert(nextNode);
            }
        }
    }


    /*
    struct Element {
        float weight;
        bool visited;
        Node<T>* node;
    };

    std::vector<Element> nodes;
     */
}

int main() {
    Node<int> n2(2);
    Node<int> n3(3);
    n2.createLinkTo(&n3);

    Node<int> n1(1);
    n3.createLinkTo(&n1);

    Node<int> n4(4);
    n1.createLinkTo(&n4);

    Node<int> n7(7);
    n4.createLinkTo(&n7);
    n7.createLinkTo(&n1);

    Node<int> n5(5);
    n7.createLinkTo(&n5);

    Node<int> n6(6);
    n7.createLinkTo(&n6);

    Node<int> n8(8);
    n6.createLinkTo(&n8);

    std::cout << "Largeur:" << std::endl;
    largeur(&n1);
    std::cout << std::endl << "Profondeur iter:" << std::endl;
    profondeurIter(&n1);
    std::cout << std::endl << "Profondeur rec:" << std::endl;
    profondeurRec(&n1);
    std::cout << std::endl << "Dijkstra:" << std::endl;
    dijkstra(&n3, &n6);

    return 0;
}
