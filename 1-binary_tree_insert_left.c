#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnod;

	if (parent == NULL)
		return (NULL);

	newnod = (struct binary_tree_s *)malloc(sizeof(binary_tree_t));

	if (newnod == NULL)
		return (NULL);

	newnod->n = value;
	newnod->parent = parent;
	newnod->right = NULL;

	if ((parent->left) != NULL)
		/* shifting left node to be replaced occurs here */
		(parent->left)->parent = newnod;
	{
		newnod->left = parent->left;
		parent->left = newnod;
	}
	return (newnod);
}
