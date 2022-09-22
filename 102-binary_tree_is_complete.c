#include "binary_trees.h"
/**
 * binary_tree_is_complete - is complete
 * @tree: tree
 * Return: 0 in false 1 in true
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	unsigned int i = 0;
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	return (check(tree, i, size));
}
/**
 * check - helper func for binary_tree_is_complete
 * @tree: tree
 * @index: current node
 * @size: size
 * Return: 0 in false 1 in true
 */
int check(const binary_tree_t *tree, unsigned int index, size_t size)
{
	int isComplete = 0;

	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	isComplete = check(tree->left, 2 * index + 1, size) &&
		check(tree->right, 2 * index + 2, size);
	return (isComplete);
}

/**
 * binary_tree_size - measure the size
 * @tree: input
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int size;

	if (tree == NULL)
		return (0);

	size = 1 + binary_tree_size(tree->right) + binary_tree_size(tree->left);

	return (size);
}
