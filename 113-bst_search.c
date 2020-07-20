#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Binary tree
 * @value: Value to search for
 * Return: Pointer to value found or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
