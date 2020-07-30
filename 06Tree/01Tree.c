//Bst implementation in c
#include<stdio.h>
#include<stdlib.h>
#define COUNT 10
struct BST {
    int data ;
    struct BST * left;
    struct BST * right;
};


struct BST * getNewNode(int d){
    struct BST * temp =  
    (struct BST *)malloc(sizeof(struct BST));
     temp->data = d;
     temp->left = NULL; temp->right = NULL;
     return temp;
}

struct BST * insert(struct BST * rt, int data){
    if(rt == NULL){
         rt = getNewNode(data);
        
    }
    else if(data <= rt->data){
      rt->left  = insert(rt->left,data);
        }
    else {
    rt->right= insert(rt->right,data);
    }    
   return rt;
}

int search(struct BST * rt,int d){ 
    if(rt==NULL)
    return 0;
    else if(rt->data ==d)
      return 1;
    else if(d<=rt->data)
       return search(rt->left,d);
    else {
        return search(rt->right,d);
    }  
}
//--------------------------------------------
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
int main(){
struct BST * root = NULL;
    root = insert(root,34);
    root = insert(root,123);
    root = insert(root,1);
    root = insert(root,45);
    root = insert(root,718);
    root = insert(root,12);
    root = insert(root,0);
    root = insert(root,4);
    root = insert(root ,31);

  /*   int n,x;
    printf("How many elements you want to enter in TREE? : ");
    scanf("%d",&n);
    printf("Enter elements one by one : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root = insert(root,x);
    }
    print2D(root);
    printf("Which element you want to search in Tree? : ");
    scanf("%d",&x);

    if(search(root,x)==1)
    printf("found\n");
    else  printf(" not found\n");
    
   */
  print2D(root);
   return 0;
}