
#include<stdio.h> 
#include<malloc.h> 
#define COUNT 10 

// A binary tree BST 
struct BST 
{ 
	int data; 
	struct BST* left, *right; 
}; 

// Helper function to allocates a new BST 
struct BST* getNewNode(int data) 
{ 
	struct BST* BST = malloc(sizeof(struct BST)); 
	BST->data = data; 
	BST->left = BST->right = NULL; 
	return BST; 
} 

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct BST *root, int space) 
{ 
	// Base case 
	if (root == NULL) 
		return; 

	// Increase distance between levels 
	space += COUNT; 

	// Process right child first 
	print2DUtil(root->right, space); 

	// Print current BST after space 
	// count 
	printf("\n"); 
	for (int i = COUNT; i < space; i++) 
		printf(" "); 
	printf("%d\n", root->data); 

	// Process left child 
	print2DUtil(root->left, space); 
} 

// Wrapper over print2DUtil() 
void print2D(struct BST *root) 
{ 
// Pass initial space count as 0 
print2DUtil(root, 0); 
} 

// Driver program to test above functions 
int main() 
{ 
	struct BST *root = getNewNode(1); 
	root->left = getNewNode(2); 
	root->right = getNewNode(3); 

	root->left->left = getNewNode(4); 
	root->left->right = getNewNode(5); 
	root->right->left = getNewNode(6); 
	root->right->right = getNewNode(7); 

	root->left->left->left = getNewNode(8); 
	root->left->left->right = getNewNode(9); 
	root->left->right->left = getNewNode(10); 
	root->left->right->right = getNewNode(11); 
	root->right->left->left = getNewNode(12); 
	root->right->left->right = getNewNode(13); 
	root->right->right->left = getNewNode(14); 
	root->right->right->right = getNewNode(15); 
	
	print2D(root); 

	return 0; 
} 
