#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds node siblings in binary tree.
 * @node: pointer to node
 * Return: Pointer to sibling or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
