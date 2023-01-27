#include "gtest/gtest.h"
#include "LinkedList.h"
#include <stdexcept>

TEST(LinkedList, test)
{
    EXPECT_TRUE(true);
}

TEST(LinkedList, ctor)
{
    LinkedList ll;
    EXPECT_EQ(0, ll.size());
}

TEST(LinkedList, oneNodeSize)
{
    LinkedList ll;
    ll.insert(1);
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
    LinkedList ll;
    ll.insert(2);
    EXPECT_THROW(ll.get(ll.size()+1), std::out_of_range);
}

TEST(LinkedList, threeNodesSize)
{
    LinkedList ll;
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    EXPECT_EQ(3, ll.size());
}

TEST(LinkedList, threeNodesGetSecond)
{
    LinkedList ll;
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    EXPECT_EQ(3, ll.get(1));
}

TEST(LinkedList, threeNodesRemoveMiddle)
{
    LinkedList ll;
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);

    ll.remove(1);
    EXPECT_EQ(4, ll.get(1));
}

TEST(LinkedList, oneNodeRemoveException)
{
    LinkedList ll;
    ll.insert(2);
    EXPECT_THROW(ll.get(ll.size()+1), std::out_of_range);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}