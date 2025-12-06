#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tree_node.hpp"

TEST_CASE( "TreeNodes will return their given value" ) {
    int x = 12;
    TreeNode<int> node(&x);
    REQUIRE( *(node.value) == x);
}

TEST_CASE( "When TreeNodes don't have children, left and right are nullptr" ) {
    int x = 12;
    TreeNode<int> node_1(&x);
    REQUIRE( node_1.left == nullptr);
    REQUIRE( node_1.right == nullptr);
}

TEST_CASE( "TreeNodes can have a left child" ) {
    int x = 12;
    int y = 20;
    TreeNode<int> node_1(&x);
    TreeNode<int> node_2(&y);

    node_1.left = &node_2;
    REQUIRE( *(node_1.left->value) == y);
    REQUIRE( node_1.right == nullptr);
}

TEST_CASE( "TreeNodes can have a right child" ) {
    int x = 12;
    int y = 20;
    TreeNode<int> node_1(&x);
    TreeNode<int> node_2(&y);

    node_1.right = &node_2;

    REQUIRE( node_1.left == nullptr);
    REQUIRE( *(node_1.right->value) == y);
}

TEST_CASE( "TreeNodes can have a left and right child" ) {
    int x = 12;
    int y = 20;
    int z = 3;
    TreeNode<int> node_1(&x);
    TreeNode<int> node_2(&y);
    TreeNode<int> node_3(&z);

    node_1.left = &node_2;
    node_1.right = &node_3;

    REQUIRE( *(node_1.left->value) == y);
    REQUIRE( *(node_1.right->value) == z);
}