#include "gtest/gtest.h"
#include "BinaryTree.hpp"

TEST(BinaryTreeTest, ContainsElementAfterInsert)
{
    BinaryTree<int> intTree;
    ASSERT_FALSE(intTree.contains(1));
    intTree.insert(7);
    intTree.insert(1);
    intTree.insert(2);
    ASSERT_TRUE(intTree.contains(1));
}

TEST(BinaryTreeTest, NonDefaultConstructorInsertsRoot)
{
    BinaryTree<int> intTree(6);
    ASSERT_TRUE(intTree.contains(6));
}

TEST(BinaryTreeTest, DefaultConstructorDoesntContainAnyElements)
{
    BinaryTree<int> empty;
    ASSERT_EQ(empty.size(), 0);
}

TEST(BinaryTreeTest, InsertTheSameElementWorks)
{
    BinaryTree<int> intTree(3);
    intTree.insert(3);
    ASSERT_EQ(intTree.size(), 2);
}

TEST(BinaryTreeTest, NonEmptyTreeSizeWorks)
{
    BinaryTree<int> intTree(5);
    intTree.insert(7);
    intTree.insert(1);
    intTree.insert(2);
    ASSERT_EQ(intTree.size(), 4);
}

TEST(BinaryTreeTest, MaxDepthWorks)
{
    BinaryTree<int> intTree(5);
    intTree.insert(7);
    intTree.insert(1);
    intTree.insert(2);
    ASSERT_EQ(intTree.maxDepth(), 3);
}

TEST(BinaryTreeTest, minValWorks)
{
    BinaryTree<int> intTree(5);
    intTree.insert(7);
    intTree.insert(1);
    intTree.insert(2);
    ASSERT_EQ(intTree.minVal(), 1);
}

TEST(BinaryTreeTest, minValInEmptyTree)
{
    BinaryTree<int> empty;
    ASSERT_THROW(empty.minVal(), std::invalid_argument);
}

TEST(BinaryTreeTest, maxValWorks)
{
    BinaryTree<int> intTree(5);
    intTree.insert(7);
    intTree.insert(1);
    intTree.insert(2);
    ASSERT_EQ(intTree.maxVal(), 7);
}

TEST(BinaryTreeTest, isEqualWorks)
{
    BinaryTree<int> intTree1(5);
    intTree1.insert(7);
    intTree1.insert(1);
    intTree1.insert(2);
    BinaryTree<int> intTree2(5);
    intTree2.insert(7);
    intTree2.insert(1);
    intTree2.insert(2);
    ASSERT_TRUE(intTree1.isEqual(intTree2));
}

TEST(BinaryTreeTest, isNotEqualWorks)
{
    BinaryTree<int> intTree1(5);
    intTree1.insert(7);
    intTree1.insert(1);
    intTree1.insert(2);
    BinaryTree<int> intTree2(5);
    intTree2.insert(7);
    intTree2.insert(1);
    intTree2.insert(3);
    ASSERT_FALSE(intTree1.isEqual(intTree2));
}

TEST(BinaryTreeTest, isEqualEmptyTrees)
{
    BinaryTree<int> empty1;
    BinaryTree<int> empty2;
    ASSERT_TRUE(empty1.isEqual(empty2));
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}