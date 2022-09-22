#include "binary_trees.h"
/**
 * binary_tree_rotate_left - rotate left
 * @tree: tree
 * Return: 0 in false 1 in true
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp, *PARENT;
	int left_child;

	if (tree == NULL)
		return (NULL);
	left_child = 0;
	tmp = tree->right;
	if (tmp != NULL)
	{
		PARENT = tree->parent;
		if (PARENT != NULL)
			left_child = tree->parent->left == tree;

		tree->right = tmp->left;
		if (tmp->left)
			tmp->left->parent = tree;
		tree->parent = tmp;

		tmp->left = tree;
		tmp->parent = PARENT;
		if (PARENT)
		{
			if (left_child)
				PARENT->left = tmp;
			else
				PARENT->right = tmp;
		}
	}
	while (tree->parent)
		tree = tree->parent;
	return (tree);
}
