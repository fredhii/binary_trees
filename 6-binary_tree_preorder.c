#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree in preorder
 * @tree: Binary tree.
 * @func: Function to print value in node
 * Return: None
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
