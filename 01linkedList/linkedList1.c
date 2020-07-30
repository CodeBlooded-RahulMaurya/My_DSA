//SIMPLE PROGRAM TO ADD NUMBERS at end in LINKED LIST 
#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *link;
};
int main(){
    struct node *head,*next_add,*temp;
    int n,i,j;
    next_add = (struct node *)malloc(sizeof(struct node));
    head = next_add;
    printf("ENTER NO. OF VALUES YOU WANT TO ENTER \n");
    scanf("%d",&n);
    printf("Enter values one by one :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&next_add->data);
        temp= (struct node *)malloc(sizeof(struct node));
        temp->link= NULL;
        next_add->link=temp;
        next_add=temp;
    }
    printf("Values entered in linked list : \n");
    temp=head;
    while(temp->link!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
  printf("ENDED\n");
    
    
    
    return 0;
}