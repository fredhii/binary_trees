#include "binary_trees.h"

/**
 * _bt_height - Mearure the height of a binary tree
 * @tree: Binary tree
 * Return: Binary tree height
 */
size_t _bt_height(const binary_tree_t *tree)
{
	size_t tLeft = 0, tRight = 0;

	if (tree)
	{
		tLeft = tree->left ? 1 + _bt_height(tree->left) : 1;
		tRight = tree->right ? 1 + _bt_height(tree->right) : 1;
		return ((tLeft > tRight) ? tLeft : tRight);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: Binary tree
 * Return: Tree balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (_bt_height(tree->left) - _bt_height(tree->right));

	return (0);
}
