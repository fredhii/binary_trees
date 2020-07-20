#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: First node's pointer
 * @second: Second node's pointer
 * Return: Pointer to ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *mommy, *daddy;

	if (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		mommy = first->parent;
		daddy = second->parent;
		if (first == daddy || !mommy || (!mommy->parent && daddy))
			return (binary_trees_ancestor(first, daddy));
		else if (mommy == second || !daddy || (!daddy->parent && mommy))
			return (binary_trees_ancestor(mommy, second));
		return (binary_trees_ancestor(mommy, daddy));
	}
	return (NULL);
}
