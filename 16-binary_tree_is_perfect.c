#include "binary_trees.h"

/**
 * _bite_height - Mearure the height of a binary tree
 * @tree: Binary tree
 * Return: Binary tree height
 */
size_t _bite_height(const binary_tree_t *tree)
{
	size_t tLeft = 0, tRight = 0;

	if (tree)
	{
		tLeft = tree->left ? 1 + _bite_height(tree->left) : 1;
		tRight = tree->right ? 1 + _bite_height(tree->right) : 1;
		return ((tLeft > tRight) ? tLeft : tRight);
	}
	return (0);
}

/**
 * _bite_balance - Measures balance factor of a binary tree
 * @tree: Binary tree
 * Return: Tree balance factor
 */
int _bite_balance(const binary_tree_t *tree)
{
	if (tree)
		return (_bite_height(tree->left) - _bite_height(tree->right));

	return (0);
}

/**
 * _bt_is_full - Checks if a binary tree is full
 * @tree: Binary tree
 * Return: 1 if is full, 0 otherwise
 */
int _bt_is_full(const binary_tree_t *tree)
{
	int lSize, rSize;

	if (tree)
	{
		if (!tree->right && !tree->left)
			return (1);

		lSize = _bt_is_full(tree->left);
		rSize = _bt_is_full(tree->right);

		return ((lSize == 0 || rSize == 0) ? 0 : 1);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: tree to check from
 * Return: returns 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree)
		if (_bt_is_full(tree) && _bite_balance(tree) == 0)
			return (1);
	return (0);
}
