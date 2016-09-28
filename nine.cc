/*############################################################################
#                                                                            #
#  treetrav.cc                                                               #
#                                                                            #
#  Complete by: Oliver Keh                                                   #
#                                                                            #
#  April 17, 2016                                                            #
#                                                                            #
#  This file provides methods that analyze trees and provide information on  #
#  the number of nodes, branches, leaves, height, whether or not it is full  #
#  or balanced, and a function that allows different ways of traversing a    #
#  tree.                                                                     #
#                                                                            #
############################################################################*/

#include "treetrav.h"

size_t count_nodes(node *tree)
{
    // if the tree is empty, returns zero 
    if (tree == NULL)
        return 0;

    // otherwise adds nodes to the left and right including the root
    return (count_nodes(tree -> left) + count_nodes(tree -> right) + 1);
}

size_t count_branches(node *tree)
{
    // if the tree is empty, returns zero
    if (tree == NULL)
        return 0;

    /* otherwise, counts the number of nodes and subtracts the root to find
       the number of branches */
    return (count_nodes(tree) - 1);
}

size_t count_leaves(node * tree)
{
    // if the tre is empty, returns zero
    if (tree == NULL)
        return 0;

    // returns 1 if the node is a singleton or a leaf
    if (tree -> left == NULL && tree -> right == NULL)
        return 1;
    
    // counts number of leaves to right and left of each subtree
    return (count_leaves(tree -> left) + count_leaves(tree -> right));
}

double branching_factor(node *tree)
{
    // returns 0 if tree is empty or has only 1 node
    if (count_nodes(tree) <= 1)
        return 0.0;

    /* divides number of branches by internal nodes and returns branching
       factor */
    return (count_branches(tree)/ (double) (count_nodes(tree) -
            count_leaves(tree)));
}

size_t height(node *tree)
{
    // returns 0 if tree is empty
    if (tree == NULL)
        return 0;

    // if tree is a singleton or node is a leaf, returns 1
    if (tree -> left == NULL and tree -> right == NULL)
        return 1;
    
    // calculates height of tree to left and right of subtree
    size_t left_tree = height(tree -> left);
    size_t right_tree = height(tree -> right);

    /* if height of left subtree is greater than the height of the right
       subtree, the height of the left subtree is returned, otherwise the
       right subtree is returned */
    if (left_tree > right_tree)
        return left_tree + 1;
    return right_tree + 1;
    
}
void depth_traverse(node *tree, 
            Direction direction, Order order, 
            void (*visit)(node *tree))
{
    // if the tree is empty, returns
    if (tree == NULL)
        return;

    // checks if the direction to check goes from left to right
    else if (direction == LEFTTORIGHT) {
        
        // checks if the order to traverse is preorder
        if (order == PREORDER) {

	    // visits node first
            visit(tree);
	    
	    // traverses to the left and right subtrees from node
            depth_traverse(tree -> left, direction, order, visit);
            depth_traverse(tree -> right, direction, order, visit);
        }

	// checks if the order to travers is inorder
        else if (order == INORDER) {

	    // traverses to left from node
            depth_traverse(tree -> left, direction, order, visit);

	    // visits the node after all left nodes have been traversed
            visit(tree);

	    // traverses to right from node
            depth_traverse(tree -> right, direction, order, visit);
        }

	// checks if the order to traverse is postorder
        else {

      	    // traverses to the left and right subtrees from node
            depth_traverse(tree -> left, direction, order, visit);
            depth_traverse(tree -> right, direction, order, visit);
	    
	    // visits the node after left and right nodes have been traversed
            visit(tree);
        }
    }

    // checks if the direction to check goes from right to left
    else if (direction == RIGHTTOLEFT) {

        // checks if the order to traverse is preorder
        if (order == PREORDER) {

	    // visits the node before traversing
            visit(tree);

	    // traverses to the left and right subtrees from node
            depth_traverse(tree -> right, direction, order, visit);
            depth_traverse(tree -> left, direction, order, visit);
        }

	// checks if the order to traverse is inorder
        else if (order == INORDER) {

	    // traverses to right from node
            depth_traverse(tree -> right, direction, order, visit);

	    // visits the node after traversing rightwards
            visit(tree);

	    // traverses to left from node
            depth_traverse(tree -> left, direction, order, visit);
        }

	// checks if the order to traverse is postorder
        else {

	    // traverses to the left and right subtrees from node
            depth_traverse(tree -> right, direction, order, visit);
            depth_traverse(tree -> left, direction, order, visit);

	    // visits the node after traversing both directions
            visit(tree);
        }
    }
}

bool is_full(node *tree)
{
    /* returns true if the tree is full from a branching factor of 2, from
       an empty tree or a singleton tree */
    if ((branching_factor(tree) == 2.0) or tree == NULL or (tree -> left
         == NULL && tree -> right == NULL))
        return true;

    // if the tree is not full, returns false
    return false;
}

bool is_equal(node *tree1, node *tree2)
{
    // returns true if the node is a leaf or trees are singelton
    if (tree1 == NULL && tree2 == NULL)
        return true;

    // checks if the number of nodes in each tree are the same
    if (count_nodes(tree1) == count_nodes(tree2)) {

        // checks if the data at each node is equal in each tree
        if (tree1 -> data == tree2 -> data) {

	    // traverses to left and right nodes in each tree
            is_equal(tree1 -> left, tree2 -> left);
            is_equal(tree1 -> right, tree2 -> right);

	    // returns true if all the data values in each node is equal
            return true;
        }

	// if the trees are not equal, returns false
        return false;
    }

    // if the trees are not equal, returns false
    else
        return false;
}

bool is_balanced(node * tree)
{
    // if the tree is empty, returns true
    if (tree == NULL)
        return true;

    /* checks if height at each subtree differs by no less than 1 and returns
       true if the tree is balanced */
    if (is_balanced(tree -> left) && is_balanced(tree -> right) &&
        (abs(height(tree -> left) - height(tree -> right) < 2))) {
        return true;
    }

    // returns false if the tree is not balanced
    return false;
}



