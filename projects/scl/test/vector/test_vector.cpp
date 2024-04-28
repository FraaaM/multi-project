#include <gtest/gtest.h>

#include "vector.hpp"

TEST(VectorTest, Insert) {
    MCherevko::Vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.insert(1, 2);
    EXPECT_EQ(v.size(), 3);
    EXPECT_TRUE(v.has_item(2));
    EXPECT_TRUE(v.has_item(3));
}

TEST(VectorTest, RemoveFirst) {
    MCherevko::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.remove_first(1);
    EXPECT_EQ(v.size(), 2);
    EXPECT_TRUE(v.has_item(1));
}

TEST(VectorTest, DefaultConstructor) {
    MCherevko::Vector<int> v;
    EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, PushBack) {
    MCherevko::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
}

TEST(VectorTest, HasItem) {
    MCherevko::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    EXPECT_TRUE(v.has_item(2));
    EXPECT_FALSE(v.has_item(4));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
