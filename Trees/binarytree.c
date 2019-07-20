#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void preorder(struct node *root)
{
	if (root)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

//Finding size of binary tree
int size(struct node *root)
{
	if (root == NULL)
		return 0;
	else
		return size(root->left) + 1 + size(root->right);
}

//Finding height of binary tree
int height(struct node *root)
{
	int lefth, righth;
	if (root == NULL)
		return 0;
	else
	{
		//Compute the depth of each subtree
		lefth = height(root->left);
		righth = height(root->right);
		if (lefth > righth)
			return (lefth + 1);
		else
			return (righth + 1);
	}
