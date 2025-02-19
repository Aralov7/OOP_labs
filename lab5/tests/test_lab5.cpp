// test_lab5.cpp

#include <gtest/gtest.h>
#include "../include/CostomMemoryResource.h"
#include "../include/DoublyLinkedList.h"
#include "../include/ComplexType.h"

// Тестирование работы DoublyLinkedList с int
TEST(DoublyLinkedListTest, IntPushBack) {
    CustomMemoryResource my_resource;
    std::pmr::polymorphic_allocator<std::byte> alloc(&my_resource);
    DoublyLinkedList<int> int_list(alloc);

    int_list.push_back(10);
    int_list.push_back(20);
    int_list.push_back(30);

    DoublyLinkedList<int>::Iterator it = int_list.begin();
    ASSERT_EQ(*it, 10);
    ++it;
    ASSERT_EQ(*it, 20);
    ++it;
    ASSERT_EQ(*it, 30);
    ++it;
    ASSERT_EQ(it, int_list.end());
}

TEST(DoublyLinkedListTest, IntPushFront) {
    CustomMemoryResource my_resource;
    std::pmr::polymorphic_allocator<std::byte> alloc(&my_resource);
    DoublyLinkedList<int> int_list(alloc);

    int_list.push_front(10);
    int_list.push_front(20);
    int_list.push_front(30);

    DoublyLinkedList<int>::Iterator it = int_list.begin();
    ASSERT_EQ(*it, 30);
    ++it;
    ASSERT_EQ(*it, 20);
    ++it;
    ASSERT_EQ(*it, 10);
    ++it;
    ASSERT_EQ(it, int_list.end());
}

// Тестирование работы DoublyLinkedList с ComplexType
TEST(DoublyLinkedListTest, ComplexTypeTest) {
    CustomMemoryResource my_resource;
    std::pmr::polymorphic_allocator<std::byte> alloc(&my_resource);
    DoublyLinkedList<ComplexType> struct_list(alloc);

    struct_list.push_back(ComplexType(1, 1.1, "first"));
    struct_list.push_back(ComplexType(2, 2.2, "second"));
    struct_list.push_back(ComplexType(3, 3.3, "third"));

    DoublyLinkedList<ComplexType>::Iterator it = struct_list.begin();

    ASSERT_EQ(it->a, 1);
    ASSERT_DOUBLE_EQ(it->b, 1.1);
    ASSERT_EQ(it->c, "first");
    ++it;

    ASSERT_EQ(it->a, 2);
    ASSERT_DOUBLE_EQ(it->b, 2.2);
    ASSERT_EQ(it->c, "second");
    ++it;

    ASSERT_EQ(it->a, 3);
    ASSERT_DOUBLE_EQ(it->b, 3.3);
    ASSERT_EQ(it->c, "third");
    ++it;

    ASSERT_EQ(it, struct_list.end());
}

// Тестирование двунаправленного итератора
TEST(DoublyLinkedListTest, BidirectionalIterator) {
    CustomMemoryResource my_resource;
    std::pmr::polymorphic_allocator<std::byte> alloc(&my_resource);
    DoublyLinkedList<int> int_list(alloc);

    int_list.push_back(1);
    int_list.push_back(2);
    int_list.push_back(3);

    // Обратный обход
    DoublyLinkedList<int>::Iterator it = int_list.rbegin();
    ASSERT_EQ(*it, 3);
    --it;
    ASSERT_EQ(*it, 2);
    --it;
    ASSERT_EQ(*it, 1);
    --it;
    ASSERT_EQ(it, int_list.rend());
}

// Тестирование работы с пустым списком
TEST(DoublyLinkedListTest, EmptyList) {
    CustomMemoryResource my_resource;
    std::pmr::polymorphic_allocator<std::byte> alloc(&my_resource);
    DoublyLinkedList<int> int_list(alloc);

    ASSERT_EQ(int_list.begin(), int_list.end());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}