#include <iostream>

#include "Node.hpp"

int main() {
    Node<int> n(5);

    std::cout << n.getContent() << std::endl;
    return 0;
}
