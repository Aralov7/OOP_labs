// main.cpp

#include <iostream>
#include "include/CostomMemoryResource.h"
#include "include/DoublyLinkedList.h"
#include "include/ComplexType.h"

int main() {
    CustomMemoryResource my_resource;

    // Создаем полиморфный аллокатор с использованием нашего кастомного memory_resource
    std::pmr::polymorphic_allocator<std::byte> alloc(&my_resource);

    // DoublyLinkedList<int>
    DoublyLinkedList<int> int_list(alloc);

    int_list.push_back(1);
    int_list.push_back(2);
    int_list.push_back(3);

    std::cout << "Content of DoublyLinkedList<int> (straight bypass):\n";
    for (auto it = int_list.begin(); it != int_list.end(); ++it) {
        std::cout << *it << "\n";
    }

    std::cout << "Content of DoublyLinkedList<int> (reverse bypass):\n";
    for (auto it = int_list.rbegin(); it != int_list.rend(); --it) {
        std::cout << *it << "\n";
    }

    // DoublyLinkedList<ComplexType>
    DoublyLinkedList<ComplexType> struct_list(alloc);

    struct_list.push_back(ComplexType(1, 2.0, "hello"));
    struct_list.push_back(ComplexType(3, 4.0, "world"));

    std::cout << "\nContent of DoublyLinkedList<ComplexType> (straight bypass):\n";
    for (auto it = struct_list.begin(); it != struct_list.end(); ++it) {
        std::cout << "a: " << it->a << ", b: " << it->b << ", c: " << it->c << "\n";
    }

    std::cout << "Content of DoublyLinkedList<ComplexType> (reverse bypass):\n";
    for (auto it = struct_list.rbegin(); it != struct_list.rend(); --it) {
        std::cout << "a: " << it->a << ", b: " << it->b << ", c: " << it->c << "\n";
    }

    return 0;
}