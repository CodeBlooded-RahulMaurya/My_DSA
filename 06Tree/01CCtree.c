#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
int max(int a,int b){
    return (a>b)?a:b;
}

struct BstNode* GetNewNode(int data){
struct BstNode* newNode =
 (struct BstNode*)malloc(sizeof(struct BstNode));
(*newNode).data = data;
(*newNode).left = (*newNode).right = NULL;
return newNode;

}

struct BstNode* Insert(struct BstNode* rootPtr, int data){
if(rootPtr == NULL){
rootPtr = GetNewNode(data);
}
else if(data <= rootPtr->data) {
rootPtr->left = Insert(rootPtr->left, data);
}
else {
rootPtr->right = Insert(rootPtr->right, data);
}
return rootPtr;
}

int Search(struct BstNode* rootPtr, int data) {
if(rootPtr == NULL) {
return 0;
}
else if(rootPtr->data == data) {
return 1;
}
else if(data <= rootPtr->data) {
return Search(rootPtr->left, data);
}
else {
return Search(rootPtr->right, data);
}
}
void print2DUtil(struct BstNode *root, int space) 
{ 
	// Base case 
	if (root == NULL) 
		return; 

	// Increase distance between levels 
	space += COUNT; 

	// Process right child first 
	print2DUtil(root->right, space); 

	// Print current BstNode after space 
	// count 
	printf("\n"); 
	for (int i = COUNT; i < space; i++) 
		printf(" "); 
	printf("%d\n", root->data); 

	// Process left child 
	print2DUtil(root->left, space); 
} 

// Wrapper over print2DUtil() 
void print2D(struct BstNode *root) 
{ 
// Pass initial space count as 0 
print2DUtil(root, 0); 
} 
int findHeight(struct BstNode * rt){
    if(rt==NULL)
    return -1;
    return max(findHeight(rt->left),findHeight(rt->right))+1;
}
void printLevel(struct BstNode * rt){
	if(rt==NULL)
	return ;
	printf("%d ",rt ->data);
	printLevel(rt->left);
	printLevel(rt->right);
}

int main(void){
struct BstNode* rootPtr;
rootPtr = NULL;
rootPtr = Insert(rootPtr, 15);
rootPtr = Insert(rootPtr, 10);
rootPtr = Insert(rootPtr, 20);
rootPtr = Insert(rootPtr, 5);
rootPtr = Insert(rootPtr, 30);
rootPtr = Insert(rootPtr, 25);
int n;
print2D(rootPtr);
printf("Enter number to be searched: \n");
scanf("%d",&n);
if(Search(rootPtr, n) == 1) {
printf("Found\n");
}
else {
printf("Not Found\n");
}
printf("max : %d\n",findHeight(rootPtr));
printLevel(rootPtr);
return 0;
}

