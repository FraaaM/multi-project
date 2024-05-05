
#include <gtest/gtest.h>
#include "vector.hpp"

TEST(VectorTest, DefaultConstructor) {
    MCherevko::Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, PushBack) {
    MCherevko::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(), 3);
}

TEST(VectorTest, HasItem) {
    MCherevko::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_TRUE(vec.has_item(2));
    EXPECT_FALSE(vec.has_item(4));
}

TEST(VectorTest, Insert) {
    MCherevko::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.insert(1, 2);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_TRUE(vec.has_item(2));
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

TEST(VectorTest, RemoveAll) {
    MCherevko::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.remove_all(2);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_FALSE(vec.has_item(2));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*TEST(VectorTest, RemoveFirst) {
    MCherevko::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.remove_first(2);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_FALSE(vec.has_item(2));
}*/