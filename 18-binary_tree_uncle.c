#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds node's uncle in binary tree.
 * @node: Node's pointer.
 * Return: Pointer to uncle or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
