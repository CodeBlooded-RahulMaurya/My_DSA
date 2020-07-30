//Tree implementation in C for $ max and $ min values and $ Height of Tree
#include<stdio.h>
#include<stdlib.h>

struct BST {
    int data ;
    struct BST * left;
    struct BST * right ;
};

struct BST * getNewNode(int d){
    struct BST * new = (struct BST *)malloc(sizeof(struct BST));
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int max(int a,int b){
    return (a>b)?a:b;
}

struct BST * insert(struct BST * rt, int d){
    if(rt == NULL){
        rt = getNewNode( d);
    }
    else if(d <= rt->data){
        rt->left  =  insert(rt->left,d);
    }
    else {
        rt->right = insert(rt->right,d);
    }
    return rt;
}

int search(struct BST * rt , int d){
    if(rt==NULL){
        return 0;
    }
    else if(rt->data==d)
    return 1;
    else if(d < rt->data){
        search(rt->left,d);
    }
    else search(rt->right,d);
}

int minTree(struct BST * rt){
while(rt->left!=NULL){
    rt = rt->left;
}
printf("min : %d \n",rt->data);
return rt->data;
}

int maxTree(struct BST * rt){
    while(rt->right!=NULL){
        rt = rt ->right;
    }
    printf("max : %d \n",rt->data);
    return rt->data;
}

int findHeight(struct BST * rt){
    if(rt==NULL)
    return -1;
    return max(findHeight(rt->left),findHeight(rt->right))+1;
}

int main(){
    struct BST * root = NULL;
    int n,x;
    printf("How many numbers you want to enter ? : ");
    scanf("%d",&n);
    printf("ENter numbers : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root = insert(root,x);
    }
    printf("Which number you want to search in Tree : ");
    scanf("%d",&x);
    if(search(root,x)==1)
    printf("Found \n");
    else printf("Not found \n");
    maxTree(root);
    minTree(root);
    printf("Height : %d",findHeight(root));
    return 0;
}