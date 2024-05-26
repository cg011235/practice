#include "bst.hh"

#include <gtest/gtest.h>

TEST(BST, ConstructWithArray) {
  int arr[0];
  EXPECT_THROW(BST(arr, 0), std::invalid_argument);

  int nums[3] = {12, 3, 15};
  BST bst(nums, 3);
  node *t;
  EXPECT_TRUE(bst.Search(12, t));
  EXPECT_TRUE(bst.Search(3, t));
  EXPECT_TRUE(bst.Search(15, t));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}