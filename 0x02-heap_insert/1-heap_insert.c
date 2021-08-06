#include "binary_trees.h"

/**
* heap_insert -  Heap insert
*
* @root: node root
* @value: value to inser
*
* Return: node
*/
heap_t *heap_insert(heap_t **root, int value)
{
	size_t i, tmp;
	size_t level = 0;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node((binary_tree_t *) *root, value);
		return (*root);
	}
	level = height_check(*root);
	for (i = 0; i <= level; i++)
	{
		node = (heap_t *) insert_node((binary_tree_t *) *root, i, value);
		if (node)
		{
			break;
		}
	}
	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
	return (node);
}

/**
* height_check - Height of the tree
*
* @tree: node
*
* Return: height
*/
size_t height_check(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (!tree)
	{
		return (0);
	}
	if (leaf_check(tree) == 1)
	{
		return (0);
	}

	left_height = height_check(tree->left);
	right_height = height_check(tree->right);

	if (left_height >= right_height)
	{
		return (1 + left_height);
	}
	return (1 + right_height);
}

/**
* leaf_check - leaf node check
*
* @node: node
*
* Return: status
*/
int leaf_check(const binary_tree_t *node)
{
	if (!node)
	{
		return (0);
	}
	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	return (0);
}

/**
* insert_node - inser node
*
* @tree: tree
* @level: level
* @value: new node
*
* Return: insertion
*/
binary_tree_t *insert_node(binary_tree_t *tree, size_t level, int value)
{
	binary_tree_t *left, *right;

	if (!tree)
	{
		return (NULL);
	}
	if (depth_check(tree) == level)
	{
		if (leaf_check(tree))
		{
			return (tree->left = binary_tree_node(tree, value));
		}
		if (tree->left != NULL && tree->right == NULL)
		{
			return (tree->right = binary_tree_node(tree, value));
		}
		return (NULL);
	}
	left = insert_node(tree->left, level, value);
	if (left == NULL)
	{
		right = insert_node(tree->right, level, value);
	}
	else
	{
		return (left);
	}
	return (right);
}

/**
* depth_check -  Check deepth of the tree
*
* @tree: tree to check
*
* Return: number of levels
*/
size_t depth_check(const binary_tree_t *tree)
{
	int i = 0;

	if (tree == NULL)
	{
		return (0);
	}
	while (tree->parent != NULL)
	{
		i++;
		tree = tree->parent;
	}
	return (i);
}
