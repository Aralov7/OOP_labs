// DoublyLinkedList.h

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <memory_resource>
#include <memory>
#include "../include/ComplexType.h"

template <typename T>
class DoublyLinkedList {
public:
    using allocator_type = std::pmr::polymorphic_allocator<T>;

    DoublyLinkedList(const allocator_type& alloc = {});
    ~DoublyLinkedList();

    void push_back(const T& value);
    void push_front(const T& value);

    struct Node {
        T value;
        Node* next;
        Node* prev;

        Node(const T& val, Node* n = nullptr, Node* p = nullptr);
    };

    class Iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator();
        explicit Iterator(Node* node);

        reference operator*() const;
        pointer operator->() const;

        Iterator& operator++();   
        Iterator operator++(int); 

        Iterator& operator--();   
        Iterator operator--(int); 

        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

    private:
        Node* node_;
    };

    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();

private:
    Node* head_;
    Node* tail_;
    allocator_type alloc_;
    using NodeAllocator = typename std::allocator_traits<allocator_type>::template rebind_alloc<Node>;
    NodeAllocator node_alloc_;
};

extern template class DoublyLinkedList<int>;
extern template class DoublyLinkedList<ComplexType>;

#endif // DOUBLY_LINKED_LIST_H