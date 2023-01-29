#include "gtest/gtest.h"
#include "LinkedList.h"
#include <stdexcept>

LinkedList createLinkedList(const int size)
{
    LinkedList ll;
    for(int i = 0; i < size; ++i)
    {
        ll.insert(i);
    }
    EXPECT_EQ(size, ll.size());
    return ll;
}

TEST(LinkedList, defaultCtor)
{
    LinkedList ll;
    EXPECT_EQ(0, ll.size());
}

TEST(LinkedList, ctor)
{
    LinkedList ll{5};

    EXPECT_EQ(1, ll.size());
    EXPECT_EQ(5, ll.get(0));
}

TEST(LinkedList, oneNodeSize)
{
    LinkedList ll = createLinkedList(1);
    EXPECT_EQ(1, ll.size());
}

TEST(LinkedList, oneNodeGet)
{
    LinkedList ll;
    ll.insert(2);
    EXPECT_EQ(2, ll.get(0));
}

TEST(LinkedList, oneNodeGetException)
{
    LinkedList ll = createLinkedList(1);
    EXPECT_THROW(ll.get(ll.size()+1), std::out_of_range);
}

TEST(LinkedList, threeNodesSize)
{
    LinkedList ll = createLinkedList(3);
    EXPECT_EQ(3, ll.size());
}

TEST(LinkedList, threeNodesGetSecond)
{
    LinkedList ll = createLinkedList(3);
    int index = 1;
    EXPECT_EQ(index, ll.get(index));
}

TEST(LinkedList, threeNodesRemoveMiddle)
{
    LinkedList ll = createLinkedList(3);

    ll.remove(1);

    EXPECT_EQ(2, ll.get(1));
}

TEST(LinkedList, reverseListFourNodes)
{
    LinkedList ll = createLinkedList(4);

    ll.reverse();

    EXPECT_EQ(3, ll.get(0));
}

TEST(LinkedList, oneNodeRemoveException)
{
    LinkedList ll;
    ll.insert(2);
    EXPECT_THROW(ll.get(ll.size()+1), std::out_of_range);
}

TEST(LinkedList, clear)
{
    LinkedList ll = createLinkedList(10);

    ll.clear();

    EXPECT_EQ(0, ll.size());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}