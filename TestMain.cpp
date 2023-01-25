#include "gtest/gtest.h"
#include "LinkedList.h"

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

TEST(LinkedList, twoNodesSize)
{
    LinkedList ll;
    ll.insert(2);
    ll.insert(3);
    EXPECT_EQ(2, ll.size());
}

TEST(LinkedList, twoNodesGetSecond)
{
    LinkedList ll;
    ll.insert(2);
    ll.insert(3);
    EXPECT_EQ(3, ll.get(1));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}