#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Binary tree
 * @value: Value to insert
 * Return: Pointer to new node or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp;

	if (tree)
	{
		if (!(*tree))
		{
			*tree = binary_tree_node(NULL, value);
			return (*tree);
		}
		tmp = *tree;
		while (tmp)
		{
			if (tmp->n == value)
				break;
			if (tmp->n > value)
			{
				if (!tmp->left)
				{
					tmp->left = binary_tree_node(tmp, value);
					return (tmp->left);
				}
				tmp = tmp->left;
			}
			else if (tmp->n < value)
			{
				if (!tmp->right)
				{
					tmp->right = binary_tree_node(tmp, value);
					return (tmp->right);
				}
				tmp = tmp->right;
			}
		}
	}
	return (NULL);
}
