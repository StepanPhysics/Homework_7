#include "list.hpp"
#include "vector.hpp"
#include <iostream>

int main(int, char**) {
    std::cout << "Hello from otus list demo project!" << std::endl;

    const size_t count = 10;

    otus::List<size_t> list;
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
        list.push_front(i);
    }

    for (size_t i = 0; i < count * 2; ++i) {
        std::cout << list.front() << ' ';
        list.pop_front();
    }
    std::cout << std::endl;

    otus::Vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);

    std::cout << "Vector size: " << myVector.size() << std::endl;
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}