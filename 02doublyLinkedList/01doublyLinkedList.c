//implementation of Doubly Linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
struct node * head=NULL;
struct node * makeNewNode(int  d){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->next=NULL;
    newNode->data=d;
    return newNode;
}
void insertAtHead(int d){
    struct node * newNode = makeNewNode(d);
    if(head==NULL){
        head=newNode;
        return;
    } 
    head->prev=newNode;
    newNode->next=head;
    head=newNode;

}
void insertAtTail(int d){
    struct node * h=head,*newNode;
    newNode=makeNewNode(d);
    if(h==NULL){
        head=newNode;
        return;
    }
    while(h->next!=NULL){
        h=h->next;
    }
    newNode->prev=h;
    h->next=newNode;
}
void print(struct node * head){
    struct node * h=head;
    while(h!=NULL){
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
}
void reversePrint(struct node * head){
    struct node * h=head;
    while(h->next!=NULL){
     h=h->next;
    }
    while(h!=NULL)
    {
        printf("%d ",h->data);
        h=h->prev;    }
    printf("\n");
}
int main(){
    int n,x;
    printf("how many values you want to enter ?\n");
    scanf("%d",&n);
    printf("Enter values one by one \n");
    for(int i=0;i<n;i++){
   scanf("%d",&x);
   insertAtTail(x);
   print(head);
   reversePrint(head);
    }
    return 0;
}