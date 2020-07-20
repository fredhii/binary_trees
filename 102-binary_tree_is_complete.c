#include "binary_trees.h"

/**
 * _bt_nodes - Counts nodes with at least 1 child in a binary tree
 * @tree: Binary tree
 * Return: Node's sum
 */
int _bt_nodes(const binary_tree_t *tree)
{
	int nodes = 0;

	if (!tree)
		return (nodes);

	nodes += _bt_nodes(tree->left) + 1;
	nodes += _bt_nodes(tree->right) + 1;
	return (nodes - 1);
}

/**
 * _check_full - is binary tree complete using index & num nodes
 * @tree: root node
 * @index: index of node
 * @nodes: num of nodes
 * Return: 1 if complete,0 otherwise
 */
int _check_full(const binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);

	if (index >= nodes)
		return (0);

	return (_check_full(tree->left, 2 * index + 1, nodes) &&
		_check_full(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: root node
 * Return: 1 if true 0 if false
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;
	int nodes = _bt_nodes(tree);

	if (!tree)
		return (0);

	return (_check_full(tree, index, nodes));

}
