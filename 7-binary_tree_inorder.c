#include "binary_trees.h"

/**
 * binary_tree_inorder - traversing binary tree (in-order).
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 * Return: void.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/* recursion on left subtree. */
	binary_tree_inorder(tree->left, func);

	/* using node value */
	func(tree->n);

	/* recursion on right subtree. */
	binary_tree_inorder(tree->right, func);
}
