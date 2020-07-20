#include "binary_trees.h"

/**
 * _min_value - Minimum value to search for
 * @root: Binary tree
 * Return: The minimum value in @tree.
 */
bst_t *_min_value(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * _bst_delete - Deletes a node in a binary tree
 * @root: Binary tree
 * @node: Node to delete
 * Return: Pointer to new root or NULL
 */
bst_t *_bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor;

	/* No children or right-child */
	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (!parent ? node->right : root);
	}

	/* Left-child */
	if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = _min_value(node->right);
	node->n = successor->n;

	return (_bst_delete(root, successor));
}

/**
 * _bst_search - Finds node to delete in binary tree
 * @root: Binary tree
 * @node: Node to check
 * @value: Value to search for
 * Return: Pointer to new root or NULL
 */
bst_t *_bst_search(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (node->n == value)
			return (_bst_delete(root, node));
		if (node->n > value)
			return (_bst_search(root, node->left, value));
		return (_bst_search(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: Binary tree
 * @value: Value to remove
 * Return: Pointer to new root or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (_bst_search(root, root, value));
}
