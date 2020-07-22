#include "binary_trees.h"

/**
 * _bt_height_one - Mearure the height of a binary tree
 * @tree: Binary tree
 * Return: Binary tree height
 */
size_t _bt_height_one(const binary_tree_t *tree)
{
	size_t tLeft = 0, tRight = 0;

	if (tree)
	{
		tLeft = tree->left ? 1 + _bt_height_one(tree->left) : 0;
		tRight = tree->right ? 1 + _bt_height_one(tree->right) : 0;
		return ((tLeft > tRight) ? tLeft : tRight);
	}

	return (0);
}

/**
 * _bt_height_two - Mearure the height of a binary tree
 * @tree: Binary tree
 * Return: Binary tree height
 */
size_t _bt_height_two(const binary_tree_t *tree)
{
	size_t tLeft = 0, tRight = 0;

	if (tree)
	{
		tLeft = tree->left ? 1 + _bt_height_one(tree->left) : 1;
		tRight = tree->right ? 1 + _bt_height_one(tree->right) : 1;
		return ((tLeft > tRight) ? tLeft : tRight);
	}

	return (0);
}

/**
 * _bt_balance - Measures balance factor of a binary tree
 * @tree: Binary tree
 * Return: Tree balance factor
 */
int _bt_balance(const binary_tree_t *tree)
{
	return (tree ? _bt_height_two(tree->left) - _bt_height_two(tree->right) : 0);
}

/**
 * _avl_aux - Inserts a value into an AVL tree
 * @tree: Binary tree
 * @parent: Current node's parent
 * @new: Node to insert
 * @value: Value to insert
 * Return: Pointer to node or NULL
 */
avl_t *_avl_aux(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int factor;

	if (!(*tree))
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = _avl_aux(&(*tree)->left, *tree, new, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = _avl_aux(&(*tree)->right, *tree, new, value);
		if (!(*tree)->right)
			return (NULL);
	}
	else
		return (*tree);

	factor = _bt_balance(*tree);
	if (factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Binary tree
 * @value: Value to insert
 * Return: Pointer to node or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	_avl_aux(tree, *tree, &new, value);
	return (new);
}
