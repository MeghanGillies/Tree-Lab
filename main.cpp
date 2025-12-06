#include <iostream>

#include "src/squirrel.h"
#include "src/tree_node.hpp"

// Pre-Order Traversal = Node -> Left -> Right
void pre_order_traversal(const TreeNode<Squirrel>* node) {
    // Base Case returns nothing if the node is null
    if (node == nullptr) {
        return;
    }

    // Prints name of the squirrel stored in the current node
    std::cout << node->value->get_name() << " ";

    // Performs traversal on left child
    pre_order_traversal(node->left);

    // Performs traversal on right child
    pre_order_traversal(node->right);
}

// Post-Order Traversal = Left -> Right -> Node
void post_order_traversal(const TreeNode<Squirrel>* node) {
    // Base Case returns nothing if the node is null
    if (node == nullptr) {
        return;
    }

    // Performs traversal on left child
    post_order_traversal(node->left);

    // Performs traversal on right child
    post_order_traversal(node->right);

    // Prints name of the squirrel stored in the current node
    std::cout << node->value->get_name() << " ";
}

// In-Order Traversal = Left -> Node -> Right
void in_order_traversal(const TreeNode<Squirrel>* node) {
    // Base Case returns nothing if the node is null
    if (node == nullptr) {
        return;
    }

    // Performs traversal on left child
    in_order_traversal(node->left);

    // Prints name of the squirrel stored in the current node
    std::cout << node->value->get_name() << " ";

    // Performs traversal on right child
    in_order_traversal(node->right);
}

int main() {
    // Creating Squirrel objects
    Squirrel carla("Carla");
    Squirrel lucy("Lucy");
    Squirrel lance("Lance");
    Squirrel greta("Greta");
    Squirrel jeff("Jeff");
    Squirrel joker("Joker");
    Squirrel chip("Chip");
    Squirrel dale("Dale");
    Squirrel athena("Athena");

    // Creating Nodes
    TreeNode node_1_root(&carla);
    TreeNode node_2(&lucy);
    TreeNode node_3(&lance);
    TreeNode node_4(&greta);
    TreeNode node_5(&jeff);
    TreeNode node_6(&joker);
    TreeNode node_7(&chip);
    TreeNode node_8(&dale);
    TreeNode node_9(&athena);

    // Attaching Nodes to the tree from the Root
    node_1_root.left = &node_2;
    node_1_root.right = &node_3;
    node_1_root.left->left = &node_4;
    node_1_root.left->left->left = &node_5;
    node_1_root.left->left->right = &node_6;
    node_1_root.right->left = &node_7;
    node_1_root.right->right = &node_8;
    node_1_root.right->left->right = &node_9;

    // Traversing through the tree in 3 different methods
    std::cout << "Pre-Order Traversal: ";
    pre_order_traversal(&node_1_root);

    std::cout << "\nPost Order Traversal: ";
    post_order_traversal(&node_1_root);

    std::cout << "\nIn-Order Traversal: ";
    in_order_traversal(&node_1_root);
    std::cout << std::endl;

    return 0;
}