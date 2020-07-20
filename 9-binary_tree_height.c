#include "binary_trees.h"

/**
 * binary_tree_height - Mearure the height of a binary tree
 * @tree: Binary tree
 * Return: Binary tree height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t tLeft = 0, tRight = 0;

	if (tree)
	{
		tLeft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		tRight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((tLeft > tRight) ? tLeft : tRight);
	}

	return (0);
}
