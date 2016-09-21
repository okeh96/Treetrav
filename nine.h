// nine.h
// Alistair Campbell

// Headers for "nine functions on trees"

#ifndef NINE
#define NINE

#include <cstdlib>

struct node {
  int data;
  node *left;
  node *right;
  node(int data, node *left, node *right): data(data), 
					   left(left), right(right) {}
};

enum Direction {LEFTTORIGHT, RIGHTTOLEFT};
enum Order {INORDER, PREORDER, POSTORDER};

size_t count_nodes(node *tree);

size_t count_branches(node *tree);

size_t count_leaves(node *tree);

double branching_factor(node *tree);

size_t height(node *tree);

void depth_traverse(node *tree, 
		    Direction direction, Order order, 
		    void (*visit)(node *tree));

bool is_full(node *tree);

bool is_equal(node *tree);

bool is_balanced(node *tree);

#endif
