#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotate right
 * @tree: tree
 * Return: 0 in false 1 in true
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp, *PARENT;
	int left_child;

	if (tree == NULL)
		return (NULL);
	left_child = 0;
	tmp = tree->left;
	if (tmp != NULL)
	{
		PARENT = tree->parent;
		if (PARENT != NULL)
			left_child = tree->parent->left == tree;

		tree->left = tmp->right;
		if (tmp->right)
			tmp->right->parent = tree;
		tree->parent = tmp;

		tmp->right = tree;
		tmp->parent = PARENT;
		if (PARENT != NULL)
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
