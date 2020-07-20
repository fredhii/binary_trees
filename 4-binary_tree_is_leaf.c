#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if node is a leaf in binary tree
 * @node: Node to check.
 * Return: 1 if is leaf, 0 if is not a leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);

	return (0);
}
