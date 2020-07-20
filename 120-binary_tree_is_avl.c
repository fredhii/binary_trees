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
 * _avl_checker - Checks if a binary tree is a valid AVL tree
 * @tree: Binary tree
 * @lowest: Smallest node to check
 * @highest: Biggest node to check
 * Return: 1 if is valid, 0 otherwise
 */
int _avl_checker(const binary_tree_t *tree, int lowest, int highest)
{
	size_t hLeft, hRight, diff;

	if (tree)
	{
		if (tree->n < lowest || tree->n > highest)
			return (0);
		hLeft = _bt_height(tree->left);
		hRight = _bt_height(tree->right);
		diff = hLeft > hRight ? hLeft - hRight : hRight - hLeft;
		if (diff > 1)
			return (0);
		return (_avl_checker(tree->left, lowest, tree->n - 1) &&
				_avl_checker(tree->right, tree->n + 1, highest));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid
 *                      Adelson-Velsky and Landis Tree
 * @tree: Binary tree
 * Return: 1 if is valid, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_avl_checker(tree, INT_MIN, INT_MAX));
}
