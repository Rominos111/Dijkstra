// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 11/03/2021.

#include <iostream>

#include "Node.hpp"
#include "Link.hpp"

int main() {
    Node<int> n1(5);
    Node<int> n2(7);
    n1.createLinkTo(n2);

    std::cout << n1.getContent() << std::endl;
    return 0;
}
