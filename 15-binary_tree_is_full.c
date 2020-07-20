#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Binary tree
 * Return: 1 if is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int lSize, rSize;

	if (tree)
	{
		if (!tree->right && !tree->left)
			return (1);

		lSize = binary_tree_is_full(tree->left);
		rSize = binary_tree_is_full(tree->right);

		return ((lSize == 0 || rSize == 0) ? 0 : 1);
	}
	return (0);
}
