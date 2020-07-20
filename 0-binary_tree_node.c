#include "binary_trees.h"

/**
 * binary_tree_node - Creates a node froma  binary tree
 * @parent: Base of the binary tree
 * @value: Value to include in node
 * Return: Pointer to binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = new->right = NULL;

	return (new);
}
