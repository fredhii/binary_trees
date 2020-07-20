#include "binary_trees.h"

/**
 * _bst_checker - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Binary tree
 * @lowest: Smallest node to check
 * @highest: Biggest node to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int _bst_checker(const binary_tree_t *tree, int lowest, int highest)
{
	if (tree)
	{
		if (tree->n < lowest || tree->n > highest)
			return (0);
		return (_bst_checker(tree->left, lowest, tree->n - 1) &&
			_bst_checker(tree->right, tree->n + 1, highest));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Binary tree
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_bst_checker(tree, INT_MIN, INT_MAX));
}
