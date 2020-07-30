//Level Order traversal $ breadth first search Using Queue
#include<stdio.h>
#include<stdlib.h>
#define COUNT 10
struct node {
    struct BST * data;
    struct node * next;
};
struct BST{
  int data;
  struct BST * left;
  struct BST * right;
};
struct node * front, * rear = NULL;
void dequeue(){
  if(front==NULL && rear==NULL){
      printf("Error : Queue is empty \n");
      return ;
  }
  struct node * temp = front;
  front = front-> next;
  free(temp);
}

void enqueue(struct BST *  d)
{   
    struct node * newAdd = (struct node * )malloc(sizeof(struct node));
    newAdd->data = d;
    newAdd->next = NULL;
    if(front == NULL && rear == NULL){
     front = newAdd;
     rear = newAdd;
    }
    else {
        rear->next = newAdd;
        rear = newAdd;
    }
}
int isEmpty(){
    if(front == NULL && rear == NULL){
     //   printf("Empty\n");
        return 1;
    }
    else 
    {
      //  printf("Not Empty\n");
        return 0;
}
}

struct BST *  Front(){
 if(front==NULL&&rear==NULL)
     printf("Error : Queue is empty \n");
 else {return front->data;
 }    
}

void Print(){
    struct node * temp = front;
    printf("ELements : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp ->next;
    }
    printf("\n");
}
struct BST * getNewNode(int d){
    struct BST * temp = (struct BST *)malloc(sizeof(struct BST));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct BST * insert(struct BST *  rt,int d){
    if(rt==NULL){
        rt =  getNewNode(d);
    }
    else if(d<= rt->data) rt->left = insert(rt->left,d);
          
        else rt ->right =  insert(rt->right,d);
    
    return rt;
}



int search(struct BST * rt, int d){
    if(rt == NULL)
    return 0;
     else if(rt->data == d)
    return 1;
    else if(d<rt->data) search(rt->left,d);
    else if(d>rt->data) search(rt->right,d);
}

void levelOrder(struct BST * rt){
    struct BST * temp ;
    if(rt == NULL)
    return ;
    enqueue(rt);
    while(!isEmpty()){
        temp  = Front();
        printf("%d ",temp->data);
       if(temp->left!=NULL) enqueue(temp->left);
        if(temp->right!=NULL ) enqueue(temp->right);

        dequeue();
    }

}

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
   levelOrder(root);
    return 0;
}
