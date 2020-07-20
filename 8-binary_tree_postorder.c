#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree in posorder
 * @tree: Binary tree.
 * @func: Function to print value in node
 * Return: None
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
