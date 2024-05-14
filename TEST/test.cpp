#include "..//gtest/gtest-all.cc"
#include "..//SKIPLIST/skiplist.h"
#include"..//PRIORETY/priorety.h"

// �������� ����� ��� ������ SkipList
TEST(SkipListTest, InsertAndSearch) {
    SkipList<int> list(3); // ������������ ������� 3

    // 1. ���� �� ������� � ����� ���������
    list.insert(10);
    list.insert(20);
    list.insert(15);
    list.insert(5);
    ASSERT_EQ(list.getSize(), 4);
    EXPECT_TRUE(list.search(15));
    EXPECT_FALSE(list.search(25));

    // 2. ���� �� ������� ������������� ���������
    list.insert(10);
    ASSERT_EQ(list.getSize(), 5);
    EXPECT_TRUE(list.search(10));

    // 3. ���� �� ����� � ������ ������
    SkipList<int> emptyList(3);
    EXPECT_FALSE(emptyList.search(10));
}

TEST(SkipListTest, DeleteAndSize) {
    SkipList<int> list(3);

    // 4. ���� �� �������� �������� �� ������� ������
    list.remove(10);
    ASSERT_EQ(list.getSize(), 0);

    // 5. ���� �� �������� ������������� ��������
    list.insert(10);
    list.insert(20);
    list.insert(15);
    list.remove(20);
    ASSERT_EQ(list.getSize(), 2);
    EXPECT_FALSE(list.search(20));

    // 6. ���� �� �������� ��������, ������� �� ��������� � ������
    list.remove(30);
    ASSERT_EQ(list.getSize(), 2);
}

TEST(PriorityQueueTest, EmptyQueue) {
    PriorityQueue<int> queue;
    EXPECT_TRUE(queue.empty());
}

TEST(PriorityQueueTest, PushPopTop) {
    PriorityQueue<int> queue;
    queue.push(10, 2);
    queue.push(20, 1);
    queue.push(30, 3);
    EXPECT_EQ(queue.top(), 30);
    queue.pop();
    EXPECT_EQ(queue.top(), 10);
    queue.pop();
    EXPECT_EQ(queue.top(), 20);
    queue.pop();
    EXPECT_TRUE(queue.empty());
}

TEST(PriorityQueueTest, PushPopTopStrings) {
    PriorityQueue<std::string> queue;
    queue.push("apple", 2);
    queue.push("banana", 1);
    queue.push("orange", 3);
    EXPECT_EQ(queue.top(), "orange");
    queue.pop();
    EXPECT_EQ(queue.top(), "apple");
    queue.pop();
    EXPECT_EQ(queue.top(), "banana");
    queue.pop();
    EXPECT_TRUE(queue.empty());
}
