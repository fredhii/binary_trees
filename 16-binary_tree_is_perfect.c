#include "binary_trees.h"

/**
 * bte_is_leaf - Check if node is a leaf in binary tree
 * @node: Node to check
 * Return: 1 if is leaf, 0 otherwise
 */
unsigned char bte_is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Returns the depth of a BT
 * @tree: Binary tree
 * Return: Depth from node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: Binary tree
 * Return: Pointer to leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (bte_is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * _check_if_perfect - Checks if a binary tree is perfect
 * @tree: Binary tree
 * @leaf_depth: Depth node
 * @level: Current node
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int _check_if_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (bte_is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (_check_if_perfect(tree->left, leaf_depth, level + 1) &&
		_check_if_perfect(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: tree to check from
 * Return: returns 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_check_if_perfect(tree, depth(get_leaf(tree)), 0));
}
