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
		tLeft = tree->left ? 1 + _bt_height(tree->left) : 0;
		tRight = tree->right ? 1 + _bt_height(tree->right) : 0;
		return ((tLeft > tRight) ? tLeft : tRight);
	}

	return (0);
}

/**
 * _bt_order - Goes trough binary tree using levelorder
 * @tree: Binary tree
 * @level: Tree level
 * @func: Function to print node
 */
void _bt_order(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (level == 1)
		func(tree->n);
	else
	{
		_bt_order(tree->left, level - 1, func);
		_bt_order(tree->right, level - 1, func);
	}
}
/**
* binary_tree_levelorder - Goes through a binary tree
*						   using level-order traversal
* @tree: Binary tree
* @func: Function to print node
* Return: None
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i = 0, level;

	if (!tree || !func)
		return;

	level = _bt_height(tree);

	while (i < level)
	{
		_bt_order(tree, i, func);
		i++;
	}
}
