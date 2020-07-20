#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree
 * @tree: Binary tree.
 * Return: None
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
	{
		/* Pos-order iteration */
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
