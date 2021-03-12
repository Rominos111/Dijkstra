// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "Node.hpp"
#include "Link.hpp"

template <typename T>
void largeur(Node<T>* origin) {
    int i = 0;

    std::unordered_set<Node<T>*> visited;
    std::queue<Node<T>*> toVisit;
    toVisit.push(origin);
    visited.insert(origin);

    while (!toVisit.empty()) {
        Node<T>* currentNode = toVisit.front();
        toVisit.pop();

        std::vector<Link<T>*> currentLinks = currentNode->getLinks();

        std::cout << *currentNode << std::endl;

        for (Link<T>* link : currentLinks) {
            auto* nextNode = (Node<T>*) link->getOther(currentNode);

            // FIXME: Complexity
            if (visited.find(nextNode) == visited.end()) {
                toVisit.push(nextNode);
                visited.insert(nextNode);
            }
        }

        if (i == 100) {
            std::cout << "erreur !";
            break;
        }
        i++;
    }
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

    largeur(&n1);

    // std::cout << n1.getContent() << std::endl;
    return 0;
}
