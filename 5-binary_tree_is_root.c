#include "binary_trees.h"

/**
 * binary_tree_is_root - Check if node is root in binary tree
 * @node: Node to check.
 * Return: 1 if is root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->left && node->right)
		return (1);

	return (0);
}
