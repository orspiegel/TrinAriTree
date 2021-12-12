#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utils.h"
#define COUNT 8
/***********************************************************************************
* Name: Or Spiegel
* ID: 318720067
* Group: 1
* Assignment: ex6
***********************************************************************************/
// Function to print Trinary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct node* root, int space)
{
	// Base case 
	if (root == NULL)
		return;

	// Increase distance between levels 
	space += COUNT;

	// Process right child first 
	print2DUtil(root->right, space);
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%s %d\n", root->name, root->id);
	// Process middle child 
	print2DUtil(root->middle, space);
	printf("\n");
	// Process left child 
	print2DUtil(root->left, space);
}